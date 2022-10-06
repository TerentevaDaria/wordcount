#include <iostream>
#include <vector>
#include <fstream>
#include <string>

uint64_t WordCounter(const std::string& filename) {
    std::ifstream file(filename);

    char current_char;
    char previous_char = ' ';
    uint64_t word_count = 0;

    for (current_char = file.get(); file.good(); current_char = file.get()) {
        if (std::isspace(current_char) && !std::isspace(previous_char)) {
            ++word_count;
        }
        previous_char = current_char;
    }
    if (!std::isspace(previous_char)) {
        ++word_count;
    }

    file.close();

    return word_count;
}

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

    for (const std::string& filename : filenames) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cout << "enable to open " << filename << '\n';
            continue;
        }

        file.close();

        if (words_arg) {
            uint64_t word_count = WordCounter(filename);
            std::cout << word_count << ' ';
        }

        if (!words_arg) {
            uint64_t word_count = WordCounter(filename);
            std::cout << word_count << ' ';
        }
        std::cout << filename << '\n';
    }

    return 0;
}
