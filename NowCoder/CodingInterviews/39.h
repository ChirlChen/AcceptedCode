/**
 * @Author: zugzwang
 * @Date:   2017-06-12T18:23:30+08:00
 * @Last modified by:   zugzwang、Chirl
 * @Last modified time: 2017-08-1T15:21:43+08:00
 * @OS: Linux_16.04
 */
#ifndef _39_H_
#define _39_H_

#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <map>
 using namespace std;
namespace Sansan
{
    /*
    解题思路:1、所有的数字异或得到两个只出现一次的数的异或值
            2、根据异或值的二进制表示的最后一个1把数组分成两组，两组各自异或得到最后的值
    */
    class Solution_40
    {
    public:
        void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
        {
            int xorVal = 0;
            vector<int>xor1;
            vector<int>xor0;
            for(int i = 0; i < data.size(); i++)
                xorVal ^= data[i];
            int lastBit = (xorVal&(xorVal-1))^xorVal;
            for(int i = 0; i < data.size(); i++)
            {
                switch ( lastBit & data[i])
                {
                case 0:
                    xor0.push_back(data[i]);
                    break;
                default:
                    xor1.push_back(data[i]);
                    break;
                }
            }
            int val=0;
            for(int i = 0 ; i < xor0.size() ; i++)
                val ^= xor0[i];
            *num1 = val;val=0;
            for(int i = 0 ; i < xor1.size() ; i++)
                val ^= xor1[i];
            *num2 = val;
        }
        void static test()
        {
            Solution_40 solve;
            int* num0 = new int[2];
            vector<int> num={2,4,3,6,3,2,5,5};
            solve.FindNumsAppearOnce(num,num0,num0+1);
            cout<< num0[0] <<" "<<num0[1]<<endl;
        }
    };
}
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_39
    {
    public:
        void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
            if(data.size() <= 1) return;

            int res = SingleNum(data);
            res = res & (res-1) ^ res;

            vector<int> left, right;
            left.reserve(data.size());
            right.reserve(data.size());

            for(int i = 0; i < data.size(); ++i){
                if(data[i] & res){
                    left.push_back(data[i]);
                }
                else{
                    right.push_back(data[i]);
                }
            }

            num1 = num1 == nullptr ? new int : num1;
            num2 = num2 == nullptr ? new int : num2;
            *num1 = SingleNum(left);
            *num2 = SingleNum(right);

            return;
        }

        int SingleNum(const vector<int> &data){
            int ans = 0;
            for(int i = 0; i < data.size(); ++i){
                ans ^= data[i];
            }

            return ans;
        }
  
        static void test()
        {
            int tmp[] = {1,2,3,7,6,4,1,2,3,4,5};
            Solution_39 su;
            int num1 = 0, num2 = 0;
            su.FindNumsAppearOnce(vector<int>(begin(tmp), end(tmp)), &num1, &num2);
        }
    };
  
}


#endif //!_39_H_
