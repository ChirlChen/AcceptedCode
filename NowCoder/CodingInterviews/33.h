/************************************************
  FileName    : 33.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/28                      ;
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
#ifndef _33_H_
#define _33_H_

#include<map>
#include <string>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_33
    {
    public:
        int FirstNotRepeatingChar(string str) {
            if(str.length() <= 0) return -1;

            char cnt[256] = {0};
            map<char, int> pos;
            for(int i = 0; i < str.length(); ++i){
                char tmp = str[i];
                cnt[tmp] += 1;
                if(cnt[tmp] == 1) pos.insert(pair<char, int>(tmp, i));
                else pos.erase(tmp);
            }

            int ans = 256;
            for(auto itr = pos.begin(); itr != pos.end(); ++itr){
                if(itr->second < ans) ans = itr->second;
            }

            return ans;
        }
  
        static void test()
        {
            Solution_33 su;
            su.FirstNotRepeatingChar("abaabdcddescee");
        }
    };
  
}


#endif //!_33_H_
