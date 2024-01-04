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


​    
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
??? abstract "For循环"

    for(i = 1; i < argc; i++) {  
    printf("arg %d: %s\n", i, argv[i]);     
    }    
    其中i=1:初始化的变量/.  
    i < argc : 判断条件（不满足时会执行大括号里面的，满足则继续循环）  
    i++ : 自增恒量变量，就是循环的内容  
    其实不只是可以++，还可以+=2，就是自增2，可以在循环中用


​	
​	
​	
***
## ex12while语句
??? abstract "while循环"

    语法:  
    while(i＜arge)  
    {  
    printf"xxx";  
    i++;  
    }   
    其中（）中的__条件__，如果是true则执行大括号里面的，如果是false则跳出括号。  
    布尔表达式:只有true和false


​	
***
## ex13 Switch 语句  
??? abstract "Switch语句"

    语法：  
    switch(表达式){  
    case   
    case  
    default  


​	
***
## ex14 编写并使用函数  
??? abstract "编写函数"

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


​	
***
## ex15 指针  

???astract "指针"

    ![](./c1.png)
    比如 int a =1 就是为a申请一个地方，名字为a，但是地址不会变。  
    int 类型储存的东西是整数  
    	
    了解内存空间之后，指针就好理解了  
    指针和 int一样，也是一种类型，不过它储存的是一个地址
    比如int\*p = &a  
    ![](./c2.png)
    	
    指针名字叫p，int\*p指的是p是一个指针  &a是一个地址  
    int\*p = &a 代表的是把a的地址保存到p中  
    Int d = p 的话会直接报错，要int d =\*p  
    就把1这个数给了d   
    上面用到了两个\*，但此星非彼星  
    上面的\*是int\* ，是一种指针类型，同理有char\*,short\*,等  
    下面的星是间接运算符，是间接引用a的值。  

??? abstract "指针+-整数"

    ![这是指针加数组的一串代码](./11.png)  
    数组是什么，默认是首元素的地址  指针取数组的地址实际是取的首元素的地址，也就是索引为0的地址  比如int\*p = arr  
    但是如果int\* p = &arr ，取出的是数组本身的地址  
    这张图片中的指针加整数的意思是让它往后索引几个  

### 指针数组和数组指针  
??? abstract "指针数组和数组指针"

    指针数组 - 数组 -存放指针的数组  
    数组指针 - 指针  
    字符串指针数组：char \*names[ ]  
    这种声明方式创建了一个数组，数组的每个元素都是一个指向字符串的指针。  
    相比于char  names[ ] 的优点：  
    char *names[] 的优势：  
    1. 动态长度的字符串存储：  
    	char \*names[] 声明的是一个字符串指针数组。这种声明方式允许存储不同  长度的字符串，因为每个元素都是一个指向字符（字符串）的指针。  
    	这种声明方法支持动态分配和存储不同长度的字符串。  
    	
    2. 方便指向其他字符串：  
    	使用字符串指针数组，可以方便地更改指针指向不同的字符串。例如，可以将指针重新赋值为其他字符串的地址。  
    	
    ***
    ## char names[] 的优势：  
    1. 静态字符串存储：  
    	char names[] 声明的是一个字符数组，通常用于存储静态长度的字符串。  
    	这种方式不太方便存储和处理不同长度的字符串。   
    	
    2. 更直接、更简单：   
    	对于单个字符串的存储和操作，使用 char names[] 可能更简洁直观，因为它直接存储字符串。  
    	
    ***
    ## 何时选择哪种方式？  
    如果需要存储和处理多个长度不同的字符串，或者需要在运行时动态地更改指向的字符串，那么 char *names[] 可能更适合。  
    如果只需要存储单个固定长度的字符串或者有明确的固定字符串长度限制，那么 char names[] 可能更为方便。  
    综合考虑不同场景下的需求，可以选择合适的字符串存储方式。  


​	
### ex15 题目与附加题
??? abstract "ex15"

    ~~~
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };
    ~~~
    这段代码定义了两个数组 ages 和 names。ages 是一个整数类型的数组，包含了一些年龄；  
    names 是一个__字符串指针数组__，包含了一些姓名。  
    ~~~
    int *cur_age = ages;
    char **cur_name = names;
    
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(cur_name+i), *(cur_age+i));
    }
    	
    ~~~
    其中char \*\*cur_name = names 这一段代码创建了指向names的指针。char \*已经是“指向char的指针”了，所以它只是个字符串。你需要两个层级，因为names是二维的，也就是说你需要char \*\*作为“指向‘指向字符的指针’的指针”。把它学会，并且自己解释它。  
    ~~~
    int *cur_age = ages;
    char **cur_name = names;
    	
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(cur_name+i), *(cur_age+i));
    }
    	
    ~~~
    这段代码再次展示了使用指针和数组下标来访问数组元素。这次直接使用指针变量 cur_name 和 cur_age 作为数组来访问元素。  
    为什么可以直接使用指针变量 cur_name 和 cur_age 作为数组来访问元素？  
    在 C 语言中，指针变量本质上是数组的首地址。当你声明指针 cur_name 和 cur_age 分别指向数组 names 和 ages 的起始位置时，这些指针变量包含了数组的地址。  
    因此，可以通过这些指针变量以及数组下标来访问数组中的元素。  
    __cur_name = names__实际上cur_name的值是names数组中的首个元素的值  
    
    ~~~
    for(cur_name = names, cur_age = ages;
            (cur_age - ages) < count;
            cur_name++, cur_age++)
    {
        printf("%s lived %d years so far.\n",
                *cur_name, *cur_age);
    }
    
    ~~~
    __让指针动起来__
    这段代码展示了一种复杂的方式，使用指针进行数组遍历。通过同时移动两个指针 cur_name 和 cur_age，通过对它们进行指针算术运算来访问数组元素，直到达到数组的末尾。  
    	
    ## 附加题  
    将for循环改为while循环，并且观察对于每种指针用法哪种循环更方便。  
    ~~~
    #include <stdio.h>
    
    int main() {
        int ages[] = {23, 43, 12, 89, 2};
        char *names[] = {
            "Alan", "Frank",
            "Mary", "John", "Lisa"
        };
    
        int count = sizeof(ages) / sizeof(int);
        int i = 0;
    
        // first way using indexing with while loop
        i = 0;
        while(i < count) {
            printf("%s has %d years alive.\n",
                    names[i], ages[i]);
            i++;
        }
    
        printf("---\n");
    
        // setup the pointers to the start of the arrays
        int *cur_age = ages;
        char **cur_name = names;
    
        // second way using pointers with while loop
        i = 0;
        while(i < count) {
            printf("%s is %d years old.\n",
                    *(cur_name + i), *(cur_age + i));
            i++;
        }
    
        printf("---\n");
    
        // third way, pointers are just arrays, with while loop
        i = 0;
        while(i < count) {
            printf("%s is %d years old again.\n",
                    cur_name[i], cur_age[i]);
            i++;
        }
    
        printf("---\n");
    
        // fourth way with pointers in a complex way, with while loop
        i = 0;
        while((cur_age - ages) < count) {
            printf("%s lived %d years so far.\n",
                    *cur_name, *cur_age);
            cur_name++;
            cur_age++;
            i++;
        } 
        return 0;
    }
    ~~~
    感觉while和for 对于指针遍历是差不多的  只不过while写的字多了点  


