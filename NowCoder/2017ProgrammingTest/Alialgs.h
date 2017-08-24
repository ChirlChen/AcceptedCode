/************************************************
  FileName    : Alialgs.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/08                      ;
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
#ifndef _ALIALGS_H_
#define _ALIALGS_H_
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>

using namespace std;
namespace Chirl
{
    /************************************************************************
    题      目：小明是一名刚入职的搜索算法工程师，有一天想看一下搜索关键词
                “dress”在我们日志中出现的次数，发现统计的数字和看到的报表
                并不相符，通过向师兄请教，小明发现同一个关键词，用户的输入
                千奇百怪，像“drass”、“drese”等，用全词匹配的方式就自然
                被漏掉了。请你帮助小明改进一下匹配算法，在最多只能错1个字的
                情况下（当然长度必须一致），计算所有的匹配数。
    输       入:
                多行，第一行是测试用例数T，后面T行每行包含一次待匹配的日志全
                文和关键词，空格分隔。为方便处理，均使用英文、数字和英文符号
                作为字母表，字符串长度不超过5万。
    输       出:
                T行，若匹配到，则顺序输出所有匹配到的起始下标，空格分隔；若匹
                配不到，输出-1。、

     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_Alialgs
    {
    public:
        bool is_match(const string &str1, const string &str2)
        {
            if (str1.size() != str2.size())
            {
                return false;
            }
            
            int errCnt = 0;
            for (int i = 0; i < str1.size(); ++i)
            {
                if (str1[i] != str2[i])
                {
                    errCnt++;
                }
            }
            return errCnt <= 1;
        }
        string  aproximate_match(const string &log, const string &query) {
            string ans;
            int queLen = query.size();
            int logLen = log.size();
            
            int logIdx = 0; string tmp;
            while (logIdx <= logLen)
            {
                if (log[logIdx] != ' ' && log[logIdx] != '\0')
                {
                    tmp.push_back(log[logIdx]);
                }
                else
                {
                    if (is_match(tmp, query))
                    {
                        ans.append(to_string((long long)(logIdx - queLen)));
                        ans.push_back(' ');
                    }
                    tmp.clear();
                }
                ++logIdx;
            }

            if (ans.size() > 0)
            {
                ans.pop_back();
            }
            else
                ans.append("-1");

            return ans;
        }

  
        static void test()
        {
            int T;
            cin >> T;
            Solution_Alialgs su;
            for (int t=0;t<T;t++)
            {
                string log, query;
                log.append("abc abd bbc ases abca");
                cin >> query;

                cout << su.aproximate_match(log, query) << endl;
            }

        }
    };
  
}


#endif //!_Alialgs_H_
