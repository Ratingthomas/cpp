//
// Created by Thomas Levels on 18/03/2024.
//

#ifndef WC_WEEK_4_OPTIONS_H
#define WC_WEEK_4_OPTIONS_H

#include <iostream>
#include <vector>
#include <string>

namespace Options {

    class Options {
    public:
        Options(int argc, char * argv[]);
        Options();

        bool lines() const;
        bool words() const;
        bool characters() const;
        bool bytes() const;
        bool longest_line() const;
        bool help() const;
        bool version() const;

        /// Contains a vector with file names to process
        const std::vector<std::string>& file_names() const;

        /* Modifiers */

        // Parses command-line arguments and replaces the the current values
        // of file names with new, parsed values
        void parse(int argc, char * argv[]);

        /* Debug/ helper functions */
        bool verbose() const;
        void print(std::ostream& out) const;

    private:
        bool lines_;
        bool words_;
        bool characters_;
        bool bytes_;
        bool longest_line_;
        bool help_;
        bool version_;
        bool verbose_;

        std::vector<std::string> file_name_;
    };

    // you may use this function to print directly to a stream
    inline std::ostream& operator<<(std::ostream& out, const Options& opt)
    {
        out << "Options:"
            << "\n\tlines: "        << std::boolalpha << opt.lines()
            << "\n\twords: "        << std::boolalpha << opt.words()
            << "\n\tcharacters: "   << std::boolalpha << opt.characters()
            << "\n\tbytes: "        << std::boolalpha << opt.bytes()
            << "\n\tlongest_line: " << std::boolalpha << opt.longest_line()
            << "\n\thelp: "         << std::boolalpha << opt.help()
            << "\n\tversion: "      << std::boolalpha << opt.version()
            << "\n\tfiles:";
        for (const auto& fn: opt.file_names())
        {
            out << "\n\t * " << fn;
        }
        return out;
    }
} // Options

#endif //WC_WEEK_4_OPTIONS_H
