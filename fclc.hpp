#ifndef fclc_hpp
#define fclc_hpp
#include <vector>
namespace fclc
{
    #define version "v0.0.15 future view"
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
#endif
