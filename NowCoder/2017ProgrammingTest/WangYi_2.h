/************************************************
  FileName    : WangYi_2.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/24                      ;
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
#ifndef _WANGYI_2_H_
#define _WANGYI_2_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Chirl
{
    /************************************************************************
     题      目：https://www.nowcoder.com/question/next?pid=6291726&qid=112723&tid=9890658;
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_WangYi_2
    {
    public:
        string IsAP(const vector<int> &arr)
        {
            int firstMin = 0xFFFFFFF;
            int secMin = 0xFFFFFFF;
            int cnt = arr.size();
            vector<int> minusVal(cnt, 0);
            vector<int> flags(cnt, 0);

            for (int i = 0; i < cnt; ++i)
            {
                int tmp = arr[i] - arr[0];
                minusVal[i] = tmp;

                if (firstMin >= tmp)
                {
                    secMin = firstMin;
                    firstMin = tmp;
                }
                if (firstMin < tmp && secMin > tmp)
                {
                    secMin = tmp;
                }
            }

            if (firstMin == secMin)
            {
                return "Possible";
            }
            secMin = secMin - firstMin;
            for (int i = 0; i < cnt; ++i)
            {
                int idx = (minusVal[i] - firstMin) / secMin;
                if (idx >= cnt || flags[idx] == 1)
                {
                    return "Impossible";
                }
                flags[idx] = 1;
            }

            return "Possible";
        }

        static void test()
        {
            int tmp[] = {1,1,1,1};
            vector<int> arr(begin(tmp), end(tmp));
            
            Solution_WangYi_2 su;
            cout << su.IsAP(arr);
        }
    };
  
}


#endif //!_WangYi_2_H_
