/**************************************************
  Description :
  Editor      : Chirl
  EditDate    : 2017/02/27
              _ 
             /  \               
            /|oo \              
           (_|  /_)             
             `@/  \    _        
             |     \   \\       
              \||   \   ))      
              |||\ /  \//       
            _//|| _\   /          
     ______(_/(_|(____/_________ 
**************************************************/
#ifndef _7_H_
#define _7_H_

#pragma execution_character_set("utf-8")

namespace Chirl
{
    class Solution_7
    {
    public:
        Solution_7()
        {
            for (int i = 0; i < 40; i++) 
            {
                F[i] = 0;
            }
        }

        int Fibonacci(int n) 
        {
            if (1 >= n) 
            {
                F[n] = n;
                return n;
            }
            else if (0 != F[n]) 
            {
                return F[n];
            }

            F[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
            return F[n];
        }

        static void test()
        {
            Solution_7 su;
            su.Fibonacci(30);
        }

    private:
        int F[40];



    };

}
namespace Wcytem
{
    class Solution_7
    {
    public:
        int Fibonacci(int n) {
            if(n < 0)
                return -1;
            int pre1 = 0, pre2 = 1,temp = 0;
            while(n)
            {
                temp = pre1;
                pre1 = pre2;
                pre2 += temp;
                n--;
            }
            return pre1;
        }
        static void test()
        {
            Solution_7 su;
            su.Fibonacci(30);
        }          
    };



}


#endif //!_7_H_