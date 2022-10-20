#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>
#include <string.h>

#define ARRAY_SIZE 5
#define SENTENCE_LENGTH 20

#define NORMAL 0x07
#define HIGHLIGHT 0xA5
#define COL_START 6
#define ROW_START 6


void swap(int*, int*);

int main()
{
    //1. Swap 2 integers
/*
    int x = 10, y = -2;
    printf("Before swap: X = %d, Y = %d", x, y);
    swap(&x, &y);
    printf("\nAfter swap: X = %d, Y = %d", x, y);
*/

    //2. Array
    /*
    int arr[ARRAY_SIZE];
    int* ptr = arr;
    int i;
    printf("Enter The Elements of Array");

    // read array
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("\n Element %d: ", i+1);
        scanf("%d", &ptr[i]);
    }

    // write array
    printf("\nThe Array Elements");
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("\n Element %d: %d", i+1, *(ptr+i));
    }
    */

    //3. Line Editor
    char sen[SENTENCE_LENGTH];
    char input, nxt_nxt, before;
    char* ptr;
    char* start = sen;
    char* end = sen;
    char* current = sen;

    // initialize the array with spaces
    int i, cursor = 0;
    for(i = 0; i < SENTENCE_LENGTH - 1; i++)
        sen[i] = ' ';
    sen[i] = '\0';
    /*input = getche();
    printf("%d", input);
    input = getche();
    printf("%d", input);
*/
    printf("Enter a sentence:\n");
    textattr(HIGHLIGHT);

    // loop
    gotoxy(COL_START, ROW_START);
    puts(sen);
    gotoxy(COL_START, ROW_START);

    do{
        input = getch();
        switch(input)
        {
            case -32:
            case 0:
                input = getch();
                switch(input)
                {
                    // Delete
                    case 83:
                        //*current = ' ';
                        //printf("%c", *current);
                        if(cursor == SENTENCE_LENGTH - 2)
                        {
                            *current = ' ';
                        }

                        else
                        {
                            *end = ' ';
                            *current = *(current+1);
                            nxt_nxt = *(current+2);
                            for(ptr = current+1; ptr < end; ptr++)
                            {
                                *ptr = nxt_nxt;
                                nxt_nxt = *(ptr+2);
                            }
                        }
                        //printf("%c", *current);
                        if(cursor != 0)
                        {
                            current--;
                            cursor--;
                            end--;
                        }
                        break;


                    //right
                    case 77:
                        if (cursor < end - start)
                        {
                            cursor++;
                            current++;
                        }
                        break;

                    //left
                    case 75:
                        if (cursor != 0)
                        {
                            cursor--;
                            current--;
                        }
                        break;

                    //home
                    case 71:
                        cursor = 0;
                        current = start;
                        break;

                    //end
                    case 79:
                        cursor = end - start;
                        current = end;
                        break;
                }
                break;

            // Backspace
            case 8:
                /*
                if(cursor != 0)
                {
                    current--;
                    cursor--;
                    end--;
                }
*/
                /*if(cursor+1 == SENTENCE_LENGTH - 2)
                {
                    *(current+1) = ' ';
                }

                else
                {*/
                if(cursor > 0)
                {
                    current--;
                    cursor--;
                    end--;

                    *current = *(current+1);
                    nxt_nxt = *(current+2);
                    for(ptr = current+1; ptr < end+1; ptr++)
                    {
                        *ptr = nxt_nxt;
                        nxt_nxt = *(ptr+2);
                    }
                    *(end+1) = ' ';
                }
                //}

                break;

            //ESC & Enter
            case 13:
            case 27:
                gotoxy(COL_START, ROW_START * 2);
                printf("Your sentence is:");

                textattr(NORMAL);
                printf("\n");

                gotoxy(COL_START, (ROW_START * 2) + 1);
                textattr(HIGHLIGHT);
                //*end = '\0';
                puts(sen);
                break;

            default:
                before = *current;
                *current = input;
                //printf("%c", *current);
                if (cursor < SENTENCE_LENGTH - 2)
                {
                    cursor++;
                    current++;
                    if(before == ' ')
                        end++;
                }
                break;
        }

        gotoxy(COL_START, ROW_START);
        puts(sen);

        gotoxy(COL_START + cursor, ROW_START);

    }while(input != 13 && input != 27);

    textattr(NORMAL);

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
