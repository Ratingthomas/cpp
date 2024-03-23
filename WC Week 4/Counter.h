//
// Created by Thomas Levels on 23/03/2024.
//

#ifndef WC_WEEK_4_COUNTER_H
#define WC_WEEK_4_COUNTER_H
#include "Options.h"
#include "FileCounts.h"

namespace Counter {

    class Counter {
        public:
            Counter(const Options::Options& opts);
            FileCounts process(const std::string& file_name);

        private:
            const Options::Options& opts_;
    };

} // Counter

#endif //WC_WEEK_4_COUNTER_H
