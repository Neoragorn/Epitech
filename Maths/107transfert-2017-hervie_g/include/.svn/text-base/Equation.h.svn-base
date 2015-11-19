#ifndef EQUATION_H_
#define EQUATION_H_

#include <math.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

class Equation
{
public:
    Equation(int size): mFactors(size) {}
    Equation(std::string &str, bool reverse = false);

    inline int size(void) const
    {
        return mFactors.size();
    }

    inline int operator[](unsigned int index) const
    {
        if (index >= mFactors.size())
        {
            throw std::runtime_error("Index out of range!");
        }
        return mFactors[index];
    }

    inline int &operator[](unsigned int index)
    {
        if (index >= mFactors.size())
        {
            throw std::runtime_error("Index out of range!");
        }
        return mFactors[index];
    }

    inline double operator()(double x)
    {
        double result = 0;
        for (unsigned int i = 0; i < mFactors.size(); i++)
        {
            result += mFactors[i] * pow(x, i);
        }
        return result;
    }

private:
    std::vector<int> mFactors;
};

inline std::ostream &operator<<(std::ostream &stream, const Equation &eq)
{
    for (int i = eq.size() - 1; i >= 0; i--)
    {
        stream << eq[i];
        if (i > 0)
        {
            stream << "x";
            if (i > 1)
            {
                stream << "^" << i;
            }
            stream << " + ";
        }
    }
    return stream;
}

#endif /* EQUATION_H_ */
