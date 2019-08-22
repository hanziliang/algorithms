// give a DAG, find all path from node(A) to node(B)
#include <vector>
#include <queue>
using namespace std;

// use BFS algorithm
int find_all(vector<vector<int>> &graph, int from, int to) {

    vector<int> &fpaths = graph[from];
    queue<int> que;
    que.push(from);

    int count = 0;
    while (!que.empty()) {
        int x = que.front();
        que.pop();

        if (x==to) {
            count++;
            continue;
        }

        vector<int> &paths = graph[x];
        for(int i=0; i<paths.size(); i++) {
            if(paths[i]==1) {
                que.push(i);
            }
        }
    }

    return count;
}

int main(int argc, char* argv[]) {

    vector<vector<int>> dag = {
            {2, 0, 1, 0, 1, 1},
            {0, 2, 1, 0, 0, 0},
            {0, 0, 2, 1, 0, 0},
            {0, 0, 0, 2, 0, 1},
            {0, 0, 0, 1, 2, 1},
            {0, 0, 0, 0, 0, 2},};

    if (argc!=3) {
        printf("2 args, 'from','to' is required\n");
        return 0;
    }

    int from = atoi(argv[1]);
    int to = atoi(argv[2]);

    if (from<1 || from>dag.size() || to<1 || to>dag.size()) {
        printf("'from', 'to' should be in range[%d, %d]\n", dag.size(), dag[0].size());
        return 0;
    }

    int pathcount = find_all(dag, from-1, to-1);

    printf("find %d paths from(%d) to(%d)\n", pathcount, from , to);
    return 0;
}





