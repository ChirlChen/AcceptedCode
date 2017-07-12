/************************************************
  FileName    : BWCards.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/12                      ;
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
#ifndef _BWCARDS_H_
#define _BWCARDS_H_
#include <iostream>
#include <string>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_BWCards
    {
    public:
        int NumOfFlipCards(const string &cards)
        {
            int numCards = cards.length();
            int bFlipCnt = 0, wFlipCnt = 0;

            for (int i = 0; i < numCards; ++i)
            {
                if (i % 2 == 0)
                {
                    bFlipCnt += 'B' == cards[i] ? 0 : 1;
                    wFlipCnt += 'B' == cards[i] ? 1 : 0;
                }
                else
                {
                    bFlipCnt += 'B' == cards[i] ? 1 : 0;
                    wFlipCnt += 'B' == cards[i] ? 0 : 1;
                }
            }
            return bFlipCnt < wFlipCnt ? bFlipCnt : wFlipCnt;
        }
  
        static void test()
        {
            string cards;
            cin >> cards;
            Solution_BWCards su;
            
            cout << su.NumOfFlipCards(cards);
        }
    };
  
}


#endif //!_BWCards_H_
