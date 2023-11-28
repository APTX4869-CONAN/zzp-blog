# 缺失的一课-精通工具
 __有哪些需要要精通的工具__  
	
主要有:命令行与shell工具  
	
版本控制   
	
文本编辑  
	
远程服务器  	
	

查找文件  
	
虚拟机  
	

安全  
	

***
## shell是什么:文字接口  
shell脚本  
#和$都是shell提示符，#普通用户，$超级用户  
## bash  
在bash中为变量赋值的语法是foo=bar  
注意:foo = bar （如果使用空格隔开）是不能正确工作的，因为解释器会调用程序foo 并将 = 和 bar作为参数。 总的来说，在shell脚本中使用空格会起到分割参数的作用，有时候可能会造成混淆，请务必多加检查。  
Bash中的字符串通过' 和 "分隔符来定义，但是它们的含义并不相同。以'定义的字符串为原义字符串，其中的变量不会被转义，而 "定义的字符串会将变量值进行替换。   
	
用双引号打印bar，用单引号打印foo  
foo=bar  
echo "$foo"  
#打印 bar  
echo '$foo'  
#打印 $foo  
bash也支持if, case, while 和 for和函数  
## 表示参数的指令  
$0 - 脚本名  
$1 到 $9 - 脚本的参数。 $1 是第一个参数，依此类推。  
$@ - 所有参数  
$# - 参数个数  
$? - 前一个命令的返回值  
$$ - 当前脚本的进程识别码   
!! - 完整的上一条命令，包括参数。常见应用：当你因为权限不足执行命令失败时，可以使用 sudo !!再尝试一次。  
$_ - 上一条命令的最后一个参数。如果你正在使用的是交互式 shell，你可以通过按下 Esc 之后键入 . 来获取这个值。  
STDOUT来返回输出值  
STDERR 来返回错误及错误码  
可以和&&（与操作符）和 ||（或操作符）搭配使用  
注:程序 ture 的返回值一直为0，而 false 返回值为1，于是就有以下东西:(#中是输出的东西 )  
	
false || echo "Oops, fail"  
#Oops,fail  
	
true || echo "Will not be printed"  
#
	
true && echo "Things went well"  
#Things went well  
	
false && echo "Will not be printed"  
#
	
false ; echo "This will always run"  
#This will always run  
	
rg命令  
ripgrep (rg) ，因为它速度快，而且用法非常符合直觉。例子如下：  
	
#查找所有使用了 requests 库的文件  
rg -t py 'import requests'  
#查找所有没有写 shebang 的文件（包含隐藏文件）  
rg -u --files-without-match "^#!"  
#查找所有的foo字符串，并打印其之后的5行  
rg foo -A 5  
#打印匹配的统计信息（匹配的行和文件的数量）  
rg --stats PATTERN  
	
查找 shell 命令  
按ctrl R回溯记录  
	
跳转  
例如， 如果您经常访问/home/user/files/cool_project 目录，那么可以直接使用 z cool 跳转到该目录。S  
对于 autojump(模糊匹配你想要的目录)，则使用j cool代替即可  
	
##  数据整理  
	
***