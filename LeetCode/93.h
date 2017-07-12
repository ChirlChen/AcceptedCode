/************************************************
  FileName    : 93.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/04                      ;
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
#ifndef _93_H_
#define _93_H_

#include <string>
#include <vector>
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_93
    {
    public:
        vector<string> restoreIpAddresses(string s) 
        {
            if (s.length() < 4)
            {
                return vector<string>();
            }
            
            DivideIpStr(s);
            return m_addrs;
        }


  
        static void test()
        {
            Solution_93 su;
            string str("010010"); //"010010"   "25525511135"
            vector<string> res = su.restoreIpAddresses(str);
        }

    private:
        void DivideIpStr(const string &s)
        {
            string addr;
            DivideIpStr(s, 0, 4, addr);
        }
        
        bool DivideIpStr(const string &s, int curIdx, int restn, string addr)
        {
            int restLen = (s.length() - curIdx);
            if (restLen < restn || restLen > MAX_LEN * restn)
            {
                return false;
            }
            if (restLen == 0 && restn == 0)
            {
                addr.pop_back();
                m_addrs.push_back(addr);
                return true;
            }
            for (int i = 1; i <= MAX_LEN && (i+curIdx) <= s.length(); ++i)
            {
                string tmpStr(&(s[curIdx]), &(s[curIdx+i]));
                int tmp = atoi(tmpStr.c_str());
                if (tmp <= MAX_NUM && tmp >= 0)
                {
                    DivideIpStr(s, curIdx + i, restn - 1, addr + tmpStr + ".");
                    if (s[curIdx] == '0')
                    {
                        break;
                    }
                }
                int a = 0;
            }
            
        }

    private:
        const static int MAX_LEN = 3;
        const static int MAX_NUM = 255;
        vector<string>      m_addrs;
    };
  
}


#endif //!_93_H_
