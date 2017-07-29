/************************************************
  FileName    : 303.h           ;
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
#ifndef _303_H_
#define _303_H_
#include <vector>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_303
    {
    public:
        Solution_303(vector<int> nums) {
            int numCnt = nums.size();
            if(numCnt == 0) return; 

            m_vSumOfFirstK.resize(numCnt+1, 0);
            for(int i = 0; i < numCnt; ++i){
                // m_vSumOfFirstK[i] = (i == 0 ? nums[i] : m_vSumOfFirstK[i-1]+nums[i]);
                m_vSumOfFirstK[i+1] =  m_vSumOfFirstK[i] + nums[i];
            }
        }

        int sumRange(int i, int j) {
            //return m_vSumOfFirstK[j] - (i == 0 ? 0 : m_vSumOfFirstK[i-1]);
            return m_vSumOfFirstK[j+1] - m_vSumOfFirstK[i];
        }
  
        static void test()
        {
            int tmp[] = {-2,0,3,-5,2,-1};
            Solution_303 su(vector<int>(begin(tmp), end(tmp)));
            int ans = su.sumRange(2, 5);
        }

    private:
        vector<int> m_vSumOfFirstK;  
    };
  
}


#endif //!_303_H_
