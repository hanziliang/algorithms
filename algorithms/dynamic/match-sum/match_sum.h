#include <vector>
using namespace std;

bool subset_recursion(std::vector<int> &arr, int index, int sum);

bool subset_memoize(std::vector<int> &arr, std::vector<std::vector<const bool*>> &cache, int index, int sum);

bool subset_dynamic(std::vector<int> &arr, int sum);

void show2dvect(vector<int> &arr,const vector<vector<const bool *>> &vec);
