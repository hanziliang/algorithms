find the shortest path in a DAG

Dijkstra

https://www.hackerearth.com/zh/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

https://blog.csdn.net/lbperfect123/article/details/84281300

http://www.wutianqi.com/blog/1890.html

思想:
先设置一个起始点, 把起始点到所有点的距离保存起来为一个数组,
每次在数组中寻找距离最短的点, 用来更新所有点的距离(每个点只使用一次)
更新完成以后, 就得到了起始点到各个点的最短距离.

Dijkstra算法是处理单源最短路径的有效算法, 但它局限于边的权值非负的情况,
若图中出现权值为负的边,Dijkstra算法就会失效, 求出的最短路径就可能是错的.

这时候,就需要使用其他的算法来求解最短路径,
Bellman-Ford算法就是其中最常用的一个.
