#ifndef _33_H_
#define _33_H_

#include <iostream>
#include <vector>

namespace NanerLee
{
class Solution_33
{
  public:
    Solution_33();
    virtual ~Solution_33();

    //  用二分法.一个递增序列旋转之后,[first, last] 必定先递增后递减,且last <
    //  first
    //  此时mid的位置只有两种情况,
    //  当first < mid 时, [first, mid] 必是递增的, [mid, last]
    //  必是先递减后递增的,
    //  当first > mid 时, [first, mid] 必是先递增后递减的, [mid, last]
    //  必是递增的,
    //  根据target的值来判断target在哪个区间,更新first(last) 和 mid,循环即可

    int Search(std::vector<int>& nums, int target)
    {
        int first = 0;
        int last = nums.size();
        while (first != last)
        {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else
            {
                if (nums[first] <= nums[mid])
                {
                    if (target >= nums[first] && target < nums[mid])
                    {
                        last = mid;
                    }
                    else
                    {
                        first = mid + 1;
                    }
                }
                else
                {
                    if (target > nums[mid] && target <= nums[last])
                    {
                        first = mid + 1;
                    }
                    else
                    {
                        last = mid;
                    }
                }
            }
        }
        return -1;
    }

    static int test()
    {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
        Solution_33 su;
        int result = su.Search(nums, 0);
        std::cout << "the index is " << result << '\n';
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _33_H_ */
