#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
#define STD 2
#define SUB 3
#define M_SIZE 2
#define ARRAYS_COUNT 3
void main()
{
    // 1- take an array elements from user, then print them out "using 2 for loops".
    /*
    int i, arr[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("\nEnter the element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nNow let's see the whole array you entered ==>\n [");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d", arr[i]);
        if(i != SIZE-1)
                printf(", ");
    }
    printf("]\n\n");


    //2- find the minimum & maximum value of array elements. (Min_Max Array)
    int min = arr[0], max = arr[0];
    for(i = 1; i < SIZE; i++)
    {
        if(min > arr[i])
            min = arr[i];

        if(max<arr[i])
            max = arr[i];
    }
    printf("\nThe max = %d ,, The min = %d\n", max, min);
    */

    // 3- Claculate Sum of each row in a 2D Array. (3 std, 4 subjects)
/*
    int grades[STD][SUB], sum[STD] = {0};
    float avg[SUB] = {0};
    int i, j;
    int min, max;
    int std_min[STD], std_max[STD];
    // sum & avg
    for(i = 0; i < STD; i++)
    {
        printf("\nFor student %d\n", i+1);
        for(j = 0; j < SUB; j++)
        {
            printf("\nEnter grade of subject %d: ", j+1);
            scanf("%d", &grades[i][j]);
            sum[i] += grades[i][j];
            avg[j] += grades[i][j];

            if(j ==0)
            {
               if(i == 0) min = grades[0][0], max = grades[0][0];
               std_min[i] = grades[i][0], std_max[i] = grades[i][0];
            }
            else
            {
                if(min > grades[i][j])
                    min = grades[i][j];

                if(max < grades[i][j])
                    max = grades[i][j];

                if(std_min[i] > grades[i][j])
                    std_min[i] = grades[i][j];

                if(std_max[i] < grades[i][j])
                    std_max[i] = grades[i][j];
            }

        }
    }

    // print array
    for(i = 0; i < STD; i++)
    {
        printf("\n[");
        for(j = 0; j < SUB; j++)
        {
            printf("%d ", grades[i][j]);
            if(j != SUB-1)
                printf(", ");
        }
        printf("]\n");
    }

    // print sum & avg
    for(i = 0; i < STD; i++)
    {
        printf("\nFor student %d\n", i+1);
        printf("Total grades %d is %d", i+1, sum[i]);
        printf("\nThe max = %d ,, The min = %d\n", std_max[i], std_min[i]);
    }

    for(j = 0; j < SUB; j++)
    {
        printf("\n\nAVG of subject %d is %0.2f", j+1, avg[j]/STD);
    }
    printf("\nThe max = %d ,, The min = %d\n", max, min);
*/

    // add two matrix
    /*
    int a[M_SIZE][M_SIZE], b[M_SIZE][M_SIZE], c[M_SIZE][M_SIZE];
    int i, j;
    for(i=0; i<M_SIZE; i++)
    {
        for(j=0; j<M_SIZE; j++)
        {
            printf("\nEnter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            printf("\nEnter b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // print array a
    printf("******** Array A ********");
    for(i = 0; i < M_SIZE; i++)
    {
        printf("\n[");
        for(j = 0; j < M_SIZE; j++)
        {
            printf("%d ", a[i][j]);
            if(j != M_SIZE-1)
                printf(", ");
        }
        printf("]\n");
    }

    // print array b
    printf("******** Array B ********");
    for(i = 0; i < M_SIZE; i++)
    {
        printf("\n[");
        for(j = 0; j < M_SIZE; j++)
        {
            printf("%d ", b[i][j]);
            if(j != M_SIZE-1)
                printf(", ");
        }
        printf("]\n");
    }

    // print array c
    printf("******** Array C ********");
    for(i = 0; i < M_SIZE; i++)
    {
        printf("\n[");
        for(j = 0; j < M_SIZE; j++)
        {
            printf("%d ", c[i][j]);
            if(j != M_SIZE-1)
                printf(", ");
        }
        printf("]\n");
    }
    */

    // Jagged Array
    /*
    int a1[5] = {1, 2, 3 , 4, 5};
    int a2[2] = {2, 4};
    int a3[1] = {6};

    int sizes[3] = {5, 2, 1};
    int jagged [100] = {0};
    int pos [6]={0};
    int i,j;

    pos[0] = 0;
    for(i=1,j=0; i<(sizeof(pos)/sizeof(int)); i+=2, j++)
    {
        pos[i] = pos[i-1] + sizes[j] - 1;
        pos[i+1] = pos[i]+1;
    }

    int k;
    for(i=pos[0], j=0; i<=pos[1]; i++, j++)
    {
        jagged[i] = a1[j];
    }

    for(i=pos[2], j=0; i<=pos[3]; i++, j++)
    {
        jagged[i] = a2[j];
    }

    for(i=pos[4], j=0; i<=pos[5]; i++, j++)
    {
        jagged[i] = a3[j];
    }

    int x = 1, y = 1;
    int index = 0;
    for(i = 0; i < x; i++)
    {
        index += sizes[i];
    }
    index += y;

    printf("The element is %d, %d", jagged[index], index);

    printf("The jagged array is: \n");
    k = 1;
    for(i = 0; i <= pos[5]; i++)
    {
        printf(" %d ", jagged[i]);
        if(i == pos[k])
        {
            k+=2;
            printf("\n");
        }
    }
    */

    int sizes[3] = {0};
    int jagged [100] = {0};
    int i, j, last_index = 0;

    for(i = 0; i < ARRAYS_COUNT; i++)
    {
        printf("\nPlease, enter the size of array %d: ", i+1);
        scanf("%d", &sizes[i]);
        for(j = 0; j<sizes[i]; j++)
        {
            printf("\nPlease, enter element %d: ", j+1);
            scanf("%d", &jagged[last_index]);
            last_index++;
        }
    }

    printf("\nThe jagged array is: \n");
    j = 0;
    int k = 0;
    for(i = 0; i < last_index; i++)
    {
        printf(" %d ", jagged[i]);
        k++;
        if(k == sizes[j])
        {
            j++;
            printf("\n");
            k = 0;
        }
    }

    int x = 1, y = 1;
    printf("\nNow enter the indecies of the the element you want in jagged array:\n");
    printf("x = ");
    scanf("%d", &x);
    printf("\ny = ");
    scanf("%d", &y);

    int index = 0;
    for(i = 0; i < x; i++)
    {
        index += sizes[i];
    }
    index += y;

    printf("The element is %d", jagged[index]);

}
