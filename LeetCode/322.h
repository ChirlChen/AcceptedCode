/************************************************
  FileName    : 322.h           ;
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
#ifndef _322_H_
#define _322_H_
#include <vector>
#include <algorithm>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路：动态规划; 
     算法复杂度：
     ************************************************************************/
    class Solution_322
    {
    public:
        int coinChange(vector<int>& coins, int amount) {
            if(coins.empty() || amount < 0) return -1; 

            int ans = 0; 
            const int INF_VAL = 0xFFFFFFF;
            vector<int> DP(amount+1, INF_VAL);


            DP[0] = 0;
            sort(coins.begin(), coins.end());
            for(int i = 1; i <= amount; ++i){
                for(auto itr = coins.begin(); itr != coins.end(); ++itr){
                    if(i - *itr < 0) break;
                    DP[i] = min(DP[i], DP[i-*itr] + 1);
                }
            }

            return DP[amount] == INF_VAL ? -1 : DP[amount];
        }
  
        static void test()
        {
            int tmp[] = {1, 2, 5};
            Solution_322 su;
            int ans = su.coinChange(vector<int>(begin(tmp), end(tmp)), 11);
        }
    };
  
}


#endif //!_322_H_
