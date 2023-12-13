Learn C the Herd way  

## 目的  
这本书的目的是让你足够熟悉C语言，并能够使用它编写自己的软件，或者修改其他人的代码。
这本书中我会让你立即开始编程，之后我会解释你做了什么。这样更有效果，因为你已经经历过的事情解释起来更加容易。  
	
	
## ex2 makefile  
### 附加题  
1.man make 
	
![](./10.png)
	
	
2.man cc
	
~~~html
cc -o hello hello.c   
~~~

这个命令将hello.c编译成一个可执行文件，并将其命名为hello（使用-o选项指定输出文件名）。然后，你可以运行./hello来执行编译后的程序  
‘-wall’这个命令后缀用于在编译过程中开启额外的警告信息，帮助程序员发现代码中潜在的问题或错误  
	
	
3.在另一个C语言项目中找到Makefile文件，并且尝试理解它做了什么。  
- [Makefile工作原理](https://aptx4869-conan.github.io/zzp-blog/sundries/makefile/)
	
	

## ex3 格式化打印  
![](./4.png)  
	
## ex5 运算符，ex6语法    
不再赘述  
附加题  
1.搜索“printf格式化”，试着使用一些高级的占位符。  
- [占位符](https://aptx4869-conan.github.io/zzp-blog/sundries/placeholder/)  
	

2.研究可以用几种方法打印数字。尝试以八进制或十六进制打印，或者其它你找到的方法。  
- [进制](https://aptx4869-conan.github.io/zzp-blog/sundries/1/)  
	

3.试着打印空字符串，即""。  
/0  
	
4..上网搜索unsigned做了什么。  
unsigned long 是无符号长整型数据类型，只能表示非负整数。  
	
5.试着自己解释（在下个练习之前）为什么char可以和int相乘。  
- [本题答案](https://aptx4869-conan.github.io/zzp-blog/sundries/2/)  
	

## ex7 变量和类型  
make  
![](./5.png)  
break  
	
![](./6.png)  
	
有很多类型，整数型，浮点型，字符型  
int对应%d  
long 对应%ld  abcdefgabcdefg
short对应%u  
float 对应%f  
double 对应%lf 
char对应%c（单个字符）和%s（字符串）  
字符串即多个字符  
	
	
## ex8 if,else  

![](./7.jpg)
	
	
	
## ex9 while循环和布尔表达式  

![](./8.png)
	
***
## ex10 switch 循环  

![](./9.png)
	
	
## ex11 数组  

int arr[10]={1，2，3}  
其中int 处填类型  
arr处填数组名  
[]中表示元素索引，索引一般从0开始，所以[1]代表的是数组中的第二个元素，以此类推  
填入1.2.3三个数，剩下默认为0  
	
### 附加题  
1.尝试将areas的一个元素赋值为name中的字符。  
会报错  
	
2.上网搜索在不同的CPU上整数所占的不同大小。  
- [本题答案](https://aptx4869-conan.github.io/zzp-blog/sundries/3/)
	
3.
- [本题答案](https://aptx4869-conan.github.io/zzp-blog/sundries/4/)



***
## 命令  
sizeof（name）  
问c语言name这个量占多少字节  
	
***
## 循环  abcdefg
for  
for(i = 1; i < argc; i++) {  
printf("arg %d: %s\n", i, argv[i]);     
}    
其中i=1:初始化的变量/.  
i < argc : 判断条件（不满足时会执行大括号里面的，满足则继续循环）  
i++ : 自增恒量变量，就是循环的内容  
	
while  
语法:  
while(i＜arge)  
{  
printf"xxx";  
i++;  
}  
其中（）中的事条件，如果是true则执行大括号里面的，如果是false则跳出括号。  
	
布尔表达式:只有true和false
	/

***
## Switch 语句  
语法：  
switch(表达式){  
case   
case  
default  