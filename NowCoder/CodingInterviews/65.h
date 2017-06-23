#ifndef _65_H__
#define _65_H__
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
namespace Sansan
{
	class Solution_65 
	{
	public:
		void toCoordinate(int strPos, int& rowth, int& colth,int cols)
		{
	       rowth = strPos/cols;
		   colth = strPos%cols;
		}
		bool dfs(char* matrix,vector<vector<int> >& visited, char* str, int pos0,int srLen,int row,int col,int rows,int cols)
		{
			if(pos0 == srLen)
				return true;
			if(col < 0 || col >= cols || row < 0 || row >= rows || visited[row][col] || matrix[col + cols*row] != str[pos0])
				return false;
			visited[row][col] = 1;
			if(dfs(matrix,visited,str,pos0+1,srLen,row,col-1,rows,cols) || dfs(matrix,visited,str,pos0+1,srLen,row,col+1,rows,cols) ||dfs(matrix,visited,str,pos0+1,srLen,row-1,col,rows,cols)||dfs(matrix,visited,str,pos0+1,srLen,row+1,col,rows,cols))
				return true;
			visited[row][col] = 0;
			return false;
		}
		bool hasPath(char* matrix, int rows, int cols, char* str)
		{
			vector<vector<int>> visited(rows,vector<int>(cols,0));//0表示为访问过，1表示访问过
			//找到起始搜索点
			if(!str)
				return true;
			if(!matrix || strlen(matrix) != rows*cols)
				return false;
			vector<int>iniPos;
			for (int i = 0; i <= strlen(matrix) ; i++)
			{
				if (*str == matrix[i])
				  iniPos.push_back(i);
			}
			for (int i= 0 ;i < iniPos.size();i++)
			{
				int rowth,colth;
				toCoordinate(iniPos[i],rowth,colth,cols);
				if(dfs(matrix,visited,str,0,strlen(str),rowth,colth,rows,cols))
					return true;
			}
			return false;
		}
		static void test()
		{
			char* matrix = "abcesfcsadee";
			char* str = "bcced";
			Solution_65 solved;
			cout<<solved.hasPath(matrix,3,4,str)<<endl;
		}

	};
}
#endif // _65_H__
