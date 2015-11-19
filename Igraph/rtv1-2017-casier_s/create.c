/*
** create.c for create in /home/casier_s//rtv1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Mar 14 19:13:20 2013 sofian casier
** Last update Fri Jun  7 11:27:48 2013 sofian casier
*/

#include <mlx.h>
#include <X11/X.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

static float            create_paralel(t_expose *expose)
{
  float v1x;
  float v1y;
  float v2x;
  float v2y;
  float k1;
  float k2;

  v1x = PARAL_X3 - PARAL_X1;
  v1y = PARAL_Y3 - PARAL_Y1;
  v2x = PARAL_X2 - PARAL_X1;
  v2y = PARAL_Y2 - PARAL_X1;
  k2 = ((v1x * expose->y) - (expose->x * v1y)) / ((v2y * v1x) - (v1y * v2x));
  k1 = ((expose->x - (k2 * v2x) / v1x));
  if ((k1 > 0 && k1 < 1) || (k2 > 0 && k2 < 1))
    return (1);
  else
    return (-1);
}

float   inter_plan(t_sphere *sphere, t_expose *expose)
{
  float	result;

  sphere->z1 -= Z_PLAN;
  sphere->x1 -= X_1;
  sphere->y1 -= Y_1;
  rotation_x(sphere, PLAN_ROTX);
  rotation_y(sphere, PLAN_ROTY);
  rotation_z(sphere, PLAN_ROTZ);
  if (sphere->z1 == 0)
    return (0);
  sphere->k = - (sphere->zo / sphere->z1);
  rotation_x(sphere, -(PLAN_ROTX));
  rotation_y(sphere, -(PLAN_ROTY));
  rotation_z(sphere, -(PLAN_ROTZ));
  sphere->z1 += Z_PLAN;
  sphere->x1 += X_1;
  sphere->y1 += Y_1;
  result = create_paralel(expose);
  if (sphere->k < 0)
    return (sphere->k1);
  //  else if (result != -1)
  // return (sphere->k);
  else
    return (0);
}

float	create_cone_follow(t_sphere *sphere)
{
  if (sphere->delta < 0)
    return (0);
  else if (sphere->delta == 0)
    {
      sphere->k1 = (-sphere->b) / (2 * sphere->a);
      return (sphere->k1);
    }
  else
    {
      sphere->k1 = (-sphere->b - sqrtf(sphere->delta)) / (2 * sphere->a);
      sphere->k2 = (-sphere->b + sqrtf(sphere->delta)) / (2 * sphere->a);
      if (sphere->k1 < 0 && sphere->k2 < 0)
        return (0);
      else if ((sphere->k2 <= sphere->k1
                && sphere->k2 >= 0) || (sphere->k2 >= 0 && sphere->k1 < 0))
        return (sphere->k2);
      else if ((sphere->k1 <= sphere->k2 && sphere->k1 >= 0)
               || (sphere->k1 >= 0 && sphere->k2 < 0))
        return (sphere->k1);
    }
  return (0);
}

float   create_cone(t_sphere *sphere)
{
  float	k;

  sphere->x1 -= X_CONE;
  sphere->y1 -= Y_CONE;
  sphere->z1 -= Z_CONE;
  rotation_x(sphere, CONE_ROTX);
  rotation_y(sphere, CONE_ROTY);
  rotation_z(sphere, CONE_ROTZ);
  sphere->a = powf(sphere->x1, 2) + powf(sphere->y1, 2)
    - (powf(sphere->z1, 2) / powf(tanf(RAD * ANGLE_CONE), 2));
  sphere->b = 2 * ((sphere->xo * sphere->x1) + (sphere->yo * sphere->y1)
		   - (powf(sphere->zo, 2) / powf(tanf(RAD * ANGLE_CONE), 2)));
  sphere->c = powf(sphere->xo, 2) + powf(sphere->yo, 2)
    - (powf(sphere->zo, 2) / powf(tanf(RAD * ANGLE_CONE), 2));
  rotation_x(sphere, -(CONE_ROTX));
  rotation_y(sphere, -(CONE_ROTY));
  rotation_z(sphere, -(CONE_ROTZ));
  sphere->x1 += X_CONE;
  sphere->y1 += Y_CONE;
  sphere->z1 += Z_CONE;
  sphere->delta = powf(sphere->b, 2) - (4 * sphere->a * sphere->c);
  k = create_cone_follow(sphere);
  return (k);
}

float	create_sphere_follow(t_sphere *sphere)
{
  if (sphere->delta < 0)
    return (0);
  else if (sphere->delta == 0)
    {
      sphere->k1 = (-sphere->b) / (2 * sphere->a);
      return (sphere->k1);
    }
  else
    {
      sphere->k1 = (-sphere->b - sqrtf(sphere->delta)) / (2 * sphere->a);
      sphere->k2 = (-sphere->b + sqrtf(sphere->delta)) / (2 * sphere->a);
      if (sphere->k1 < 0 && sphere->k2 < 0)
        return (0);
      else if ((sphere->k2 <= sphere->k1
                && sphere->k2 >= 0) || (sphere->k2 >= 0 && sphere->k1 < 0))
        return (sphere->k2);
      else if ((sphere->k1 <= sphere->k2 && sphere->k1 >= 0)
               || (sphere->k1 >= 0 && sphere->k2 < 0))
        return (sphere->k1);
    }
  return (0);
}

float   create_sphere(t_sphere *sphere)
{
  float k;

  sphere->x1 -= X_SPHERE;
  sphere->y1 -= Y_SPHERE;
  sphere->z1 -= Z_SPHERE;
  rotation_x(sphere, SPHERE_ROTX);
  rotation_y(sphere, SPHERE_ROTY);
  rotation_z(sphere, SPHERE_ROTZ);
  sphere->a = powf(sphere->x1, 2) + powf(sphere->y1, 2) + powf(sphere->z1, 2);
  sphere->b = 2 * ((sphere->xo * sphere->x1)
		   + (sphere->yo * sphere->y1) + (sphere->zo * sphere->z1));
  sphere->c = powf(sphere->xo, 2) + powf(sphere->yo, 2)
    + powf(sphere->zo, 2) - powf(R_SPHERE, 2);
  rotation_x(sphere, -(PLAN_ROTX));
  rotation_y(sphere, -(PLAN_ROTY));
  rotation_z(sphere, -(PLAN_ROTZ));
  sphere->x1 += X_SPHERE;
  sphere->y1 += Y_SPHERE;
  sphere->z1 += Z_SPHERE;
  sphere->delta = powf(sphere->b, 2) - (4 * sphere->a * sphere->c);
  k = create_sphere_follow(sphere);
  return (k);
}

