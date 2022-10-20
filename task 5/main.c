#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MyLibrary.h>

#define NUM_EMPS 2
#define NORMAL 0x07
#define HIGHLIGHT 0x70

struct Emp_Struct
{
    int ID;
    char Name[30];
    float Salary;
    float Bonus;
    float Deduction;
    int notEmpty;
};

struct Dept
{
    int ID;
    char Name[30];
    struct Emp_Struct emps[NUM_EMPS];
};

int emps_count = 0;

int largest(int, int, int);
struct Emp_Struct AddNewEmployee();
void DisplayEmployee(struct Emp_Struct);

int main()

{
    // 1. takes 3 numbers as parameter, and returns the largest one among them
/*
    int i, nums[3];
    for(i = 0; i < 3; i++)
    {
        printf("\nEnter num %d: ", i+1);
        scanf("%d", &nums[i]);
    }
    int large = largest(nums[0], nums[1], nums[2]);
    printf("\nThe largest number is %d", large);
    */

    // 2. Emp
    /*
    printf("\n *** Enter the employee's data ***");
    struct Emp_Struct emp;
    int i;
    printf("\nEnter ID: ");
    scanf("%d", &emp.ID);

    _flushall();
    printf("\nEnter Name: ");
    gets(emp.Name);

    _flushall();
    printf("\nEnter Salary: ");
    scanf("%f", &emp.Salary);

    printf("\nEnter Bonus: ");
    scanf("%f", &emp.Bonus);

    printf("\nEnter Deduction: ");
    scanf("%f", &emp.Deduction);

    int net_salary = emp.Salary + emp.Bonus - emp.Deduction;
    printf("\n\n Employee ");
    puts(emp.Name);
    printf(" with ID (%d) has net salary of (%f)", emp.ID, net_salary);
    */

    // 3
    /*
    struct Emp_Struct emps[NUM_EMPS];
    int i;

    for(i = 0; i < NUM_EMPS; i++)
    {
        printf("\n *** Enter the data of employee %d ***", i+1);
        printf("\nEnter ID: ");
        scanf("%d", &emps[i].ID);

        _flushall();
        printf("Enter Name: ");
        gets(emps[i].Name);

        _flushall();
        printf("Enter Salary: ");
        scanf("%f", &emps[i].Salary);

        printf("Enter Bonus: ");
        scanf("%f", &emps[i].Bonus);

        printf("Enter Deduction: ");
        scanf("%f", &emps[i].Deduction);
    }

    printf("\n\n");
    for(i = 0; i < NUM_EMPS; i++)
    {
        printf("\n\n*** Emp %d ***", i+1);
        printf("\nID: %d", emps[i].ID);
        printf("\nName: ");
        puts(emps[i].Name);
        printf("Net Salary: %f", emps[i].Salary + emps[i].Bonus - emps[i].Deduction);
    }
    */
    // 4
    /*
    struct Emp_Struct e;
    e = AddNewEmployee();
    DisplayEmployee(e);
    */

    // 5
    /*
    int i;
    char menu[3][8] = {"New", "Display", "Exit"};
    int index, choice;
    char input = '\0';
    int exit = 0, cur = 0;
    struct Emp_Struct emps[NUM_EMPS];

    // The bigger loop to keep the menu going
    do
    {
        // Printing the menu
        clrscr();
        printf("\t\t\t\t\tMain Menu\n");
        for(i = 0; i < 3; i++)
        {
            gotoxy(20, i*3+5);
            if(i == cur) textattr(HIGHLIGHT);
            puts(menu[i]);
            textattr(NORMAL);
        }

        // Actions upon pressing a key
        input = getch();
        switch(input)
        {
            // ** Extended keys **
            case -32:
            case 0:
                input = getch();
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

            // ** Tab **
            case 9:
                cur = (cur+1)%3;
                break;

            // ** ESC **
            case 27:
                exit = 1;
                break;

            // ** Enter **
            case 13:
                clrscr();
                // Pressing Exit
                if(cur == 2)
                {
                    printf("Bye Bye");
                    exit = 1;
                }

                else
                {
                    // NEW
                    if(cur == 0)
                    {
                        printf("*** If you want to exit, press -1 *** \n\n");
                        printf("Enter an index in range of [0: %d]: ", NUM_EMPS-1);
                        scanf("%d", &index);

                        // keep getting index from user
                        while(index != -1)
                        {
                            if(index >= NUM_EMPS && index < 0)
                            {
                                printf("\nPlease input an index in range of [0: %d]", NUM_EMPS-1);
                            }

                            else
                                emps[index] = AddNewEmployee();

                            printf("\nEnter an index in range of [0: %d]: ", NUM_EMPS-1);
                            scanf("%d", &index);
                        }
                    }

                    // Display
                    else if(cur == 1)
                    {
                        // Don't display anything if there are no employees
                        if(emps_count == 0)
                        {
                            printf("There are no employees yet.");
                            getch();
                        }
                        else
                        {
                            printf("*** If you want to exit, press -1 *** \n\n");

                            printf("If you want to display all employees, press 2\nIf you want to display an employee by index press 3\n");
                            scanf("%d", &choice);
                            switch(choice)
                            {
                            case 2:
                                for(i = 0; i < emps_count; i++)
                                {
                                    if(emps[i].notEmpty == 1)
                                        DisplayEmployee(emps[i]);
                                }
                                getch();
                                break;

                            case 3:
                                printf("\nEnter an index in range of [0: %d]: ", NUM_EMPS-1);
                                scanf("%d", &index);

                                while(index != -1)
                                {
                                    if(index >= NUM_EMPS || index < 0)
                                        printf("\nPlease input an index in range of [0: %d] ", NUM_EMPS-1);

                                    else if(emps[index].notEmpty != 1)
                                        printf("\nThere is no employee with this index ");

                                    else
                                        DisplayEmployee(emps[index]);

                                    printf("\nEnter an index in range of [0: %d]: ", NUM_EMPS-1);
                                    scanf("%d", &index);
                                }
                                break;

                            default:
                                printf("Please enter 2 (All employees) or 3 (Employee by index) only");
                                break;
                            }
                        }
                    }
                }
                //if(exit != 1) getch();
                break;
        }
    }while(exit != 1);
    */


    // 7

    /*
    struct Dept d;
    int i;

    printf("\n *** Enter the data of department ***");
    printf("\nEnter ID: ");
    scanf("%d", &d.ID);

    _flushall();
    printf("Enter Name: ");
    gets(d.Name);


    for(i = 0; i < NUM_EMPS; i++)
    {
        d.emps[i] = AddNewEmployee();
    }

    printf("\n\n");
    printf("This is Department (%s) with ID %d\n", d.Name, d.ID);
    for(i = 0; i < NUM_EMPS; i++)
    {
        DisplayEmployee(d.emps[i]);
    }
    */
    return 0;
}

int largest(int a, int b, int c)
{
    if(a > b && a > c)
        return a;

    else if (b > a && b > c)
        return b;

    return c;
}

struct Emp_Struct AddNewEmployee()
{
    printf("\n *** Enter the employee's data ***");
    struct Emp_Struct emp;
    printf("\nEnter ID: ");
    scanf("%d", &emp.ID);

    _flushall();
    printf("Enter Name: ");
    gets(emp.Name);

    _flushall();
    printf("Enter Salary: ");
    scanf("%f", &emp.Salary);

    printf("Enter Bonus: ");
    scanf("%f", &emp.Bonus);

    printf("Enter Deduction: ");
    scanf("%f", &emp.Deduction);
    emp.notEmpty = 1;
    emps_count++;
    return emp;
}

void DisplayEmployee(struct Emp_Struct emp)
{
    printf("\n\n*** Emp ***");
    printf("\nID: %d", emp.ID);
    printf("\nName: ");
    puts(emp.Name);
    printf("Net Salary: %f", emp.Salary + emp.Bonus - emp.Deduction);
}