​	
​	

## ex16 结构体和指向它们的指针  
??? abstract "结构体和指针"

    在C语言中，结构体（Structures）是一种用户自定义的数据类型，允许你将__不同类型__的变量组合在一起，以表示一个相关联的__数据集合__。结构体可以包含各种不同类型的数据成员（也称为字段或属性），这些成员可以是整数、字符、指针、其他结构体等等。  
	
    结构体的定义使用关键字 struct，并指定结构体的名称以及包含在结构体内部的成员变量。  
    strcut和int一样，也是种类型  
    比如：  
    ~~~
    struct Person {
        char *name;
        int age;
        float height;
    };
    
    ~~~
    附加题
    ~~~
    struct Person *Person_create(char *name, int age, int height, int         weight)
    {
        struct Person *who = malloc(sizeof(struct Person));
        assert(who != NULL);
    
        who->name = strdup(name);
        who->age = age;
        who->height = height;
        who->weight = weight;
    
        return who;
    }
    
    ~~~
    这段代码是提前声明的自定义函数  
    其中struct是结构体的命令    
        malloc：用于分配内存以存储一个 Person 结构体大小的空间。  
    assert：用于断言 malloc 是否成功分配内存，若分配失败，则终止程序执行。  
    strdup：复制传入的姓名字符串并分配内存。  
    ~~~
     who->name = strdup(name);
        who->age = age;
        who->height = height;
        who->weight = weight;
    ~~~
    设置 Person 结构体实例的成员值  
    	
    return who  
    返回创建的实例指针。  
    \*who是实例指针  
    \*Person_create是函数指针  
    	
    ~~~ 
    void Person_destroy(struct Person *who)
    {
        assert(who != NULL);
    
        free(who->name);
        free(who);
    }
    
    ~~~
    Person_destroy 函数：用于释放通过 Person_create 创建的 Person 结构体实例的内存。  
    使用 free 函数释放姓名字符串的内存，然后释放整个结构体实例的内存。  
    	
    	
    	
    ~~~
    void Person_print(struct Person *who)
    {
        printf("Name: %s\n", who->name);
        printf("\tAge: %d\n", who->age);
        printf("\tHeight: %d\n", who->height);
        printf("\tWeight: %d\n", who->weight);
    }
    
    ~~~
    Person_print 函数：用于打印 Person 结构体实例的信息  
    ~~~
    int main(int argc, char *argv[])
    {
        // make two people structures
        struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
    
        // print them out and where they are in memory
        printf("Joe is at memory location %p:\n", joe);
        Person_print(joe);
    
        printf("Frank is at memory location %p:\n", frank);
        Person_print(frank);
    
        // make everyone age 20 years and print them again
        joe->age += 20;
        joe->height -= 2;
        joe->weight += 40;
        Person_print(joe);
    
        frank->age += 20;
        frank->weight += 20;
        Person_print(frank);
    
        // destroy them both so we clean up
        Person_destroy(joe);
        Person_destroy(frank);
    
        return 0;
    }
    
    ~~~
    main 函数：程序的入口点。  
    创建了两个 Person 结构体实例 joe 和 frank，并分别传入不同的参数。  
    修改了实例的属性值，然后再次打印了它们的信息。   
    最后，调用 Person_destroy 函数释放了 joe 和 frank 实例所占用的内存，完成了清理工作。  
    整个程序的主要功能是创建、操作和销毁 Person 结构体实例，并且通过函数对其进行了封装，以方便管理和使用。   
    
    
    	
	
	
	
	
