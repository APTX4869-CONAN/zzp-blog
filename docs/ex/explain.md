# 解释  
~~~
FILE *filePointer;：这行声明了一个指向 FILE 类型的指针变量 filePointer。FILE 类型是C语言中用于处理文件的结构体类型，filePointer 将用于指向文件流。  
~~~

~~~
filePointer = fopen("output.txt", "w");：这行代码打开一个名为 "output.txt" 的文件以便写入（写入模式为 "w"）。fopen() 是一个C标准库函数，用于打开文件并返回一个文件指针。如果成功打开文件，filePointer 将指向这个文件流；否则，如果文件无法打开，filePointer 将为 NULL。
~~~

~~~
putchar('c\n')是不行的
只能
putchar('c')
putcahr('\n')
~~~

