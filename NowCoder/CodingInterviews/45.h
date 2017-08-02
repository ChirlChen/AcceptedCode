/************************************************
  FileName    : 45.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/08/01                      ;
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
#ifndef _45_H_
#define _45_H_

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_45
    {
    private:
        typedef struct _ListNode{
            _ListNode *next;
            int num;

            _ListNode(int anum) : num(anum), next(nullptr) {}
        }ListNode;
    public:
        int LastRemaining_Solution(int n, int m)
        {
            if(n < 1 || m < 1) return -1;

            ListNode *head = new ListNode(0);
            ListNode *ptr = head;
            for(int i = 1; i < n; ++i){
                ptr->next = new ListNode(i);
                ptr = ptr->next;
            }
            ptr->next = head;
            ListNode *prev = ptr;
            ptr = head;

            int restChild = n;
            while(prev != ptr){
                //int curCnt = m % (restChild+1);

                for(int i = 1; i < m; ++i){
                    prev = ptr;
                    ptr = prev->next;
                }

                prev->next = ptr->next;
                delete ptr;
                ptr = prev->next;

                restChild--;
            }

            return ptr->num;
        }
  
        static void test()
        {
            Solution_45 su;
            int ans = su.LastRemaining_Solution(6, 7);
        }
    };
  
}


#endif //!_45_H_
