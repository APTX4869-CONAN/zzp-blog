# C语言代码记录  
## 得到数组中元素的数量  
~~~
int count = sizeof(ages) / sizeof(int);
~~~
这行代码计算了数组 ages 中元素的数量。通过使用 sizeof 运算符，将 ages 数组的总字节数除以 int 类型的字节数，得到数组中元素的数量。  
	
***


​	
​	
## 从1到10用i++,用来遍历数组  
~~~
#include <stdio.h>

int main() {
    // 声明一个字符串指针数组，包含三个字符串的地址
    char *names[] = {
        "Alice",
        "Bob",
        "Charlie"
    };

    // 打印数组中的字符串
    for (int i = 0; i < 3; ++i) {
        printf("Name %d: %s\n", i, names[i]);
    }

    return 0;
}
~~~
会输出：  
~~~
Name 0: Alice
Name 1: Bob
Name 2: Charlie
~~~


***


​	
​	
## 字符串指针数组  
~~~
#include <stdio.h>

int main() {
    // 声明一个字符串指针数组，包含三个字符串的地址
    char *names[] = {
        "Alice",
        "Bob",
        "Charlie"
    };

~~~
怎么写一个指向字符串指针数组的指针，参见：  
[ex15](https://aptx4869-conan.github.io/zzp-blog/sundries/9/)  
	
	
	
	
	

***
## 阶乘  
用到<mark>\*= </mark>这个东西  
~~~
fact *= i 是一个简写形式，表示将变量 fact 乘以变量 i，并将结果赋值给变量 fact。

这种写法是 C 语言中的复合赋值运算符，它将乘法操作和赋值操作合并在一起。具体来说，fact *= i 的含义与 fact = fact * i 是相同的。
~~~
自己写的一个函数（用for循环实现了阶乘，并且计算了 m!/（m-n）！）
~~~
//用函数实现m!/（m-n）！
#include<stdio.h>
int jie_cheng(int n)//计算阶乘的函数
{
	int x = 1;
	for (int i = 1; i <= n; i++) {
		x *= i;
	}
	return x;
}
int main()
{
	int m;
	int n;
	printf("请输入两个数m和n");
	scanf_s("%d,%d", m, n);
	int result = jie_cheng(m) / jie_cheng(m - n);
	printf("结果是：%d\n", result);

	return 0;
}
~~~
实现阶乘很简单  
就是用了一个函数，里面用了一个for循环的++，只不过函数主体是x\*=1 ，这是一个实现阶乘的东西  