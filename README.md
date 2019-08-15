## T1

只需要基础的c++编译环境即可运行

Px.csv Py.csv为 分别为32个单元4种移相器配置在(AZ=10,EL=5)振动方程矢量形式的信号幅度在x轴，y轴分解后的结果

Tx.csv Ty.csv为 分别为32个单元4种移相器配置在(AZ=10,EL=5)振动方程矢量形式的信号幅度在x轴，y轴分解后的结果

cin1.csv cin2.csv为32个单元4种移相器配置的修正误差后的参数

------

+ 包裹需要读入Px.csv Py.csv Tx.csv Ty.csv，输出结果为outBG.txt

+ 仓库需要读入Px.csv Py.csv outBG.txt，输出结果为outCK.txt

+ 旁瓣电平需要读入cin1.csv cin2.csv outCK.txt 输出结果为outPBDP.txt    为对应的仓库编号和改配置列表对应的旁瓣电平。

------

考虑到c++运算中存在着误差，最终(AZ=10,EL=10) 和 (AZ=10,EL=5) 方向的合成功率由绘图目录下drawConfig.m文件求出，运行需要读入Phase.mat和raw_data.mat文件。

其整理结果可见：配置列表.csv 配置列表.xlsx 选取配置列表合成功率.txt




## T2

T2贪婪算法 中只需要基础的c++环境即可运行。其输出结果csv为每个点在该配置下的功率大小，单位dBm。

txt为波束个数不同时的配置列表，其格式为： 单元编号+移相器配置编号 。

T2优化算法 需要Google:: ceres 运行库的支持。
其输入为60位lambda的值，输出也是60位lambda的值，并且有每个点功率的csv文件。

obj model 中为展示中所使用的三维模型以及贴图，可以使用Meshlab打开obj文件,注意不要有中文路径。(不是matlab)

曲面拟合 中输入为csv文件为每个点在该配置下的功率大小，输出为 obj格式的曲面模型。


微波问题二中，T2 波束个数12 凹坑大小1.93.txt T2 波束个数15 凹坑大小1.63.txt
分别为波束个数不同时的配置列表，其格式为： 单元编号+移相器配置编号 
没有提及的单元即为未使用。 我们只给出了每个单元被使用的次数，对于每个波束中使用哪些单元不做说明。
可以根据每个单元使用的次数自行选择每个波束中使用哪些单元，只需要满足使用次数即可。
csv文件为每个点在该配置下的功率大小，单位dBm。



## T3

文件运行需要支持bits头文件

3.cpp 用于生成原始图

check.cpp 执行换边操作

random.cpp 用于稳定性检验生成数据


dis.txt rate.txt volume.txt 为读入数据

origin.txt 为3.cpp的输出数据

new.txt 为check.cpp的输出数据

输出表明边，距离，总流量，每种传输格式的选择情况以及总花费

最后一行为价值函数

## T4

文件运行需要支持bits头文件

4.cpp 用于生成原始图
check.cpp 执行换边操作

dis.txt rate.txt volume.txt 为读入数据 

originT4.txt 为4.cpp的输出数据

newT4.txt 为check.cpp的输出数据


输出表明边，距离，总流量，每种传输格式的选择情况以及总花费

最后一行为价值函数

## 绘图

#### /data

用于T1 T2绘图的各种数据

#### /src

用于T1 T2绘图的代码
