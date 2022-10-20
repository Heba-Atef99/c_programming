#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>
#include <string.h>

#define ARRAY_SIZE 5
//#define SENTENCE_LENGTH 20

#define NORMAL 0x07
#define HIGHLIGHT 0xA5
#define COL_START 6
#define ROW_START 6

int main()
{
    int SENTENCE_LENGTH;
    printf("Insert the length of the sentence: ");
    scanf("%d", &SENTENCE_LENGTH);

    //3. Line Editor
    char sen[SENTENCE_LENGTH];
    char input, before;
    char* ptr;
    char* nxt_nxt;
    char* start = sen;
    char* end = sen;
    char* current = sen;
    int insert_flag = 0;

    // initialize the array with spaces
    int i, cursor = 0;
    for(i = 0; i < SENTENCE_LENGTH - 1; i++)
        sen[i] = ' ';
    sen[i] = '\0';

    // To know the ASCII of a key
    /*input = getche();
    printf("%d", input);
    input = getche();
    printf("%d", input);
    */

    printf("\n\nEnter a sentence:\n");
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

                        // when the cursor is at the last char
                        if(cursor == SENTENCE_LENGTH - 2)
                        {
                            *current = ' ';
                        }

                        else
                        {
                            //*end = ' ';

                            // in case standing at the end of the sentence
                            *current = *(current+1);

                            // in case standing in the mid of the sentence
                            nxt_nxt = current+2;
                            for(ptr = current+1; ptr < end; ptr++)
                            {
                                *ptr = *nxt_nxt;
                                nxt_nxt = ptr+2;
                            }
                            *end = ' ';
                        }
                        /*
                        if(nxt_nxt == end)
                        {
                            *end = ' ';
                        }
                        */
                        //*end = *current
                        // DON'T shift the cursor, current, or end when it's at the start

                        // always shift the end unless you are at the end of the sentence
                        if(current != end)
                        {
                            //current--;
                            //cursor--;
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

                    // insert
                    case 82:
                        if(insert_flag == 0)
                            insert_flag = 1;

                        else
                            insert_flag = 0;
                        break;
                }
                break;

            // Backspace
            case 8:
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

                break;

            //ESC & Enter
            case 13:
            case 27:
                textattr(NORMAL);
                gotoxy(COL_START, ROW_START * 2);
                printf("Your sentence is:");

                printf("\n");

                gotoxy(COL_START, (ROW_START * 2) + 1);
                textattr(HIGHLIGHT);
                if(*end == ' ')
                    *end = '\0';
                else if(*(end+1) != '\0')
                    *(end+1) = '\0';
                puts(sen);
                break;

            // upon entering any char
            default:
                // NORMAL MODE
                before = *current;
                if(insert_flag == 0)
                {
                    *current = input;

                    // if cursor is not at the end of the sentence
                    if ((cursor < SENTENCE_LENGTH - 2))
                    {
                        //int h = end-start;
                        cursor++;
                        current++;

                    // shift end in three cases
                    // 1. with the increment of current (writing for the first time)
                    // 2. overriding the last character written with spaces ahead of it
                    // 3. in insert mode
                        if(before == ' ' || (before != ' ' && current > end))
                            end++;
                    }

                }

                // INSERT MODE
                else
                {
                    int h = end-start;

                    // in case of not full sentence
                    // full sentence has sen_len - 2 char with no space at the end
                    if(!(end-start == SENTENCE_LENGTH-2 && *end != ' '))
                    {
                        //shift the current
                        if(*end == ' ')
                            ptr = end;
                        else
                            ptr = end+1;

                        for(; ptr > current; ptr--)
                        {
                            *ptr = *(ptr-1);
                        }
                        //update the current
                        *current = input;

                        if(*(end+1) != '\0')
                        {
                            cursor++;
                            current++;
                            end++;
                        }
                    }
                }
                /*
                // if cursor is not at the end of the sentence & we are not in the insert mode with full sentence
                if ((cursor < SENTENCE_LENGTH - 2) && !(insert_flag == 1 && end-start >= SENTENCE_LENGTH-1))
                {
                    //int h = end-start;
                    cursor++;
                    current++;

                    // shift end in three cases
                    // 1. with the increment of current (writing for the first time)
                    // 2. overriding the last character written with spaces ahead of it
                    // 3. in insert mode
                    if(before == ' ' || (before != ' ' && current > end) || (before != ' ' && insert_flag == 1 && end-start < SENTENCE_LENGTH-1 && *(end+1) != '\0'))
                        end++;
                }
                */
                break;
        }

        // print the sentence in its place
        gotoxy(COL_START, ROW_START);
        puts(sen);

        // shift the cursor
        gotoxy(COL_START + cursor, ROW_START);

    }while(input != 13 && input != 27);

    textattr(NORMAL);

    return 0;
}
