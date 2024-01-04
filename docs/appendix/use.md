这里的目的是# 理解与用法  
!!! example "前言"

    只有会写代码，会使用，你才能看懂，才能理解，当函数指针，指针函数，结构体，数组，函数，在一起的时候，就是头大的时候。
***
## 函数用法  
??? abstract "函数用法"

    函数包括函数头和函数体两部分  
    ~~~
    int add(int a,int b)//函数头
    {            //函数体
    int sum = a+b;
    return sum;
    }
    ~~~
    1. 函数头包括函数的返回类型，函数名，和可能的参数列表  
    int ：返回类型  
    add  : 函数名  
    (int a,int b)  :a,和b是参数   
    2. 函数体包括要执行的实际操作  
    ### 函数调用  
    在下面可以调用函数  
    int result = add(3,5);  
    add即是这个函数，3，5是输入的两个参数，将执行函数体的内容  


​	
***
## 指针用法  
??? abstract "指针用法"

    1. 声明指针  
    	如int  \*ptr 声明了一个指向整数的指针  
    	
    2. 获取变量的地址  
    	使用&获得地址  
    	int \*ptr = &num  
    	
    3. 访问指针指向的值(引用)  
    	比如 int value = \*ptr  
    	这会访问指针指向地址的值，所以可以把\*想象成打开地址  


​	
​	
***
## 指针数组用法  
??? abstract "指针数组用法"

    特别容易和指针搞混淆  
    如：char \*name 和 char\*name[]  
    就差一个数组，意义却完全不同  
    第一个代表指针名叫name 第二个代表数组名叫name,数组中的所有元素是指针  


​	
***
## 函数指针的用法  
??? abstract "函数指针的用法"

    和函数的用法不要搞混了   
    int (\*func)(int,int)这是函数指针  
    int func(int,int) 这是函数  
    函数指针的声明是声明一个指针，如果函数中有两个参数，那在函数指针中也要后面一个括号表示一下  
    然后func = &sum 或者 func = sum 都可以  
    ### 通过函数指针调用函数  
    int result = (\*func)(3.5) 和 int result =func(3,5)都可以  
    和直接用函数 int result = sum(3,5)的效果一样，这三者等同  
    ## 为什么用函数指针而不直接用函数：
    函数指针可以用于动态地选择要调用的函数，或者作为参数传递给其他函数，以便在运行时选择不同的行为。函数本身是代码块，被调用时执行其中的指令，完成特定任务。  
    理解：函数指针能更灵活的使用，甚至把函数当做变量使用  

!!! tip "注"

    函数指针可以用于回调函数当中
***
## 结构体用法  
??? abstract "结构体用法"

    1. 声明结构体  
    ~~~
    struct student {
    int x;
    int y;
    };
    ~~~
    结构体顾名思义就是把一堆东西弄到一起成为一个整体  
    student 是结构体的名字  
    x,y 是结构体的成员  
    	
    2. 创造结构体变量，（结构体变量是根据该结构体类型创造的具体实例）
    ~~~
    struct Student student1
    ~~~
    student1就是student 这个结构体的一个具体实例  
    	
    3. 访问结构体成员  
    用符号.(点)来访问结构体成员  
    student1.x = 10;即给student1 中的x赋值为10  
    4. 或者可以初始化  
    	struct student student1 = {5,15};  
    	给x,y一个初始化的值  


​    	
***
## 指针  
??? abstract "指针"

    指针指向的是变量的地址，正确用法是 int \*name = &num 而不是int \*name = num
    后面那种写法是不合法的，因为这样会把num的数值赋值给name指针，这毫无意义  

***
## typdef用法
??? abstract "typdef用法"

    typedef可以为函数指针创造一个别名，起到简化代码的作用
    一个typedef的用法：
    ~~~
    // 假设有一个函数原型为 int add(int a, int b);
    int add(int a, int b) {
        return a + b;
    }
    
    // 使用 typedef 定义函数指针的别名
    typedef int (*Operation)(int, int);
    
    int main() {
        // 使用 Operation 别名声明函数指针变量
        Operation operationPtr;
    
        // 指向 add 函数的指针赋值给 operationPtr
        operationPtr = add;
    
        int result = operationPtr(5, 3); // 调用函数指针
        printf("Result: %d\n", result);
    
        return 0;
    }
    ~~~    
    我的理解：typedef了一个函数指针Operation ,Operation只相当于一个模板，而operationPtr声明了一个函数指针
     operationPtr = add;这步操作把函数add的值赋值给了operationPtr这个函数指针

## 回调函数
??? note "回调函数的作用"

    首先我在想，回调函数究竟有什么作用。
    我现在水平有限，能比较理解的是事件处理：比如，在图形用户界面（GUI）中，当用户点击按钮时可能需要执行某些操作。这时可以注册一个回调函数，使得当按钮被点击时，这个回调函数被自动调用。这种机制让代码能够响应事件，而无需在每次事件发生时都重复相同的代码。


​	
??? abstract "回调函数"

    首先弄清楚，回调函数的用法:
    ~~~
        #include <stdio.h>
    
      定义回调函数类型
    typedef void (*CallbackFunction)(int);
    
    // 函数接受回调函数作为参数
    void performOperation(int x, int y, CallbackFunction callback) {
        int result = x + y;
        printf("The result is: %d\n", result);
    
        // 调用回调函数，将结果作为参数传递
        callback(result);
    }
    
    // 回调函数示例
    void displayResult(int result) {
        printf("The result received in the callback function is: %d\n",     result);
    }
    
    int main() {
        int a = 10, b = 20;
    
        // 调用 performOperation，并传递回调函数 displayResult
        performOperation(a, b, displayResult);//performOperation中的三个数据分别对应前面的里面的
    
        return 0;
    }
    ~~~
    我的理解：callback(result);这个操作实际上是将这个结果通知给外部，让外部的代码能够处理这个结果。