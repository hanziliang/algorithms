#include <climits>
#include <set>
#include <utility>
#include "../../../utils/utils.h"

#define INF INT_MAX

#define PATH std::vector< std::vector<int> >

// 'infinity' = inf
// 'not_a_number' = nan
std::unordered_map<int, string> alias {
    {INF, "INF"}, {0, "NAN"},};

void dijkstra(PATH &paths, int startpoint);
vector<int> dijkstra2(vector<vector<pair<int,int>>> &v, int firstpoint);

int main(int argc, char *argv[]) {
    PATH paths = {
#if 1
        {0, 1,   2,   3,   4,   5,   6},
        {1, 0,   INF, 10,  INF, 30,  100},
        {2, INF, 0,   5,   INF, INF, INF},
        {3, INF, INF, 0,   50,  INF, INF},
        {4, INF, INF, INF, 0,   INF, 10},
        {5, INF, INF, INF, 20,  0,   60},
        {6, INF, INF, INF, INF, INF, 0}
#else
        {0, 1,   2,   3,   4,   5,   6},
        {1, 0,   1,   12,  INF, INF,  INF},
        {2, INF, 0,   9,   3,   INF, INF},
        {3, INF, INF, 0,   INF, 5,   INF},
        {4, INF, INF, 4,   0,   13,  15},
        {5, INF, INF, INF, INF, 0,   4},
        {6, INF, INF, INF, INF, INF, 0}
#endif
    };

    int start = 1;
    dijkstra(paths, start);
    cout << "get final result:";
    display_vect(paths[start], &alias);

    printf("\n------------------------------------\n");
    vector<vector<pair<int,int>>> v = {
            { {2, 10}, {4, 30}, {5, 100}},
            { {2, 5},},
            { {3, 50}},
            { {5, 10}},
            { {3, 20}, {5, 60}}, {} };

    vector<int> dist = dijkstra2(v, start-1);

    cout << "dijkstra2 get final result:";
    display_vect(dist, &alias);
}

void dijkstra(PATH &paths, int startpoint) {
    int size = paths.size();

    vector<bool> marks(size, false);
    vector<int> &dist = paths[startpoint];
    marks[startpoint]  = marks[0] = true;

    int c = 1;

    cout << "init status:" ;
    display_vect(dist, &alias);

    while( c<size ) {
        int minpoint = 1;
        int find_null = true;

        cout << "min distance Point search process:";
        for(int i=1; i<size; i++) {
            if (minpoint!=i && !marks[i] && dist[i]!=0 && dist[i]!=INF && (dist[minpoint]>dist[i]||dist[minpoint]==0) ) {
                minpoint = i;
                find_null = false;
                cout << "-> "  << i << " ";
            }
        }

        if(find_null) {
            cout << "didn't found 'min_distance_point', should exit loop" << endl;
            cout << "----------------------" << endl;
            break;
        }

        cout << endl;

        vector<int> &curpoint = paths[minpoint];

        cout << "shortest distance point " << minpoint << ":";
        display_vect(curpoint, &alias);

        for(int i=1; i<size; i++) {
            if( i==minpoint || curpoint[i]==INF || curpoint[i]==0 ) continue;

            int value = curpoint[i] + dist[minpoint];

            if( value<dist[i] ) {
                dist[i] = value;
            }
        }

        cout << "after this process, get result:";
        display_vect(dist, &alias);
        cout << "----------------------" << endl;

        c++;
        marks[minpoint] = true;
    }
}



// https://www.hackerearth.com/zh/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
// 参考资料中的迪杰斯特拉算法的实现有一个bug.可以自行比较
// 这种实现方法,使用一个multiset来保存, 插入时就会自动排序
// 省去了每次重新查找最近的节点的for循环
vector<int> dijkstra2(vector<vector<pair<int,int>>> &v, int firstpoint) {
    multiset< pair< int,int > > s;
    s.insert({0, firstpoint});

    vector<int> dist(v.size(), INF);
    vector<bool> vis(v.size(), false);

    s.insert({0 , firstpoint});                 // insert the source node with distance = 0

    while(!s.empty()){
        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second, min_weight = p.first;

        if( vis[x] ) continue;                  // check if the popped vertex is visited before
        vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            // distance from point('x') to point('e') is 'w'
            int e = v[x][i].first, w = v[x][i].second;

            if(min_weight == INF) {continue;}

            int tmp_weight = min_weight + w;
            // so if min_distance[e] > min_distance[x] + w, update min_distance[e] to (min_distance[x] + w)
            if( tmp_weight < dist[e] ) {        // check if the next vertex distance could be minimized
                dist[e] = tmp_weight;
                s.insert({tmp_weight, e});      // insert the next vertex with the updated distance
            }

        }
    }

    return dist;
}
