// Includes string library for input/token, iostream to use cout & cin, and sstream tokens
#include <string>
#include <iostream>
#include <sstream>

// Using standard namespace
using namespace std;

// Main Method
int main()
{
	// String to store input line
        string input;
	
	// While loops infinitely, unless a break statement executes
        while(true)
        {
		// Output to ask for command
                cout << "Please enter your command: ";
		
		// getline method used to transfer input line into input string
                getline(cin, input);

		// If the input is exit, displays "Exiting" and  breaks from loop
                if(input == "exit")
		{
			cout << "Exiting" << endl;
                        break;
		}
		
		// Token string to store each token within the input line
                string token;
		
		// String to hold the previous token
		string before;

		// istringstream buffer to tokenize input
                istringstream is(input);

		// Continues as long as there is another token within the line
                while(is >> token)
                {
			// Pipe token case
                        if(token == "|")
                                cout << "Pipe" << endl;
			// Redirection token case
                        else if(token == "<" || token == ">" || token == ">>")
                                cout << "File Redirection: " + token  << endl;
                        // File token case
			else if(before == "<" || before == ">" || before == ">>")
                                cout << "File: " + token << endl;
                        // Option token case
			else if(token[0] == '-')
                                cout << "Options: " + token << endl;
                       	// Arguments token case
		        else if(before[0] == '-')
                                cout << "Arguments: " + token << endl;
                        // Command token case
			else
                                cout << "Command: " + token << endl;
			before = token;
               
		 }
        }
	// Returns 0 to indicate successful completion
	return 0;
}
