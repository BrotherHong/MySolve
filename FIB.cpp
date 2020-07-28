#include <stdio.h>  
int f(int n) ;
int count = 0;
  
int main()  
{  
    int n;  
    scanf("%d", &n);  
    printf("%d ", f(n));  
    printf("%d", count);  
    return 0;  
} 

int f(int n) {  
    count += 1;  
    if (n == 0) {  
        return 0;
    } else if (n == 1) {  
        return 1;  
    } else {  
        return f(n-1) + f(n-2);  
    }  
}  
