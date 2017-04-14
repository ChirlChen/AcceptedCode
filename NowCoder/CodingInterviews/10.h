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
#ifndef _10_H_
#define _10_H_

#pragma execution_character_set("utf-8")

namespace Chirl
{
    class Solution_10
    {
    public:
        int rectCover(int number) {
            if (0 == number) 
                return 0;
            int cnt = number / 2;
            int coverCnt = 1;

            while (cnt > 0) {
                coverCnt += combination(number - cnt, cnt);
                cnt--;
            }

            return coverCnt;
        }


        static void test()
        {
            Solution_10 su;
            su.rectCover(20);
        }

    private:
        int combination(int all, int n) {
            if (0 == all || all == n) {
                return 1;
            }
            return factorial(all, all - n) / factorial(n, 1);
        }

        long long factorial(int s, int e) {
            long long res = 1;
            while (e < s) {
                res *= s--;
            }
            return res;
        }
    };

}
namespace Wcytem
{
    class Solution_10
    {
    public:
        int rectCover(int number) {
            if (number <= 0)
                return 0;
            else
            {
                int pre1 = 1, pre2 = 2, temp = 0;
                while(--number)
                {
                    temp = pre1;
                    pre1 = pre2;
                    pre2 += temp;
                }
                return pre1;
            }
        }

        static void test()
        {
            Solution_10 su;
            su.rectCover(20);
        }         
    };



}


#endif //!_10_H_