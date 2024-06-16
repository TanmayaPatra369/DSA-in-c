#include <stdio.h>


struct Complex {
    float real;
    float imaginary;
};


struct Complex add(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}


struct Complex subtract(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}


struct Complex multiply(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return result;
}


struct Complex divide(struct Complex num1, struct Complex num2) {
    struct Complex result;
    float denominator = num2.real * num2.real + num2.imaginary * num2.imaginary;
    result.real = (num1.real * num2.real + num1.imaginary * num2.imaginary) / denominator;
    result.imaginary = (num1.imaginary * num2.real - num1.real * num2.imaginary) / denominator;
    return result;
}

int main() {
    int choice;
    struct Complex num1, num2, result;

    printf("Enter real and imaginary parts of Complex Number 1:\n");
    scanf("%f %f", &num1.real, &num1.imaginary);

    printf("Enter real and imaginary parts of Complex Number 2:\n");
    scanf("%f %f", &num2.real, &num2.imaginary);

    printf("Select operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2f + %.2fi\n", result.real, result.imaginary);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2f + %.2fi\n", result.real, result.imaginary);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2f + %.2fi\n", result.real, result.imaginary);
            break;
        case 4:
            result = divide(num1, num2);
            printf("Result: %.2f + %.2fi\n", result.real, result.imaginary);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}