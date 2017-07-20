/************************************************
  FileName    : Package.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/12                      ;
              _                                 ;
             /  \         吉                    ;     
            /|oo \         祥                   ;    
           (_|  /_)       物                    ;   
             `@/  \   _    镇                   ;    
             |     \  \\  楼                    ;   
              \||   \  ))  !!                   ;    
              |||\ / \//                        ; 
            _//|| _\  /                         ;
    ______(_/(_|(____/_________                 ;
*************************************************/
#ifndef _PACKAGE_H_
#define _PACKAGE_H_
#include <iostream>
#include <algorithm>
using namespace std;
namespace Chirl
{
    /************************************************************************
     题      目:给定一个数组，将连续的几个数字分成一组，共分成P组，使得每组的;
                 和最小;
     思      路：深度优先搜索;
     算法复杂度：O(2^P)
     ************************************************************************/
    class Solution_Package
    {
    public:
        int maximumPackage(int  goods[], int P, int len)
        {
            int total = 0;
            for (int i = 0; i < len; i++){
                total += goods[i];
            }
            int aver = total / P;
            
            return maximumPackage(goods, P, len, 0, aver);
        }
        int maximumPackage(int  goods[], int P, int len, int maxP, int aver){
            if (P == 0 && len == 0)
            {
                return maxP;
            }
            else if (P == 1 || len == 0)
            {
                return max(accumulate(goods, goods+len, 0), maxP);
            }
            int curP = 0;
            for (int i=0; i <= len-1; ++i)
            {
                curP += goods[i];
                if (curP > aver || i == len - 1 || len-i == P) 
                {
                    return maximumPackage(&goods[i+1], P-1, len-i-1, max(curP, maxP), aver);                    
                }
                else if (curP + goods[i+1] > aver)
                {
                    int tmp1 = maximumPackage(&goods[i+1], P-1, len-i-1, max(curP, maxP), aver);
                    int tmp2 = maximumPackage(&goods[i+2], P-1, len-i-2, max(curP + goods[i+1], maxP), aver);
                    return tmp1 < tmp2 ? tmp1 : tmp2;
                }
            }
        }
        

        inline int max(int a, int b)
        {
            return a > b ? a : b;
        }
        static void test()
        {
            Solution_Package su;
            int goods[6] = {1, 1, 1, 2000, 1, 1};
            int minPackage = su.maximumPackage(goods, 2, 6);
        }
  
    };
  
}


#endif //!_Package_H_



