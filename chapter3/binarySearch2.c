#include <stdio.h>

int binSearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(v[high] == x)
        return high;
    return -1;   /* no match */
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 31, 32, 33, 38, 69};
    int size = sizeof(v) / sizeof(v[0]);
    int x = 38;

    int result = binSearch(x, v, size);

    printf("%d\n", result);
    return 0;
}