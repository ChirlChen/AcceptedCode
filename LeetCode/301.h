/************************************************
  FileName    : 301.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/04/12                      ;
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
#ifndef _301_H_
#define _301_H_
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_301
    {
    public:
        vector<string> removeInvalidParentheses(string s) 
        {
            vector<string> result;
            if (s.empty())
            {
                return result;
            }
            char p[] = {'(', ')'};
            remove(s, 0, result, p);

            return result;
        }  
        
    private:
      
        void remove(string &s, int begIdx, vector<string> &ans, char p[])
        {
            int pcnt = 0;
            for (int j = 0; j < s.size(); ++j)
            {
                if (s[j] == p[0]) pcnt++;
                else if (s[j] == p[1]) pcnt--;
                
                if (pcnt < 0)
                {
                    for (int i = begIdx; i <= j; ++i)
                    {
                        if (s[i] == p[1] && (i == j || s[i+1] != p[1]))
                        {
                            string tmp(s.substr(0, i));
                            tmp.append( s.substr(i+1, s.size()));
                            remove(tmp, i+1, ans, p);
                        }
                    }
                    return;
                }    
            }
            
            reverse(s.begin(), s.end());
            if (p[0] == '(')
            {
                char p1[] = {')', '('};
                remove(s, 0, ans, p1);
            }
            else
            {
                ans.push_back(s);
            }
            return;
        }
    public:
        static void test()
        {
            Solution_301 su;
            string str(")(a)())(()()()");
            vector<string> ans = su.removeInvalidParentheses(str);
        }
    };
  
}


#endif //!_301_H_
