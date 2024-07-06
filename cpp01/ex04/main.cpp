#include <iostream>
#include <fstream>

using str = std::string;

void    find_replace(str &string_raw, str find, str rep)
{
    size_t  pos;
    size_t  f_len;
    size_t  r_len;

    pos = 0;
    f_len = find.length();
    r_len = rep.length();
    while ((pos = string_raw.find(find, pos)) != str::npos)
    {
        string_raw.erase(pos, f_len);
        string_raw.insert(pos, rep);
        pos += r_len;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid number of args" << std::endl;
        return 0;
    }
    //REmember this cases "" or " " 
    str file_name = argv[1];
    str find = argv[2];
    str replace = argv[3];
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cerr << "Failed to open the file" << std::endl;
        return (1);
    }
    std::string line;
    std::ofstream outfile(file_name + ".replace");
    if (!outfile.is_open())
    { 
        std::cout << "Failed to open the outfile" << std::endl;
        return (1);
    }
    while (std::getline(file, line))
    {
        find_replace(line, find, replace);
        outfile << line << std::endl;
    }
    file.close();
    outfile.close();
}