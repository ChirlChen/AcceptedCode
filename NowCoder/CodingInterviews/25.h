/************************************************
  FileName    : 25.h           ;
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
#ifndef _25_H_
#define _25_H_

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(nullptr), random(nullptr) {
    }
};
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_25
    {
    public:
        RandomListNode* Clone(RandomListNode* pHead) {
            if(pHead == nullptr) return nullptr;

            Copy(pHead);
            return Split(pHead);
        }

        void Copy(RandomListNode* pHead){
            RandomListNode *next = nullptr, *cur = pHead;
            while(cur != nullptr){
                next = cur->next;
                cur->next = new RandomListNode(cur->label);
                cur->next->next = next;
                cur = next;
            }

            cur = pHead;
            while(cur != nullptr){
                if(cur->random != nullptr){
                    next = cur->next;
                    next->random = cur->random->next;
                }
                cur = cur->next->next;
            }
        }

        RandomListNode* Split(RandomListNode* pHead){
            RandomListNode *newHead = pHead->next;
            RandomListNode *newNext = newHead;
            RandomListNode *next = nullptr;
            while(pHead != nullptr){
                newNext = pHead->next;
                next = newNext->next;

                newNext->next = next ? next->next : next;
                pHead->next = next;

                pHead = next;
            }

            return newHead;
        }  
  
        static void test()
        {
            RandomListNode *pHead = new RandomListNode(0);
            RandomListNode *ptr = pHead;
            for (int i = 1; i < 5; ++i)
            {
                ptr->next = new RandomListNode(i);
                ptr = ptr->next;
            }

            pHead->random = pHead->next->next->next;
            Solution_25 su;
            RandomListNode *newHead =  su.Clone(pHead);
        }
    };
  
}


#endif //!_25_H_
