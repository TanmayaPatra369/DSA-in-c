//Write a program to read two numbers and compare the numbers using function call by address.


#include <stdio.h>
int  main()
{
    int n1,n2;
    printf("enter 2 nos");
    scanf("%d %d",&n1,&n2);
    int *m1=&n1;
    int *m2=&n2;
    {
    
    {if (*m1=*m2)

    printf("%d is equal to %d",n1,n2);
    
     }
    
         {

        if(*m1<*m2)
        printf("%d is greater than %d",n2,n1);
        
        }
        if(*m1> *m2) 
        {
            printf("%d is greater than %d",n1,n2);
        }
    }     
     return 0;
}