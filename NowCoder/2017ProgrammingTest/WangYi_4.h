/************************************************
  FileName    : WangYi_4.h           ;
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
#ifndef _WANGYI_4_H_
#define _WANGYI_4_H_
#include <iostream>
#include <vector>

using namespace std;
namespace Chirl
{
    /************************************************************************
     题      目：https://www.nowcoder.com/question/next?pid=6291726&qid=112725&tid=9890658
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_WangYi_4
    {
    public:
        vector<int> ReverseSeq(const vector<int> &seq){
            int len = seq.size();

            vector<int> ans(len, 0);
            bool odd = len & 0x1;
            int mid = len/2;
            for(int i = 0; i < len; ++i){
                if(odd){
                    if(i & 0x1){
                        ans[mid + (i+1)/2] = seq[i];   
                    }
                    else{
                        ans[mid - (i+1)/2] = seq[i];
                    }
                }
                else{
                    if(i & 0x1){
                        ans[mid - (i+1)/2] = seq[i];
                    }
                    else{
                        ans[mid + (i+1)/2] = seq[i];
                    }
                }
            }

            return ans;
        }
  
        static void test()
        {
            Solution_WangYi_4 su;
            int tmp[] = {1, 2, 3};
            vector<int> seq(begin(tmp), end(tmp));
           

            vector<int> ans = su.ReverseSeq(seq);
            for(int i = 0; i < seq.size() - 1; ++i){
                cout << ans[i] << " ";
            }
            cout << ans[seq.size() - 1];
        }
    };
  
}


#endif //!_WangYi_4_H_
