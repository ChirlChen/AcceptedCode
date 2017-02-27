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
#ifndef _5_H_
#define _5_H_

#pragma execution_character_set("utf-8")
#include <stack>
using namespace std;

namespace Chirl
{
	class Solution_5
    {
    public:
        void push(int node) {
            stack1.push(node);
        }

        int pop() {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            int headNode = stack2.top();        
            stack2.pop();

            return headNode;
        }
        
        static void test()
        {
            Solution_5 su;
            su.push(20);
            su.push(21);
            su.push(22);
            su.pop();
            su.pop();
            su.pop();
            su.pop();
                
        }

    private:
        stack<int> stack1;
        stack<int> stack2;
    };
	
}


#endif //!_5_H_