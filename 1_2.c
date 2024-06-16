#include <stdio.h>
#include <stdlib.h>


int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}


int sumOfPrimeElements(int *arr, int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    
    return sum;
}

int main() {
    int n;
    
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    
    int *array = (int *)malloc(n * sizeof(int));
    
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int sum = sumOfPrimeElements(array, n);
    printf("Sum of prime elements: %d\n", sum);
    
    
    free(array);
    
    return 0;
}
