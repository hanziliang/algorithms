http://www.wutianqi.com/blog/1903.html
https://www.bilibili.com/video/av54668527
https://www.bilibili.com/video/av36886554
https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

Floyd-Warshall
the algrorithm to get shortest path form any vertex to any vertex.

例如:       {NAN,  3,    8,   INF, -4},
            {INF,  NAN,  INF, 1,    7},
            {INF,  4,    NAN, INF,  INF},
            {2,    INF,  -5,  NAN,  INF},
            {INF,  INF,  INF, 6,    NAN},
可以最终得到结果:

最短路径的序列:
INF 4 4 4 4
3 INF 3 3 3
1 1 INF 1 1
NAN 2 2 INF NAN
3 3 3 3 INF

i, j, 保存了, 从顶点i,到顶点j, 走最短路径时, 需要先从i出发的下一个点,
如果, [i][j] = j 说明, 直接就是最短距离, 不需要中间点.


最短路径的值:
NAN 1 -3 2 -4
3 NAN -4 1 -1
7 4 NAN 5 3
2 -1 -5 NAN -2
8 5 1 6 NAN

当需要查找顶点0->顶点2的距离时,

