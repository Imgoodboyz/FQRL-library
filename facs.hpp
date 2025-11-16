#ifndef facs_hpp
#define facs_hpp
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
typedef std::fpos<mbstate_t> fpos;
   #define facs_version "v0.0.16 future view"
class Facs : public std::fstream
 {
    public:
    Facs(const std::string& filename,const std::ios::openmode mode) : std::fstream(filename,mode)
    {
        if (!is_open()) throw std::runtime_error("no such file or dirrectory!");
    }
    using std::fstream::seekg;
    using std::fstream::seekp;
    using std::fstream::tellg;
    inline void rol(std::fpos<mbstate_t> pos,std::string& outs)
    {
    seekg(pos);
    char ch;
    while (get(ch))
       {
       if (ch == '\n') break;
       outs += ch;
       }
       return;
    }
    inline void readline(std::string& str)
    {
    char ch;
    while (get(ch))
    {
        if (ch == '\n') break;
        str+= ch;
    }
    return;
    }
    inline std::vector<std::streampos> takeline(std::vector<std::streampos>& vec)
    {
        vec = {fpos(0)};
        std::streampos pos = 0;
        std::string str;
        char ch;
        while (true)
        {
             if (eof()) break;
             seekg(pos);
             readline(str);
             get(ch);
             pos = tellg();
             vec.push_back(std::fpos<mbstate_t>(pos));
        }
    }
    inline bool exist()
    {
        return is_open() || good();
    }
    inline bool readable(std::string filename)
    {
        char ch;
        get(ch);
        return good();
    }
    inline bool writeable(std::string name)
    {
        write("");;
        return good();
    }
    inline std::string write(const std::string data)
    {
        if (!is_open()) return "cant_open";
        *this << data << std::endl;
        return data;
    }
    ~Facs() {};
};
namespace ultils
{
    inline std::vector<std::string> reverse_vector(std::vector<std::string> vec)
    {
        std::vector<std::string> new_vec;
        for (int len=vec.size();len >= 0;--len)
        {
             new_vec.push_back(vec[len]);
        }
        return new_vec;
    }
}
#endif
