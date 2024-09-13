// Includes cstdlib for system method
// Includes fstrem to print commands into myprog3
#include <cstdlib>
#include <fstream>

// Main Method
int main()
{
	// Recursively prints all directories/files in the current directory
	std :: system("ls -R");
	
	// Makes an ofstream for a new file, myprog3.cpp
	std :: ofstream of("myprog3.cpp");
	
	// Prints the pre-processor inclusion into myprog3
	of << "#include <cstdlib> \n";
	
	// Prints main method into myprog3
	of << "int main() {";
	
	// Prints a remove system call to recursively delete files/directories
	of << "std :: system(\" rm -r dir1 dir2 file1 link1\" ); ";
	
	// Prints a return 0 statement to indicate successful completion
	of << "return 0; }";

	// Closes the output file buffer
	of.close();
	
	// Compiles myprog3.cpp into executable myprog3
	std :: system("g++ myprog3.cpp -o myprog3");
	
	// Runs myprog3 executable
	std ::system("./myprog3");

	// Recursively prints all directories/files in the current directory to show deletion
	std :: system("ls -R");
	
	// Returns 0 to indicate successful completion
	return 0;
}
	
		

