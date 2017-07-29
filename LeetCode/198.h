/************************************************
  FileName    : 198.h           ;
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
#ifndef _198_H_
#define _198_H_
#include <vector>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_198
    {
    public:
        int rob(vector<int>& nums) {
            if(nums.empty()) return 0;
            if(nums.size() <= 1) return nums[0];

            vector<int> DP(nums.size()+1, 0);
            DP[1] = nums[0]; 
            for(int i = 1; i < nums.size(); ++i){
                DP[i+1] = max(DP[i-1] + nums[i], DP[i]);
            }

            return *DP.rbegin();
        }
  
        static void test()
        {
            int tmp[] = {4,3,5,8,3,2};
            Solution_198 su;
            int ans = su.rob(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_198_H_
