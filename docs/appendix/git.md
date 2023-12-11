# git  
Git是一个免费，开源的分布式版本管理控制器  
可以清楚记录软件版本的变化，可以轻松退回以前的版本   
速度和性能很好  
	
为什么要用Git:git的用处就是当你的程序出错了，你能够退回到之前的版本， 储存以前的数据，防 止你的失误导致整个系统无法使用  
	
## git的使用  
### 配置
git confit --global user.name "zhang San" 用户名  
git confit --global user.email "..." 邮箱  
	
### 新建  
直接 git init 新建一个git 库  
git log 查看当前所有的存档  
	
### 工作区，暂存区，版本区  
	
![这是一个图片](./3.jpg)  
HEAD是里面的一个指针
	
### 存档  
git status 查看是否有新的文件未被跟踪，就是看工作区是否干净  
git add .. 将文件加入列表，相当于是加入了暂存区  
git commit -m '版本名‘ 创建一个版本  
	
### 版本回退  
git reset --hard b87c  
b87c是code 的前缀
hard不能随便用，因为在回退版本之后的版本都将被删除
	
### 撤销  
情况1. git checkout -- code,txt,把工作区的东西撤销，同时也可以撤销回来    
情况2. 删除暂存区的东西 git reset HRAD code.txt  
情况3. 存到版本区里了 只能回退了  
	
### 对比文件不同  
对比文件和库里的文件有哪些不同 git diff 代码 -- 代码  
出现了+-，代表两条代码的不同  
	
	
### 删除文件  
直接用rm 1.txt  
可以用 git checkout -- 1.txt 让它回来  

### 分支  
分支相当于平行宇宙  
HEAD 本质上是指向master分支 master 才指向最新版本  
创建一个新的分支就是创建一个新的指针，让HEAD指向它，比如dev分支  
此时再提交就是针对dev了，跟master没有关系了  
git branch 可以查看所有分支（指针）  
git branch 名字 #创建一个新的分支  
git checkout 名字 #跳转到指定分支  
git checkout -b dev 创建并切换到另一个分支里面  
合并分支并不总会成功，要解决冲突  
