#ifndef _494_H_
#define _494_H_
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
namespace Sansan
{
    class Solution_494
    {
    public:
        /*
          sum(P)-sum(N)=target;
          2*sum(p)=target+sum(nums);
          问题求解归结为在nums中找到子数组subArray的和为(target+sum(nums))/2;
        */
        int subArraySum(vector<int>& nums,int sum)
        {
            int* dp=new int[sum+1]();
            dp[0]=1;
            int len=nums.size();
            for (int i=0;i<len;i++)
            {
                for (int s=sum;s>=nums[i];s--)
                    dp[s]+=dp[s-nums[i]];
            }
            return dp[sum];
        }
        int findTargetSumWays(vector<int>& nums, int S)
        {
           int total=accumulate(nums.begin(),nums.end(),0);
           return (total<S || (total+S)%2!=0)?0:subArraySum(nums,(total+S)/2);
        }
        void static test()
        {
            Solution_494 tes;
            int a[]={1,1,1,1,1};
            vector<int>nums(a,a+sizeof(a)/sizeof(int));
            cout<<tes.findTargetSumWays(nums,3)<<endl;
        }
    };
}
#endif