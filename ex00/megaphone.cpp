#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv) {
    std::string output;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        for (std::size_t j = 0; j < arg.length(); ++j)
            arg[j] = std::toupper(arg[j]);
        output += arg;
    }
    if (output.empty())
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        std::cout << output << std::endl;
    return 0;
};
//another day of not working waw aw wa  wa