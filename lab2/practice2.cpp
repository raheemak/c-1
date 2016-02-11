/*
 * raheema kadwa
 * practice lab2
 */


#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;

main() {

	string  fName, lName, university;
	char mi, slash;
	int month, date, year;
	double gpa;
	long salary;

	/*asking individually for each variable
	cout << "Enter first name: ";
	cin >> fName;
	cout << "Enter Middle Initial: ";
	cin >> mi;
	cout << "Enter Last name: ";
	cin >> lName;
	*/

	// input name in one line of code 
	cout << "Enter your name in the form first middle last: ";
	cin >> fName >> mi >> lName;
	
	/*ask for birthday with spaces in between 
	cout << "Enter birth date in the form of MM DD YYYY: ";
	cin >> month >> date >> year;
	*/

	//ask for birthday with / in between
	cout << "Enter your birthday in the form MM/DD/YY: ";
	cin >>  month >>  slash >> date >> slash >> year ;
	
	cout << "Enter current University: ";
	cin >>  university;
	
	cout << "Enter your GPA: ";
	cin >> gpa;

	cout << "Enter your salary: ";
	cin >> salary;
	
	
	cout <<  "This is what you entered: \n";
	cout << "\n--------\n";
	cout <<"Name: " << fName << " " << mi << " " << lName << endl;
	cout <<"Birthday: "<<month<<" " << date <<" " << year << endl;
	cout << "University: " << university << endl;
	cout << "GPA: " << std::setprecision(4) << gpa << endl;
	cout << "salary: " << std::setw(10) << salary << endl << endl;
	
	}


	
