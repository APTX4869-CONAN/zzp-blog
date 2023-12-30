#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include<errno.h>
#include "dbg.h"
#include <stdarg.h>

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
//下面是数据库相关代码
#define MAX_DATA 512// 定义了最大数据长度为 512
#define MAX_ROWS 100// 定义了最大行数为 100

struct Address {//用于表示一个地址，包括 id、set（标记记录是否已设置）、name 和 email。
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {//包含了一个 Address 结构体数组，用于表示整个数据库。
    struct Address rows[MAX_ROWS];
};

struct Connection {// 包含一个文件指针和指向数据库的指针。
    FILE *file;
    struct Database *db;
};

void die(const char *message)// 一个辅助函数，用于打印错误信息并退出程序。
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)//打印地址信息。
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)//加载数据库。
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{//打开数据库连接。
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error");

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file");

    return conn;
}

void Database_close(struct Connection *conn)
{//关闭数据库连接
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{//将数据库写入文件。
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.");

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{//创建数据库。
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{// 设置数据库记录。
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first");

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    if(!res) die("Name copy failed");

    res = strncpy(addr->email, email, MAX_DATA);
    if(!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{//获取数据库记录。
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{//删除数据库记录。
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{//列出数据库记录
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}
//上面是数据库相关代码

//下面函数指针相关代码
// 定义一个错误处理函数 die，用于输出错误信息并退出程序
void die1(const char *message)
{
    if(errno) {
        perror(message); // 输出错误信息
    } else {
        printf("ERROR: %s\n", message); // 输出错误信息
    }
    exit(1); // 退出程序
}

// 定义一个类型别名，用于表示一个指向函数的指针
typedef int (*compare_cb)(int a, int b);

// 冒泡排序函数，使用函数指针 compare_cb 进行排序
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    // 声明一些变量
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int)); // 分配内存来存放排序后的数组

    // 如果分配内存失败，调用 die 函数并打印错误信息
    if (!target) die("Memory error.");

    // 将 numbers 数组中的数据复制到 target 数组中
    memcpy(target, numbers, count * sizeof(int));

    // 冒泡排序算法
    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target; // 返回排序后的数组指针
}

// 比较函数，按照升序排序
int sorted_order(int a, int b)
{
    return a - b;
}

// 比较函数，按照降序排序
int reverse_order(int a, int b)
{
    return b - a;
}

// 比较函数，按照奇偶性排序
int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

// 用于测试排序的函数，执行排序并打印结果
void test_sorting(int *numbers, int count1, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count1, cmp); // 使用指定的比较函数排序数组

    // 如果排序失败，调用 die 函数并打印错误信息
    if (!sorted) die("Failed to sort as requested.");

    // 打印排序后的数组
    for (i = 0; i < count1; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted); // 释放排序后的数组内存
}
//上面函数指针相关代码

//下面是枚举相关代码
enum Weekday {
    SUNDAY,     // 默认为 0
    MONDAY,     // 默认为 1
    TUESDAY,    // 默认为 2
    WEDNESDAY,  // 默认为 3
    THURSDAY,   // 默认为 4
    FRIDAY,     // 默认为 5
    SATURDAY    // 默认为 6
};
//上面是枚举相关代码


//下面是fscanf相关代码
#define MAX_DATA_2 100

// 定义枚举表示不同的眼睛颜色
typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, OTHER_EYES
} EyeColor;

// 用于表示眼睛颜色的字符串数组
const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

// 定义一个结构体表示一个人
typedef struct Person_2 {
    int age;
    char first_name[MAX_DATA_2];
    char last_name[MAX_DATA_2];
    EyeColor eyes;
    float income;
} Person_2;
//上面是fscanf相关代码


//下面是变参函数相关代码
#define MAX_DATA_3 100

int read_string(char **out_string, int max_buffer)
{
    *out_string = calloc(1, max_buffer + 1);
    check_mem(*out_string);

    char *result = fgets(*out_string, max_buffer, stdin);
    check(result != NULL, "Input error.");

    return 0;

error:
    if(*out_string) free(*out_string);
    *out_string = NULL;
    return -1;
}

int read_int(int *out_int)
{
    char *input = NULL;
    int rc_2 = read_string(&input, MAX_DATA);
    check(rc_2 == 0, "Failed to read number.");

    *out_int = atoi(input);

    free(input);
    return 0;

error:
    if(input) free(input);
    return -1;
}

int read_scan(const char *fmt, ...)
{
    int i = 0;
    int rc_2 = 0;
    int *out_int = NULL;
    char *out_char = NULL;
    char **out_string = NULL;
    int max_buffer = 0;

    va_list argp;
    va_start(argp, fmt);

    for(i = 0; fmt[i] != '\0'; i++) {
        if(fmt[i] == '%') {
            i++;
            switch(fmt[i]) {
                case '\0':
                    sentinel("Invalid format, you ended with %%.");
                    break;

                case 'd':
                    out_int = va_arg(argp, int *);
                    rc_2 = read_int(out_int);
                    check(rc_2 == 0, "Failed to read int.");
                    break;

                case 'c':
                    out_char = va_arg(argp, char *);
                    *out_char = fgetc(stdin);
                    break;

                case 's':
                    max_buffer = va_arg(argp, int);
                    out_string = va_arg(argp, char **);
                    rc_2 = read_string(out_string, max_buffer);
                    check(rc_2 == 0, "Failed to read string.");
                    break;

                default:
                    sentinel("Invalid format.");
            }
        } else {
            fgetc(stdin);
        }

        check(!feof(stdin) && !ferror(stdin), "Input error.");
    }

    va_end(argp);
    return 0;

error:
    va_end(argp);
    return -1;
}

//上面是变参函数相关代码












int main(int argc, char *argv[])
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

	
	printf("函数指针相关代码：\n");
	printf("使用回调函数和函数指针实现数字排序\n");
	printf("输入5个数字，便会按顺序，逆序，奇偶排序\n");
    	   int count_2 = 5; // 读取 5 个数
    int i5 = 0;
    int numbers_2[5]; // 创建数组以存储 5 个数

    // 从标准输入中读取 5 个数
    printf("请输入五个数字: \n");
    for(i5 = 0; i5 < count_2; i5++) {
        scanf("%d", &numbers_2[i5]);
    }

    	// 分别使用三种不同的排序方式测试排序函数
    	test_sorting(numbers_2, count_2, sorted_order);
    	test_sorting(numbers_2, count_2, reverse_order);
    	test_sorting(numbers_2, count_2, strange_order);

	
	//枚举相关代码
	printf("枚举相关代码：\n");
	// 使用枚举常量
    enum Weekday today = SATURDAY;
    
    // 打印今天是星期几
    switch (today) {
        case SUNDAY:
            printf("Today is Sunday.\n");
            break;
        case MONDAY:
            printf("Today is Monday.\n");
            break;
        case TUESDAY:
            printf("Today is Tuesday.\n");
            break;
        case WEDNESDAY:
            printf("Today is Wednesday.\n");
            break;
        case THURSDAY:
            printf("Today is Thursday.\n");
            break;
        case FRIDAY:
            printf("Today is Friday.\n");
            break;
        case SATURDAY:
            printf("Today is Saturday.\n");
            break;
        default:
            printf("Unknown day.\n");
            break;
    }

	
    	printf("输入输出和文件相关代码：\n");
	Person_2 you = {.age = 0}; // 初始化一个 Person 结构体实例 'you'，将年龄设置为 0
    int i6 = 0;
    char *in = NULL;
    in = fgets(you.first_name, MAX_DATA_2-1, stdin);
    check(in != NULL, "Failed to read first name.");
    // 询问用户的姓氏
    printf("你的名字? \n");
    in = fgets(you.last_name, MAX_DATA_2-1, stdin); // 读取用户输入的姓氏
    check(in != NULL, "Failed to read last name."); // 检查是否成功读取输入

    // 询问用户的年龄
    printf("你的年龄? \n");
    int rc = fscanf(stdin, "%d", &you.age); // 读取用户输入的年龄
    check(rc > 0, "You have to enter a number."); // 检查是否成功读取输入

    // 询问用户的眼睛颜色选择
    printf("你眼睛的颜色是哪种：\n");
    for(i6 = 0; i6 <= OTHER_EYES; i6++) {
        printf("%d) %s\n", i6+1, EYE_COLOR_NAMES[i6]); // 显示眼睛颜色选项
    }
    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes); // 读取用户输入的眼睛颜色选择
    check(rc > 0, "You have to enter a number."); // 检查是否成功读取输入

    you.eyes = eyes - 1; // 在 'you' 的 Person 结构中设置用户选择的眼睛颜色
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option."); // 检查是否为有效的眼睛颜色选项

    // 询问用户的时薪
    printf("你的时薪？ ");
    rc = fscanf(stdin, "%f", &you.income); // 读取用户输入的时薪

	check(rc > 0, "Enter a floating point number.");

    printf("----- RESULTS -----\n");

    // 显示关于用户的收集信息
    printf("Name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);








	printf("变参函数相关代码：");
	    char *first_name_2 = NULL;
    char initial = ' ';
    char *last_name_2 = NULL;
    int age_2 = 0;

    
    printf("\n");
    int rc_2 = read_scan("%s", MAX_DATA_3, &first_name_2);
    check(rc_2 == 0, "Failed first name.");

    printf("你的名字? ");
    rc_2 = read_scan("%s", MAX_DATA_3, &last_name_2);
    check(rc_2 == 0, "Failed last name.");

    printf("你几岁? ");
    rc_2 = read_scan("%d", &age_2);

    printf("---- RESULTS ----\n");
    printf("\n");
    printf("Name: %s", last_name_2);
    printf("Age: %d\n", age_2);

    free(first_name_2);
    free(last_name_2);


	
    	return 0;
	
	error:
    return -1;	
}
