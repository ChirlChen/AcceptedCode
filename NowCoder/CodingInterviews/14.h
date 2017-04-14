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
#ifndef _14_H_
#define _14_H_

#pragma execution_character_set("utf-8")
#include <iostream>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

namespace Wcytem
{
    class Solution_14
    {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            ListNode* travel = pListHead;
            unsigned int lengthOfPoint = 0;
            while(travel)
            {
                lengthOfPoint++;
                travel = travel->next;
            }
            ListNode* ret = NULL;
            if(k > lengthOfPoint || k == 0)
                return ret;
            else
            {
                travel = pListHead;
                for(unsigned int i = 0; i <= (lengthOfPoint - k); i++)
                {
                    ret = travel;
                    travel = travel->next;
                }
                return ret;
            }
        }

        static void test()
        {
            Solution_14 su;
            ListNode *p = new ListNode(3);
            su.FindKthToTail(p,1);
        }         
    };



}


#endif //!_14_H_