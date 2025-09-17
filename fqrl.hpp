#ifndef header
#define header
#define version = "0.0.14-preview"
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
    inline T log(const T data)
    {
       std::filesystem::path caller(__FILE__);
       std::filesystem::path logger = caller.parent_path()/"log.txt";
       std::ofstream out(logger,std::ios::app);
       out << data << std::endl;
       if (!out) return "cant_open";
       return "logged";
    }
    inline std::string read(std::string file)
    {
    	std::ifstream dc(abs(file));
	if (!dc.is_open())
	{
	   throw std::runtime_error("cant open.file");
	}
	std::string out;
	std::getline(dc, out);
	return out;
    }
    inline std::string write(std::string file,std::string data)
    {
	std::ofstream lk(abs(file),std::ios::app);
	if (!lk.is_open())
	{
	   throw std::runtime_error("cant open");
	}
	lk << data << std::endl;
	return "done";
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
    template<typename T>
    inline void ipt(T& name)
    {
        std::cin>>name;
    }
}
#endif
