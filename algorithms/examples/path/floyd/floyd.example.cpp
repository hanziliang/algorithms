#include "../../../utils/utils.h"

typedef UTIL_Type<int>::ARR2D PATH;

UTIL_Type<int>::ARR2D floyd_warshall(vector<vector<int>> &ths) {

    int size = ths.size();

    UTIL_Type<int>::ARR2D min_dist(ths);

    UTIL_Type<int>::ARR2D min_path(size);
    
    for(int i=0; i<size; i++) {
        vector<int> v = {0, 1, 2, 3, 4};
        v[i] = INF;
        min_path[i] = v;
    }

    for(int k=0; k<size; k++) {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                int tmp_min = min_dist[i][k] + min_dist[k][j];

                if (tmp_min < min_dist[i][j]) {
                    min_dist[i][j] = tmp_min;
                    min_path[i][j] = min_path[i][k];
                }
            }
        }
    }

    cout << "all min_path is " << endl;
    for(vector<int> v:min_path) {
        display_vect(v, &ALIAS);
    }
    return min_dist;
}

int main(int argc, char* argv[]) {
    PATH paths = {
#if 0
            {NAN,  2,    6,   4},
            {INF,  NAN,  3,   INF},
            {7,    INF,  NAN, 1},
            {5,    INF,  12,  NAN},
#else
            {NAN,  3,    8,   INF, -4},
            {INF,  NAN,  INF, 1,    7},
            {INF,  4,    NAN, INF,  INF},
            {2,    INF,  -5,  NAN,  INF},
            {INF,  INF,  INF, 6,    NAN},
#endif
            };

    UTIL_Type<bool>::ARR2D marks(paths.size(), vector<bool>(paths.size(), false));

    PATH shortest = floyd_warshall(paths);

    cout << "all shorted path is " << endl;
    for(vector<int> v:shortest) {
        display_vect(v, &ALIAS);
    }

}
