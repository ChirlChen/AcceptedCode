在线测评Accepted代码管理项目

项目目录树：
AcceptedCode
	|	 	
	|- LeetCode		//以OJ平台的名字命名
	|	|- main.cpp
	|	|- 1.h   	//文件名以题号命名
	|	|- 2.h
	|	|- ……
	|
	|- NowCoder
	|	|- main.cpp
	|	|- 1.h
	|	|- 2.h
`	|	|……
	|
	|- ……


项目添加规则：
1、添加新的OJ平台规则:
	创建对应平台名的文件夹，并将该OJ平台下自己提交的各题Accepted代码放于文件夹下；
	eg. LeetCode OJ 平台 —— 则创建名为LeetCode的文件夹用于放代码；

2、添加题目规则:
	以对应OJ平台下的题目编号为文件名编写头文件，个人相关的所有代码放于该头文件中；
	eg. LeetCode OJ 平台第一题 —— 则创建名为 1.h 的头文件；

3、编写Solution规则:
        （1）以自己的名字定义namespace，在namespace中编写对应的Solution类，并且Solution后跟上题目编号；
	 eg. Chirl编写LeetCode OJ 平台第一题 —— 
	    namespace Chirl
	    {
		class Solution_1
		{
			//算法代码
			……
		}
	    }	
	     
4、关于测试代码：
	也放在自己的名字空间的类中，以静态函数方式存在，并命名为 test（）
	eg. 
	    namespace Chirl
	    {
		class Solution_1
		{
			//算法代码
			……

			static void test(){//测试代码……}
		}
	    }	

5、main中调用对应的算法：
	#include对应题号的头文件，并调用想要调用的算法的test函数;
	eg. 调用Chirl的第一题算法：
	//main.cpp中
	  #include "1.h"
	  int main(int argc, char **argv)
	  {
		Chirl::Solution_1::test();
		return 0;	
	  }	

