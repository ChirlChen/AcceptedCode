#ifndef _30_H_
#define _30_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace NanerLee
{
class Solution_30
{
  public:
    Solution_30();
    virtual ~Solution_30();
    //假设s的长度为m,words的大小为n,时间复杂度为O(m*n)
    std::vector<int> FindSubstring(std::string s, std::vector<std::string>& words)
    {
        int word_length = words[0].length();  //每一个单词的长度
        int substr_length = words.size() * word_length;  //符合要求的子字符串的长度
        std::vector<int> result;  //储存每一个符合规则字符串的开始标号

        if (s.length() < word_length)
        {
            return result;
        }

        //统计words中每一个word出现的次数,用unordered_map,不用排序,减少时间消耗,时间复杂度O(n)
        std::unordered_map<std::string, int> word_count;
        for (auto& word : words)
        {
            ++word_count[word];
        }

        // 判断每一个子字符串是否符合要求,每一个子串的范围为[i, i +
        // substr_length),
        // i的范围是[0, s.length() - substr_length + 1),
        for (size_t i = 0; i < s.length() - substr_length + 1; ++i)
        {
            std::unordered_map<std::string, int> temp_map;  //记录从i开始的每一个子串中word出现的次数
            // [i, i + substr_length)
            // 中每一个temp_word都是word,且次数不超,则此子串必满足要求,循环次数为words.size()
            size_t j = i;
            for (; j < i + substr_length; j = j + word_length)
            {
                std::string temp_word = s.substr(j, word_length);

                // temp_word 是一个 word 时
                if (word_count.find(temp_word) != word_count.end())
                {
                    ++temp_map[temp_word];  //出现次数加一

                    //如果出现次数过多,跳出
                    if (temp_map[temp_word] > word_count[temp_word])
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            //全部循环都执行成功时
            if (j == i + substr_length)
            {
                result.push_back(i);
            }
        }
        return result;
    }

    static int test()
    {
        std::string s = "barfoothefoobarman";
        std::vector<std::string> words = {"foo", "bar"};
        Solution_30 su;
        std::vector<int> result = su.FindSubstring(s, words);
        for (auto& item : result)
        {
            std::cout << item << '\n';
        }
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _30_H_ */
