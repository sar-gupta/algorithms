#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> array, int start, int end, int number) {
    if(start > end) {
        return -1;
    }
    int mid = (start+end)/2;    
    if (number == array[mid]) {
        return mid;
    }
    else if (number > array[mid]) {
        return binary_search(array, mid+1, end, number);
    }
    else {
        return binary_search(array, start, mid-1, number);
    }
    return -1;
}

int main() {
    vector<int> v = {1,2,3,4,5,6};
    cout<<binary_search(v, 0, v.size(), 6);
    cout<<binary_search(v, 0, v.size(), 0);
}