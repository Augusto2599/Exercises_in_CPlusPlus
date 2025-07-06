#ifndef INPUTREADER_HPP
#define INPUTREADER_HPP

#include <string>

class InputReader {
public:
    std::string readString(const std::string &prompt);

    std::string readOptionalString(const std::string &prompt);

    int readInt(const std::string &prompt);

    int readInt(const std::string &prompt, int min, int max);
};

#endif
