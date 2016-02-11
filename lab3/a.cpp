#include  <iostream>

using std::cout;
using std::cin;
using std::string;

main () {
	char  oned; 
	cout << "enter: " ;
	cin >> oned;

	switch (oned) {
		case '1':
			cout << "one\n";
		case '2':
			cout << "two\n";
		case '3':	
			cout <<"three\n";
			break;
		case '4':
			cout <<"four\n";
			break;
		default:
			cout << "bish wht";
} 
}
