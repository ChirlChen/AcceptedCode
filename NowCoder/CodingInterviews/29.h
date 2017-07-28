/************************************************
  FileName    : 29.h           ;
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
#ifndef _29_H_
#define _29_H_
#include <vector>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_29
    {
    public:
        vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
            if(input.size() < k) return vector<int>();

            int first = 0, last = input.size()-1;
            first = Partion(input, first, last);
            while(first != k-1) {
                if(first < k-1){
                    first = Partion(input, first+1, last);
                }
                else if(first >= k){
                    first = Partion(input, 0, first-1);
                }
            }

            return vector<int>(&input[0], &input[k]);
        }

        int Partion(vector<int> &in, int first, int last){
            int p = in[first];

            int beg = first, end = last;
            while(beg < end) {
                for(; in[beg] < p; ++beg);
                for(; in[end] > p; --end);

                swap(in[beg], in[end]);
            }

            return end;
        }
        static void test()
        {
            Solution_29 su;
            int tmp[] = {4,5,1,6,2,7,3,8};

            su.GetLeastNumbers_Solution(vector<int>(begin(tmp), end(tmp)), 5);
        }
    };
  
}


#endif //!_29_H_
