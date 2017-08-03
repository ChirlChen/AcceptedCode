/************************************************
  FileName    : 49.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/03                      ;
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
#ifndef _49_H_
#define _49_H_
#include <vector>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_49
    {
    public:
        bool duplicate(int numbers[], int length, int* duplication) {
            if(nullptr == numbers || length < 2) return false;

            vector<int> numCnt(length, 0);
            for(int i = 0; i < length; ++i){
                numCnt[numbers[i]] += 1;

                if(numCnt[numbers[i]] > 1){
                    //if(duplication != nullptr) delete duplication;

                    *duplication = numbers[i];
                    return true;
                } 
            }

            return false;
        }
  
        static void test()
        {
            int tmp[] = {1,2,3,4,4,2,3,1,1};
            Solution_49 su;
            int ans = 0;
            bool dup = su.duplicate(tmp, sizeof(tmp)/sizeof(int), &ans);
        }
    };
  
}


#endif //!_49_H_
