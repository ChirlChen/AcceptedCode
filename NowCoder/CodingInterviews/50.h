/************************************************
  FileName    : 50.h           ;
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
#ifndef _50_H_
#define _50_H_

#include <vector>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_50
    {
    public:
        vector<int> multiply(const vector<int>& A) {
            vector<int> ans;
            if(A.empty()) return ans;

            int len = A.size();
            vector<int> leftMulti(len, 1);
            vector<int> rightMulti(len, 1);
            for(int i = 1; i < len; ++i){
                leftMulti[i] = A[i-1] * leftMulti[i-1];
                rightMulti[i] = A[len-i] * rightMulti[i-1]; 
            }

            for(int i = 0; i < len; ++i){
                ans.push_back(leftMulti[i] * rightMulti[len-1-i]);
            }

            return ans;
        }
  
        static void test()
        {
            Solution_50 su;
  
        }
    };
  
}


#endif //!_50_H_
