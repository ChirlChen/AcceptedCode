/************************************************
  FileName    : BigNumMutil.h           ;
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
#ifndef _BIGNUMMUTIL_H_
#define _BIGNUMMUTIL_H_

#include <string>
#include <vector>

using namespace std;
namespace Chirl
{
    /************************************************************************
     问      题：大数相乘;
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_BigNumMutil
    {
    public:
        string BigNumMutil(string num1, string num2)
        {
            int len1 = num1.length(), len2 = num2.length();
            if (len1 == 0 || len2 == 0)
            {
                return string("");
            }

            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());
            vector<int> vans(len1 + len2, 0);
            for (int i = 0; i < len1; ++i)
            {
                for (int j = 0; j < len2; ++j)
                {
                    int tmp = vans[i+j] + (num1[i] - '0') * (num2[j] - '0');
                    vans[i+j+1] += tmp / 10;
                    vans[i+j] = tmp % 10;
                }
            }
            
            string ans; ans.reserve(len1 + len2);
            auto itr = vans.rbegin();
            for (int i = 0; i < len1+len2 && itr != vans.rend(); ++i)
            {
                if (*itr || !ans.empty())
                {
                    ans.push_back(*itr + '0');
                }
                ++itr;
            }

            return ans;
        }
  
        static void test()
        {
            Solution_BigNumMutil su;
            string ans = su.BigNumMutil(string("4"), string("5"));
        }
    };
  
}


#endif //!_BigNumMutil_H_
