/************************************************
  FileName    : 646.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/29                      ;
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
#ifndef _646_H_
#define _646_H_
#include <vector>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_646
    {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            if(pairs.empty()) return 0;

            vector<int> link(pairs.size(), -1);
            link[0] = 0;
            int ans = 1;
            for(int i = 1; i < pairs.size(); ++i){
                int j = 0;
                for(; j < ans; ++j){
                    if(pairs[link[j]][1] >= pairs[i][1]){
                        int k = ans;
                        while(k > j){
                            link[k--] = link[k];
                        }
                        link[j] = i;
                        ans++;

                        break;
                    }
                }
                if (j == ans){
                    link[ans] = i;
                    ans++;
                }
            }

            ans = 1; int curVal = pairs[link[0]][1];
            for(int i = 0; i < link.size(); ++i){
                if(pairs[link[i]][0] > curVal) {
                    curVal = pairs[link[i]][1];
                    ans++;
                }
            }
            return ans;
        }
  
        static void test()
        {
            int tmp[] = {9,10,-9,9,-6,1,-4,1,8,10,7,10,9,10,2,10};
            vector<vector<int>> pairs;
            for (int i = 0; i < sizeof(tmp)/sizeof(int)/2; ++i){
                pairs.push_back(vector<int>(tmp+i*2, tmp+2+i*2));
            }
            Solution_646 su;
            su.findLongestChain(pairs);
        }
    };
  
}


#endif //!_646_H_
