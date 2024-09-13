// Includes cstdlib library to use system functions
#include <cstdlib>
;

// Main Method
int main()
{
	// Makes dir1 and file10 inside it
	std :: system("mkdir dir1");
	std:: system("touch dir1/file10");
	
	// Makes dir2 and file20 inside it
	std :: system("mkdir dir2");
	std :: system("touch dir2/file20");
	
	// Makes file1 in the current directory
	std:: system("touch file1");
	
	// Makes a symbolic link, link1, in the current directory which links to file20 of dir2
	std :: system("ln -s dir2/file20 link1");
	
	// Returns 0 to indicate a successful completion
	return 0;
}
