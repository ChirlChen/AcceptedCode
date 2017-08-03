/************************************************
  FileName    : 48.h           ;
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
#ifndef _48_H_
#define _48_H_
#include <string>
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_48
    {
    public:
        int StrToInt(string str) {
            m_bIsSuccees = false;
            int len = str.length();
            if(len <= 0) return 0;

            int num = 0;
            int i = 0; bool minus = false;
            if(str[0] == '-'){
                i = 1;
                minus = true;
            }
            else if(str[0] == '+'){
                i = 1;
                minus = false;
            }
            for(; i < len; ++i){
                if(str[i] < '9' && str[i] > '0'){
                    num = num*10 + (str[i] - '0');
                }
                else
                    return 0;
            }

            m_bIsSuccees = true;
            return minus ? -num : num;
        }
        static void test()
        {
            Solution_48 su;
            int ans = su.StrToInt("123");
        }
    private:
        bool m_bIsSuccees;  
    };
  
}


#endif //!_48_H_
