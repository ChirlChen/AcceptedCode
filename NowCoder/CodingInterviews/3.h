/**************************************************
	Description :
	Editor	  	: Chirl
	EditDate	  : 2017/02/27
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

#ifndef _3_H_
#define _3_H_

#include <vector>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
namespace Chirl
{
    class Solution_3 {
    public:
        vector<int> printListFromTailToHead(ListNode* head) 
        {
            if (head == NULL)
            {
                return vector<int>();
            }
            ListNode *preNode = NULL;
            ListNode *nxtNode = head->next;
            int       listLen = 0;

            do
            {
                head->next = preNode;

                preNode    = head;
                head       = nxtNode;
                if (nxtNode != NULL)
                {
                    nxtNode    = head->next;    
                }
                listLen++;
            } while (head != NULL);
            head = preNode;

            vector<int> inversedListValue;
            inversedListValue.reserve(listLen);

            preNode = head;
            while (preNode != NULL) 
            {
                inversedListValue.push_back(preNode->val);
                preNode = preNode->next;
            }

            return inversedListValue;
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

        static void test() 
        {
            ListNode *tmp = NULL;
          
            ListNode *l2 = new ListNode(1);
            tmp = l2;
            tmp = insertNode(tmp, 2);
            tmp = insertNode(tmp, 3);
            tmp = insertNode(tmp, 4);
            tmp = insertNode(tmp, 5);
            tmp = insertNode(tmp, 6);
            tmp = insertNode(tmp, 7);
            tmp = insertNode(tmp, 8);
      
            Solution_3 su;
            vector<int> result = su.printListFromTailToHead(l2);
        }

    };

}

#endif