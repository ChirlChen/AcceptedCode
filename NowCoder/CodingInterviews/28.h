/************************************************
  FileName    : 28.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/21                      ;
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
#ifndef _28_H_
#define _28_H_
#include <vector>
#include <algorithm>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_28
    {
    public:
        int MoreThanHalfNum_Solution(vector<int> numbers) {
            if (numbers.empty()) return 0;

            int ans = numbers[0];
            int cnt = 1;

            for(int i = 1; i < numbers.size(); ++i){
                cnt += numbers[i] == ans ? 1 : -1;

                if(cnt == 0){
                    ans = numbers[i];
                    cnt = 1;
                }
            }

            return std::count(numbers.begin(), numbers.end(), ans) > (numbers.size() / 2) ? ans : 0;
        }
  
        static void test()
        {
            Solution_28 su;
            int tmp[] = {1,2,3,2,2,2,5,4,2};
            su.MoreThanHalfNum_Solution(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_28_H_
