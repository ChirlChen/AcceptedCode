/************************************************
  FileName    : 42.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/01                      ;
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
#ifndef _42_H_
#define _42_H_

#include <string>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_42
    {
    public:
        string LeftRotateString(string str, int n) {
            int len = str.length();

            string ans;
            n %= len;
            ans += (string(&str[0] + n, &str[0] + len));
            ans += (string(&str[0], &str[0] + n));

            return ans;
        }
  
        static void test()
        {
            Solution_42 su;
            string ans = su.LeftRotateString("abcdef", 5);
        }
    };
  
}


#endif //!_42_H_
