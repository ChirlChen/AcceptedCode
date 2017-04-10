/**
 * @Author: nanerlee
 * @Date:   2017-04-10T20:01:12+08:00
 * @Email:  nanerlee@qq.com
 * @Last modified by:   nanerlee
 * @Last modified time: 2017-04-10T20:13:05+08:00
 * @Copyright: Copyright (c) by NanerLee. All Rights Reserved.
 */

#ifndef _38_H_
#define _38_H_

#include <iostream>
#include <string>

namespace NanerLee
{
class Solution_38
{
  public:
    Solution_38();
    virtual ~Solution_38();

    /**
     * 统计 string s 在 [pos, end) 中连续且与 s[pos]相同的元素的个数
     * @method Count
     * @param  pos   开始的位置
     * @param  s     输入的字符串
     * @return       个数
     */
    int Count(size_t pos, std::string& s)
    {
        int count = 0;
        for (size_t i = pos; i < s.size(); ++i)
        {
            if (s[i] != s[pos])
            {
                return count;
            }

            ++count;
        }

        return count;
    }

    /**
     * 根据输入的 string 生成下一个 count and say string
     * @method Say
     * @param  s   输入
     * @return     输出
     */
    std::string Say(std::string& s)
    {
        std::string next;
        for (size_t i = 0; i < s.size();)
        {
            //  num 个 c
            char c   = s[i];
            int  num = Count(i, s);
            next.push_back('0' + num);
            next.push_back(c);
            //更新i
            i += num;
        }
        return next;
    }

    std::string CountAndSay(int n)
    {
        std::string s = "1";
        for (size_t i = 1; i < n; ++i)
        {
            s = Say(s);
        }
        return s;
    }

    static int test()
    {
        int n;
        std::cout << "input n: " << '\n';
        std::cin >> n;
        Solution_38 su;
        std::string result = su.CountAndSay(n);
        std::cout << result << '\n';
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _38_H_ */
