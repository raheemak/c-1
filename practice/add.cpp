#include <iostream>
using std::cout;
using std::cin;
using std:: endl;

main(){
	int op1, op2 , result = -1;
	char op;
	bool cont = false; 

	int add (int, int);
	bool  getEquation(int&, char& , int&);

	do {
		cont = getEquation (op1, op, op2);
		if (op == '+')	
			result =  add (op2, op1);
		cout << op1 << op << op2 << "=" << result << endl;
	}while (cont);
}//main()

int add (int op1, int op2){
	cout << "num() op1:" << op1 << " op2:" << op2 << endl;
	int r = op1 + op2;
	op1=op2=0;
	return r;
}//add()

bool getEquation ( int& op1, char& op, int&op2){
	cout << "Enter equation: ";
	cin >> op1 >> op >> op2;
	cout << "get(): " << op1 << op << op2 << endl;
	bool valid = false;
	switch (op){
		case '+':
			valid = true;	
			break;
		default: 
			valid = false;
	}
	return valid; 
}//getEquation()

