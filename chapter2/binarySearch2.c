#include <stdio.h>

int binSearch(int x, int v[], int n){
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high){
        middle = (low + high)/2;
        if (x < v[middle]){
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    
    if (v[high] == x)
        return high;
        
    return -1;
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 31, 32, 33, 38, 69};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 3;

    int result = binSearch(x, v, n);
    printf("result: %d", result);

    return 0;
}