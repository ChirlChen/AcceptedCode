/************************************************
  FileName    : 32.h           ;
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
#ifndef _32_H_
#define _32_H_
#include <vector>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_32
    {
    public:
        int GetUglyNumber_Solution(int index) {
            if(index <= 0) return 0;

            int tmp[] = {1, 2, 3, 4, 5};
            vector<int> uglyNum(begin(tmp), end(tmp));
            uglyNum.reserve(index);

            if(index <= 5) return tmp[index - 1];

            int idx2 = 2, idx3 = 2, idx5 = 2;
            int ugly2 = 0, ugly3 = 0, ugly5 = 0;
            while(uglyNum.size() < index) {
                int curMax = *uglyNum.rbegin();

                while(ugly2 <= curMax){
                    ugly2 = 2 * uglyNum[idx2++];
                }
                while(ugly3 <= curMax){
                    ugly3 = 3 * uglyNum[idx3++];
                }
                while(ugly5 <= curMax){
                    ugly5 = 5 * uglyNum[idx5++];
                }

                uglyNum.push_back(min(min(ugly2, ugly3), ugly5));
            }

            return *uglyNum.rbegin();
        }
  
        static void test()
        {
            Solution_32 su;
            int ans = su.GetUglyNumber_Solution(6);
        }
    };
  
}


#endif //!_32_H_
