/************************************************
  FileName    : WangYi_1.h           ;
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
#ifndef _WANGYI_1_H_
#define _WANGYI_1_H_

#include <string>
#include <iostream>
#include <set>
using namespace std;

namespace Chirl
{
    /************************************************************************
     题      目：https://www.nowcoder.com/test/question/8c29f4d1bea84d6ba2847e079b7420f7?pid=6291726&tid=9890658;
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_WangYi_1
    {
    public:
        int BeautifulBrick(const string &bricks)
        {
            set<char> colors;
            for (int i = 0; i < bricks.length(); i++)
            {
                colors.insert(bricks[i]);
            }

            switch (colors.size())
            {
            case 1:
                return 1;
            case 2:
                return 2;
            default:
                return 0;
            }
        }
        static void test()
        {
            Solution_WangYi_1 su;
            cout << su.BeautifulBrick("ABAB");
        }
    };
  
}


#endif //!_WangYi_1_H_
