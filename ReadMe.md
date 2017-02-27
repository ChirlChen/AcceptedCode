###在线测评Accepted代码管理项目###

* **项目目录树**：（`修改对应源文件后，请同时更新目录树` | `添加题目解法后，请在对应的提交者栏加入自己的ID` | `更新请以题目序号保持递增`）
> `AcceptedCode`
>>`LeetCode`		//文件夹名以OJ平台的名字命名，文件夹中算法头文件以题目标号命名
>>> | 题目 | 文件名 | 提交者 |
>>> |:---:|:-------:|:-------:|
>>> | |[main.cpp](https://github.com/CheilQuan/AcceptedCode/blob/master/LeetCode/main.cpp)|  |
>>> |[1.Two Sum](https://oj.leetcode.com/problems/two-sum/)|[1.h](https://github.com/CheilQuan/AcceptedCode/blob/master/LeetCode/1.h)          | Chirl、NanerLee |
>>> |[2.Add Two Numbers](https://oj.leetcode.com/problems/add-two-numbers/)|[2.h](https://github.com/CheilQuan/AcceptedCode/blob/master/LeetCode/2.h)          | Chirl、 |
>>>……
>
>> `NowCoder`  //牛客网
>>> |题目 | 文件名 | 提交者 |
>>> |:---:|:-------:|:-------:|
>>> | |[main.cpp](https://github.com/CheilQuan/AcceptedCode/blob/master/NowCoder/main.cpp)|  |
>>> |[1.矩阵查找](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) |[1.h](https://github.com/CheilQuan/AcceptedCode/blob/master/NowCoder/1.h)  | Chirl、 |
>>> |[2.替换空格](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) |[2.h](https://github.com/CheilQuan/AcceptedCode/blob/master/NowCoder/2.h)  | Chirl、 |
>>> |[3.逆序打印链表](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) |[3.h](https://github.com/CheilQuan/AcceptedCode/blob/master/NowCoder/3.h)  | Chirl、 |
>>> |[4.重建二叉树](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) |[4.h](https://github.com/CheilQuan/AcceptedCode/blob/master/NowCoder/4.h)  | Chirl、 |
>
>> ……


* **项目维护规则**：<br>
	1、添加新的OJ平台规则:<br>
		创建对应平台名的文件夹，并将该OJ平台下自己提交的各题Accepted代码放于文件夹下；<br>
		eg. LeetCode OJ 平台 —— 则创建名为LeetCode的文件夹用于放代码；<br>
	<br>
	2、添加题目规则:<br>
		以对应OJ平台下的题目编号为文件名编写头文件，个人相关的所有代码放于该头文件中；<br>
		eg. LeetCode OJ 平台第一题 —— 则创建名为 1.h 的头文件；<br>
	<br>
	3、编写Solution规则:<br>
		（1）以自己的名字定义namespace，在namespace中编写对应的Solution类，并且Solution后跟上题目编号；<br>
		eg. Chirl编写LeetCode OJ 平台第一题<br>
	``` C++
	//1.h
	namespace Chirl
	{
		class Solution_1
		{
			//算法代码
			……
		}
	}
	```

	4、关于测试代码：<br>
		也放在自己的名字空间的类中，以静态函数方式存在，并命名为 test()<br>
		eg.<br>
	``` C++
	  //1.h
	namespace Chirl
	{
	class Solution_1
	{
		//算法代码
		……

		static void test()
		{
			//测试代码……
		}
	}
	}
	```

	5、main中调用对应的算法：<br>
		引用对应题号的头文件，并调用想要调用的算法的test函数;<br>
		eg. 调用Chirl的第一题算法：<br>
	``` C++
	//main.cpp中
	#include "1.h"
	int main(int argc, char **argv)
	{
		Chirl::Solution_1::test();
		return 0;
	}
	```
