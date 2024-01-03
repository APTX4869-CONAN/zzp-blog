# C语言
!!! note "目的"
	
    这本书的目的是让我足够熟悉C语言，并能够使用它编写自己的软件，或者修改其他人的代  码。这本书中我会让你立即开始编程，之后我会解释你做了什么。这样更有效果，因为你已经经历过事情解释起来更加容易。      


​	
​		
​		

***
## ex2 makefile  
??? example 

    ![](./10.png)

??? abstract "附加题" 

    1.man make   
    
    ![](./10.png)
    
    2.man cc
    
    ~~~html
    cc -o hello hello.c   
    ~~~
    
    这个命令将hello.c编译成一个可执行文件，并将其命名为hello（使用-o选项指定输出文件名）。然后，你可以运行./hello来执行编译后的程序 -wall’这个命令后缀用于在编译过程中开启额外的警告信息，帮助程序员发现代码中潜在的问题或错误
    
    3.在另一个C语言项目中找到Makefile文件，并且尝试理解它做了什么。 


​	
​	
??? tip "Makefile工作原理"

    Makefile是一个包含一系列规则的文件，用于告诉make工具如何编译和构建软件项目。它描述了项目中源代码文件之间的依赖关系以及如何将它们编译成最终的可执行文件、库文件或其他目标文件。  
    
    当你运行make命令时，它会检查Makefile文件并执行其中定义的规则，这些规则指定了如何生成目标文件，以及哪些文件需要重新生成。  
    
    通常，Makefile包含以下内容：  
    
    目标(Targets)：指定要构建的最终输出文件的名称。例如，可执行文件的名称或库文件的名称等。  
    
    依赖关系(Dependencies)：指定了每个目标文件所依赖的源文件、头文件或其他目标文件。  
    
    规则(Rules)：规定了如何根据依赖关系生成目标文件的命令。这些规则由目标、依赖项和命令组成。  
    
    变量(Variables)：定义了在整个Makefile中使用的变量，这些变量可以包含编译器选项、文件路径等。  
    
    ### 一个实例
    
    ~~~html
    CC = gcc
    CFLAGS = -Wall -O2
    TARGET = my_program
    SRCS = main.c utils.c
    OBJS = $(SRCS:.c=.o)
    
    $(TARGET): $(OBJS)
        $(CC) $(CFLAGS) -o $@ $^
    
    %.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@
    
    clean:
        rm -f $(OBJS) $(TARGET)
    ~~~
    
    在这个例子中：   
        
    CC 是C编译器的变量，CFLAGS 是编译器选项的变量。  
    	
    TARGET 是最终要生成的可执行文件的名称，SRCS 是源文件的列表，OBJS 是编译后的目标文件列表。  
    	
    第一个规则定义了如何生成最终的可执行文件。它告诉make如果$(OBJS)中的文件发生变化，应该使用$(CC)编译器和$(CFLAGS)选项将它们链接在一起形成$(TARGET)可执行文件。      
    	
    第二个规则告诉make如何将.c源文件编译成.o目标文件。  
    	
    clean规则是一个特殊的目标，用于删除生成的目标文件和可执行文件，以便重新构建整个项目。  
    通过make命令执行该Makefile，它将会根据规则编译源文件并生成最终的可执行文件。    Makefile使得构建复杂项目变得更加自动化和可靠。  


​    	
​	    
***
## ex3 格式化打印  
??? example 

    ![](./4.png)  

***
## ex5 运算符，ex6语法    

??? abstract "附加题1"

    1.搜索“printf格式化”，试着使用一些高级的占位符。  
     %d: 用于输出十进制整数。  
    %f: 用于输出浮点数。  
    %c: 用于输出字符。  
    %s: 用于输出字符串。  
    %x 或 %X: 用于输出十六进制整数，分别表示小写字母和大写字母。  
    %o: 用于输出八进制整数。  
    %u: 用于输出无符号整数。  
    %e 或 %E: 用于以指数形式输出浮点数，分别表示小写字母和大写字母。  
    %p: 用于输出指针地址。  
    这些占位符通常用于格式化输出函数，比如 printf()、scanf() 等。   

