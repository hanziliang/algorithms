#include <climits>
#include <set>
#include <utility>
#include "../../../utils/utils.h"

typedef std::vector< std::pair<string, int> > PATH_Node;
typedef std::unordered_map<string, PATH_Node> PATH;

void bellmanford(PATH &paths, string from) {
    PATH::iterator ipn = paths.find(from);
    if (ipn==paths.end()) {
        printf("cann't found '%s' vertext\n", from.c_str());
        return;
    }

    unordered_map<string, int> dist;
    for(auto i: paths) { dist.insert({i.first, INT_MAX}); }
    dist["s"] = 0;

    // 初始化dist为from
    PATH_Node &pnode = ipn->second;
    for( auto &i: pnode) { dist[i.first] = i.second; }

    printf("init state of distance vector:\n");
    display_map(dist, &ALIAS);
    cout<<endl<<endl;

    int size = paths.size();
    int index = 0;

    while( index<size-1 ) {

        bool canibreak = true;
        for(auto i : dist) {

            if (i.second==INT_MAX){ continue; }

            for(auto ii:paths[i.first]) {
                if (dist[ii.first] > dist[i.first] + ii.second) {
                   dist[ii.first] = dist[i.first] + ii.second;
                    canibreak = false;
                }
            }

            printf("after check vertex : %s\n", i.first.c_str());
            display_map(dist, &ALIAS);
            cout << endl;

        }

        if (canibreak) break;

        cout << endl;

        printf("index=%d -> ", index);
        for(auto i : dist) {
            printf("%s:%2d, ", i.first.c_str(), i.second);
        }
        cout<<endl;

        index ++;
    }

    printf("\nfrom vertex:%s, get shortest path result\n", from.c_str());
    display_map(dist, &ALIAS);
    cout << endl;
}

int main(int argc, char *argv[]) {
     PATH paths = {
             {"s", {{"a", 10}, {"e", 8}}},
             {"a", {{"c", 2}}},
             {"b", {{"a", 1}}},
             {"c", {{"b", -2}}},
             {"d", {{"c", -1}, {"a", -4}}},
             {"e", {{"d", 1}}},};

     bellmanford(paths, "s");

    return 0;
}
