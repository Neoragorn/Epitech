#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <unistd.h>
#include "Grapher.h"
#include "matplotpp.h"

static Grapher *grapher;

static void graph_display()
{
    grapher->display();
}

static void graph_reshape(int w, int h)
{
    grapher->reshape(w, h);
}

static void graph_idle()
{
    glutPostRedisplay();
    usleep(10000);
}

static void graph_mouse(int button, int state, int x, int y)
{
    grapher->mouse(button, state, x, y);
}

static void graph_motion(int x, int y)
{
    grapher->motion(x, y);
}

static void graph_passivemotion(int x, int y)
{
    grapher->passivemotion(x, y);
}

void Grapher::show(int argc, char **argv)
{
    grapher = this;

    glutInit(&argc, argv);
    glutCreateWindow(100, 100, 800, 600);
    glutDisplayFunc(&graph_display);
    glutReshapeFunc(&graph_reshape);
    glutIdleFunc(&graph_idle);
    glutMouseFunc(&graph_mouse);
    glutMotionFunc(&graph_motion);
    glutPassiveMotionFunc(&graph_passivemotion);
    glutMainLoop();
}

void Grapher::DISPLAY()
{
    std::vector<std::pair<Equation, Equation> >::iterator pit;
    std::vector<double> x(20 * 30);
    std::vector<std::vector<double> > values;
    std::vector<double> total(x.size());

    for (unsigned int i = 0; i < x.size(); i++)
    {
        x[i] = -10.0 + 20.0 * i / x.size();
        total[i] = 0;
    }

    for (pit = mPairs.begin(); pit < mPairs.end(); pit++)
    {
        std::vector<double> y(x.size());
        points(*pit, y, total);
        values.push_back(y);
    }

    for (unsigned int i = 0; i < mPairs.size(); i++)
    {
        std::stringstream stream;
        stream << "Composant " << (i + 1);

        layer(stream.str(), 1);
        axis(-10.0, 10.0, -30.0, 30.0);
        grid(1);
        plot(x, values[i]);
    }

    layer("Total", 1);
    axis(-10.0, 10.0, -30.0, 30.0);
    grid(1);
    plot(x, total);
}

void Grapher::points(std::pair<Equation, Equation> &pair,
                     std::vector<double> &y, std::vector<double> &total)
{
    for (unsigned int i = 0; i < y.size(); i++)
    {
        double values[2];

        values[0] = pair.first(-10.0 + 20.0 * i / y.size());
        values[1] = pair.second(-10.0 + 20.0 * i / y.size());

        if (values[1] != 0)
        {
            y[i] = values[0] / values[1];
            if (total[i] != 0)
            {
                total[i] *= y[i];
            }
            else
            {
                total[i] = y[i];
            }
        }
    }
}
