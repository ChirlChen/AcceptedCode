#ifndef _434_H_
#define _434_H_
#include <iostream>
#include <string>
using namespace std;
namespace Sansan
{
	class Solution_434
	{
	public:
		int countSegments(string s)
		{
			int res=0;
			if(s.empty())
				return 0;
			s.push_back(' ');
			for (int j=1;j<s.length();j++)
			{
				if(s[j]==' '&&s[j-1]!=' ')
					res++;
			}
			return res;
		}
		static void test()
		{
			Solution_434 test;
			string s="   dewewew  efret  rtgretgre  re ";
			printf("%d\n",test.countSegments(s));
		}
	};
}
#endif