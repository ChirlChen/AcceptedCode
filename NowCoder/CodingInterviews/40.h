/**
 * @Author: zugzwang
 * @Date:   2017-06-12T18:23:30+08:00
 * @Last modified by:   zugzwang
 * @Last modified time: 2017-06-12T15:21:43+08:00
 * @OS: Linux_16.04
 */
 #ifndef  _40_H
 #define _40_H
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
 #endif/*end _40_H*/
