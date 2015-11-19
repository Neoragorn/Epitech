#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "Equation.h"
#include "Grapher.h"
#include "Benchmark.h"
#include "Timer.h"

static void benchmark(Equation &eq)
{
    Benchmark benchmark(eq);

    benchmark.run();
}

static void graph(std::vector<Equation> &eqs, int argc, char **argv)
{
    Grapher grapher;
    std::vector<Equation>::iterator eit;
    std::vector<std::pair<Equation, Equation> >::iterator pit;

    for (eit = eqs.begin(); eit < eqs.end(); eit += 2)
    {
        std::pair<Equation, Equation> pair(*eit, *(eit + 1));
        grapher.pairs().push_back(pair);
    }

    for (pit = grapher.pairs().begin(); pit < grapher.pairs().end(); pit++)
    {
        std::cout << pit->first << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << pit->second << std::endl << std::endl;
    }

    grapher.show(argc, argv);
}

int main(int argc, char **argv)
{
    try
    {
        if (argc == 2)
        {
            std::string eqStr(argv[1]);
            Equation eq(eqStr, true);

            if (eq.size() > 0)
            {
                benchmark(eq);
            }
            else
            {
                throw std::runtime_error("Erreur: Equation vide!");
            }
        }
        else if (argc > 2 && (argc - 1) % 2 == 0)
        {
            std::vector<Equation> eqs;
            for (int i = 1; i < argc; i++)
            {
                std::string eqStr(argv[i]);
                Equation eq(eqStr);
                eqs.push_back(eq);
            }
            graph(eqs, argc, argv);
        }
        else
        {
            throw std::runtime_error("Mauvais nombre d'arguments!");
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
