/**************************************************
  Description :
  Editor      : Chirl
  EditDate    : 2017/02/27
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
namespace Wcytem
{
    class Solution_6
    {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            int len = rotateArray.size();
            if (len == 0)
                return 0;
            else
            {
                int first = 0;
                int last = len-1;
                int mid = len/2;
                while(rotateArray[mid]!=rotateArray[last] || rotateArray[mid] != rotateArray[first])
                {
                    if(rotateArray[mid] <= rotateArray[last] )
                    {
                        last = mid;
                        if ((last + first)%2 == 0)
                        {
                            mid = (last + first)/2;
                        }
                        else
                            mid = (last + first)/2-1;
                    }
                    if(rotateArray[mid] >= rotateArray[first])
                    {
                        first = mid;
                        if ((last + first)%2 == 0)
                        {
                            mid = (last + first)/2;
                        }
                        else
                            mid = (last + first)/2+1;
                    }
                    if (last - first <=2)
                    {
                        int minVal = rotateArray[first];
                        for (int i = first+1; i <= last; i++)
                        {
                            if (minVal > rotateArray[i])
                            {
                                minVal = rotateArray[i];
                            }
                        }
                        return minVal;
                    }
                }
                return rotateArray[mid];
            }
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