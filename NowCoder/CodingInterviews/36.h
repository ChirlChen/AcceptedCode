/************************************************
  FileName    : 36.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/31                      ;
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
#ifndef _36_H_
#define _36_H_
#include <vector>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_36
    {
    public:
        int GetNumberOfK(vector<int> data ,int k) {
            int cnt = 0;
            if(data.empty()) return 0;

            int first = 0, last = data.size()-1;
            int mid = 0;
            while(first < last){
                mid = (first + last) / 2;
                if(data[mid] < k){
                    first = mid + 1;
                }
                else if(data[mid] > k){
                    last = mid - 1;
                }
                else
                    break;
            }

            last = mid + 1; first = mid;
            while(first >= 0 && data[first] == k){
                cnt++; 
                first--;
            }
            while(last < data.size() && data[last] == k){
                cnt++;
                last++;

            }

            return cnt;
        }
  
        static void test()
        {
            int tmp[] = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
            Solution_36 su;
            int ans = su.GetNumberOfK(vector<int>(begin(tmp), end(tmp)), 4);
        }
    };
  
}


#endif //!_36_H_
