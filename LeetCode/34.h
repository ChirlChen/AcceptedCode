#ifndef _34_H_
#define _34_H_

#include <iostream>
#include <vector>

namespace NanerLee
{
class Solution_34
{
  public:
    Solution_34();
    virtual ~Solution_34();

    //  由于已经排好序了,利用二分法搜索出第一个和最后一个的目标值
    std::vector<int> SearchRange(std::vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return {-1, -1};
        }
        std::vector<int> result;

        int first = 0;
        int last = nums.size() - 1;
        while (first < last)
        {
            int mid = (first + last) /
                      2;  // mid取值为靠近first一边,防止last更新后值不变
            if (nums[mid] < target)
            {
                first = mid + 1;
            }
            else if (nums[mid] > target)
            {
                last = mid - 1;
            }
            else
            {
                last = mid;  //有可能会造成无限循环,用mid的取值偏向来解决
            }
        }

        //检测是否有目标值存在
        if (nums[first] == target)
        {
            result.push_back(first);
        }
        else
        {
            return {-1, -1};
        }

        //不需要将first设为初始值
        last = nums.size() - 1;
        while (first < last)
        {
            int mid = (first + last) / 2 +
                      1;  // mid取值靠近last一边,防止first更新后值不变
            if (nums[mid] < target)
            {
                first = mid + 1;
            }
            else if (nums[mid] > target)
            {
                last = mid - 1;
            }
            else
            {
                first = mid;  //有可能会造成无限循环,用mid的取值偏向来解决
            }
        }
        //这里不用检测目标值
        result.push_back(first);

        return result;
    }

    static int test()
    {
        std::vector<int> nums = {5, 7, 7, 8, 8, 10};
        Solution_34 su;
        std::vector<int> result = su.SearchRange(nums, 8);
        std::cout << result[0] << "---" << result[1] << '\n';
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _34_H_ */
