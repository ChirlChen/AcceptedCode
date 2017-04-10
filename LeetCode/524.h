/************************************************
  FileName    : 11.h                            ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/02/27                      ;
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
#ifndef _524_H_
#define _524_H_
#include <vector>
using namespace std;

namespace Chirl
{
    class Solution_524
    {
    public:
        /************************************************************************
         思路： 依次从d中取出一个字符串bs;
                逐字符去查看ds中的字符在s中是否存在;
                对于同一个字符串ds，s中找过的字符不再重复查找;
                如果, bs中所有的字符在s中都能找到，则该字符是可能的返回值;
                      反之则不是可能的返回值;
                返回最终找到的最长且字符序最小的字符串;
         算法复杂度：;
                s的长度：m; d的长度：n; d中字符串平均长度：k
                复杂度：O(m*n);
        ************************************************************************/
        string findLongestWord(string s, vector<string>& d)
        {
            if (d.empty() || s.empty())
            {
                return string();
            }

            string resultStr;           //可能的结果字符串;
            int dictSize = d.size();
            for (int i = 0; i < dictSize; i++)
            {
                if (d[i].size() > s.size() || d[i].size() < resultStr.size())
                {
                    continue;
                }

                const char *pds = d[i].c_str();
                const char *ps  = s.c_str();
                while (*ps != '\0')
                {
                    if (*pds == *ps)
                    {
                        pds++;
                    }
                    if ('\0' == *pds)   //字典d中当前字符被全部找到;
                    {
                        if (resultStr.size() < d[i].size() ||               //如果比上次结果更长，则更新返回结果;
                            0 > strcmp(d[i].c_str(), resultStr.c_str()))    //等长但是字典序更小;
                        {
                            resultStr = d[i];
                        }
                        break;
                    }
                    ps++;
                }
            }
            return resultStr;
        }
  
        string findLongestWord_1(string s, vector<string>& d)   //网上其他人的方案（https://discuss.leetcode.com/topic/80876/10-lines-solutions-for-c），思路一致,但代码很精练;
        {
            string ans;                                         
            for (int i = 0; i < d.size(); i++) 
            {
                int pi = 0, pj = 0;
                for (; pi < s.size() && pj < d[i].size(); pi++) 
                {
                    pj += s[pi] == d[i][pj];                    //这一行很精妙;
                }
                if (pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && strcmp(ans.c_str(),d[i].c_str()))))
                    ans = d[i];
            }
            return ans;
        }
        static void test()
        {
            string s = "abpcplea";//"bab";//
            string tmps[] = {"ale","apple","monkey","plea"};//{"ba","ab","a","b"};//
            vector<string> d(begin(tmps), end(tmps)); 
            
            Solution_524 su;
            string str = su.findLongestWord(s, d);
        }
    };
  
}


#endif //!_524_H_