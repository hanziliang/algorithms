

#include "utils.h"

// 算法思想:
// 把两个排好序的数组合并为一个数组
// 当数组长度为1的时候, 数组为有序状态, 然后两两合并

typedef vector<int> IARR;

IARR merge(IARR &l, IARR &r) {

    size_t left=0, right = 0, lsize = l.size(), rsize = r.size();

    IARR merged_arr(lsize + rsize, 0);

    while( left<lsize && right<rsize ) {
        if(l[left] < r[right]) {
            merged_arr[left + right] = l[left];
            left++;
        } else if (l[left] > r[right]) {
            merged_arr[left + right] = r[right];
            right++;
        } else {
            merged_arr[left + right] = l[left];
            merged_arr[left + right + 1] = l[left];
            left++; right++;
        }
    }

    while(left<lsize) {
        merged_arr[left+right] = l[left];
        left++;
    }

    while(right<rsize) {
        merged_arr[left+right] = r[right];
        right++;
    }

    return merged_arr;
}

vector<int> merge_sort_recursive(vector<int> &arr) {

    int size = arr.size();

    if(size==1) {
        return arr;
    }

    IARR::const_iterator begin = arr.cbegin();
    IARR::const_iterator middle = begin + arr.size()/2;
    IARR::const_iterator end = arr.cend();

    IARR left = IARR(begin, middle);
    left = merge_sort_recursive(left);

    IARR right = IARR(middle, arr.end());
    right = merge_sort_recursive(right);

    return merge(left, right);
}

vector<int> merge_sort(vector<int> &arr) {
    if(arr.size()==0) {
        return vector<int>();
    }

    vector< vector<int> > arrs;

    for(size_t i=0; i<arr.size(); i++) {
        arrs.push_back( {arr[i]} ) ;
    }

    while(arrs.size()!=1) {
        vector< vector<int> > tmps;
        int arrs_size = arrs.size();

        int i;
        for(i=0; i<arrs_size/2; i++) {
            tmps.push_back(merge(arrs[i*2], arrs[i*2+1]));
        }

        if(arrs_size%2==1) {
            tmps.push_back(arrs[arrs_size-1]);
        }

        arrs = tmps;
    }

    return arrs[0];
}

int main(int argc, char * argv[]) {
    IARR arr = scan_int_array();

    cout << "get an array:" << endl;
    display_vect(arr);

    printf("-------  recursive approach--------\n");

    IARR sorted_arr = merge_sort_recursive(arr);
    display_vect(sorted_arr);


    printf("-------no recursive approach--------\n");

    IARR sorted_arr_no_recursive = merge_sort(arr);
    display_vect(sorted_arr_no_recursive);

    return 0;
}
