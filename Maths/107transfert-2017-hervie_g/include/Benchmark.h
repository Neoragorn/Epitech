#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include "Equation.h"

class Benchmark
{
public:
    Benchmark(Equation &equation): mEquation(equation) {}

    void run();
    void runNaive();
    void runHorner();

private:
    Equation &mEquation;
};

#endif /* BENCHMARK_H_ */
