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
#ifndef _6_H_
#define _6_H_

#pragma execution_character_set("utf-8")
#include <vector>
using namespace std;
namespace Chirl
{
	class Solution_6
    {
	public:
        int minNumberInRotateArray(vector<int> rotateArray) 
        {
            if (rotateArray.empty()) 
            {
                return 0;
            }

            int arrLen = rotateArray.size() - 1;
            for (int i = 0; i < arrLen; ++i) 
            {
                if (rotateArray[i] > rotateArray[i+1]) 
                {
                    return rotateArray[i+1];
                }
            }
            return rotateArray[0];
        }

        static void test()
        {
            int tmp[] = {3,4,5,1,2};
			vector<int> rotateArray(tmp, tmp+sizeof(tmp)/sizeof(int));

            Solution_6 su;
			su.minNumberInRotateArray(rotateArray);
        }
    };
	
}


#endif //!_6_H_