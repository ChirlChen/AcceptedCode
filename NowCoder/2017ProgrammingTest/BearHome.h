/************************************************
  FileName    : BearHome.h           ;
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
#ifndef _BEARHOME_H_
#define _BEARHOME_H_
#include <iostream>
#include <math.h>
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_BearHome
    {
    public:
        int BearHome(){
            int n = 0;
            cin >> n;
            if(n <= 2){
                return -1;
            }
            int *arr = new int[n];

            for(int i = 0; i < n; i++){
                cin >> arr[i];
            }
            int **sumArr = new int*[2];
            sumArr[0] = new int[n]();   
            sumArr[1] = new int[n]();
            sumArr[0][0] = 0;
            sumArr[1][0] = 0;
            for (int i = 1; i < n; ++i){
                sumArr[0][i] = sumArr[0][i-1] + abs(arr[i] - arr[i-1]);
                sumArr[1][i] = sumArr[1][i-1] + abs(arr[n-i-1] - arr[n-i]);
            }

            int distance = 0xFFFFFFF;
            for (int i = 1; i < n-1; i++){
                int tmp = sumArr[0][i-1] + sumArr[1][n-i-2] + abs(arr[i-1] - arr[i+1]);
                distance = tmp < distance ? tmp : distance;
            }

            cout << distance;
            return 0;
        }

  
        static void test()
        {
            Solution_BearHome su;
            su.BearHome();
        }
    };
  
}


#endif //!_BearHome_H_
