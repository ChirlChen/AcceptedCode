#ifndef _525_H_
#define _525_H_
#include <iostream>
#include <vector>
using namespace std;
namespace Sansan
{
class Solution_525
{
  public:
    int findMaxLength(vector<int>& nums)
    {
        int maxLen = 0, sum = 0, size = nums.size();
        int* p = new int[2 * size + 1]();
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] ? 1 : -1;
            if (sum + size == size)
                maxLen = i + 1;
            else if (p[sum + size] == 0)
                p[sum + size] = i + 1;
            else
                maxLen = max(maxLen, i - p[sum + size] + 1);
        }
        return maxLen;
    }
    void static test()
    {
        Solution_525 tes;
        int a[] = {0, 0, 1};
        vector<int> nums(a, a + sizeof(a) / sizeof(int));
        cout << tes.findMaxLength(nums) << endl;
    }
};
}
#endif
