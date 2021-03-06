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
using namespace std;
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


namespace Chirl
{
    class Solution_13
    {
    public:
        void reOrderArray(vector<int> &array) {
            int oddIdx = 0, evenIdx = 0;

            for(int i = 0; i < array.size(); ++i){
                if(array[i] & 0x1) {
                    int tmp = array[i];
                    for(int j = oddIdx; j > evenIdx; --j) {
                        array[j] = array[j-1];
                    }
                    array[evenIdx] = tmp;
                    evenIdx++; oddIdx++;
                }
                else
                    oddIdx++;
            }
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
}


#endif //!_13_H_