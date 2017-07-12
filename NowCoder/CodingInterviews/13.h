/**************************************************
  Description :
  Editor      : Wcyetm
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
#ifndef _13_H_
#define _13_H_
#include <vector>
#pragma execution_character_set("utf-8")

namespace Wcytem
{
    class Solution_13
    {
    public:
        void reOrderArray(vector<int> &array) {
            vector<int> oddArray;
            vector<int> evenArray;
            int len = array.size();
            for(int i = 0; i < len; i++)
            {
                if(array[i] % 2 == 1)
                    oddArray.push_back(array[i]);
                else
                    evenArray.push_back(array[i]);
            }
            oddArray.insert(oddArray.end(),evenArray.begin(),evenArray.end());
            array = oddArray;
        }

        static void test()
        {
            Solution_13 su;
            vector<int> arr;
            arr.push_back(1);
            su.reOrderArray(arr);
        }         
    };



}


#endif //!_13_H_