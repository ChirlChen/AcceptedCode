/************************************************
  FileName    : 41.h           ;
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
#ifndef _41_H_
#define _41_H_
#include <vector>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_41
    {
    public:
        vector<int> FindNumbersWithSum(vector<int> array,int sum) {
            vector<int> ans;
            if(array.size() <= 1) return ans;

            int first = 0, last = array.size()-1;
            while(first < last){
                int res = sum - array[last];
                while(first < last && res > array[first]){
                    first++;
                }

                if(res == array[first]){
                    ans.push_back(array[first]);
                    ans.push_back(array[last]);
                    break;
                }
                else{
                    last--;
                }

            }
            return ans;
        }
  
        static void test()
        {
            int tmp[] = {1, 2, 3, 4, 5, 6, 10, 14, 15, 18};
            Solution_41 su;
            vector<int> ans = su.FindNumbersWithSum(vector<int>(begin(tmp), end(tmp)), 20);
        }
    };
  
}


#endif //!_41_H_
