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


#endif //!_15_H_