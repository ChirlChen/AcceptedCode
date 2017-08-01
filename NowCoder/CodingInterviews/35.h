/************************************************
  FileName    : 35.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/31                      ;
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
#ifndef _35_H_
#define _35_H_
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_35
    {
    public:
        ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
            if(pHead1 == nullptr || pHead2 == nullptr){
                return nullptr;
            }

            stack<ListNode *> s1, s2;
            while(pHead1 != nullptr){
                s1.push(pHead1);
                pHead1 = pHead1->next;
            }
            while(pHead2 != nullptr){
                s2.push(pHead2);
                pHead2 = pHead2->next;
            }

            ListNode *ans = nullptr;
            while(!s1.empty() && !s2.empty()){
                if(s1.top() != s2.top()){
                    break;
                }
                ans = s1.top();
                s1.pop(); s2.pop();
            }

            return ans;
        }
  
        static void test()
        {
            Solution_35 su;
            su.FindFirstCommonNode(nullptr, nullptr);
        }
    };
  
}


#endif //!_35_H_
