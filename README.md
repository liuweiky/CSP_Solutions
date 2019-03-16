# My_CCF-CSP_Answer
记录我在解 CCF - CSP 时遇到的一些问题以及总结的经验。

## 201609-4 交通规划

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201609/20160904/main.cpp)

### 解题思路

Dijkstra + 最小生成树。

注意使用边链表存储图时，快速获取最短路上任意一条边的长度的方式：https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201609/20160904/main.cpp#L73,  https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201609/20160904/main.cpp#L112

为了取得最小总长度，Dijkstra 算法在遇到相同长度的路径时，应选择 ```graph[u][j]``` 最小的 https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201609/20160904/main.cpp#L75 （画个图就清楚了）

## 201612-1 中间数

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201612/20161201/main.cpp)

### 解题思路

两趟遍历。

## 201612-2 工资计算

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201612/20161202/main.cpp)

### 解题思路

正向求解难，反向顺推易。

## 201612-4 压缩编码

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201612/20161204/main.cpp)

### 解题思路

石子相邻合并的动态规划问题。

## 201712-4 行车路线

[C++ (90/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201712/20171204/main.cpp)

### 解题思路

改变 dijkstra 最短路路径长度求解方法即可，有 20 分没拿到，暂不知原因。

通过将 int 改为 long long 又多得了 10 分。

## 201709-4 通信网络

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201709/20170904/main.cpp)

### 解题思路

正向、反向分别进行深搜，检查是否能够全部访问，若能， count++。

刚开始使用 int 二维数组，60分， 超时。改用邻接 vector 数组，100 分。

## 201709-5 除法

[C++ (50/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201709/20170905/main-50.cpp)

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201709/20170905/main.cpp)

### 解题思路

使用[树状数组](https://github.com/Heliovic/AlgorithmSet/blob/master/BinaryIndexedTree/main.cpp)。

为避免超时，此题要注意的点非常多。

[数值范围够用时，不用 long long，而用 int 来节省运算时间](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201709/20170905/main.cpp#L8)

[树状数组更新时，若 delta 为零，无需任何更新](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201709/20170905/main.cpp#L58, https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201709/20170905/main.cpp#L62)

## 201803-1 跳一跳

[Java (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180301/Main.java)

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180301/main.cpp)

### 解题思路

简单模拟。

## 201803-2 碰撞的小球

[Java (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180302/Main.java)

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180302/main.cpp)

### 解题思路

简单模拟。

## 201803-3 URL映射

[Java (60/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180303/Main.java)

### 解题思路

字符串处理

## 201803-4 棋局评估

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180304/main.cpp)

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180304/main-new.cpp)

### 解题思路

博弈搜索。

* 对于 Alice，她想获得高分。因此需要遍历当前棋盘下每一种落子方案，选择使得自己得到较高的分数。

* 对于 Bob，要抑制 Alice 获得高分，就要从每一种落子方案中选择使得 Alice 得分最低的那一个。

* 注意，在选择落子之前，要检查是否已经决出胜负或平局。

* ~~有 10 分没拿到，暂时不知为何。~~ 这 10 分注意区分**平局**和**以最后一子取胜**的情况即可！

> 20190315：精简了代码

## 201809-1 卖菜

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201809/20180901/main.cpp)

## 201809-2 买菜

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201809/20180902/main.cpp)

## 201809-4 再卖菜

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201809/20180904/main.cpp)

### 解题思路

回溯。 ~~运行超时。~~ [记忆化搜索](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201809/20180904/main.cpp#L24)解决运行超时。

## 201812-1 小明上学

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201812/20181201/main.cpp)

### 解题思路

简单模拟。

## 201812-2 小明放学

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201812/20181202/main.cpp)

### 解题思路

简单模拟。

## 201812-3 CIDR合并

[C++ (90/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201812/20181203/main.cpp)

### 解题思路

复杂模拟 + 字符串处理。运行超时。

## 201812-4 数据中心

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201812/20181204/main.cpp)

### 解题思路

Kruskal + 并查集求最小生成树。
