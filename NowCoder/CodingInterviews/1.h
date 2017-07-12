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

#ifndef _1_H_
#define _1_H_
#include <vector>
using namespace std;

namespace Chirl
{
    class Solution_1 
    {
    public:
        bool Find(vector<vector<int> > array,int target)
        {
            int m,n,x,y;
            m = array.size();
            n = array[0].size();
            x=m-1;y=0;
            while(x>=0 && y<=n-1)
            {
                if(target<array[x][y])
                {
                    x--;
                }
                else if(target>array[x][y])
                {
                    y++;
                }
                else 
                {
                    return true;
                }
            }
            return false;
        }

        static void test()
        {
            Solution_1 su;

        }
    };
}

namespace Wcytem
{
    class Solution_1
    {
    public:
        bool Find(int target, vector<vector<int> > array) {
            int row = array.size();
            int col = array[0].size();
            int i = row - 1;
            int j = 0;
            while(j < col && i >= 0)
            {
                if(target > array[i][j])
                {j++;}
                else if(target < array[i][j])
                {i--;}
                else
                    return true;
            }
            return false;
        } 


    public:
        static void test()
        {
         
            Solution_1 su;

        }          
    };



}

#endif