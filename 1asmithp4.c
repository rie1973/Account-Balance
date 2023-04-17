/*--------------------------------------------------------------------------
Program File:   asmithp4.c
Author:         Ann Smith
Date:           March 20  2022
Assignment:     #4
Objective:      This program will calculate and give output for 5 deposits
                and 5 withdrawals, as well as the final total. A bank statement
                has been included.
---------------------------------------------------------------------------*/

#include <stdio.h>

int main (void)
{
//assign variables
int     counter,  number_deposits, number_withdrawals;
float   deposit[5], withdrawal[5], start_balance, current_balance;

// welcome message
    printf ("Welcome to the Computer Banking System.\n\n");

// Prompt user to input current balance.
    printf ("Enter your current balance in dollars and cents: ");
    scanf ("%f", &start_balance); //user input

        while ( start_balance < 0 )
        {
        printf("*** Beginning balance must be at least zero, please re-enter.\n");

        printf ("Enter your current balance in dollars and cents: ");
        scanf ("%f", &start_balance); //user input
        } // end of "while" loop

//prompt user for number of deposits
    printf ("\nEnter the number of deposits (0-5): ");
    scanf ("%i", &number_deposits); //user input

// "while" loop for deposits
        while ( number_deposits < 0 || number_deposits > 5 )
        {
        printf("*** Invalid number of deposits, please re-enter.\n");


        printf ("Enter the number of deposits (0-5): ");
        scanf ("%i", &number_deposits); //user input

        } // end of "while" loop

//prompt user for number of withdrawals

    printf ("\nEnter the number of withdrawals (0-5): ");
    scanf ("%i", &number_withdrawals); //user input

// "while" loop for withdrawals
        while ( number_withdrawals < 0 || number_withdrawals > 5 )
        {
        printf("Invalid number of withdrawals, please re-enter.\n");


        printf ("Enter the number of withdrawals (0-5): ");
        scanf ("%i", &number_withdrawals); //user input

        } // end of "while" loop

//set current balance if there are no deposits to be made
    if (number_deposits == 0)
        {
        current_balance = start_balance;
        }

    printf ("\n"); //creates "block spacing" for deposits

//sets counter for deposits and accumulates it to current balance
    for ( counter = 1; counter <= number_deposits; ++counter )
    {
        printf ("Enter Deposit #%i: ", counter);
        scanf ("%f", &deposit[counter - 1]); // user input

        if ( deposit[counter -1] < 0)
        {
        printf ("*** Deposit must be greater than zero, please re-enter.\n");
        counter = counter - 1;
        }//end of "if" statement

        else if (counter > 1)
        {
        current_balance = current_balance + deposit[counter - 1];
        }// end of "else if" statement

        else
        {
        current_balance = start_balance + deposit[counter - 1];
        } //end "else" statement

    }//end "for" loop

    printf ("\n"); //creates "block spacing" for deposits

 //sets counter for withdrawals and deducts from  current balance
    for ( counter = 1; counter <= number_withdrawals; ++counter )
    {
       printf ("Enter Withdrawal #%i: ", counter);
       scanf ("%f", &withdrawal[counter - 1]); // user input

       if ( withdrawal[counter -1] < 0)
        {
        printf ("*** Withdrawal must be greater than zero, please re-enter\n.");
        counter = counter - 1;
        } //end of "if" statement

       else if ( withdrawal[counter -1] > current_balance )
       {
        printf ("*** Withdrawal amount exceeds current balance, please re-enter.\n");
        counter = counter - 1;
       }// end of "else if" statement

       else
       {
        current_balance = current_balance - withdrawal[counter - 1];
       } //end "else" statement

     } //end "for" loop

    printf ("\n");//creates "block spacing" for withdrawals

//closing balance statement
    printf ("*** The closing balance is %.2f ***\n", current_balance);

    printf ("\n");//creates "block spacing" for withdrawals

// statements to print depending on a total balance after deposits and withdrawals
    if (current_balance >= 50000.00)
        {
            printf("*** It is time to invest some money! ***\n\n");
        } // end of "if" statement

       else if (current_balance >= 15000.00 && current_balance < 50000.00)
        {
            printf("*** Maybe you should consider a CD. ***\n\n");
        } // end of "else if" statement
        else if (current_balance >= 1000.00 && current_balance < 15000.00)
        {
            printf("*** Keep up the good work! ***\n\n");
        } // end of "else if" statement
        else if (current_balance >= 0.00 && current_balance < 1000.00)
        {
            printf("*** Your balance is getting low! ***\n\n");
        } //end of "else if" statement

// Begin bank record portion of output

    printf ("*** Bank Record ***\n");

    printf ("\nStarting Balance: $ %1.2f\n\n", start_balance);

    for ( counter = 1; counter <= number_deposits; ++counter )
    {
        printf ("Deposit #%i: %14.2f\n", counter, deposit[counter - 1]);
    }  //end "for" loop

    printf ("\n");//creates "block spacing" for withdrawals

    for ( counter = 1; counter <= number_withdrawals; ++counter )
    {
        printf ("Withdrawal #%i: %11.2f\n", counter, withdrawal[counter - 1]);
    }//end "for" loop

    printf ("\nEnding Balance: $ %8.2f\n", current_balance);

   return (0);

} //end of program
