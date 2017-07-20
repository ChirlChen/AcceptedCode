/**************************************************
  Description :
  Editor      : Wcytem
  EditDate    : 2017/04/14
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
#ifndef _12_H_
#define _12_H_

#pragma execution_character_set("utf-8")

namespace Wcytem
{
    class Solution_12
    {
    public:
        double Power(double base, int exponent) {
            if(exponent < 0)
                return 1/Power(base,-exponent);
            if(exponent  == 0)
            {return 1;}
            else if(exponent % 2 == 1)
            {
                return Power(base ,exponent / 2)*Power(base,exponent / 2)*base;
            }
            else
                return Power(base,exponent / 2)*Power(base,exponent / 2);
        }

        static void test()
        {
            Solution_12 su;
            su.Power(2.0,3);
        }         
    };



}

#include <math.h>
namespace Chirl
{
    class Solution_12
    {
    public:
        double Power(double base, int exponent) {
            if (abs(base) < 0.000001){
                return 0;
            }
            bool minus = exponent < 0 ? true : false;
            double result = DoPower(base, abs(exponent));

            return minus ? 1/result : result;
        }
        double DoPower(double base, int exp) {
            if (exp <= 0){
                return 1;
            }
            else if(exp == 1){
                return base;
            }

            double res = DoPower(base, exp>>1);
            res *= res;
            if(exp & 0x1) res *= base;

            return res;
        }
  
        static void test()
        {
            Solution_12 su;
            su.Power(2.0, 3);
        }         
    };
  
}

#endif //!_12_H_