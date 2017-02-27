#ifndef _32_H_
#define _32_H_

#include <iostream>
#include <stack>

namespace NanerLee
{
class Solution_32
{
  public:
    Solution_32();
    virtual ~Solution_32();

    //  最长的符合要求的字符串一定是从开头或者一个没有被匹配到的括号(左或者右)开始,
    //  用last来记录最后一个没被匹配的右括号,左括号的栈顶一定是当前的没被匹配到的左括号
    //  栈中的两个左括号之间的字符串必时配对过的括号
    //  当一个右括号匹配到一个左括号时,将左括号出栈后,
    //  如果栈为空,此时有效的字符串长度为 i - last
    //  如果不为空,此时有效的字符串长度为 i - begin.top()
    int LongestVaildParentheses(std::string s)
    {
        std::stack<int> begin;  //储存左括号的位置
        int last = -1;  //记录最后一个没被匹配的右括号的位置
        int max_len = 0;
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')  //把找到的左括号入站
            {
                begin.push(i);
            }
            else if (s[i] == ')')
            {
                if (begin.empty())  //右括号没被匹配,更新最后一个没被匹配的右括号位置
                {
                    last = i;
                }
                else  //右括号被匹配
                {
                    int temp_len = 0;
                    begin.pop();  //左括号出栈
                    if (begin.empty())
                    {
                        temp_len = i - last;
                    }
                    else
                    {
                        temp_len = i - begin.top();
                    }
                    max_len = max_len < temp_len ? temp_len : max_len;
                }
            }
        }
        return max_len;
    }

    static int test()
    {
        std::string s = "(()()(()())";
        Solution_32 su;
        int result = su.LongestVaildParentheses(s);
        std::cout << "the largest length is " << result << '\n';
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _32_H_ */
