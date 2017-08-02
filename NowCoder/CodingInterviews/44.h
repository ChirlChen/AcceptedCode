/************************************************
  FileName    : 44.h           ;
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
#ifndef _44_H_
#define _44_H_
#include <vector>
#include <algorithm>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_44
    {
    public:
        bool IsContinuous( vector<int> numbers ) {
            int len = numbers.size();
            if(len != 5) return false;

            sort(numbers.begin(), numbers.end());

            int zerosCnt = count(numbers.begin(), numbers.end(), 0);
            int idx = zerosCnt, prevCnt = zerosCnt;
            for(int i = numbers[zerosCnt]; i < *numbers.rbegin(); ++i){
                if(numbers[idx] == i) {
                    ++idx;
                }
                else if(zerosCnt > 0){
                    zerosCnt--;
                }
                else
                    return false;
            }

            if (prevCnt != 0){
                auto itr = unique(numbers.begin(), numbers.end());
                int uniqeLen = distance(numbers.begin(), itr);
                return len - uniqeLen == prevCnt - 1 ? true : false;
            }
            else
                return true;
        }
        static void test()
        {
            int tmp[] = {1,3,2,5,4};
            Solution_44 su;
            bool ans = su.IsContinuous(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_44_H_