***
## ex17 堆和栈的内存分配  
??? abstract "堆和栈的内存分配"

    在计算机科学中，堆（Heap）和栈（Stack）是两种常见的内存分配方式，用于存储程序运行时所需的数据。  
    	
    ## 栈 (Stack)
    ### 特点：  
    栈是一种线性数据结构，具有先进后出（FILO）的特性。  
    它的大小和生命周期是在编译时确定的，通常是__相对较小的固定大小__。  
    在函数调用时，会在栈上分配局部变量、函数参数、函数调用和返回地址等数据。  
    栈的分配和释放是__自动__的，由编译器/解释器管理。   
    	
    ### 用途：  
    存储函数的局部变量、函数参数和函数调用信息。  
    管理程序的执行上下文，如函数调用和返回。  
    	
    ## 堆 (Heap)  
    ### 特点：  
    堆是在程序运行时动态分配的内存区域，__大小不固定__。  
    在堆上分配内存需要__手动__申请和释放，否则可能导致内存泄漏或者内存溢出问题。  
    堆的分配和释放由程序员控制，使用像 __malloc()、free()（在C语言中）、new、    delete（在C++中）__等函数或运算符来完成。  
    	
    ### 用途：  
    存储动态分配的数据，如动态数组、对象等。  
    需要持久存储并且在不同函数间共享的数据。  
    	
    ## 区别  
    管理方式：栈的分配和释放是自动的，由编译器/解释器管理；而堆的分配和释放由程序员手动控制。  
    大小和生命周期：栈的大小和生命周期在编译时确定，通常较小；堆的大小不固定，并且可以在程序运行时动态分配和释放。  
    存储内容：栈用于存储函数调用、局部变量等；堆用于存储动态分配的数据，通常用于大量、持久或需要在不同函数间共享的数据。  
    在实际编程中，了解栈和堆的特点和用途对于正确、高效地管理内存是非常重要的。对于需要使用动态内存分配的情况，正确地申请、使用和释放堆内存是至关重要的，以避免内存泄漏和内存溢出等问题。  
    
