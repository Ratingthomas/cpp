#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>
#include "NumberFinder.h"

exam::NumberFinder::NumberFinder(bool unique, bool sorted) : unique_{unique}, sorted_{sorted} {}

bool exam::NumberFinder::find(const std::string &s) {
    std::ifstream file{s};
    std::string line;
    while (std::getline(file, line)) {
        // process line word by word
        std::string word;
        std::istringstream iss{line};
        while (iss >> word) {
            // if word is an integer, store in numbers_
            if (is_integer(word)) {
                long value = std::stol(word);
                // but check for uniqueness
                if (!unique_ || !contains(value))
                    numbers_.push_back(value);
            }
        }
    }

    // sort
    if (sorted_) std::sort(numbers_.begin(), numbers_.end());

    return false;
}

const std::vector<long> &exam::NumberFinder::numbers() const { return numbers_; }

bool exam::NumberFinder::is_integer(const std::string &s) const {
    if (s == "-") return false; // edge case: not an integer
    size_t start = 0;
    if (s.starts_with("-")) start = 1;
    for (size_t i = start; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}

bool exam::NumberFinder::contains(long nr) const {
    for (auto val : numbers_) if (val == nr) return true;
    return false;
}
