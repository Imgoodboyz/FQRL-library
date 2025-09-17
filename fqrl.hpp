#ifndef header
#define header
#define version = "0.0.14-future-preview"
#define minimum = "c++ 20"
#define last_update = "14/9/2025"
#define authorizer = "imgoodboy"
#include <initializer_list>
#include <filesystem>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <sstream>
namespace fclc
{
    template<typename T>
    inline T sum(std::initializer_list<T>num)
    {
       double total = 0;
       for (T x : num)
       {
          total += x;
       }
       return total;
    }
    template<typename T>
    inline T avg(std::initializer_list<T>num)
    {
       double total = 0;
       int length = 0;
       for (T x : num)
       {
          total += x;
          length += 1;
       }
       return total/length;
    }
}
namespace facs
{
    inline std::string abs(const std::string name)
    {
       return std::filesystem::absolute(name).string();
    }
    template<typename T>
    inline T write(const std::string file,const T data)
    {
       std::ofstream out(abs(file),std::ios::app);
       if (!out.is_open()) return "cant_open";
       out << data << std::endl;
       return data;
    }
    inline std::string read(std::string file)
    {
    	std::ifstream dc(abs(file),std::ios::in);
	if (!dc.is_open())
	{
	   throw std::runtime_error("cant open.file");
	}
	std::string out;
	std::getline(dc, out);
	return out;
    }
    template<typename T>
    inline void prt(T data,bool line)
    {
        if (line == true)
        {
             std::cout<<data<<std::endl;
        }
        if (line == false)
        {
             std::cout<<data;
        }
    }
//fixing,please dont use this
    template<typename T>
    inline T ipt(T name)
    {
        std::getline(std::cin,name);
        if (std::cin.fail())
        {
             std::cin.clear();
             std::cin.ignore();
        }
        return name;
    }
//in duty,do not use till we push a update abour this
}
#endif
