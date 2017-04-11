/************************************************
  FileName    : TencentInterview.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/04/05                      ;
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
#ifndef _TENCENTINTERVIEW_H_
#define _TENCENTINTERVIEW_H_

#include <string>

namespace Chirl
{
    /*
        题    目：求一个字符序列中的逆序数;字符序列中的字母只会包括ABCD;
              eg. DBACA, 则逆序包括 DB、DA、DC、DA、BA、BA、CA。逆序数为7;
        
        求解思路: 1、遍历整个序列，用一个字符数组charArray记录字符当前在字符序列中出现的次数;
                  2、每次去charArray中查询比当前的字符小的所有字符出现次数，然后依次加到计数器中;
    */

    class Solution_TencentInterview
    {
    public:
         int ReverseCharSquence(std::string str)
         {
             int charArray[4] = {0};
             int counter      = 0;
             const char *ptr  = str.c_str();
             bool addFlag     = true;

             while (*ptr != '\0')
             {
                 switch (*ptr++)
                 {
                 case 'A':
                     charArray[0] += 1;
                     addFlag = false;
                 case 'B':
                     if (addFlag == true)
                     {
                         charArray[1] += 1;
                         addFlag       = false;
                     }
                     else
                     {
                         counter += charArray[1]; 
                     }
                 case 'C':
                     if (addFlag == true)
                     {
                         charArray[2] += 1;
                         addFlag       = false;
                     }
                     else
                     {
                         counter += charArray[2];
                     }
                 case 'D':
                     if (addFlag == true)
                     {
                         charArray[3] += 1;
                         addFlag       = false;
                     }
                     else
                     {
                         counter += charArray[3];
                     }
                     break;

                 default:
                     break;
                 }
                 addFlag = true;
             }
             return counter;
         }
  
        static void test()
        {
            Solution_TencentInterview su;
            std::string str("DBACA");
            int cnt = su.ReverseCharSquence(str);

        }
    };
  
}


#endif //!_TencentInterview_H_
