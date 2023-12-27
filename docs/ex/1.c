#include<stdio.h>

int main()
{
	FILE *file1;
    char data[] = "Hello, World!";
    char ch = 'A';

    // 打开文件以便写入
    file1 = fopen("output.txt", "w");

    if (file1 == NULL) {
        printf("无法打开文件\n");
        return -1;
    }

    fputc(ch,file1);
    //fputc是将单个字符ch写入文件

    fputs(data,file1);
    //使用fputs将字符串data中的Hello world写入

    putc('B',file1);

   //putc用于输出单个字符

    putchar('c');
    putchar('\n');
    //purchar用于标准输出单个字符

    puts("Hello from puts");
    putchar('\n');
    //使用puts将字符串标准输出

    fclose(file1);

    return 0;
}
