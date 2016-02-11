/* 
   Raheema Kadwa
   Sept 18,2015
*/

#include <iostream>

 using std::cout;
 using std::cin;
 using std::endl;
 using std::string;

 main() {
	string name,lname;
	string location;
	int age;
		
	cout << "Hello World!\n" << endl;
	cout << "What is your name? ";
	cin >> name;
	cin >> lname;

	cout << "Where are you from? ";
	cin >> location;
	
	cout << endl << "Very nice to meet you " << name << " " << lname << " of " << location <<"." << endl <<
	"Welcome to the world of C++!!" << endl;  

	cout << endl << "How old are you? ";
	cin >> age;

	if (age>21)
		cout <<"\nCongrats " <<name << "you are legal!:\n";	
	else if(age==21)
		cout <<"Congrats, you just made it!\n";
	else if (age>13)
                cout <<"\nCongrats on being a teen!\n";
	else 
		cout<<"\nLooks like you must wait another "<<21-age<<" years.\n";

/*
	std::cout << "Hello World" << " " << "I love you\n";
*/

}
