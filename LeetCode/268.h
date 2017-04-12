/************************************************
  FileName    : 268.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/04/10                      ;
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
#ifndef _268_H_
#define _268_H_

#include <vector>
#include <algorithm>
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路：如果是以递增有序排列的情况下，可采用二分法，查找缺失数; 
     算法复杂度：拍好序情况下：O(log(n));
     ************************************************************************/
    class Solution_268
    {
    public:
        int missingNumber(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());   //算上快速排序，复杂度为O(n*log(n));
            if (nums[0] != 0)
            {
                return 0;
            }
            int begIdx = 0; 
            int endIdx = nums.size();
            
            while (begIdx < (endIdx - 1))
            {
                int medianIdx = (begIdx + endIdx) / 2;
                if (nums[medianIdx] > nums[0] + medianIdx)
                {
                    endIdx = medianIdx;
                }
                else
                {
                    begIdx = medianIdx;
                }
            }
            return nums[begIdx] + 1;
        }
          
        //网上别人的bit操作，利用异或的同为0，异为1性质，查找缺失数, 可以不用关心nums的排列顺序;
        //复杂度：O(n);
        int missingNumber_1(vector<int>& nums)   
        {
            int misNum = nums.size();
            for (int i = 0; i < nums.size(); ++i)
            {
                misNum ^= nums[i] ^ i;
            }
            return misNum;
        }

        static void test()
        {
            Solution_268 su;
            int numsVec[] = {0, 1, 2, 3, 5, 6, 7};
            vector<int> nums(begin(numsVec), end(numsVec));
            int missNum  = su.missingNumber(nums);
            int missNum1 = su.missingNumber_1(nums); 
        }
    };
  
}


#endif //!_268_H_
