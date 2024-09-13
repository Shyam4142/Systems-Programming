// Shyam Venkatesan
// Sumfact Program

// Include Statements
#include <stdio.h> // Used for printf method
#include <unistd.h> // Used for fork and getpid methods
#include <stdlib.h> // Used for atoi method
#include <sys/wait.h> // Used for wait method

// Main method that takes user input (integer) into first index of argv array 
int main(int argc, char *argv[])
{
    // ID variables for parent and the sum/factorial fork children
    int parentID, sumID, factorialID;
    
    // n1 stores the user input integer (atoi used to convert to integer)
    int n1 = atoi(argv[1]);
    
    // sum starts at 0
    int sum = 0;
    
    // factorial starts at 1
    int factorial = 1;
    
    // parentID given value of getpid method's return
    parentID = getpid();
    
    // sumID is a fork of the parent
    sumID = fork();
    
    // Checks if sumID is the child process (id value is 0)
    if(sumID == 0)
    {
        // Iterates from 1 to n1
        for(int i = 1; i <= n1; i++)
        {
            // Increments the sum
            sum += i;
        }
        
        // Outputs the sum value and the process id of the sum process
        printf("[ID = %d] Sum of positive integers up to %d is %d \n", getpid(), n1, sum);
    }
    
    // Parent and Factorial process cases
    else
    {
        // factorialID is a fork of the parent
        factorialID = fork();
        
        // Checks if factorialID is the child process (id value is 0)
        if(factorialID == 0)
        {
            // Iterates from 1 to n1
            for(int i = 1; i <= n1; i++)
            {
                // factorial multiplied by i and new value stored in factorial
                factorial *= i;
            }
            
            // Outputs the factorial value and the process id of the factorial process
            printf("[ID = %d] Factorial of %d is %d \n", getpid(), n1, factorial);
        }
        // Parent process case
        else
        {
            // wait method called twice to wait for both child processes to finish
            wait(0);
            wait(0);
            
            // Outputs a "Done" message with the process id of the parent process
            printf("[ID = %d] Done \n", getpid());
        }
    }
    
    // Returns 0 for successful execution
    return 0;
}

