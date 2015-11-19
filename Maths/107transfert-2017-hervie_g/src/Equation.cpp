#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include "Equation.h"

Equation::Equation(std::string &str, bool reverse)
{
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, '|'))
    {
        try
        {
            std::stringstream itemss(item);
            int i;

            if (item.length() == 0 || !(itemss >> i))
            {
                throw std::runtime_error("Mauvais format de nombre!");
            }
            mFactors.push_back(i);
        }
        catch (std::invalid_argument &e)
        {
            throw std::runtime_error("Mauvais format de nombre!");
        }
        catch (std::out_of_range &e)
        {
            throw std::runtime_error("Nombre tros grand :(");
        }
    }

    if (reverse)
    {
        std::reverse(mFactors.begin(), mFactors.end());
    }
}
