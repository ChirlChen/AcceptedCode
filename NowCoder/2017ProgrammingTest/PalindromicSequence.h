/************************************************
  FileName    : PalindromicSequence.h           ;
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
#ifndef _PALINDROMICSEQUENCE_H_
#define _PALINDROMICSEQUENCE_H_
#include<iostream>

using std::cin;
using std::cout;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_PalindromicSequence
    {
    public:
        int PalindromicSequence()
        {
            int n = 0;
            cin >> n;
            if(n <= 1){
                return 0;
            }

            int *items = new int[n];
            for(int i = 0; i < n; ++i){
                cin >> items[i];
            }

            int beg = 0, last = n - 1, cnt = 0;
            int begSum = items[beg], lastSum = items[last];
            while(beg < (last-1)){
                if(begSum == lastSum){
                    begSum = items[++beg];
                    lastSum = items[--last];
                }
                else if(begSum < lastSum){
                    begSum += items[++beg];
                    cnt++;
                }
                else if(begSum > lastSum){
                    lastSum += items[--last];
                    cnt++;
                }
            }

            if (begSum == lastSum) cout << cnt;
            else cout << cnt+1;

            return 0;
        }
  
        static void test()
        {
            Solution_PalindromicSequence su;
            su.PalindromicSequence();
        }
    };
  
}


#endif //!_PalindromicSequence_H_
