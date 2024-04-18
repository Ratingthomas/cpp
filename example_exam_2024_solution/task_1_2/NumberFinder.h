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
        NumberFinder(bool unique, bool sorted);
        bool find(const std::string& s);
        const std::vector<long>& numbers() const;
    private:
        bool is_integer(const std::string& s) const;

        bool unique_;
        bool sorted_;
        std::vector<long> numbers_;

        bool contains(long nr) const;
    };
}


#endif // INCLUDED_NUMBER_FINDER_H