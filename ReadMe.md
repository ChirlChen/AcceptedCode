###在线测评Accepted代码管理项目###

* **项目目录树**：（修改对应源文件后，请同时更新目录树,添加题目解法后，请在对应的提交者栏加入自己的ID）
> `AcceptedCode`
>>`LeetCode`		//文件夹名以OJ平台的名字命名，文件夹中算法头文件以题目标号命名
>>> | | 文件名 | 提交者 |
>>> |---|:-------:|:-------:| 	
>>>  |[main.cpp](https://github.com/CheilQuan/AcceptedCode/blob/master/LeetCode/main.cpp)|  |						
>>>  |[1.h](https://github.com/CheilQuan/AcceptedCode/blob/master/LeetCode/1.h)  | Chirl、 |	
>>>  |[2.h](https://github.com/CheilQuan/AcceptedCode/blob/master/LeetCode/2.h)  | Chirl、 |
>>   |455sansan.h | Sansan、 |
>>>……
>	
>> `NowCoder`  //牛客网
>>> | | 文件名 | 提交者 |
>>> |---|:-------:|:-------:| 	
>>>  |[main.cpp](https://github.com/CheilQuan/AcceptedCode/blob/master/NowCoder/main.cpp)|  |
>>>  |[1.h]()  | Chirl、 |	
>>>  |[2.h]()  | Chirl、 |				
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
	 	eg. Chirl编写LeetCode OJ 平台第一题 
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

				static void test(){//测试代码……}
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
