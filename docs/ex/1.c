#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name_1[50];
    float GPA;
};
//定义了一个学生的结构体



int jiecheng(int n)//计算阶乘的函数
{
        int x = 1;
        for (int i = 1; i <= n; i++) {
                x *= i;
        }
        return x;
}
//计算阶乘的函数


//一个人的结构体，
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

//设置了一个名为Person_create的函数，注：结构体是一种类型
struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

//设置了一个销毁函数，来销毁Person结构体
void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}


//设置了一个打印人信息的函数Person_print函数
void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}



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
    printf("puts相关代码:\n");
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


    printf("printf相关代码:\n");
    printf("Hello World from printf\n");
    //用了printf格式化输出hello world
    


    	printf("变量类型相关代码:\n");
 	int zzp_grade = 100;
	float  zzp_IQ = 250.345f;
	double zzp_age = 1.1234;
	char zzp_blood_type = 'A';
	char first_name[] = "Monkey";
	char last_name[] = "Luffy"; 
	//变量类型
	
	

	//类型的简单运算
	printf("int %d\n",zzp_grade);
	printf("float %f\n",zzp_IQ);
	printf("double %f\n",zzp_age);
	printf("char %c\n",zzp_blood_type);
	printf("char %s\n",first_name);
	printf("char %s\n",last_name);

	int num1 = 100;
	double num2 = 1.2;

	long num3 = 1L* 1024L*1024L*1024L;
	printf("long %ld\n",num3);

	double num4 = num1*num2;
	printf("100*1.2 =%f.\n",num4);

	double num5 = num4 / num3;
	printf("除法%e\n",num5);

	//无字符乘以一个数
	char num_nul = '\0';
	int percentage = zzp_grade * num_nul;
	printf("无字符乘以一个数结果%d\n",percentage);


	printf("sizeof相关代码:\n");
	printf("The size of int is %ld\n",sizeof(int));
	//sizeof的应用
	

	int numbers[5];//声明一个数组
	
	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;
	numbers[3] = 40;
	numbers[4] = 50;

	
	printf("数组相关代码:\n");
	printf("数组1第个数为：%d\n",numbers[0]);
	printf("数组2第个数为：%d\n",numbers[1]);
	printf("数组3第个数为：%d\n",numbers[2]);
	printf("数组4第个数为：%d\n",numbers[3]);
	printf("数组5第个数为：%d\n",numbers[4]);
	
	
	char name[4] ;
	name[0] = 'z';
	name[1] = 'z';
	name[2] = 'p';
	name[3] = '\0';
	

	printf("字符数组代码：\n");
	printf("字符数组单个输出: %c %c %c %c\n",
	name[0], name[1],name[2], name[3]);
	printf("字符串输出: %s\n", name);
	
	printf("for循环：\n");
	
	char *names[] = {
		"Tom",
		"Jerry",
		"Dog",
	};

	for(int i = 0; i<3; i++)
	{
	printf("用for循环遍历数组%d：%s\n",i+1,names[i]);
	}

	printf("While循环：\n");
	printf("用While循环输出1-5\n");
	int i2 = 1;
	while (i2 <= 5){
	printf("%d\n",i2);
	i2 ++;
	}


	printf("if,else相关代码：\n");
	int i3 =10;
	if(i3 > 0) {
	printf("10是正数\n");
	}
	else {
	printf("10是负数\n");
	}
	printf("switch相关代码：");
    int choice;

    printf("请输入1-3中的一个数: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("你输入了1\n");
            break;
        case 2:
            printf("你输入了2\n");
            break;
        case 3:
            printf("你输入了3\n");
            break;
        default:
            printf("你的输入不合法\n");
    }
	printf("自定义函数相关代码:\n");	
	int i4 = 0;
	printf("一个自定义阶乘函数的演示\n");
	printf("请输入一个整数m：\n");
	scanf("%d", &i4);
	int result = jiecheng(i4);
	printf("%d的阶乘是：%d\n",i4 ,result);


	printf("指针相关代码：\n");
	printf("通过指针遍历数组\n");
	int agess[] = {22, 100, 23, 31, 1000};
	char *namess[] = {
        "Ahri", "Brand",
        "Caitlyn", "Darius", "Evelynn"
    };
	int *cur_age = agess;
	char **cur_name = namess;

	int count = sizeof(agess) / sizeof(int);
	int i = 0;

	for(i = 0; i < count; i++) {
        printf("char：%s,int： %d \n",
                *(cur_name+i), *(cur_age+i));
    }

	printf("结构体相关代码：\n");
	struct Student student1;
	printf("设置了一个学生的结构体\n");
    // 初始化
    student1.id = 123;
    strcpy(student1.name_1, "Ezreal"); // 使用 strcpy 函数将字符串复制到字符数组中
    student1.GPA = 3.8;

    // 访问结构体成员并打印信息
    printf("学生ID: %d\n", student1.id);
    printf("学生Name: %s\n", student1.name_1);
    printf("学生GPA: %.2f\n", student1.GPA);	
	
	//结构体的指针
	printf("结构体，用了malloc,assert,strdup，strcpy\n");
	struct Person *Garen = Person_create(
            "Garen", 29, 92, 190);

    printf("用结构体输出:\n");
    Person_print(Garen);//打印

    	Person_destroy(Garen);//销毁，防止内存泄漏

	
    return 0;
	
}
