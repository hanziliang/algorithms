#include <vector>
#include <string>
using namespace std;

vector<vector<int>> paths = {
    {0,  2,  6,  4},
    {-1, 0,  3, -1},
    {7, -1,  0,  1},
    {5, -1,  12, 0}};

int min_path(vector<vector<int>> &ths, int from, int to) {
    if (from==to) { return 0; }

    int size = ths.size();

    vector<int> &fnexts = ths[from];

    vector<int> path_length(size, -1);

    for(int i=0; i<fnexts.size(); i++) {

        if (from==i) continue;

        if(fnexts[i]>=0) {
            if (i==to) {
                path_length[i] = fnexts[i];
            } else {
                int len = min_path(ths, i, to);
                path_length[i] = len<0? -1: fnexts[i] + len;
            }
        }
    }

    int shortest = path_length[0];

    for(int i=1; i<path_length.size(); i++) {
        if ( path_length[i] > 0 ) {

            if(shortest<0)
                shortest = path_length[i];
            else
                shortest = min(shortest, path_length[i]);
        }
    }

    return shortest;
}


int main(int argc, char* argv[]) {
    int from=1, to=2;
    int minpath = min_path(paths, from - 1, to - 1);
    printf("find path from=%d, to=%d, min path=%d\n", from, to, minpath);
}
