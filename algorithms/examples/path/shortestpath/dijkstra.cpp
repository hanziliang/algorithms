#include <climits>
#include "../../../utils/utils.h"

#define INF INT_MAX
#define PATH std::vector< std::vector<int> >

std::unordered_map<int, string> alias {
        {INF, "INF"},
        {0, "NAN"},
};

void dijstra(PATH &paths, int startpoint) ;

int main(int argc, char *argv[]) {

    PATH paths = {
#if 0
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

    dijstra(paths, start);

    cout << "get final result:";
    display_vect(paths[start], &alias);
}

void dijstra(PATH &paths, int startpoint) {
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

