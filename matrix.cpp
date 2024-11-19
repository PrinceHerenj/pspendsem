#include <iostream>
using namespace std;

void series(int arr[][7], int n, int level) {
    // base
    if(level >= n/2 + 1) return;

    int mid = n/2;
    if(level == 0) {
        cout<<arr[mid][mid]<<" ";
    }

    else {
        // square
        cout<<arr[mid-level][mid]<<" "<<arr[mid][mid+level]<<" "<<arr[mid+level][mid]<<" "<<arr[mid][mid-level]<<" ";

        // hard code :
        for(int i=1; i<level; i++) {
            cout<<arr[mid-level][mid+i]<<" ";
            cout<<arr[mid-i][mid+level]<<" ";
            cout<<arr[mid+i][mid+level]<<" ";
            cout<<arr[mid+level][mid+i]<<" ";
            cout<<arr[mid+level][mid-i]<<" ";
            cout<<arr[mid-i][mid-level]<<" ";
            cout<<arr[mid+i][mid-level]<<" ";
            cout<<arr[mid-level][mid-i]<<" ";
        }

        // corner
        cout<<arr[mid-level][mid+level]<<" "<<arr[mid+level][mid+level]<<" "<<arr[mid+level][mid-level]<<" "<<arr[mid-level][mid-level]<<" ";
    }

    series(arr, n, level+1);
}

int main() {
    const int n = 7;
    int arr[n][n] = {
        { 1,   2,   3,   4,   5,   6,   7 },
        { 8,   9,  10,  11,  12,  13,  14 },
        { 15, 16,  17,  18,  19,  20,  21 },
        { 22, 23,  24,  25,  26,  27,  28 },
        { 29, 30,  31,  32,  33,  34,  35 },
        { 36, 37,  38,  39,  40,  41,  42 },
        { 43, 44,  45,  46,  47,  48,  49 }
    };
    
    series(arr, n, 0);

}