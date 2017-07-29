/************************************************
  FileName    : 121.h           ;
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
#ifndef _121_H_
#define _121_H_
#include <vector>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路：动态规划;
     算法复杂度：O(n);
     ************************************************************************/
    class Solution_121
    {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.empty()) return 0;

            int curMin = prices[0];
            vector<int> DP(prices.size()+1, 0);
            for(int i = 0; i < prices.size(); ++i){
                curMin = min(curMin, prices[i]);
                DP[i+1] = max(DP[i], prices[i] - curMin);
            }

            return *DP.rbegin();
        }
  
        static void test()
        {
            int tmp[] = {7, 1, 5, 3, 6, 4};
            Solution_121 su;
            int ans = su.maxProfit(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_121_H_
