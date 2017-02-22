#ifndef _2_H_
#define _2_H_

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

namespace Chirl
{
    class Solution_2 
    {  
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            if (nullptr == l1 || nullptr == l2)
            {
                return nullptr ==l1 ? l2  : l1;
            }

            int carryBit = 0; //Ðè½øÎ»µÄÖµ;;;
            ListNode *result  = new ListNode(0);
            ListNode *preNode = result; 
            while ((l1 != nullptr && l2 != nullptr) || carryBit == 1)
            {
                int sum = (l1!=nullptr ? l1->val : 0) +
                    (l2!=nullptr ? l2->val : 0) + carryBit;
                carryBit = sum / 10;

                preNode->next = new ListNode(sum % 10);
                preNode = preNode->next;
                l1 = l1!=nullptr ? l1->next : nullptr;
                l2 = l2!=nullptr ? l2->next : nullptr;
            }
            preNode->next = l1 != nullptr ? l1 : l2;

            preNode = result;
            result = result->next;
            delete preNode;
            return result;
        }


        static ListNode *insertNode(ListNode *preNode, int val)
        {
            if (preNode != nullptr)
            {
                preNode->next = new ListNode(val);
                preNode = preNode->next;
            }
            return preNode;    
        } 

        static int test() 
        {
            ListNode *l1 = new ListNode(2);
            ListNode *tmp = l1;
            tmp = insertNode(tmp, 4);
            tmp = insertNode(tmp, 3);

            ListNode *l2 = new ListNode(5);
            tmp = l2;
            tmp = insertNode(tmp, 6);
            tmp = insertNode(tmp, 6);
            tmp = insertNode(tmp, 9);
            tmp = insertNode(tmp, 8);
            tmp = insertNode(tmp, 8);
            tmp = insertNode(tmp, 8);
            tmp = insertNode(tmp, 3);

            Solution_2 su;
            ListNode *result = su.addTwoNumbers(l1, l2);   
            return 0;
        }
    };
}//namespace Chirl


#endif
