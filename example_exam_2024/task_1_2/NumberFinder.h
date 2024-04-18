#ifndef INCLUDED_NUMBER_FINDER_H
#define INCLUDED_NUMBER_FINDER_H

#include <vector>
#include <string>

#include "Options.h"

namespace exam
{
    class NumberFinder
    {
    public:


    private:
        [[maybe_unused]]
        bool unique_;
        [[maybe_unused]]
        bool sorted_;
        std::vector<long> numbers_;
    };
}


#endif // INCLUDED_NUMBER_FINDER_H