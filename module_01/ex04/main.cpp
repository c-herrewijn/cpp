#include <iostream>
#include <fstream>
#include <string>

std::string find_replace(std::string in_str, std::string find_str,
                         std::string replace_str)
{
    (void)in_str; // dummy
    (void)find_str; // dummy
    (void)replace_str; // dummy
    return ("dummy"); // dummy
}

int main(int argc, char *argv[])
{
    // parsing inputs
    if (argc != 4) {
        std::cout << "invalid number of arguments" << std::endl;
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream in_file(filename);
    if (!in_file) {
        std::cout << "file " << filename << " does not exist" << std::endl;
        return (1);
    }

    // create output file
    std::ofstream out_file(filename + ".replace");
    std::string line_in;
    while (std::getline(in_file, line_in)) {
        out_file << find_replace(line_in, s1, s2) << std::endl;
    }
    in_file.close();
    out_file.close();
    return (0);
}