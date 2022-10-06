#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(int argc, char** argv) {

    std::vector <std::string> filenames;
    bool words_arg = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg[0] == '-') {
            if (arg == "-w" || arg == "--words") {
                words_arg = true;
            } else {
                std::cout << "unknown argument\n";
                return 1;
            }
        } else {
            filenames.push_back(arg);
        }
    }

    return 0;
}
