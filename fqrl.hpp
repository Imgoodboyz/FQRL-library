#ifndef header
#define header
#define version = "0.0.15-future-view"
#define minimum = "c++ 98"
#define last_update = "21/9/2025"
#define authorizer = "imgoodboy"
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <sstream>
namespace fclc
{
    inline double sum(std::vector<double>num)
    {
       int i = num.size();
       double total = 0;
       for (int x=0;x<i;x++)
       {
          total += num[x];
       }
       return total;
    }
    inline double avg(std::vector<double>num)
    {
       int i = num.size();
       double total = 0;
       int length = 0;
       for (int x = 0;x<i;x++)
       {
          total += num[x];
          length += 1;
       }
       return total/length;
    }
}
namespace facs
{
    inline bool exist(std::string name)
    {
        std::ifstream hd(name);
        return hd.is_open() || hd.good();
    }
    inline bool readable(std::string name)
    {
	std::ifstream fc(name,std::ios::in);
        return fc.good();
    }
    inline bool writeable(std::string name)
    {
	std::ofstream fo(name,std::ios::app);
        fo << "";
        return fo.good();
    }
    template<typename T>
    inline T write(const std::string file,const T data)
    {
        std::ofstream out(file,std::ios::app);
        if (!out.is_open()) return "cant_open";
        out << data << std::endl;
        return data;
    }
    inline std::string read(std::string file)
    {
    	std::ifstream dc(file,std::ios::in);
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
    template<typename E>
    inline void ipt(E& name)
    {
        std::cin>>name;
        if (std::cin.fail())
        {
             std::cin.clear();
             std::cin.ignore();
        }
        return;
    }
}
#endif
