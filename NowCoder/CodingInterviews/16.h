/**************************************************
  Description :
  Editor      : Wcytem
  EditDate    : 2017/04/14
              _ 
             /  \               
            /|oo \              
           (_|  /_)             
             `@/  \    _        
             |     \   \\       
              \||   \   ))      
              |||\ /  \//       
            _//|| _\   /          
     ______(_/(_|(____/_________ 
**************************************************/
#ifndef _16_H_
#define _16_H_
#include <iostream>
#pragma execution_character_set("utf-8")
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

namespace Wcytem
{
    class Solution_16
    {
    public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
            ListNode* bigNext = NULL;
            ListNode* smallNext = NULL;
            ListNode* ret = NULL;
            if(pHead1 == NULL && pHead2 == NULL )
                return ret;
            if(pHead1 == NULL && pHead2 != NULL)
                return pHead2;
            if(pHead1 != NULL && pHead2 == NULL)
                return pHead1;
            if(pHead1->val < pHead2->val)
            {
                ret = pHead1;
                bigNext = pHead2;
                smallNext = pHead1->next;
                ret->next = Merge(bigNext, smallNext);
            }
            else
            {
                ret = pHead2;
                bigNext = pHead1;
                smallNext = pHead2->next;
                ret->next = Merge(bigNext, smallNext);
            }
            return ret;
        }

        static void test()
        {
            Solution_16 su;
            su.Merge(NULL,NULL);
        }         
    };



}

namespace Chirl
{
    class Solution_16
    {
    public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
            if(pHead1 == NULL || pHead2 == NULL) 
                return pHead1 ? pHead1 : pHead2;

            ListNode *ptr1 = pHead1, *ptr2 = pHead2;
            ListNode *newHead = new ListNode(0), *ptrNew = newHead;
            while(ptr1 != NULL && ptr2 != NULL){
                if(ptr1->val < ptr2->val){
                    ptrNew->next = ptr1;
                    ptr1 = ptr1->next;
                }
                else{
                    ptrNew->next = ptr2;
                    ptr2 = ptr2->next;
                }
                ptrNew = ptrNew->next;
            }
            ptrNew->next = ptr1 ? ptr1 : ptr2;

            ptrNew = newHead;
            newHead = ptrNew->next;
            delete ptrNew;

            return newHead;
        }
  
        static void test()
        {
            Solution_16 su;
            su.Merge(NULL,NULL);
        }    
    };
  
}
#endif //!_14_H_