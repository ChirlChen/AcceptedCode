/************************************************
  FileName    : 27.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/21                      ;
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
#ifndef _27_H_
#define _27_H_
#include <set>
#include <vector>
#include <string>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_27
    {
    public:
        vector<string> Permutation(string str) {
            if(str.length() < 1) {
                return vector<string>();
            }

            string onePermute;
            set<string> ans;
            Permutation(str, str.length(), onePermute, ans);
            return vector<string>(ans.begin(), ans.end());
        }

        void  Permutation(string  str, int len, string onePermute, set<string> &ans){
            if(len == 1){
                onePermute.push_back(str[0]);
                ans.insert(onePermute);
                return;
            }

            for(int i = 0; i < len; ++i){
                swap(str[0], str[i]);
                Permutation(&str[1], len-1, onePermute + str[0], ans);
            }
        }
  
        static void test()
        {
            Solution_27 su;
            su.Permutation("abc");
        }
    };
  
}


#endif //!_27_H_