??? abstract "附加题2"

    2.研究可以用几种方法打印数字。尝试以八进制或十六进制打印，或者其它你找到的方法。 
    ~~~
    #include <stdio.h>
    
    int main() {
        int number = 42;
    
        // 打印十进制数
        printf("Decimal: %d\n", number);
    
        // 打印八进制数
        printf("Octal: %o\n", number);
    
        // 打印十六进制数（小写字母）
        printf("Lowercase Hexadecimal: %x\n", number);
    
        // 打印十六进制数（大写字母）
        printf("Uppercase Hexadecimal: %X\n", number);
    
        return 0;
    }
    ~~~

??? abstract "附加题3"

    3.试着打印空字符串，即""。  
    /0  

??? abstract "附加题4"

    4..上网搜索unsigned做了什么。  
    unsigned long 是无符号长整型数据类型，只能表示非负整数。  

??? abstract "附加题5"

    5.试着自己解释（在下个练习之前）为什么char可以和int相乘。  
    在C语言中，char 类型和 int 类型都是整数类型，尽管它们的大小（占用的内存空间）可能不同。虽然 char 通常用来表示字符，但它本质上也是一个整数类型。  
    	
    C语言中的类型转换规则允许将较小的整数类型（如 char）在表达式中自动转换为更大的整数类型（如 int）进行运算。这种转换称为 隐式类型转换 （implicit type conversion）或 自动类型提升 （automatic type promotion）。  
    	    
    当 char 类型参与乘法运算时，它可能会被自动提升为 int 类型，然后进行乘法运算。这是因为在表达式中，C语言倾向于将较小的整数类型提升为较大的整数类型，以避免精度丢失或截断。  

***
## ex7 变量和类型  
??? example 

    ![](./5.png)  
    ![](./6.png)  
    
    有很多类型，整数型，浮点型，字符型  
    int对应%d  
    long 对应%ld  abcdefgabcdefg
    short对应%u  
    float 对应%f  
    double 对应%lf 
    char对应%c（单个字符）和%s（字符串）  
    字符串即多个字符  


​	
***
## ex8 if,else  
??? example

    ![](./7.jpg)


​	
​	
***
## ex9 while循环和布尔表达式  
??? example

    ![](./8.png)

***
## ex10 switch 循环  
??? example

    ![](./9.png)


​	
***
## ex11 数组  
??? abstract "数组"

    int arr[10]={1，2，3}  
    其中int 处填类型  
    arr处填数组名  
    int arr[10]表示的是生成__10__个位置  
    __但是__:数组中的每个元素都可以使用 arr[0] 到 arr[9] 的索引来访问，此时srr[9]才是指的第十个位置，因为在 C 中，数组索引从 0 开始。  


​    
??? abstract "附加题1"  

     1.尝试将areas的一个元素赋值为name中的字符。  
    会报错  

??? abstract "附加题2"  

    2.上网搜索在不同的CPU上整数所占的不同大小。  
    在不同的CPU架构或计算机体系结构中，整数所占用的大小可能会有所不同。C语言标准规定了整数类型的最小范围，但并未规定确切的大小，这使得不同的平台可以根据需求选择合适的整数表示方式。  
    	
    一些常见的整数类型及其在不同平台上的典型大小（以字节为单位）如下：  
    	
    char: 通常占 1 字节，至少能表示 -128 到 127 或者 0 到 255的范围，具体取决于是带符号还是无符号的 char。  
    short: 通常占 2 字节，在一些特殊的系统上可能占用更多或更少的空间。  
    int: 在大多数系统上通常占 4 字节，但也有一些系统上可能占用 2 或 8 字节。  
    long: 在32位系统上通常占 4 字节，在64位系统上通常占 8 字节。但这也取决于编译器和操作系统的具体实现。  
    long long: 通常占 8 字节，可以表示更大范围的整数值。  
    这些大小可能因为编译器、操作系统和硬件架构的不同而变化。例如，32位和64位系统上的整数大小可能不同，因为64位系统能够处理更大范围的内存地址和数据。  
    	
    为了获取特定平台上整数类型的确切大小，可以使用 sizeof 运算符。例如，sizeof(int) 可以告诉你在当前平台上 int 类型的字节数  

