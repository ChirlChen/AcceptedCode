/************************************************
  FileName    : 30.h           ;
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
#ifndef _30_H_
#define _30_H_
#include <vector>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_30
    {
    public:
        int NumberOf1Between1AndN_Solution(int n)
        {
            if(n < 0) n = abs(n);

            vector<int> curOnes;
            int multi = 1;
            int tmpOnes = 0;
            while(n / multi){
                tmpOnes += 1 * multi + tmpOnes * 9;
                curOnes.push_back(tmpOnes);
                multi *= 10; 
            }

            int ans = 0;
            int idx = curOnes.size()-2;
            multi /= 10;

            while(n){            
                int res = n / multi;
                if(res > 1){
                    ans += 1 * multi + (multi == 1 ? 0 : (res)*(curOnes[idx]));
                }
                else if(res == 1){
                    ans += (multi == 1 ? 1 : curOnes[idx] + (n - res * multi + 1));
                }
                
                n -= res * multi;
                multi /= 10;
                --idx;
            }

            return ans;
        }  
  
        static void test()
        {
            Solution_30 su;
            su.NumberOf1Between1AndN_Solution(125);
        }
    };
  
}


#endif //!_30_H_