??? abstract "作业与附加题"

    ~~~
    #include <stdio.h>
    #include <assert.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <string.h>
    ~~~
    这些是预处理指令 (#include)，用于包含标准 C 语言库头文件，提供了输入输出、错误处理、内存分配和字符串处理等功能。  
    ~~~
    #define MAX_DATA 512
    #define MAX_ROWS 100
    
    ~~~
    这里使用 #define 定义了两个常量 MAX_DATA 和 MAX_ROWS，分别表示存储数据的最大长度和数据库中的最大行数。  
    
    
    ~~~
    struct Address {
        int id;
        int set;
        char name[MAX_DATA];
        char email[MAX_DATA];
    };
    
    struct Database {
        struct Address rows[MAX_ROWS];
    };
    
    struct Connection {
        FILE *file;
        struct Database *db;
    };
    
    ~~~
    接下来定义了三个结构体：Address、Database 和 Connection。  
    Address 结构体表示数据库中的一条记录，包含一个 ID、一个标志位 set 以及姓名和邮箱等信息。  
    Database 结构体是由多个 Address 结构体组成的数组，表示整个数据库。  
    Connection 结构体包含一个文件指针和一个指向数据库的指针，用于连接数据库。  
    ~~~ 
    void die(const char *message)
    {
        if(errno) {
            perror(message);
        } else {
            printf("ERROR: %s\n", message);
        }
    
        exit(1);
    }
    
    ~~~
    然后定义了一系列函数用来操作数据库：  
    die 函数用于报告错误并退出程序。  
    	
    	
    ~~~
    int main(int argc, char *argv[])
    {
        // ... (命令行参数解析和数据库操作)
        return 0;
    }
    ~~~
    最后，在 main 函数中：  
    解析命令行参数来确定要执行的操作，比如创建、获取、设置、删除或列出条目。  
    根据操作执行相应的数据库操作，并在必要时输出错误信息。  
    最后关闭数据库连接并退出程序。  
    整个程序实现了一个简单的命令行数据库管理系统，可以通过命令行对数据进行增删改查等操作。  
    	
    	
    
    ***
    ## 附加题  
    搜索“栈数据结构”，并且在你最喜欢的语言中实现它，然后尝试在C中实现。  
    ~~~
    #include <stdio.h>
    #include <stdlib.h>
    
    #define MAX_SIZE 100
    
    // 定义栈结构
    typedef struct {
        int items[MAX_SIZE];
        int top; // 栈顶指针
    } Stack;
    
    // 初始化栈
    void initStack(Stack *stack) {
        stack->top = -1; // 初始化栈顶指针为-1
    }
    
    // 检查栈是否为空
    int isEmpty(Stack *stack) {
        return (stack->top == -1);
    }
    
    // 检查栈是否已满
    int isFull(Stack *stack) {
        return (stack->top == MAX_SIZE - 1);
    }
    
    // 压栈操作
    void push(Stack *stack, int value) {
        if (isFull(stack)) {
            printf("栈已满，无法压栈\n");
        } else {
            stack->top++;
            stack->items[stack->top] = value;
        }
    }
    
    // 出栈操作
    int pop(Stack *stack) {
        if (isEmpty(stack)) {
            printf("栈为空，无法出栈\n");
            return -1; // 如果栈为空，返回一个特殊值表示出错
        } else {
            int popped = stack->items[stack->top];
            stack->top--;
            return popped;
        }
    }
    
    // 查看栈顶元素
    int peek(Stack *stack) {
        if (isEmpty(stack)) {
            printf("栈为空\n");
            return -1; // 如果栈为空，返回一个特殊值表示出错
        } else {
            return stack->items[stack->top];
        }
    }
    
    int main() {
        Stack stack;
        initStack(&stack);
    
        push(&stack, 10);
        push(&stack, 20);
        push(&stack, 30);
    
        printf("栈顶元素为: %d\n", peek(&stack)); // 输出栈顶元素
    
        printf("出栈: %d\n", pop(&stack)); // 出栈
    
        printf("栈顶元素为: %d\n", peek(&stack)); // 输出栈顶元素
    
        return 0;
    }
    ~~~
	
	
***
## ex18函数指针 
??? abstract "函数指针" 

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
??? abstract "回调函数"

    ~~~
    #include <stdio.h>
    
    // 声明回调函数的原型，该函数接受一个整数作为参数
    typedef void (*CallbackFunc)(int);
    
    // 主函数，接受回调函数作为参数
    void performOperation(int data, CallbackFunc callback) {
        // 执行某些操作，然后调用回调函数并将数据传递给它
        printf("Performing operation with data: %d\n", data);
        callback(data); // 调用回调函数
    }
    
    // 回调函数的具体实现
    void callbackFunction(int result) {
        printf("Callback function called with result: %d\n", result);
    }
    
    int main() {
        int inputData = 10;
    
        // 调用 performOperation，并传递回调函数作为参数
        performOperation(inputData, callbackFunction);
    
    return 0;
    }
    
    ~~~
    这段代码表示的是回调函数的基本用法  
    其中出现了3个函数，让我们来一起看一看  
    ~~~
    typedef void (*CallbackFunc)(int);
    ~~~
    这个函数是一个声明函数，声明回调函数的原型，该函数接受一个整数作为参数  
    ~~~
    void performOperation(int data, CallbackFunc callback) {
        printf("Performing operation with data: %d\n", data);
        callback(data); 
    ~~~
    这个函数是一个中间函数，把用户传进来的数据进行一些操作，函数体内部可能包含了一些未给出的具体操作，这些操作会在执行时使用传递进来的 data 数据。  
    这个函数的作用是：
    1. 接收参数： 函数 performOperation 接收两个参数：data（整数类型）和 callback（函数指针，指向一个回调函数）。  
    2. 执行某些操作： 函数体内部可能包含了一些未给出的具体操作，这些操作会在执行时使用传递进来的 data 数据。  
    3. 调用回调函数： 在执行完上述操作之后，通过 callback(data); 这行代码调用了传递进来的回调函数，并将参数 data 传递给它。这就是回调函数的作用之一，它允许你在 performOperation 内部执行完特定的任务后，通过调用传入给回调函数，将数据或结果返回或通知给调用者。  
    	
    ~~~
    void callbackFunction(int result) {
        printf("Callback function called with result: %d\n", result);
    ~~~
    这个函数就是回调函数  
    performOperation把数据整理并调用给了它  
	
	
## ex19 一个简单的对象系统  
??? abstract "一个简单的对象系统" 

    # 预处理  
    预处理不是真正编译的一部分 它是编译代码前一个单独的步骤  
    ## 宏  
    宏（Macro）在 C 语言中是一种非常有用的_工具_，它允许你用一个_标识符_来代表一个值或者一段代码，然后在程序中通过这个标识符来_引用_这个值或代码。  
    ### 用途  
    1. 创建常量：可以使用宏来定义常量，例如：
    ~~~
    #define PI 3.14159
    
    ~~~
    
    这样就定义了一个名为_ PI _的宏，它代表的值是 3.14159。这样在程序中就可以使用 PI 这个_标识符_来表示 π 的值了  
        	
    2. 简化代码：宏也可以用于简化代码。比如，你可以创建一个计算平方的宏：  
    ~~~
    #define SQUARE(x) ((x) * (x))
    
    ~~~
    然后在程序中使用 SQUARE 这个宏，传入一个参数 x：  
    ~~~
    int result = SQUARE(5); // 会被展开为 ((5) * (5))
    
    ~~~
    这样就避免了每次都写 x * x，提高了代码的可读性和易用性。  
    	
    3. 条件编译：宏还可以用于条件编译，例如：  
    ~~~
    #define DEBUG 1
    
    #ifdef DEBUG
            // 调试代码
        // 这部分代码只有在 DEBUG 被定义的情况下才会被编译
    #endif
    
    ~~~
    这种方式可以让你根据宏的定义与否来控制代码的编译。  
    	
    虽然宏在某些情况下非常有用，但也要注意宏的一些_潜在问题_，比如宏展开可能导致代码难以调试、宏的作用域难以控制等。因此，在使用宏时需要谨慎并遵循最佳实践，以避免潜在的问题。  
    ## 宏的本质  
    预处理器只不过是做了一个文本替换的工作而已  
    所有预处理命令都是以#开头   
    ### 常见的预指令处理   
    ![.](3.jpg)  
    1. #include  
    #include 指令用于将*其他文件的内容包含到当前文件中*。这是用于引入头文件的常见方式，使得程序可以重复利用其他文件中的函数声明、宏定义等信息。
    2. #define
    #define *用于创建宏定义*，将一个标识符或表达式定义为一个特定的代码片段。这种方式可以用于创建常量、简化代码或定义一段代码片段。
    3. #ifdef, #ifndef, #else, #endif
    条件编译指令用于根据条件来控制代码的编译。比如，#ifdef 用于检查某个宏*是否已经被定义*，#ifndef 用于检查某个宏*是否未被定义*，#else 和 #endif 则用于*定义条件的分支和结束。*
    4. #undef
    #undef 用于取消宏的定义，使得该宏可以重新定义或者在之后的代码中不再生效。
    5. #error
    #error 用于生成编译时错误信息，当预处理器遇到这个指令时，会停止编译并显示指定的错误消息。
    6. #pragma## 预处理  
    预处理不是真正编译的一部分 它是编译代码前一个单独的步骤  
    ## 宏  
    宏（Macro）在 C 语言中是一种非常有用的_工具_，它允许你用一个_标识符_来代表一个值或者一段代码，然后在程序中通过这个标识符来_引用_这个值或代码。  
    ### 用途  
    1. 创建常量：可以使用宏来定义常量，例如：
    ~~~
    #define PI 3.14159
    
    ~~~
    
    这样就定义了一个名为_ PI _的宏，它代表的值是 3.14159。这样在程序中就可以使用 PI 这个_标识符_来表示 π 的值了  
    	
    2. 简化代码：宏也可以用于简化代码。比如，你可以创建一个计算平方的宏：  
    ~~~
    #define SQUARE(x) ((x) * (x))
    
    ~~~
    然后在程序中使用 SQUARE 这个宏，传入一个参数 x：  
    ~~~
    int result = SQUARE(5); // 会被展开为 ((5) * (5))
    
    ~~~
    这样就避免了每次都写 x * x，提高了代码的可读性和易用性。  
    	
    3. 条件编译：宏还可以用于条件编译，例如：  
    ~~~
    #define DEBUG 1
    
    #ifdef DEBUG
        // 调试代码
        // 这部分代码只有在 DEBUG 被定义的情况下才会被编译
    #endif
    
    ~~~
    这种方式可以让你根据宏的定义与否来控制代码的编译。  
    	
    虽然宏在某些情况下非常有用，但也要注意宏的一些_潜在问题_，比如宏展开可能导致代码难以调试、宏的作用域难以控制等。因此，在使用宏时需要谨慎并遵循最佳实践，以避免潜在的问题。  
    ## 宏的本质  
    预处理器只不过是做了一个文本替换的工作而已  
    所有预处理命令都是以#开头   
    ### 常见的预指令处理   
    ![.](3.jpg)  
    1. #include  
        #include 指令用于将*其他文件的内容包含到当前文件中*。这是用于引入头文件的常见方式，使得程序可以重复利用其他文件中的函数声明、宏定义等信息。
    2. #define
    #define *用于创建宏定义*，将一个标识符或表达式定义为一个特定的代码片段。这种方式可以用于创建常量、简化代码或定义一段代码片段。
    3. #ifdef, #ifndef, #else, #endif
    条件编译指令用于根据条件来控制代码的编译。比如，#ifdef 用于检查某个宏*是否已经被定义*，#ifndef 用于检查某个宏*是否未被定义*，#else 和 #endif 则用于*定义条件的分支和结束。*
    4. #undef
    #undef 用于取消宏的定义，使得该宏可以重新定义或者在之后的代码中不再生效。
    5. #error
    #error 用于生成编译时错误信息，当预处理器遇到这个指令时，会停止编译并显示指定的错误消息。
    6. #pragma
    #pragma 用于向编译器传递特定的指令。这些指令通常用于控制编译器的行为，如优化选项、警告信息等。
    7. 文件包含保护指令
    	用于防止头文件被多次包含而导致的重定义错误。常见的方式是使用 #ifndef,         #define, #endif 来创建头文件的包含保护结构。
    
    宏中的小问题，加括号  
    ![.](4.png)
    #pragma 用于向编译器传递特定的指令。这些指令通常用于控制编译器的行为，如优化选项、警告信息等。
    7. 文件包含保护指令
    	用于防止头文件被多次包含而导致的重定义错误。常见的方式是使用 #ifndef, #define, #endif 来创建头文件的包含保护结构。


### C中构建面向对象系统  
??? abstract "C中构建面向对象系统" 
    
    ## 对象是什么  
    对象就是你的女朋友，你自己也是一个对象  
    对象就是实物，一种实物的一个个体  
    比如我是人类的一个个体  
    	
    	
    	
    	
    ***
    ## 定义  
    面向对象系统（Object-Oriented System）是一种程序设计范式，它使用对象和类的概念来组织和构建程序。这种方法的核心思想是_将数据和操作封装在一起，通过对象来表示现实世界中的实体，并允许这些对象相互交互。_  
    	
    面向对象的四大特征  
    1.抽象  
    抽象行为，抽象属性  
    属性： 一类事物的共同特征，比如人类的年龄，性别，编号  
    行为：吃饭，睡觉，跑步  
    2.封装  
    把抽象出来的属性和行为封装成一个类(结构体)  
    3.继承  
    把父类的属性和行为继承给子类，子类就拥有了父类的属性和行为  
    4.多态  
    	
    主要概念：  
    类（Class）：类是对象的模板或蓝图，描述了对象的属性（数据成员）和行为（成员函数）。比如，汽车类可能有属性如速度、颜色等，并且可能有方法如启动、加速等。  
    	
    对象（Object）：对象是类的实例，具有特定的属性和行为。例如，一辆特定的汽车可以看作是汽车类的一个对象实例。  
    	
    封装（Encapsulation）：封装是指将数据和操作封装在一个对象内部，_并对外部隐藏其内部实现细节。_只有通过对象提供的接口（公共方法）才能访问对象的状态。  
    	
    继承（Inheritance）：继承允许一个类（子类）继承另一个类（父类）的属性和行为。子类可以重用父类的功能，并且可以增加新的功能或修改已有功能。  
    	
    多态（Polymorphism）：多态性允许不同类的对象对同一消息做出不同的响应。即使这些对象所接收的消息相同，但由于不同类实现了相同的方法，它们可能会有不同的行为。  
    	
    为什么重要？  
    面向对象编程的优点在于它可以提高代码的可维护性、可扩展性和重用性。  
    通过封装数据和功能，对象可以隐藏其内部细节，使得代码更易于理解和修改。  
    继承和多态性使得代码更容易扩展和重用，减少了重复编写代码的工作量。  
    	
    在 C 语言中，并没有原生的面向对象特性，但可以使用一些技巧模拟面向对象的部分特性，如结构体和函数指针来模拟类和方法。  
    然而，如果你对面向对象的概念感兴趣，建议学习一些支持面向对象编程的语言，如 C++、Java 或 Python，它们提供了更直接和丰富的面向对象特性。  
    	
    ## c语言中实现面向对象的系统  
    在 C 语言中实现面向对象（Object-Oriented Programming, OOP）的系统需要使用一些技巧和约定，因为 C 本身并不直接支持_类、对象、继承等面向对象的概念。_然而，可以使用一些模拟方法来实现类似面向对象的设计。  
    	
    例子：
    属性：年龄，姓名  
    行为：说话  
    其他：输出自己的信息  
    ~~~
    include<stdio.h>
    include<malloc.h>
    include<string.h>
    include<
    typedef0 struct Girl{
    int age //年龄
    char name[20];
    
    }Girl;
    //注意：struct 里面不允许定义函数,所以拿到外面来
    Girl* createGirl();
    Girl* createGirlwithargs(int age,char name);
    void girl_print(Girl * pthis)
    {
    printf("%d %s",pthis ->age,pthis ->name);
    }
    
    int main()
    {
    Girl* emptyGirl = createGirl();
    Girl* yueyue = createGirlwithargs(int age,char name)(25;“月月”);
    }
    
    Girl* createGirl()
    {
    Girl* girl = calloc(1,sizeof(girl));
    if(！Girl）
    {
    return NULL;
    }
    return girl；
    }
    
    Girl* createGirlwithargs(int age,char name)
    {
    Girl *girl = createGirl();
    if(！Girl）
    {
    return NULL;
    }
    girl -> age =age
    girl -> name = name
    return girl；
    ~~~
    
    ### 注  
    typedef 是 C 语言中的一个关键字，用于创建新的类型别名。它允许程序员为现有的数据类型（如基本数据类型、结构体、指针等）定义一个新的、更具有描述性的名称。  
    	
    通过 typedef，可以为一个已存在的类型创建一个新的别名。这个别名可以让代码更易读、更易维护，并且提高了代码的可读性。它经常用于简化复杂的类型声明，特别是当你使用复杂的数据类型时。  
    	
    例如，在之前的代码中，我们使用了 typedef 来定义一个结构体类型别名 Object：  
    把标签放最后面使它成为一个新的类型  
    	
    其中pthis 是一个指针，指向Girl这个结构体  
    在 C 语言中，箭头操作符 -> 用于通过指向结构体或联合体的指针访问其成员。它的作用类似于使用点操作符 . 来访问结构体或联合体的成员，但是针对指针而不是实际的结构体或联合体本身。  
    最下面的操作里calloc和malloc一样都是分配空间的操作    
    	
    	
	
	
## ex20 调试宏  
??? abstract "测试宏"

    ## 调试  
    调试（Debugging）是指识别、定位和解决计算机程序或系统中出现的错误、故障或异常的过程。在软件开发中，程序员编写代码并进行测试，但有时代码可能会产生意外的行为，导致程序不按预期运行或出现错误。  
    	
    调试的目的是找出程序中的错误并加以修复，使程序能够按照预期的方式正常运行。这个过程通常涉及以下步骤：  
    	
    重现问题： 程序员首先要能够重现导致程序错误或异常行为的情况。这可能需要重新运行程序或者使用特定的输入数据。  
    	
    定位问题： 一旦问题被重现，程序员会使用调试工具或技术来定位问题所在。这可能涉及查看程序的代码、检查变量的值、跟踪代码执行路径等。  
    	
     识别错误： 确定问题的具体原因，这可能是由于逻辑错误、语法错误、内存问题、数据处理错误等。  	   
	
修复错误： 一旦问题被定位并识别，程序员会修改代码以解决问题，并进行进一步测试，以确保修改不会引入新的错误。  
	
验证和测试： 修改后的程序需要经过验证和测试，以确保问题已经解决，程序运行正常。  
	
调试是程序开发过程中不可或缺的一部分，因为即使经验丰富的开发人员也难以编写完全没有错误的程序。使用调试工具和技术可以帮助程序员更快速地定位和解决问题，提高代码质量和稳定性。调试也有助于开发人员更深入地理解程序的运行方式和行为。  
## 如何调试  
1.编译   
make ex10  
2.调试  
lldb ex10  
3.打断点  
break set--name:main
就会在main处打一个断点  
	
## 设计出来用于调试的宏  
C通过返回错误码或设置全局的errno值来解决这些问题，并且你需要检查这些值。这种机制可以检查现存的复杂代码中，你执行的东西是否发生错误。当你编写更多的C代码时，你应该按照下列模式：  
	
调用函数。  
如果返回值出现错误（每次都必须检查）。  
清理创建的所有资源。  
打印出所有可能有帮助的错误信息。  
这意味着对于每一个函数调用（是的，每个函数）你都可能需要多编写3~4行代码来确保它正常功能。这些还不包括清理你到目前创建的所有垃圾。如果你有10个不同的结构体，3个方式。和一个数据库链接，当你发现错误时你应该写额外的14行。  
***
~~~
#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
~~~
大佬写出来的宏，用于处理错误问题  
用的时候直接include dbg.h就行了  
这段代码是一个简单的调试宏和错误处理宏集合，它定义了一些宏来辅助程序员进行调试和错误处理。让我逐行解释这些代码：  
~~~
#ifndef __dbg_h__
#define __dbg_h__
~~~
#ifndef 检查是否定义了名为 __dbg_h__ 的宏。  
#define 定义了 __dbg_h__ 宏，以防止多次包含同一个头文件。  
	
#ifdef 检查是否定义了 NDEBUG 宏，如果定义了，则定义 debug(M, ...) 为空宏。  
如果未定义 NDEBUG，则定义 debug(M, ...) 宏为一个输出调试信息的函数。它使用 fprintf 函数将调试信息输出到标准错误流中（stderr），包括文件名、行号和格式化的消息内容。  
	
#define clean_errno() (errno == 0 ? "None" : strerror(errno))  
定义了一个 clean_errno() 宏，用于返回当前错误号的字符串描述。如果错误号为0（即没有错误），则返回字符串 "None"；否则，返回通过 strerror(errno) 得到的描述错误的字符串。  
接下来的一系列宏 log_err, log_warn, log_info, check, sentinel, check_mem, check_debug 使用了类似的模式，它们都是用来打印错误信息、检查条件、处理错误的宏。这些宏会在发生错误或者满足条件时，输出相应的信息，并跳转到错误处理代码段（通常是 goto error;）。  
	
这是一个使用调试宏的例子：  
~~~
#include "dbg.h"  // 引入包含调试宏的头文件

int main() {
    int x = 10;
    debug("x is: %d", x);  // 在程序中使用 debug 宏输出调试信息

    // ... 其他代码 ...

    return 0;
}
~~~
上面的代码中，#include "dbg.h" 将包含了定义了调试宏的头文件，使得 debug() 宏在代码中可用。在 main() 函数中，调用 debug() 宏并传入了一个格式化的调试信息字符串和相应的参数。在这个例子中，debug() 宏会在调试模式下输出带有文件名、行号和调试信息的内容。  
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
	