??? abstract "附加题3"

    3.如果一个字符数组占四个字节，一个整数也占4个字节，你可以像整数一样使用整个name吗？你如何用黑魔法实现它？  
    在理论上，可以将字符数组视为整数数组，并且通过某些技巧来操作它，使其表现得像一个整数数组。这涉及到对内存的低级别操作，需要考虑计算机的字节序（即大端序和小端序）等因素。  
    	    
    黑魔法或许可以利用联合体（union）的概念，这是C语言中一个特殊的数据结构，允许在同一内存空间存储不同的数据类型。这样可以在相同的内存位置上同时存储字符数组和整数，并可以通过一些操作在它们之间进行转换。  
    	
    以下是一个示例，展示了如何使用联合体将字符数组和整数绑定在一起：  
    ~~~
    #include <stdio.h>
    
    union 1 {
        char chars[4]; // 字符数组
        int number;    // 整数
    };
    
    int main() {
        union Magic data;
        
        // 赋值字符数组
        data.chars[0] = 'A';
        data.chars[1] = 'B';
        data.chars[2] = 'C';
        data.chars[3] = 'D';
    
        // 将字符数组转换为整数并输出
        printf("字符数组转换为整数: %d\n", data.number);
        
        // 修改整数值
        data.number = 123456789;
        
            // 将整数转换为字符数组并输出
        printf("整数转换为字符数组: %c %c %c %c\n", data.chars[0],             data.chars[1], data.chars[2], data.chars[3]);
        
        return 0;
    }
    ~~~
    union 1 { ... };：这定义了一个联合体（union）类型 1。联合体允许在相同的内存位置存储不同类型的数据。在这里，Magic联合体包含了两个成员：一个名为 chars 的长度为4的字符数组和一个名为 number 的整数。  
    	
    输出结果将是  
    ~~~
    字符数组转换为整数: 1145258561
    整数转换为字符数组: ݓ ƒ % @
    ~~~
    这些输出是根据具体的字符集和字符编码而变化的，因此输出的字符可能因系统和编译器而异。由于字符数组和整数共享相同的内存空间，在转换过程中，整数被当作字符来解释，而字符也被当作整数来解释。这种类型的转换在实际中可能导致不可预测的结果。  

??? abstract "附加题4"

    4..弄清楚在for循环的每一部分你都可以放置什么样的代码。  
    在C语言的 for 循环中，有三个部分，它们分别是初始化部分、循环条件部分和迭代部分。每个部分都有自己特定的语法，但几乎可以放置任何有效的语句或表达式。下面是每个部分可以放置的内容：  
    	
    初始化部分： 在循环开始之前只执行一次，通常用于初始化变量。  
    可以放置变量声明和赋值语句。例如：int i = 0; 或 float x = 1.5;  
    也可以放置函数调用，但这些函数必须返回一个值，如 someFunction();  
    循环条件部分： 在每次迭代开始前都会被检查，如果条件为真，则执行循环体内的代码，如果为  假，则退出循环。  
     可以放置条件表达式，比如 i < 10 或 x != 0。这些条件表达式必须返回一个布尔值     （真或假）。  
    也可以放置函数调用，但同样需要返回布尔值。例如：checkCondition();   
    
    迭代部分： 在每次循环结束后执行，通常用于更新循环控制变量。  
    可以放置增加或减少循环控制变量的语句，例如 i++、j -= 2。  

