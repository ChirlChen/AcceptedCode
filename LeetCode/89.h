/************************************************
  FileName    : 89.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/04/06                      ;
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
#ifndef _89_H_
#define _89_H_

#include <vector>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路：由于格雷码的上半部分和下半部分，除了最高位相反，其他位是成;
                 镜像关系的， 所以以镜像为基础，最高位取1即可;

     算法复杂度：O(m) - m 表示n位格雷码所能编码的总数值数，m = pow(2, n);
     ************************************************************************/
    class Solution_89
    {
    public:
        vector<int> grayCode(int n) 
        {
            if (n <= 0) 
            {
                return vector<int>();
            }
            int numsCnt = pow(2, n);
            vector<int> grayBits;
            grayBits.reserve(numsCnt);


            grayBits.push_back(0);
            for (int i = 0; i < n; ++i) 
            {
                int reCnt = pow(2, i) - 1;
                int highBit = 1 << i;
                for (int j = reCnt; j >= 0; --j) 
                {
                    int curCode = grayBits[j] | highBit;
                    grayBits.push_back(curCode);
                }
            }
            return grayBits;


        }  
  
        static void test()
        {
            Solution_89 su;
            vector<int> grayNum = su.grayCode(4);


        }
    };
  
}


#endif //!_89_H_
