/************************************************
  FileName    : InterestingSort.h           ;
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
#ifndef _INTERESTINGSORT_H_
#define _INTERESTINGSORT_H_
#include <iostream>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_InterestingSort
    {
    public:
        int InterestingSort(){
            int n = 0;
            cin >> n;
            if(n <= 1){
                cout << 0;
                return 0;
            }

            int cnt = 0, curMin = 0;
            int **arr = new int*[2];
            arr[0] = new int[n];
            arr[1] = new int[n];

            for(int i = 0; i < n; ++i){
                cin >> arr[0][i];
                arr[1][i] = arr[0][i];
            }

            int isMoved = 0, idx = n, notMovedCnt = 0;
            for(int i; (i = idx - 1, i > 0); ){
                idx = 0;
                for(int j = 0; j < i; ++j){
                    if(arr[isMoved][j] > arr[isMoved][i]){
                        cnt++;
                    }
                    else{
                        arr[!isMoved][idx++] = arr[isMoved][j];
                    }

                }
                if(idx == i){
                    notMovedCnt++;
                }
                else{
                    cnt += notMovedCnt;
                    notMovedCnt = 1;
                }
                isMoved = !isMoved;
            }

            cout << cnt;
            return 0;
        }
  
        static void test()
        {
            Solution_InterestingSort su;
            su.InterestingSort();
        }
    };
  
}


#endif //!_InterestingSort_H_
