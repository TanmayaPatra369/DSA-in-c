// 3.3
#include <stdio.h>
int main()
{
    int n1, n2, n, a[100], b[100], c[100], i, j, k;
    printf("Enter n1,n2 :");
    scanf("%d %d", &n1, &n2);

    if (n1 > n2)
    {
        n = n1;
    }
    else
    {
        n = n2;
    }

    printf("Enter co-efficient of 1st polynomial : \n");
    for (i = n; i >= 0; i--)
    {
        printf("x^%d : ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter co-efficient of 2nd polynomial : \n");
    for (j = n; j >= 0; j--)
    {
        printf("x^%d : ", j);
        scanf("%d", &b[j]);
    }

    for (k = n; k >= 0; k--)
    {
        c[k] = a[k] + b[k];
    }

    printf("The sum of polynomials is : ");
    for (k = n; k >= 0; k--)
    {
        printf("%dx^%d", c[k], k);
        if(k!=0){
            printf(" + ");
        }
    }

 return 0 ;
}
