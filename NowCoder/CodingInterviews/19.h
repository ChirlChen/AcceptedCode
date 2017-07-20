/************************************************
  FileName    : 19.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/20                      ;
              _                                 ;
             /  \         吉                    ;     
            /|oo \         祥                   ;    
           (_|  /_)       物                    ;   
             `@/  \   _    镇                   ;    
             |     \  \\  楼                    ;   
              \||   \  ))  !!                   ;    
              |||\ / \//                        ; 
            _//|| _\  /                         ;
    ______(_/(_|(____/_________                 ;
*************************************************/
#ifndef _19_H_
#define _19_H_
#include <vector>
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：
     ************************************************************************/
    class Solution_19
    {
    public:
        vector<int> printMatrix(vector<vector<int> > matrix) {
            if(matrix.empty()) return vector<int>();

            int row = matrix.size(), col = matrix[0].size();
            vector<int> out; 
            out.reserve(row*col);

            DoPrintMat(matrix, 0, 0, out);
            return out;
        }

        void DoPrintMat(vector<vector<int> > &mat, int row, int col, vector<int> &res){
            int r = mat.size(), c = mat[0].size();

            if(row * 2 >= r || col * 2 >= c) return;

            for(int i = col; i < c - col; ++i)
                res.push_back(mat[row][i]);
            for(int i = row+1; i < r-row; ++i)
                res.push_back(mat[i][c-col-1]);
            for(int i = c-col-2; i > col && r-row-1 > row; --i)
                res.push_back(mat[r-row-1][i]);
            for(int i = r-row-1; i > row && col < c-col-1; --i)
                res.push_back(mat[i][col]);

            DoPrintMat(mat, row+1, col+1, res);

        }
  
        static void test()
        {
            Solution_19 su;
            su.printMatrix(vector<vector<int>>());
        }
    };
  
}


#endif //!_19_H_
