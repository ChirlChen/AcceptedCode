#ifndef _455_H_
#define _455_H_

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
namespace Sansan
{
	class Solution_455
	{
	  public:
		int findContentChildren(vector<int>& g, vector<int>& s)
		{
			int childNum = 0, contNum = 0;
			int child = g.size(), cookies = s.size();
			if (!child || !cookies)
				return 0;
			sort(g.begin(), g.end());
			sort(s.begin(), s.end());  //使用其他方法排序效率将会提高到96%
			int i = 0, j = 0;
			while (j < cookies)
			{
				for (; i < child && s[j] >= g[i]; i++, contNum++)
					;
				if (contNum)
				{
					childNum++;
					contNum--;
				}
				j++;
			}
			return childNum;
		}
		static void test()
		{
			Solution_455 test;
			vector<int> g;
			g.push_back(1);
			g.push_back(2);
			g.push_back(3);
			vector<int> s;
			s.push_back(1);
			s.push_back(1);
			printf("%d\n", test.findContentChildren(g, s));
		}
	};
}
#endif
