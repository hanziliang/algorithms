https://www.hackerearth.com/zh/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
https://www.bilibili.com/video/av43217121/?p=1

Bellman Ford's Algorithm:
Bellman Ford's algorithm is used to find the shortest paths from the source vertex to all other vertices in a weighted graph. It depends on the following concept: Shortest path contains at most n-1 edges, because the shortest path couldn't have a cycle.

So why shortest path shouldn't have a cycle ?
There is no need to pass a vertex again, because the shortest path to all other vertices could be found without the need for a second visit for any vertices.

Algorithm Steps:

The outer loop traverses from  0:n-1.
Loop over all edges, check if the next node distance > current node distance + edge weight, in this case update the next node distance to "current node distance + edge weight".
This algorithm depends on the relaxation principle where the shortest distance for all vertices is gradually replaced by more accurate values until eventually reaching the optimum solution. In the beginning all vertices have a distance of "Infinity", but only the distance of the source vertex = 0, then update all the connected vertices with the new distances (source vertex distance + edge weights), then apply the same concept for the new vertices with new distances and so on


思想:
先设置一个起始点, 把起始点到所有点的距离保存起来为一个数组,
遍历起始点能到达的所有点, 用这些点更新到达其它点的最短距离.

由于最短距离不可能存在环路, 所以, 最多需要循环n-1次,
当时当某一次循环, 没有任何最短路径需要更新, 后面的循环也就没有必要了.

