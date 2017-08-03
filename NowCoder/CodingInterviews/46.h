/************************************************
  FileName    : 46.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/02                      ;
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
#ifndef _46_H_
#define _46_H_

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    //类模板，全特化做终止条件;
    template<int N>
    class CAccumulateAdd{
    public:
        enum {ans = CAccumulateAdd<N-1>::ans + N};
    };
    template<>
    class CAccumulateAdd<1> {
    public:
        enum {ans = 1};
    };

    //继承，基类虚函数做终止条件;
    class BaseSolution {
    public:
        virtual int Sum(int n) {
            return 0;
        }
    };

    BaseSolution *bs[2];
    class Solution : public BaseSolution {
    public:
        int Sum(int n) {
            return n + bs[!!(n-1)]->Sum(n-1);
        }

        int Sum_Solution(int n) {
            bs[0] = &BaseSolution();
            bs[1] = &Solution();
            return bs[1]->Sum(n);
        }
    };

    //静态变量，申请N个对象,实现累加;
    class Solution_46
    {
    public:
        Solution_46()
        {
            ++N;sum += N;
        }

        static void Clear()
        {
            N = 0;
            sum = 0;
        }
        int GetSum()
        {
            return sum;
        }

        static void test()
        {
            int res1 = CAccumulateAdd<10>::ans;

            int n = 10;
            
            Solution su1;
            int res2 = su1.Sum_Solution(n);

            Solution_46 *su;
            Solution_46::Clear();
            su = new Solution_46[n];
            int res3 = su[0].GetSum();
            delete []su;
        }
    private:
        static int N;
        static int sum;
    };
  
    int Solution_46::N = 0;
    int Solution_46::sum = 0;
}


#endif //!_46_H_
