/**************************************************
	Description :
	Creator	  	: Chirl
	EditDate	: 2017/02/27
				_	
	           /  \               
	          /|oo \              
	         (_|  /_)             
	           `@/  \    _        
	           |     \   \\       
	            \||   \   ))      
	            |||\ /  \//       
	          _//|| _\   /          
     _______(_/(_|(____/_________ 
**************************************************/
#ifndef _9_H_
#define _9_H_

#pragma execution_character_set("utf-8")

namespace Chirl
{
	class Solution_9
    {
	public:
        Solution_9() : m_iJumpCnt(nullptr){}


        int jumpFloorII(int number) 
        {
            if (nullptr == m_iJumpCnt) 
            {
                m_iJumpCnt = new int[number+1];
                for (int i = 0; i <= number; i++) 
                {
                    m_iJumpCnt[i] = 0;
                }
            }

            if (number <= 1) 
            {
                m_iJumpCnt[number] = number;
                return number;
            }

            if (0 == m_iJumpCnt[number]) 
            {
                m_iJumpCnt[number] = 2*jumpFloorII(number-1);
            }

            return m_iJumpCnt[number];
        }


        static void test()
        {
            Solution_9 su;
            su.jumpFloorII(20);
        }

    private:
        int *m_iJumpCnt;

        
    };
	
}


#endif //!_9_H_