/************************************************
  FileName    : 31.h           ;
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
#ifndef _31_H_
#define _31_H_
#include <string>
#include <vector>
#include <set>
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_31
    {
    private:
        struct compare {
            bool operator()(const string &lh, const string &rh) const{
                int i = 0;
                for(; i < lh.length() && i < rh.length(); ++i){
                    if(lh[i] != rh[i]) return lh[i] < rh[i];
                }

                if(lh.length() == rh.length()) return false;

                if(i == lh.length()){
                    return operator()(lh, string(&rh[i])) ? 1 : lh.length() < rh.length();
                }
                else{
                    return operator()(string(&lh[i]), rh) ? 1 : lh.length() < rh.length();
                }
            }
        } ;
    public:
        string PrintMinNumber(vector<int> numbers) {
            if(numbers.empty()) return string("");

            set<string, compare> nums;
            //nums.reserve(numbers.size());

            for(int i = 0; i < numbers.size(); ++i){
                nums.insert(to_string((long long)numbers[i]));
            }

            string ans;
            for(auto itr = nums.begin(); itr != nums.end(); ++itr){
                ans.append(*itr);
            }

            return ans;
        }


        static void test()
        {
            Solution_31 su;
            int tmp[] = {1,11,1111};
            vector<int> nums(begin(tmp), end(tmp));
            su.PrintMinNumber(nums);
 
        }
    };
  
}


#endif //!_31_H_
