# My_CCF-CSP_Answer
记录我在解 CCF - CSP 时遇到的一些问题以及总结的经验。

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

## 201712-4 行车路线

[C++ (80/100)](https://github.com/Heliovic/My_CCF-CSP_Answer/blob/master/201712/20171204/main.cpp)

### 解题思路

改变 dijkstra 最短路路径长度求解方法即可，有 20 分没拿到，暂不知原因。
