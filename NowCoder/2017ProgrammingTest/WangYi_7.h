/************************************************
  FileName    : WangYi_7.h           ;
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
#ifndef _WANGYI_7_H_
#define _WANGYI_7_H_

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace Chirl
{
    /************************************************************************
     题      目：https://www.nowcoder.com/question/next?pid=6291726&qid=112726&tid=9890658
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_WangYi_7
    {
    public:
        int MaxCrazyValue(vector<int> &heights)
        {
            if (heights.size() <= 1)
            {
                return 0;
            }
            
            sort(heights.begin(), heights.end());
            
            int idxRight = heights.size() - 1;
            int idxLeft = 0;
            int idxTmp = idxLeft;
            int idxCur = idxRight;

            int maxHeight = 0;
            //maxHeight += heights[idxCur] - heights[idxLeft];

            int cnt = 0;
            while (cnt < heights.size()-1)
            {
                if (cnt & 0x1)
                {
                    idxTmp = idxRight;
                    maxHeight +=  heights[--idxRight] - heights[idxCur];
                    idxCur = idxTmp;
                }
                else
                {
                    idxTmp = idxLeft; 
                    maxHeight += (heights[idxCur] - heights[idxLeft++]);
                    idxCur = idxTmp;
                }
                
                cnt++;
            }
            
            return maxHeight;
        }
  
        static void test()
        {
            Solution_WangYi_7 su;
            int tmp[] = {5, 10, 25, 40, 25};

            cout << su.MaxCrazyValue(vector<int>(begin(tmp), end(tmp)));
        }
    };
  
}


#endif //!_WangYi_7_H_
