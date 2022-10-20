#include<stdio.h>
#include<stdlib.h>
#include<MyLibrary.h>
void main ()
{
    //1- Receive numbers from the user, and exit when the sum exceeds 100
    /*int num, sum = 0;
    do
    {
        printf("\nPlease, enter a number: ");
        scanf("%d", &num);
        sum += num;
    }while(sum <= 100);

    printf("\n****** Thank you, the sum is %d ******", sum);
    */

    //2- Simple Menu with 3 choices.
    /*
    char input;
    do{
        printf("\t\t\t Simple Menu \n");
        printf("a) Good Morning\n\n");
        printf("b) Good Evening\n\n");
        printf("c) Bye\n\n");
        printf("Please, enter your choice: ");
        scanf("%c", &input);
        clrscr();
        switch(input){
        case 'a':
            printf("Good Morning :) \n");
            getch();
            break;
        case 'b':
            printf("Good Evening ^-^ \n");
            getch();
            break;
        }
    }while(input != 'c');
    printf("Bye Bye :' \n");
    */

    // 3- Magic Box.

    int size, sum;
    printf("Please, enter an odd number: ");
    scanf("%d", &size);
    sum = size * (size * size + 1) / 2;
    printf("\n\nThe sum of columns, rows, and diagonals shall be %d\n\n", sum);

    int row = 1, col = (size/2)+1, i = 1, margin = 5, m_col = 5;
    gotoxy((col + margin) * m_col, (row + margin) * 2);
    printf("| %d ", i);
    do
    {
        if (i % size == 0)
            row = (row == size)? 1 : row+1;

        else
        {
            row = ((row-1) < 1)? size : row-1;
            col= ((col-1) < 1)? size : col-1;
        }
        i++;
        gotoxy((col + margin) * m_col, (row + margin) * 2);
        printf("| %d ", i);

        // print the last border on the right
        if(col == size)
        {
            if(i < 10)
                printf(" |");
            else
                printf("|");
        }

    }while(i < size*size);


    //print the horizontal borders
    int k, x;
    // loop over each row
    for(k = 1; k <= size+1; k++)
    {
        // loop to print dashes till you reach the end of the row
        for(x = (1 + margin) * m_col; x <= ((size + margin) * m_col)+1; x++)
        {
            gotoxy(x, ((k + margin) * 2)-1);
            printf("----");
        }
    }

    // 4- Find the Largest Number Among Three Numbers
    /*int x, y, z;
    printf("Enter x: ");
    scanf("%d", &x);

    printf("\nEnter y: ");
    scanf("%d", &y);

    printf("\nEnter z: ");
    scanf("%d", &z);

    if (x > y && x > z) printf("\nThe max number is x = %d", x);
    else if (y > x && y > z) printf("\nThe max number is y = %d", y);
    else printf("\nThe max number is z = %d", z);
    */

    // 5- Generate Multiplication Table "1*3=3, 2*3=6, ..."
    /*int i = 2, j = 1;
    for(; i <= 9; i++)
    {
        for(j = 1; j <= 9; j++)
        {
            printf("%d x %d = %d\t", j, i, i*j);
        }
        printf("\n");
    }
    */

    // 6- Check Whether a Character is an Alphabet or not
    /*char input;
    printf("Enter a character: ");
    scanf("%c", &input);
    if((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z'))
        printf("\nThat is a character indeed ");
    else
        printf("\nThat is not a character ");
    */

    // 7- count number of Alphabets & number of words in a sentence. (word count)
    /*int alpha_count = 0, word_count = 1;
    char ch, prev_ch;
    printf("Enter a sentence: \n");
    scanf("%c", &ch);
    prev_ch = ch;
    while(ch != '\n')
    {
        if(ch == ' ' && prev_ch != ' ')
            word_count++;

        else if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            alpha_count++;
        prev_ch = ch;
        scanf("%c", &ch);
    }
    printf("Words count is %d ,, alphas count is %d", word_count, alpha_count);
    */
}
