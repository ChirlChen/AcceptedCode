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

#ifndef _2_H_
#define _2_H_
#include <string.h>

namespace Chirl
{
    class Solution_2 {
    public:
        void replaceSpace(char *str,int length) 
        {
            // 因为题目标注length为字符串最大长度，这里忽略字符串超长情况；
            int  curIdx = 0;
            char *tempS = new char[length];
            char *ptS   = tempS;
            while (str[curIdx] != '\0')
            {
                if (str[curIdx] != ' ')
                {
                    *ptS++ = str[curIdx++];

                }
                else
                {
                    *ptS++ = '%';
                    *ptS++ = '2';
                    *ptS++ = '0';
                    curIdx++;
                }     
            }
            *ptS = '\0';

            ptS   = tempS;
            curIdx = 0;
            do
            {
                str[curIdx++] = *ptS;
            }while(*ptS++ != '\0');
        }

        static void test()
        {
            Solution_2 su;
            char testStr[100] = "Hello World!";
            su.replaceSpace(testStr, sizeof(testStr));
        }
    };
}
namespace Wcytem
    {
        class Solution_2 {
        public:
            void replaceSpace(char *str,int length) {
                int j = 0;
                int len = strlen(str);
                for (int i = 0; i < len; i++)
                {
                    if (str[i] == ' ')
                        j++;
                }
                char *p = new char[len+2*j+1];
                p[len+2*j] = '\0';
                j = 0;
                for(int i = 0; i < len; i++)
                {
                    if(str[i] == ' ')
                    {
                        p[j] = '%';
                        p[j+1] = '2';
                        p[j+2] = '0';
                        j += 3;
                    }
                    else
                    {
                        p[j] = str[i];
                        j++;
                    }
                }
                strcpy(str,p);
                delete []p;
            }
            static void test()
            {
                Solution_2 su;
                char testStr[100] = "Hello World!";
                su.replaceSpace(testStr, sizeof(testStr));
            }
        };

}


#endif // !_2_H_
