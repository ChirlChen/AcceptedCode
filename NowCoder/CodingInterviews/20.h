/************************************************
  FileName    : 20.h           ;
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
#ifndef _20_H_
#define _20_H_
#include <stack>

using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_20
    {
    public:
        void push(int value) {
            int minVal = m_min.empty() ? 0xFFFFFFF : m_min.top();
            m_min.push(value < minVal ? value : minVal);
            m_vals.push(value);
        }
        void pop() {
            m_min.pop();
            m_vals.pop();
        }
        int top() {
            return m_vals.top();
        }
        int min() {
            return m_min.top();
        }

        static void test()
        {
            Solution_20 su;
            su.push(10);
        }
    private:
        stack<int> m_vals;
        stack<int> m_min;
    };
  
}


#endif //!_20_H_
