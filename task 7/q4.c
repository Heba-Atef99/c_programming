#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
//#define STD 2
//#define SUB 3
#define M_SIZE 2
#define ARRAYS_COUNT 3
void m55ain()
{
    /*
    // 3- Claculate Sum of each row in a 2D Array. (3 std, 4 subjects)
    int STD, SUB;
    printf("Enter the number of students: ");
    scanf("%d", &STD);
    printf("\nEnter the number of subjects: ");
    scanf("%d", &SUB);
    //int grades[STD][SUB], sum[STD] = {0};
    //float avg[SUB] = {0};
    int i, j;
    int min, max;
    //int std_min[STD], std_max[STD];

    int** grades = malloc(STD * sizeof(int*));
    int* sum = malloc(STD * sizeof(int));
    float* avg = malloc(SUB * sizeof(float));
    int* std_min = malloc(STD * sizeof(int));
    int* std_max = malloc(STD * sizeof(int));

    // initialize sum & avg arrays with zeros
    for(i = 0; i < STD; i++)
    {
        *(sum+i) = 0;
        *(grades+i) = malloc(SUB * sizeof(int));
    }

    for(i = 0; i < SUB; i++)
    {
        *(avg+i) = 0;
    }

    int current = 0;
    // sum & avg
    for(i = 0; i < STD; i++)
    {
        printf("\nFor student %d\n", i+1);
        for(j = 0; j < SUB; j++)
        {
            printf("\nEnter grade of subject %d: ", j+1);
            //scanf("%d", &grades[i][j]);
            scanf("%d", *(grades+i)+j);
            current = *(*(grades+i)+j);
            *(sum+i) += current;
            *(avg+j) += current;

            if(j ==0)
            {
               if(i == 0) min = *(*(grades)), max = *(*(grades));
               *(std_min+i) = *(*(grades+i)), *(std_max+i) = *(*(grades+i));
            }
            else
            {
                if(min > current)
                    min = current;

                if(max < current)
                    max = current;

                if(*(std_min+i) > current)
                    *(std_min+i) = current;

                if(*(std_max+i) < current)
                    *(std_max+i) = current;
            }

        }
    }

    // print array
    for(i = 0; i < STD; i++)
    {
        printf("\n[");
        for(j = 0; j < SUB; j++)
        {
            printf("%d ", *(*(grades+i)+j));
            if(j != SUB-1)
                printf(", ");
        }
        printf("]\n");
    }

    // print sum & avg
    for(i = 0; i < STD; i++)
    {
        printf("\nFor student %d\n", i+1);
        printf("Total grades %d is %d", i+1, *(sum+i));
        printf("\nThe max = %d ,, The min = %d\n", *(std_max+i), *(std_min+i));
    }

    for(j = 0; j < SUB; j++)
    {
        printf("\n\nAVG of subject %d is %0.2f", j+1, *(avg+j)/STD);
    }
    printf("\nThe max = %d ,, The min = %d\n", max, min);
    */
    // Jagged
    /*
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
    */

    // **************************** jagged for students
    int STD;
    int i, j;
    int min, max;
    // first know the number of students
    printf("Enter the number of students: ");
    scanf("%d", &STD);

    // second know the number of subject for each student
    int* sub_count = malloc(STD * sizeof(int));
    for(i = 0; i < STD; i++)
    {
        printf("\nEnter the number of subjects for student %d: ", i+1);
        scanf("%d",sub_count+i);
    }

    //int std_min[STD], std_max[STD];
    int** grades = malloc(STD * sizeof(int*));
    int* sum = malloc(STD * sizeof(int));
    //float* avg = malloc(SUB * sizeof(float));
    int* std_min = malloc(STD * sizeof(int));
    int* std_max = malloc(STD * sizeof(int));



    // third initialize sum array with zeros
    for(i = 0; i < STD; i++)
    {
        *(sum+i) = 0;
        *(grades+i) = malloc(sub_count[i] * sizeof(int));
    }

        int current = 0;

    // fourth take input from user & calculate sum & avg
    for(i = 0; i < STD; i++)
    {
        printf("\nFor student %d\n", i+1);
        for(j = 0; j < sub_count[i]; j++)
        {
            printf("\nEnter grade of subject %d: ", j+1);
            scanf("%d", *(grades+i)+j);
            current = *(*(grades+i)+j);
            *(sum+i) += current;
            //*(avg+j) += current;

            if(j ==0)
            {
               if(i == 0) min = *(*(grades)), max = *(*(grades));
               *(std_min+i) = *(*(grades+i)), *(std_max+i) = *(*(grades+i));
            }
            else
            {
                if(min > current)
                    min = current;

                if(max < current)
                    max = current;

                if(*(std_min+i) > current)
                    *(std_min+i) = current;

                if(*(std_max+i) < current)
                    *(std_max+i) = current;
            }
        }
    }

    // print array
    for(i = 0; i < STD; i++)
    {
        printf("\n[");
        for(j = 0; j < sub_count[i]; j++)
        {
            printf("%d ", *(*(grades+i)+j));
            if(j !=  sub_count[i]-1)
                printf(", ");
        }
        printf("]\n");
    }

    // print sum & avg
    for(i = 0; i < STD; i++)
    {
        printf("\nFor student %d\n", i+1);
        printf("Total grades %d is %d", i+1, *(sum+i));
        printf("\nThe max = %d ,, The min = %d\n", *(std_max+i), *(std_min+i));
    }

    free(grades);
    free(sum);
    free(std_max);
    free(std_min);
/*
    for(i = 0; i < SUB; i++)
    {
        *(avg+i) = 0;
    }
*/

}


