/************************************************
  FileName    : 53.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/29                      ;
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
#ifndef _53_H_
#define _53_H_
#include <vector>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_53
    {
    public:
        int maxSubArray(vector<int>& nums) {
            if(nums.empty()) return -1;
            
            int ans = nums[0];
            int curSum = 0;

            for(int i = 0; i < nums.size(); ++i){
                if(curSum < 0){
                    curSum = nums[i];
                }
                else
                    curSum += nums[i];

                if(curSum > ans){
                    ans = curSum;
                }
            }

            return ans;
        }
  
        static void test()
        {
            int tmp[] = {-2,1,-3,4,-1,2,1,-5,4};
            Solution_53 su;
            int ans = su.maxSubArray(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_53_H_
