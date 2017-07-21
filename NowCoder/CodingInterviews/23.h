/************************************************
  FileName    : 23.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/20                      ;
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
#ifndef _23_H_
#define _23_H_
#include <vector>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_23
    {
    public:
        bool VerifySquenceOfBST(vector<int> sequence) {
            if(sequence.empty()) return false;
            return DoVerifySquenceOfBST(sequence, 0, sequence.size()); 
        }

    private:
        bool DoVerifySquenceOfBST(const vector<int> &seq, int first, int last){
            if(first == last) return true;

            int root = seq[last-1];
            int div = first;
            for(; div < last; ++div){
                if(seq[div] >= root)
                    break;
            }
            for(int i = div; i < last; ++i){
                if(seq[i] < root) return false;
            }

            return DoVerifySquenceOfBST(seq, first, div) && DoVerifySquenceOfBST(seq, div, last-1);
        }
    public:
        static void test()
        {
            Solution_23 su;
            int tmp[] = {5, 7, 6, 9, 11, 10, 8, 18};
            bool res = su.VerifySquenceOfBST(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_23_H_
