#include <iostream>

using std::cin;
using std::cout;
using std::string;

main(){
	const int MAXINPUT = 5;
	string names [MAXINPUT];
	int ages [MAXINPUT];
	int id;

	cout << "\n";

	//cin names and ages
	for (int x =0 ; x< MAXINPUT ; x ++ ) {
		cout << "Name: ";
		cin >> names[x];
		cout << "Age: ";
		cin >> ages [x];
		cout << "\n";
	}

	//cout names and ages
	for (int x =0 ; x < MAXINPUT ; x++)
		cout << x<< ".) Name:" <<names [x] << " Age:" << ages [x] << "\n";
	
	cout << "\n";


	//ask user what students information they would like to see
	do {
		cout << "ID (1-" << MAXINPUT << "): ";
		cin >> id;
		if (id!=-999){
			id -- ;
			cout << "Name:" << names[id] << " Age:" << ages[id]<<"\n";
		}	
	cout << "\n";
	}while(id!=-999); 		
}
