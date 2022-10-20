#include <stdio.h>

void main()
{
    // 1. print "Hello World"
    printf("Hello, World \n");

    // 2. print ASCII number of a given char

    char input;
    printf("\nPlease, enter a character:\n");
    scanf("%c", &input);
    printf("==> The ASCII of char (%c) is (%d)\n", input, input);

    // 3. print a float number entered by the user

    float f_num;
    printf("\nPlease, enter a float number:\n");
    scanf("%f", &f_num);
    printf("==> The float number is (%f)\n", f_num);


    // 4. add two integers

    int i1, i2;
    printf("\nPlease, enter two integer numbers:\n");
    scanf("%d", &i1);
    scanf("%d", &i2);
    printf("==> The sum of the previous two numbers is (%d)\n", i1+i2);


    // 5. print Hexa of a number

    int i;
    printf("\nPlease, enter an integer number:\n");
    scanf("%d", &i);
    printf("==> The Hexa of number (%d) is (%X)\n", i, i);


    // 6. make simple calculations (add, sub, multiply, divide) on two integers
    int i1, i2;
    printf("\nPlease, enter two integer numbers:\n");
    scanf("%d", &i1);
    scanf("%d", &i2);
    printf("==> i1 + i2 = (%d)\n", i1+i2);
    printf("==> i1 - i2 = (%d)\n", i1-i2);
    printf("==> i1 * i2 = (%d)\n", i1*i2);
    printf("==> i1 / i2 = (%f)\n", (0.1*i1)/i2);

    // 7. compute Quotient and Remainder
    printf("==> The Quotient = (%d) & the Remainder = (%d)\n", i1/i2, i1%i2);

}
