find the shortest path in a DAG

Dijkstra

https://www.hackerearth.com/zh/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

https://blog.csdn.net/lbperfect123/article/details/84281300

思想:
先设置一个起始点, 把起始点到所有点的距离保存起来为一个数组,
每次在数组中寻找距离最短的点,
用来更新所有点的距离.(每个点只需要使用一次)
更新完成以后, 就得到了其实点到各个点的最短距离.
