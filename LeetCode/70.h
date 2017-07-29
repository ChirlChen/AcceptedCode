/************************************************
  FileName    : 70.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/29                      ;
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
#ifndef _70_H_
#define _70_H_

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_70
    {
    public:
        int climbStairs(int n) {
            if(n <= 1) return 1;

            int nMinus1 = 1, nMinus2 = 1;
            for(int i = 2; i <= n; ++i){
                int tmp = nMinus1 + nMinus2;
                nMinus2 = nMinus1;
                nMinus1 = tmp;
            }

            return nMinus1;
        }
  
        static void test()
        {
            Solution_70 su;
            int ans = su.climbStairs(10);
        }
    };
  
}


#endif //!_70_H_
