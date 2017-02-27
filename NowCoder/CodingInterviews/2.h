#ifndef _2_H_
#define _2_H_


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


#endif // !_2_H_
