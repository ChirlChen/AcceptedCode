/**
 * @Author: nanerlee
 * @Date:   2017-04-10T20:01:26+08:00
 * @Email:  nanerlee@qq.com
 * @Last modified by:   nanerlee
 * @Last modified time: 2017-04-10T20:17:07+08:00
 * @Copyright: Copyright (c) by NanerLee. All Rights Reserved.
 */

#ifndef _40_H_
#define _40_H_

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

namespace NanerLee
{
class Solution_40
{
  public:
    Solution_40();
    virtual ~Solution_40();
    //相比 39 题,用set保存最后结果,递归时的范围不同

    /**
     * 深度优先遍历检查结果
     * @method DFS
     * @param  begin       候选元素开始处
     * @param  end         候选元素结束处
     * @param  target      目标值
     * @param  combination 之前的组合
     * @param  result      存放最终的结果
     */
    void DFS(std::vector<int>::iterator  begin,
             std::vector<int>::iterator  end,
             int                         target,
             std::vector<int>            combination,
             std::set<std::vector<int>>& result)
    {
        if (target == 0)  //和已经相等
        {
            result.insert(combination);
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
            DFS(iter + 1, std::upper_bound(iter + 1, end, target - *iter), target - *iter, combination, result);
            combination.erase(combination.end() - 1);
        }
        return;
    }

    std::vector<std::vector<int>> CombinationSum(std::vector<int>& candidates, int target)
    {
        std::set<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> combination;
        DFS(candidates.begin(),
            std::upper_bound(candidates.begin(), candidates.end(), target),
            target,
            combination,
            result);
        std::vector<std::vector<int>> real_result(result.begin(), result.end());
        return real_result;
    }

    static int test()
    {
        std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
        int              target;
        std::cout << "input target: " << '\n';
        std::cin >> target;

        Solution_40 su;
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

#endif /* end of include guard: _40_H_ */
