#ifndef _441_H_
#define _441_H_
#include <iostream>
using namespace std;
namespace Sansan
{
    class Solution_441
    {
    public:
        int arrangeCoins(int n) 
        {
            int res=0;
            while(n>res)
            {
                res++;
                n-=res;
            }
            return res;
        }
        static void test()
        {
            Solution_441 su;
            printf("%d\n",su.arrangeCoins(8));
        }
    };
}
#endif
