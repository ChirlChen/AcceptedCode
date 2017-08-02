/************************************************
  FileName    : 43.h           ;
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
#ifndef _43_H_
#define _43_H_
#include <string>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_43
    {
    public:
        string ReverseSentence(string str) {
            string ans;
            int first = str.length();
            int last = first;

            while(first > 0){
                if(str[first-1] == ' '){
                    ans.append(&str[0] + first, &str[0] + last);
                    ans.append(" ");
                    last = first-1;
                    first -= 2;
                }
                else
                    first--;
            }
            ans.append(&str[0], &str[0] + last);

            return ans;
        }
  
        static void test()
        {
            Solution_43 su;
            string ans = su.ReverseSentence("I am a student.");
        }
    };
  
}


#endif //!_43_H_
