#include "../../utils/utils.h"

//vector<vector<vector<pair<int,int>>>>
typedef UTIL_Type<vector<pair<int,int>>>::ARR2D GRAPH;

vector<int> shortestpath_recursive(GRAPH &graph, int istage) {
    int total_vertex_size = graph.size();

    if(istage>=total_vertex_size) {
        return vector<int>( graph[total_vertex_size-1].size(), 0 );
    }

    UTIL_Type<pair<int,int>>::ARR2D &ivtx = graph[istage];

    int ivtx_size = ivtx.size();

    vector<int> next_stage = shortestpath_recursive(graph, istage+1);

    printf("at stage = %d\n", istage+1);
    display_vect(next_stage, &ALIAS);

    vector<int> stagemin_path(ivtx_size);

    for(int i=0; i<ivtx_size; i++) {

        vector< pair<int, int> > &v = ivtx[i];
        int min_v = INF;

        for(int k=0; k<v.size(); k++) {

            int tmp = next_stage[v[k].first - 1] + v[k].second;

            if(min_v > tmp) {
                min_v = tmp;
            }
        }


        stagemin_path[i] = min_v;

    }

    return stagemin_path;
}

vector<int> shortestpath_dp(GRAPH &graph) {

    int total_vertex_size = graph.size();

    vector<int> stagepath (graph[total_vertex_size-1].size(), 0);

    for (int istage=total_vertex_size-1; istage>=0; --istage) {
        printf("at stage = %d\n", istage+1);
        display_vect(stagepath, &ALIAS);

        UTIL_Type<pair<int,int>>::ARR2D &ivtx = graph[istage];

        int ivtx_size = ivtx.size();

        vector<int> prev_stagepath(ivtx_size, INF);

        for(int i=0; i<ivtx_size; i++) {

            vector< pair<int, int> > &v = ivtx[i];
            int min_v = INF;

            for(int k=0; k<v.size(); k++) {

                int tmp = stagepath[v[k].first - 1] + v[k].second;

                if(min_v > tmp) {
                    min_v = tmp;
                }
            }
            prev_stagepath[i] = min_v;
        }
        stagepath = prev_stagepath;
    }

    return stagepath;
}


int main(int argc, char* argv[]) {
    GRAPH graph = {
#if 1       // https://blog.csdn.net/xgf415/article/details/52662389
            { {{1, 5}, {2, 3}}, },
            { {{1, 1}, {2, 3}}, {{2, 8}, {3, 7}, {4, 6}}, } ,
            { {{1, 6}, {2, 8}}, {{1, 3}, {2, 5}}, {{2, 3}, {2, 3}}, {{2, 8}, {3, 4}},},
            { {{1, 2}, {2, 2}}, {{2, 1}, {3, 2}}, {{2, 3}, {3, 3}}, },
            { {{1, 3}, {2, 5}}, {{1, 5}, {2, 2}}, {{1, 6}, {2, 6}}, },
            { {{1, 4}}, {{1, 3}}},
#else       // https://blog.csdn.net/google19890102/article/details/39756297
            { {{1, 5}, {2, 3}}, },
            { {{1, 1}, {2, 6}, {3, 3}}, {{2, 8}, {4, 4}, }, } ,
            { {{1, 5}, {2, 6}}, {{1, 5}, }, {{3, 8}}, {{3, 3}},},
            { {{1, 3}, }, {{1, 4}, }, {{1, 3}, }, },
#endif
    };


    vector<int> shortest = shortestpath_recursive(graph, 0);
    printf("the recursize result is:\n");
    display_vect(shortest, &ALIAS);

    printf("----------------------------------\n");
    shortest = shortestpath_dp(graph);
    printf("the dynamic programing result is:\n");
    display_vect(shortest, &ALIAS);

}

