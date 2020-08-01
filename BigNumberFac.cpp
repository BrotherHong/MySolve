#include <iostream>  
#include<string>  
#include<string.h>  
#define MAX 1000  
using namespace std;  
void output(int[]);  
void mul(int[], int[], int[]);  
  
int main() {  
    int t, i, index, n;  
    int a[MAX], b[MAX], c[2*MAX+1];  
    c[0] = 1;  
    for (i = 1;i <= 2*MAX;i++) {  
        c[i] = 0;  
    }  
    cin >> n;  
    for (i = 1;i <= n;i++) {  
        index = 0;  
        t = i;  
        while (t != 0) {  
            a[index] = t % 10;  
            t /= 10;  
            index++;  
        }  
        memcpy(b, c, sizeof(c));  
        mul(a, b, c);  
    }  
    output(c);  
    return 0;  
}  
  
void mul(int a[], int b[], int c[]) {  
    int i, j, n, index = 0;  
    for (i = 0;i < MAX;i++) {  
        for (j = 0;j < MAX;j++) {  
            n = a[i] * b[j] + c[index];  
            c[index] = n % 10;  
            c[index+1] += n / 10;  
            index++;  
        }  
        index -= MAX-1;  
    }  
}  
  
void output(int n[]) {  
    int i;  
    for (i = 2*MAX;i >= 0;i--) {  
        if (n[i] != 0) break;  
    }  
    for (;i >= 0;i--) {  
        cout << n[i];  
    }  
    cout << endl;  
}