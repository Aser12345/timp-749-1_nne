#include<stdio.h>

int main() {
    int x = 0;
    int n = 0;
    double sum = 1;
    int i;
    (void)scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        (void)scanf("%d", &x);
        sum = sum + x;
    }
    sum = sum - 1;
    sum = sum/n;
    printf("%lf", sum);
    return 0;
}
