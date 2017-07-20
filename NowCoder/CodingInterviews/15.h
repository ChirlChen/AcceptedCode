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
#ifndef _15_H_
#define _15_H_
#include <iostream>
#include <stack>
using namespace std;
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
    class Solution_15
    {
    public:
        ListNode* ReverseList(ListNode* pHead) {
            ListNode* ret = NULL;
            ListNode* travel = pHead;
            stack<int> valOfList;
            while(travel)
            {
                valOfList.push(travel->val);
                travel = travel->next;
            }
            if(!valOfList.empty())
            {
                ret = new ListNode(valOfList.top());
                valOfList.pop();
            }
            ListNode* temp = NULL;
            travel = ret;
            while(!valOfList.empty())
            {
                temp = new ListNode(valOfList.top());           
                valOfList.pop();
                travel->next = temp;
                travel = travel->next;
            }
            return ret;
        }

        static void test()
        {
            Solution_15 su;
            su.ReverseList(NULL);
        }         
    };



}

namespace Chirl
{
    class Solution_15
    {
    public:
        ListNode* ReverseList(ListNode* pHead) {
            if(pHead == NULL || pHead->next == NULL) return pHead;

            ListNode *prev = NULL, *cur = pHead, *next = pHead->next;

            while(next != NULL){
                cur->next = prev;
                prev = cur;
                cur = next;
                next = cur->next;
            }

            cur->next = prev;
            return cur;
        }
  
        static void test()
        {
            Solution_15 su;
            int arr[5] = {5, 4, 3, 2, 1};
            ListNode *pHead = new ListNode(arr[0]);
            ListNode *curPtr = pHead;
            for (int i = 1; i < 5; ++i)
            {
                curPtr->next = new struct ListNode(arr[i]);
                curPtr = curPtr->next;
            }
            curPtr = su.ReverseList(pHead);
        }        
    };
  
}

#endif //!_15_H_