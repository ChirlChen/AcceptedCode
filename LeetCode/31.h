#ifndef _31_H_
#define _31_H_

#include <algorithm>
#include <iostream>
#include <vector>

namespace NanerLee
{
    class Solution_31
    {
    public:
        Solution_31();
        virtual ~Solution_31();

        /**
        * [NextPermutation description]
        * 要找到下一个较大的排序,首先从后往前找到第一个不是递增的数,然后再找到第一个大于它的数,交换位置即可
        * 因为从后往前的序列中,如果是递增,则这递增的部分不能继续变大了,只能找不满足的递增的,
        * 找到之后肯定将其和后面的比它大的数交换,才能使序列变大,要使变大程度最小,只能将其和后面大的数中最小的数进行交换,
        * 由于高位变大,后边的序列无论怎样怎样都比原来的大,所以将后面的序列排序一下.
        * @method NextPermutation
        * @param  nums            [输入的序列]
        */
        void NextPermutation(std::vector<int>& nums)
        {
            if (nums.size() == 0 || nums.size() == 1)
            {
                return;
            }
            int i = -1;
            int j = -1;

            //从后向前搜索第一个不是递增的数,k的范围为[nums.size() - 1, 0)
            for (int k = nums.size() - 1; k > 0; --k)
            {
                //搜索到时
                if (nums[k] > nums[k - 1])
                {
                    i = k - 1;  //第一个不是递增的元素标号
                    //在此元素后搜索最后一个比它大的数(因为后边是有序数列,所以是比它大的数中最小的)
                    //搜索范围为[i + 1, nums.size()]
                    for (size_t l = k; l < nums.size(); ++l)
                    {
                        if (nums[l] > nums[i])
                        {
                            j = l;
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                }
            }

            if (i != -1 && j != -1)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                std::sort(nums.begin() + i + 1, nums.end());
            }
            else
            {
                std::sort(nums.begin(), nums.end());
            }
        }

        static int test()
        {
            std::vector<int> nums = {1, 2};
            Solution_31 su;
            su.NextPermutation(nums);
            for (auto& item : nums)
            {
                std::cout << item << '\n';
            }
            return 0;
        }
    };

} /* NanerLee */

#endif /* end of include guard: _31_H_ */
