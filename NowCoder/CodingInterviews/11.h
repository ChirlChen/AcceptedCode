/************************************************
  FileName    : 11.h                            ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/02/27                      ;
              _                                 ;
             /  \         ¼ª                    ;     
            /|oo \         Ïé                   ;    
           (_|  /_)       Îï                    ;   
             `@/  \   _    Õò                   ;    
             |     \  \\  Â¥                    ;   
              \||   \  ))  !!                   ;    
              |||\ / \//                        ; 
            _//|| _\  /                         ;
    ______(_/(_|(____/_________                 ;
*************************************************/
#ifndef _11_H_
#define _11_H_

namespace Wcytem
{
    class Solution_11
    {
    public:
        int NumberOf1(int n) {
            int NumOf1 = 0;
            int temp = 1;
            for (int i = 0; i < 8*sizeof(n); i++)
            {
                if(temp&n)
                {
                    NumOf1++;
                }
               n>>=1;
            }
            return NumOf1;
        }
        //ÖÐÎÄ×¢ÊÍ²âÊÔ;
        static void test()
        {
            Solution_11 su;
            int a = su.NumberOf1(-2);

        }
    };

}

namespace Chirl
{
    class Solution_11
    {
    public:
        int  NumberOf1(int n) {
            int cnt = 0;
            while(n){
                cnt++;
                n = n & (n-1);
            }
            return cnt;
        }
  
        static void test()
        {
            Solution_11 su;
            int a = su.NumberOf1(-2);

        }
    };
  
}
#endif //!_11_H_
