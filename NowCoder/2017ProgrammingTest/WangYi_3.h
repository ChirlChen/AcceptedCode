/************************************************
  FileName    : WangYi_3.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/24                      ;
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
#ifndef _WANGYI_3_H_
#define _WANGYI_3_H_
#include <iostream>
#include <string>

using namespace std;
namespace Chirl
{
    /************************************************************************
     题      目：https://www.nowcoder.com/question/next?pid=6291726&qid=112730&tid=9890658
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_WangYi_3
    {
    public:
  
        int LengthOf01Seq(const string &seq){
            int len = seq.length();
            if(len == 0){
                return 0;
            }

            int maxLen = 1;
            int curLen = 1;
            char prev = seq[0];
            for(int i = 1; i < len; ++i){
                if(seq[i] != prev){
                    curLen++;
                }
                else{
                    maxLen = max(maxLen, curLen);
                    curLen = 1;
                }
                prev = seq[i];
            }
            return max(maxLen, curLen);
        }
        static void test()
        {
            Solution_WangYi_3 su;
            string str("1010101");
            

            cout << su.LengthOf01Seq(str);
        }
    };
  
}


#endif //!_WangYi_3_H_
