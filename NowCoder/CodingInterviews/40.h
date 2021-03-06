/************************************************
  FileName    : 40.h           ;
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
#ifndef _40_H_
#define _40_H_

#include <vector>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_40
    {
    public:
        vector<vector<int> > FindContinuousSequence(int sum) {
            vector<vector<int> > ans;
            if(sum == 0) return ans;

            int curSum = 0, first = 1, last = 1, end = (sum+1)/2 + 1;
            while(last <= end){
                if(curSum < sum){
                    curSum += last++;
                }
                else if(curSum > sum){
                    curSum -= first++;
                }
                else if(curSum == sum && first - last > 1){
                    vector<int> seq;
                    seq.reserve(last - first + 1);
                    for(int i = first; i < last; ++i){
                        seq.push_back(i);
                    }
                    ans.push_back(seq);
                    curSum += last++;
                }
            }

            return ans;
        }
  
        static void test()
        {
            Solution_40 su;
            vector<vector<int> > ans = su.FindContinuousSequence(3);
        }
    };
  
}


#endif //!_40_H_
