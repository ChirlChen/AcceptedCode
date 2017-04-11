/************************************************
  FileName    : 279.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/04/05                      ;
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
#ifndef _279_H_
#define _279_H_

#include <vector>

namespace Chirl
{
    /************************************************************************
     思      路：该题目乍一看可以用贪心做，但是实际上贪心无法正确求解。;
                 这里使用动态规划的方法:; 
                    1、完全平方序列: N = {N_1, N_2, ... ,N_j} = {1, 4, 9, ..., 16};
                    2、状态转移函数: d(0) = 0;
                                     d(i) = min{d(i-N_j) + 1}, (i-N_j >= 0); 
     算法复杂度：O(n*m)
     ************************************************************************/
    class Solution_279
    {
    public:
        int numSquares(int n) 
        {
            std::vector<int> D(n+1, 0xFFFFFFF);
            std::vector<int> square(sqrt(n) + 1);
            
            for (int i = 0; i < square.size(); ++i)
            {
                square[i] = i*i;
            }

            D[0] = 0;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 0; j < square.size(); ++j)
                {
                    if (i >= square[j])
                    {
                        D[i] = min(D[i-square[j]] + 1, D[i]);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            return D[n];
        }
    
        int min(int a, int b)
        {
            return a < b ? a : b;
        }
        static void test()
        {
            Solution_279 su;
            int num = su.numSquares(12);
        }
    };
  
}


#endif //!_279_H_
