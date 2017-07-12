/************************************************
  FileName    : GracePoints.h           ;
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
#ifndef _GRACEPOINTS_H_
#define _GRACEPOINTS_H_
#include <iostream>
#include <math.h>
using std::cin;
using std::cout;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_GracePoints
    {
    public:
        void GracePoints()
        {
            int rsqrt = 0;
            cin >> rsqrt;

            int r = sqrt(rsqrt);
            int xmax = sqrt(rsqrt/2.0f);
            int cnt = 0;

            for(int x = 1; x <= xmax; ++x){
                int ymin = sqrt(rsqrt - pow(x, 2));
                if(pow(x, 2) + pow(ymin, 2) == rsqrt) cnt += 8;
                if(pow(x, 2) + pow(ymin+1, 2) == rsqrt) cnt += 8;

            }
            if(pow(r, 2) == rsqrt) cnt += 4;
            if(2 * pow(xmax, 2) == rsqrt) cnt -= 4;

            cout << cnt;

            return;
        }
  
        static void test()
        {
            Solution_GracePoints su;
            su.GracePoints();
        }
    };
  
}


#endif //!_GracePoints_H_
