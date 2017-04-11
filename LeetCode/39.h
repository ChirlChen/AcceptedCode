/**
 * @Author: nanerlee
 * @Date:   2017-04-10T20:01:19+08:00
 * @Email:  nanerlee@qq.com
 * @Last modified by:   nanerlee
 * @Last modified time: 2017-04-10T20:15:05+08:00
 * @Copyright: Copyright (c) by NanerLee. All Rights Reserved.
 */

#ifndef _39_H_
#define _39_H_

#include <algorithm>
#include <iostream>
#include <vector>

namespace NanerLee
{
class Solution_39
{
  public:
    Solution_39();
    virtual ~Solution_39();

    /**
     * 深度优先遍历检查结果
     * @method DFS
     * @param  begin       候选元素开始处
     * @param  end         候选元素结束处
     * @param  target      目标值
     * @param  combination 之前的组合
     * @param  result      存放最终的结果
     */
    void DFS(std::vector<int>::iterator     begin,
             std::vector<int>::iterator     end,
             int                            target,
             std::vector<int>               combination,
             std::vector<std::vector<int>>& result)
    {
        if (target == 0)  //和已经相等
        {
            result.push_back(combination);
            return;
        }

        if (begin == end)  //没有元素小于等于target
        {
            return;
        }

        //在候选的元素范围内遍历
        for (auto iter = begin; iter != end; ++iter)
        {
            combination.push_back(*iter);
            //注意这里缩小了候选范围
            DFS(iter, std::upper_bound(iter, end, target - *iter), target - *iter, combination, result);
            combination.erase(combination.end() - 1);
        }
        return;
    }

    std::vector<std::vector<int>> CombinationSum(std::vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> combination;
        DFS(candidates.begin(),
            std::upper_bound(candidates.begin(), candidates.end(), target),
            target,
            combination,
            result);
        return result;
    }

    static int test()
    {
        std::vector<int> candidates = {2, 3, 6, 7};
        int              target;
        std::cout << "input target: " << '\n';
        std::cin >> target;

        Solution_39 su;
        auto        result = su.CombinationSum(candidates, target);
        for (auto& item : result)
        {
            for (auto& var : item)
            {
                std::cout << " " << var;
            }
            std::cout << '\n';
        }
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _39_H_ */
