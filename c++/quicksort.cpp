#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high) {
      int pivot = a[high];
      int i = low-1;

      for (int j=low;j<high;j++) {
          if(a[j] <= pivot) {
              i++;
              int temp = a[i];
              a[i] = a[j];
              a[j] = temp;
          }
      }
      int temp = a[i+1];
      a[i+1] = a[high];
      a[high] = temp;

      return i+1;
}

void quicksort(int a[], int low, int high) {

    if(low<high) {
        int p = partition(a,low, high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);        
    }
}

int main() {
    int v[] = {7,4,5,1,3};
    int n = sizeof(v)/sizeof(v[0]);
    quicksort(v, 0, n-1);
    for(int i=0;i<n;i++) {
        cout<<v[i];
    }
    return 0;
}