/************************************************
  FileName    : 21.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/20                      ;
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
#ifndef _21_H_
#define _21_H_

#include <queue>
#include <stack>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_21
    {
    public:
        bool IsPopOrder(vector<int> pushV,vector<int> popV) {
            if(pushV.size() != popV.size()) return false;

            queue<int> q;
            stack<int> s;
            for(auto itr = popV.begin(); itr != popV.end(); ++itr){
                q.push(*itr);
            }

            for(auto itr = pushV.begin(); itr != pushV.end(); ++itr){
                if(*itr == q.front()) {
                    q.pop();
                    while(!q.empty() && !s.empty() && q.front() == s.top()){
                        q.pop();
                        s.pop();
                    }
                }
                else s.push(*itr);
            }

            if(q.empty() && s.empty())
                return true;
            return false;
        }
  
        static void test()
        {
            Solution_21 su;
            int tmp[] = {1,2,3,4,5};
            int tmp1[] = {4,5,3,2,1};
            su.IsPopOrder(vector<int>(begin(tmp), end(tmp)), vector<int>(begin(tmp1), end(tmp1)));
        }
    };
  
}


#endif //!_21_H_
