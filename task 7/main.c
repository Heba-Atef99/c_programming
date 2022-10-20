#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

float power(int, int);
int* IncrementArray_wrong();
int* IncrementArray();

int main_2()
{
    //1. power
/*
    int num, p;
    printf("Enter num: ");
    scanf("%d", &num);
    printf("\nEnter power: ");
    scanf("%d", &p);

    float result;
    result = power(num, p);
    if(result != -1)
        printf("\n\nThe result ==> %d^%d = %f", num, p, result);

*/
/*
    // 2. Increment Array
    // will access garbage

    //int* ptr = IncrementArray_wrong();
    int* ptr = IncrementArray();
    int i;
    printf("The array you entered: \n");
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("\nElement %d: %d", i+1, *(ptr+i));
    }

*/
    //3. Employee with dynamic allocation

    return 0;
}

float power(int num, int p)
{
    if(p < 0)
    {
        return ((1.0/num) * power(num, p+1));
    }

    if(p == 0)
        return 1;

    return (num * power(num, p-1));
}

int* IncrementArray_wrong()
{
    int arr[ARRAY_SIZE];
    int i;
    printf("Enter Array\n");
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
        arr[i] += 2;
    }
    return arr;
}

int* IncrementArray()
{
    int* arr = malloc(ARRAY_SIZE * sizeof(int));
    int i;
    printf("Enter Array\n");
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", arr+i);
        arr[i] += 2;
    }
    return arr;
}
