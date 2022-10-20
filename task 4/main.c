#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>
#include <string.h>
#define NORMAL 0x07
#define HIGHLIGHT 0x70

int main()
{
    /************************ 1 *****************************/
  /*  char str [20], letter;
    int i;
    for(i = 0; i < 20; i++)
    {
        letter = getche();
        if(letter == 13)
        {
            str[i] = '\0';
            break;
        }
        str[i] = letter;
    }

    printf("\n");

    for(i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
*/

    /************************ 2 *****************************/
    /*char ch = '\0';
    while(ch != 32)
    {
        ch = getche();
        if(ch == 0 || ch == -32)
        {
            ch = getche();
            printf("\n Extended key with ASCII = %d", ch);
        }
        else
            printf("\n Normal key with ASCII = %d", ch);
    }
    */

    /************************ 3 *****************************/
    /*
    char first_name[15], last_name[15], full_name[30];
    printf("\nEnter first name: ");
    gets(first_name);
    printf("\nEnter last name: ");
    gets(last_name);

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    printf("\n\nYour name is ");
    puts(full_name);
    */
    /************************ 4 *****************************/
    /*int i;
    char menu[3][8] = {"New", "Display", "Exit"};
    char output[3][20] = {"You entered new","You entered display", "bye"};
    char input = '\0';
    int exit = 0, cur = 0;

    do
    {
        //textattr(NORMAL);
        clrscr();
        printf("\t\t\t\t\tMain Menu\n");
        for(i = 0; i < 3; i++)
        {
            gotoxy(20, i*3+5);
            if(i == cur) textattr(HIGHLIGHT);
            puts(menu[i]);
            textattr(NORMAL);
        }
        input = getche();
        switch(input)
        {
            case -32:
            case 0:
                input = getche();
                switch(input)
                {
                    // up
                    case 72:
                        cur = (cur-1 < 0)? 2 : cur-1;
                        break;
                    // down
                    case 80:
                        cur = (cur+1 > 2)? 0 : cur+1;
                        break;
                    // home
                    case 71:
                        cur = 0;
                        break;
                    // end
                    case 79:
                        cur = 2;
                        break;
                }
                break;
            // Tab
            case 9:
                cur = (cur+1)%3;
                break;
            // ESC
            case 27:
                exit = 1;
                break;
            // Enter
            case 13:
                //textattr(NORMAL);
                clrscr();
                puts(output[cur]);
                if(cur == 2) exit = 1;
                if(exit != 1) getch();
                break;
        }
    }while(exit != 1);
*/

    /************************ 5 *****************************/
    /*char word[50];
    int freq[26] = {0};
    printf("\nEnter a word: ");
    gets(word);

    int i, index;
    strlwr(word);
    for(i = 0; i < strlen(word);i++)
    {
        if(word[i] >= 'a' && word[i] <= 'z')
        {
            index = word[i] - 'a';
            freq[index] += 1;
        }
    }

    char ch;
    do{
        printf("\n which letter do you want to know its freq? ");
        ch = getche();
        ch = tolower(ch);
        if(ch == 32) break;
        index = ch - 'a';
        printf("\nfreq of letter %c is %d", ch ,freq[index]);
    }while(ch != 32);
    *//************************ 6 *****************************/
    /*
    char x[15], y[15];
    printf("\nEnter first word: ");
    gets(x);
    printf("\nEnter second word: ");
    gets(y);
    int i;
    for(i = 0; y[i] != '\0';i++)
    {
        x[i] = y[i];
    }
    x[i] = '\0';
    printf("\nFirst word: ");
    puts(x);

*/
    /************************ 7 *****************************/
    /*
    char x[15];
    printf("\nEnter a word: ");
    gets(x);

    int i = 0;
    while(x[i] != '\0')
    {
        i++;
    }
    printf("\nLength of this word is %d", i);
    */

    /************************ 8 *****************************/
    /*
    char word[50], edited[50];
    printf("\nEnter a word: ");
    gets(word);

    int i, j;
    for(i = 0, j = 0; i < strlen(word);i++)
    {
        if((word[i] > 'a' && word[i] < 'z') ||(word[i] > 'A' && word[i] < 'Z') || word[i] == ' ')
        {
            edited[j] = word[i];
            j++;
        }
    }
    edited[j] = '\0';
    printf("\nThe edited word is ");
    puts(edited);
    */
    return 0;
}
