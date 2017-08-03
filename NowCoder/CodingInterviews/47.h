/************************************************
  FileName    : 47.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/03                      ;
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
#ifndef _47_H_
#define _47_H_

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_47
    {
    public:
        int Add(int num1, int num2)
        {
            int ans = 0; 
            int carry = 0;

            do{
                ans = num1 ^ num2;
                carry = (num1 & num2) << 1;

                num1 = ans;
                num2 = carry;
            }while(carry != 0);

            return ans;
        }
  
        static void test()
        {
            Solution_47 su;
            int ans = su.Add(10, -4);
        }
    };
  
}


#endif //!_47_H_
