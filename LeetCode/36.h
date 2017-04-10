#ifndef _36_H_
#define _36_H_

#include <iostream>
#include <vector>

namespace NanerLee
{
class Solution_36
{
  public:
    Solution_36();
    virtual ~Solution_36();

    //  一个有效的数独不一定有解,只要被填充的数字满足不重复的条件即可
    bool IsVaildSudoku(std::vector<std::string>& board)
    {
        //  第i行的9个元素为 board 中第i行中 1 - 9 是否用过
        bool row_flag[9][9] = {false};
        //  第i行的9个元素为 board 中第i列中 1 - 9 是否用过
        bool column_flag[9][9] = {false};
        //  第i行的9个元素为 board 中第i个小方块区域中 1 - 9 是否用过
        bool area_flag[9][9] = {false};

        //  注意下标的开始是0
        for (size_t i = 0; i < 9; ++i)
        {
            for (size_t j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';

                    //  num 是否在其所在行, 列, 区域中出现过
                    bool& flag1 = row_flag[i][num - 1];
                    bool& flag2 = column_flag[j][num - 1];
                    bool& flag3 = area_flag[(i / 3) * 3 + j / 3][num - 1];

                    if (flag1 || flag2 || flag3)
                    {
                        return false;
                    }

                    flag1 = true;
                    flag2 = true;
                    flag3 = true;
                }
            }
        }

        return true;
    }

    static int test()
    {
        std::vector<std::string> board = {"..4...63.",
                                          ".........",
                                          "5......9.",
                                          "...56....",
                                          "4.3.....1",
                                          "...7.....",
                                          "...5.....",
                                          ".........",
                                          "........."};
        Solution_36 su;
        bool result = su.IsVaildSudoku(board);
        std::cout << result << '\n';
        return 0;
    };
};
} /* NanerLee */

#endif /* end of include guard: _36_H_ */
