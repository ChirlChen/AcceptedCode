#ifndef _523_H_
#define _523_H_
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
namespace Sansan
{
    class Solution_523
    {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) 
        {
            int len=nums.size();
            int total=accumulate(nums.begin(),nums.end(),0);
            if(!len)
                return false;
            for (int i=0;i<len;i++)
            {
                if(i!=0)
                    total-=nums[i-1];
                int res=total;
                for (int j=len-1;j>=i+1;j--)
                {
                    if(!res)
                        return true;
                    if(res && k && res%k==0)
                        return true;
                    res-=nums[j];
                }
            }
            return false;
        }
        void static test()
        {
            Solution_523 tes;
            int a[]={0,0};
            vector<int>nums(a,a+sizeof(a)/sizeof(int));
            cout<<tes.checkSubarraySum(nums,-1)<<endl;
        }
    };
}
#endif