#include <iostream>
#include <math.h>
#include "Equation.h"
#include "Benchmark.h"
#include "Timer.h"

void Benchmark::run()
{
    runNaive();
    runHorner();
}

void Benchmark::runNaive()
{
    Timer timer;

    timer.start();
    for (double x = 0; x < 1000; x += 0.001)
    {
        mEquation(x);
    }
    timer.stop();
    std::cout << "Methode naive: " << timer.diff() << " ms" << std::endl;
}

static double horner(Equation &eq, double x)
{
    double y = eq[0];
    for (int n = 0; n < eq.size(); n++)
    {
        int puissance = eq.size() - n - 1;
        y = (x * y) + puissance;
    }
    return y;
}

void Benchmark::runHorner()
{
    Timer timer;

    timer.start();
    for (double x = 0; x < 1000; x += 0.001)
    {
        horner(mEquation, x);
    }
    timer.stop();
    std::cout << "Methode de Horner: " << timer.diff() << " ms" << std::endl;
}
