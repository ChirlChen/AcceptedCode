#ifndef _35_H_
#define _35_H_

#include <iostream>
#include <vector>

namespace NanerLee
{
class Solution_35
{
  public:
    Solution_35();
    virtual ~Solution_35();

    //  利用二分法查找第一个大于等于 target 的元素的位置
    int SearchInsert(std::vector<int>& nums, int target)
    {
        int first = 0;
        int last = nums.size();  //插入位置有可能为最大下标的下一位
        while (first < last)
        {
            int mid = (first + last) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                first = mid + 1;
            }
            else if (nums[mid] > target)
            {
                last = mid;  //有可能造成无线循环,用mid解决,参见34题
            }
        }
        return first;
    }

    static int test()
    {
        std::vector<int> nums = {1, 3, 5, 6};
        int target = 7;
        Solution_35 su;
        int index = su.SearchInsert(nums, target);

        std::cout << "the inserted index is " << index << '\n';
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _35_H_ */
