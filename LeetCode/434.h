#ifndef _434_H_
#define _434_H_
#include <iostream>
#include <string>
using namespace std;
namespace Sansan
{
    class Solution_434
    {
    public:
        int countSegments(string s)
        {
            int res=0;
            if(s.empty())
                return 0;
            s.push_back(' ');
            for (int j=1;j<s.length();j++)
            {
                if(s[j]==' '&&s[j-1]!=' ')
                    res++;
            }
            return res;
        }
        static void test()
        {
            Solution_434 su;
            string s="   dewewew  efret  rtgretgre  re ";
            printf("%d\n",su.countSegments(s));
        }
    };
}

namespace Chirl
{
    class Solution_434
    {
    public:
        int countSegments(string s)
        {
            int numSegments = 0;
            s.push_back(' ');                   // 字符串尾追加一个空字符，方面后面判断;
            const char *p = s.c_str();

            while ('\0' != *p)
            {
                if (*p != ' ' && *(p+1) == ' ') // 以单词尾为判断独立单词的标准;
                {
                    numSegments++;
                    p++;                        // 跳过已知空格;
                }
                p++;
            }

            return numSegments;
        }
  
        static void test()
        {
            Solution_434 su;
            string s="   dewewew,  efret  rtgretgre  re ";
            cout << su.countSegments(s) << endl;  
        }
    };
  
}
#endif