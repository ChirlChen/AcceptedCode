/**
 * @Author: nanerlee
 * @Date:   2017-04-10T20:01:01+08:00
 * @Email:  nanerlee@qq.com
 * @Last modified by:   nanerlee
 * @Last modified time: 2017-04-10T20:18:00+08:00
 * @Copyright: Copyright (c) by NanerLee. All Rights Reserved.
 */
#ifndef _37_H_
#define _37_H_

#include <iostream>
#include <vector>

#include "36.h"

namespace NanerLee
{
class Solution_37
{
  public:
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

    //递归的方法
    bool SolveSudoKu(std::vector<std::string>& board)
    {
        for (size_t i = 0; i < 9; ++i)
        {
            for (size_t j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    for (size_t k = 0; k < 9; ++k)
                    {
                        board[i][j] = '1' + k;
                        if (IsVaildSudoku(board) && SolveSudoKu(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                    return false;  //填入哪一个数字都不能有解,说明当前的borad无解
                }
            }
        }
        return true;  //没有一个'.',即所有都填满,返回true
    }

    static int test()
    {
        std::vector<std::string> board = {"53..7....",
                                          "6..195...",
                                          ".98....6.",
                                          "8...6...3",
                                          "4..8.3..1",
                                          "7...2...6",
                                          ".6....28.",
                                          "...419..5",
                                          "....8..79"};
        Solution_37 su;
        bool        flag = su.SolveSudoKu(board);
        if (flag)
        {
            for (auto& item : board)
            {
                std::cout << item << '\n';
            }
        }
        else
        {
            std::cout << "no solution" << '\n';
        }
        return 0;
    }
};
} /* NanerLee */

#endif /* end of include guard: _37_H_ */
