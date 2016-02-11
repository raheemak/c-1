/*code to raise base to exponent*/

#include<iostream>
using std :: cin;
using std :: cout;

float powerTo ( int exponent, int base) {
	float product = 1;
	for (int counter = 0 ; counter < exponent ; counter ++ ) 
		product *= base;
	return product ;
}

main(){
	int base, exponent;

	cout << "\nEnter base <ENTER> followed by exponent <ENTER>: ";
	cin >> base >> exponent;

	float product = powerTo(base, exponent);
	cout << "product: " << product << "\n\n";
}
