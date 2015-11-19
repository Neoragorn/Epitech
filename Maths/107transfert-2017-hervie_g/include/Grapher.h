#ifndef GRAPHER_H_
#define GRAPHER_H_

#include <vector>
#include <utility>
#include "Equation.h"
#include "matplotpp.h"

class Grapher: public MatPlot
{
public:
    void show(int argc, char **argv);
    void DISPLAY();
    void points(std::pair<Equation, Equation> &pair, std::vector<double> &y,
                std::vector<double> &total);

    inline std::vector<std::pair<Equation, Equation> > &pairs(void)
    {
        return mPairs;
    }

private:
    std::vector<std::pair<Equation, Equation> > mPairs;
};

#endif /* GRAPHER_H_ */
