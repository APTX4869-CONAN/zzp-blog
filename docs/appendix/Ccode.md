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