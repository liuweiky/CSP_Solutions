# My_CCF-CSP_Answer
记录我在解 CCF - CSP 时遇到的一些问题以及总结的经验。

## 201712-4 行车路线

[C++ (90/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201712/20171204/main.cpp)

### 解题思路

改变 dijkstra 最短路路径长度求解方法即可，有 20 分没拿到，暂不知原因。

通过将 int 改为 long long 又多得了 10 分

## 201709-4 通信网络

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201709/20170904/main.cpp)

### 解题思路

正向、反向分别进行深搜，检查是否能够全部访问，若能， count++。

刚开始使用 int 二维数组，60分， 超时。改用邻接 vector 数组，100 分。

## 201803-1 跳一跳

[Java (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180301/Main.java)

## 201803-2 碰撞的小球

[Java (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180302/Main.java)

### 解题思路

简单模拟

## 201803-3 URL映射

[Java (60/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180303/Main.java)

### 解题思路

字符串处理

## 201803-4 棋局评估

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201803/20180304/main.cpp)

### 解题思路

博弈搜索。

* 对于 Alice，她想获得高分。因此需要遍历当前棋盘下每一种落子方案，选择使得自己得到较高的分数。

* 对于 Bob，要抑制 Alice 获得高分，就要从每一种落子方案中选择使得 Alice 得分最低的那一个。

* 注意，在选择落子之前，要检查是否已经决出胜负或平局。

* ~~有 10 分没拿到，暂时不知为何。~~ 这 10 分注意区分**平局**和**以最后一子取胜**的情况即可！

## 201809-1 卖菜

[C++ (100/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201809/20180901/main.cpp)

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