??? abstract "附加题5" 

    5.查询NULL是什么东西  
    NULL 是C语言中的一个常见标识符，用于表示空指针，可以帮助在程序中更加清晰地表达和处理空指针相关的情况。


  	
??? abstract "附加题6"

    6.argc argv 是什么  
    在程序执行时，操作系统会将命令行输入的参数传递给 main 函数。argc 表示参数的数量，而argv 是一个指针数组，每个指针指向一个以 null 结尾的字符串，这些字符串存储了实际传递给程序的命令行参数。argv[0] 存储的是程序的名称。
    
    
??? abstract "附加题7"

    7.我已经向你简短地介绍了&&，它执行“与”操作。上网搜索与之不同的“布尔运算符”。  
    布尔运算符是用于执行逻辑运算的运算符。它们通常用于布尔类型的操作数（只有两个可能值：真和假），在计算机编程中经常使用。   
    
    在大多数编程语言中，布尔运算符包括以下几种：  
    	
    逻辑与（AND）：表示为 &&，当且仅当两个操作数都为真时，结果才为真。例如：A && B，当 A 和 B 同时为真时，结果为真，否则为假。  
    	
    逻辑或（OR）：表示为 ||，只要两个操作数中有一个为真，结果就为真。例如：A || B，当 A 或 B 其中一个为真时，结果为真，只有当两个都为假时，结果为假。  
    	
    逻辑非（NOT）：表示为 !，用于取反操作，将真变为假，将假变为真。例如：!A，当 A 为真时，结果为假；当 A 为假时，结果为真。  
    	
    这些布尔运算符在控制流语句、条件语句和循环结构等编程结构中扮演重要角色。它们使程序能够根据条件执行不同的代码路径，或根据给定的条件重复执行特定代码块。  

??? abstract "附加题8"

    8.使用if语句使循环提前退出。你需要break语句来实现它，搜索它的有关资料。  
        在(for、while、do-while)循环中，break 语句可以立即终止当前的循环，将控制转移到循环后的下一个语句。  
    在 switch 语句中，break 用于结束当前 case 分支的执行，使程序控制流跳出 switch 语句。  
    ### 命令  
    sizeof（name）  
    问c语言name这个量占多少字节  


​	
***
## ex12 For    
for(i = 1; i < argc; i++) {  
printf("arg %d: %s\n", i, argv[i]);     
}    
其中i=1:初始化的变量/.  
i < argc : 判断条件（不满足时会执行大括号里面的，满足则继续循环）  
i++ : 自增恒量变量，就是循环的内容  
其实不只是可以++，还可以+=2，就是自增2，可以在循环中用
	
	
***
## ex12while语句  
语法:  
while(i＜arge)  
{  
printf"xxx";  
i++;  
}   
其中（）中的__条件__，如果是true则执行大括号里面的，如果是false则跳出括号。  


布尔表达式:只有true和false
	
	
***
## ex13 Switch 语句  
语法：  
switch(表达式){  
case   
case  
default  
	
	
***
## ex14 编写并使用函数  
自己声明函数就跟脚本一样  
比如以下  
~~~
void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; i++) {
        print_letters(argv[i]);
    }
~~~


***
## ex15 指针  

