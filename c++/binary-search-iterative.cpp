#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> array, int number) {
    int low = 0, high = array.size();
    while(low<=high) {
        int mid = (low+high)/2;
        if (number < array[mid]) high = mid-1;
        else if (number > array[mid]) low = mid+1;
        else return mid;
    }
    return -1;
}

int main() {
    vector<int> v = {1,2,3,4,5,6};
    cout<<binary_search(v, 6);
    cout<<binary_search(v, 0);
}