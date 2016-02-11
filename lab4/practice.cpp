#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#include <iomanip>
using std::setprecision;
using std::fixed;
using std::setw;
using std::left;

main (){
	string status;

	cout << "----\n";
	cout << "Hello, Welcome to my seasonal game! " <<endl;
	cout << "Do you want to play the game? Type 'YES' or 'NO': ";
	cin >> status;

	//check if user wants to play game
	if (status == "YES" || status== "yes" || status== "y" || status == "Y"){
		/*switch (){
		}*/		
	}
	//user does not want to play game 
	else if (status == "NO" || status == "no" || status=="N" || status=="n")
		cout << "----\nQuitting game...\n----\n";
	//command entered not recognized
	else {
		cout << "----\nFollow directions next time.\n";
		cout <<"Quitting game...\n----\n";
	}
}