-[什么是指针](https://aptx4869-conan.github.io/zzp-blog/sundries/7/)  
### 指针+-整数
![这是指针加数组的一串代码](./11.png)  
数组是什么，默认是首元素的地址  指针取数组的地址实际是取的首元素的地址，也就是索引为0的地址  比如int\*p = arr  
但是如果int\* p = &arr ，取出的是数组本身的地址  
这张图片中的指针加整数的意思是让它往后索引几个  
### 指针数组和数组指针  
指针数组 - 数组 -存放指针的数组  
数组指针 - 指针  
字符串指针数组：char \*names[ ]  
这种声明方式创建了一个数组，数组的每个元素都是一个指向字符串的指针。  
相比于char  names[ ] 的优点：  
- [链接](https://aptx4869-conan.github.io/zzp-blog/sundries/8/)  
	
### ex15 题目与附加题  
-[链接](https://aptx4869-conan.github.io/zzp-blog/sundries/9/)  
	
	
	
## ex16 结构体和指向它们的指针  
-[结构体](https://aptx4869-conan.github.io/zzp-blog/sundries/10/)  
- [作业与附加题](https://aptx4869-conan.github.io/zzp-blog/sundries/11/)  
	
	
	
	
	
***
## ex17 堆和栈的内存分配  
-[堆和栈的内存分配](https://aptx4869-conan.github.io/zzp-blog/sundries/13/)  
-[作业与附加题](https://aptx4869-conan.github.io/zzp-blog/sundries/12/)  
	
	
***
## ex18函数指针  
函数指针的格式类似这样：  
~~~
int (指针名)(int a, int b)  
~~~
记住如何编写它的一个方法是：  
	
编写一个普通的函数声明：  
~~~
int callme(int a, int b)  
~~~
将函数用指针语法包装：  
~~~ 
int (*callme)(int a, int b)  
~~~
将名称改成指针名称：   
~~~
int (*compare_cb)(int a, int b)  
~~~
指针的变量名称为compare_cb，你可以将它用作函数。这类似于指向数组的指针可以表示所指向的数组。指向函数的指针也可以用作表示所指向的函数，只不过是不同的名字。  
![](./12.png)  
这就是一个函数指针，它储存了show这个函数  
为了和普通指针区别一下，它用了括号括住了  
调用函数可以直接用show()或者 pFun()  
### 回调函数  
有两个函数A,B，函数A有参数，参数是函数B，则B就是回调函数  
被当做参数来使用的函数就是回调函数  
-[回调函数](https://aptx4869-conan.github.io/zzp-blog/sundries/14/)  
	
	
## ex19 一个简单的对象系统  
-[预处理和宏定义](https://aptx4869-conan.github.io/zzp-blog/sundries/15/)  
### C中构建面向对象系统  
-[C中构建面向对象系统](https://aptx4869-conan.github.io/zzp-blog/sundries/16/)  
	
	
	
***
## ex20 调试宏  
-[调试宏](https://aptx4869-conan.github.io/zzp-blog/sundries/17/)  
-[具体内容](https://aptx4869-conan.github.io/zzp-blog/sundries/20/)  
	
	
***
## ex21 高级数据类型和控制结构  
-[数据类型和控制结构](https://aptx4869-conan.github.io/zzp-blog/sundries/18/)  
	
	
	
***

## ex22 栈、作用域和全局  
-[栈、作用域和全局](https://aptx4869-conan.github.io/zzp-blog/sundries/19/)

## ex23 认识达夫设备  
-[达夫设备](https://aptx4869-conan.github.io/zzp-blog/sundries/21/)  
	
	
	
## ex24 输入输出和文件  
用到了fscanf 和 fgets   
-[输入输出和文件](https://aptx4869-conan.github.io/zzp-blog/sundries/22/)  
		
	
***
##  ex25 参变函数  
-[参变函数](https://aptx4869-conan.github.io/zzp-blog/sundries/23/)  
	
	
## ex26 实现一个真正的程序  
-[参变函数](https://aptx4869-conan.github.io/zzp-blog/sundries/24/)  
	
	
	
***
## ex27 创造性和防御性编程  
-[创造性和防御性编程](https://aptx4869-conan.github.io/zzp-blog/sundries/25/)  
	
	
***
## ex28 Makefile进阶   
-[Makefile](https://aptx4869-conan.github.io/zzp-blog/sundries/26/)  
	
	
	
***
## ex29 库和链接  
-[库和链接](https://aptx4869-conan.github.io/zzp-blog/sundries/27/)  
	
	
***
## ex30 自动化测试  
![](./14.jpg)  
	