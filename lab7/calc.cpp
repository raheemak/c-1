/*Raheema Kadwa
 * Lab 7
 *
 * program to simulate calculator:
 * can perform multiplication, division, subtraction and addition 
 * performs as many calculations as user wants 
  */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


main(){
	//functions
	bool parseInput (int&, char&, int&);
	double calculator (int, char, int);
	
	//variables
	int op1, op2;
	char space, oprt;
	bool valid = false;
	double result;
	
	cout << endl<<"------" <<endl;

	do{ 
		valid = parseInput (op1, oprt, op2); 
		result = calculator (op1, oprt, op2);
		if (op2 != 0  oprt == '/'){
			cout << op1 << " " << oprt << " " << op2 << " = "; 
			cout << result <<  "\n";
		}//if() 
	}while (valid);
	cout << "ok. It was a pleasure doing math with you. \n";
	cout << "------" <<endl << endl;	
}//main


//returns true if operand is one of "*+-/" and if user is not dividing by 0 
bool parseInput (int& op1, char& oprt, int& op2){
	cout << "Enter an expression or 0x0 to quit: ";
	cin >> op1 >> oprt >> op2;
	bool valid ;
	switch (oprt){
		case '+':
		case '-':
		case '*':
		case '/':	
			valid =  true;
			break;
		default:
			cout << "Error... Invalid operand. " << endl << endl;
			valid =  false;
	}//switch
	return valid;
}//parseInput


//calculator function: determines what operation to perform
double calculator (int op1, char oprt, int op2){
	double result; 
	switch (oprt){
		case '+':
			int addition (int, int);
			result =  addition (op1,op2);		
			break;
		case '-':
			int  subtraction (int, int);
			result = subtraction ( op1, op2);
			break;
		case '*':
			double multiplication (int , int );
			result =  multiplication ( op1, op2);	
			break;
		case '/':
			double division (int , int );
			result =  division ( op1,  op2);
			break;
	}//end of switch statement 
	return result; 
}//calculator 


//below are operational functions: perform addition, multiplication, division and subtraction
int addition (int op1, int op2){
	int sum =  op1 + op2;
	return sum;
}

int subtraction (int op1, int op2){
	int difference =  op1 - op2;
	return difference; 
}

double multiplication (int op1, int op2){
	double product = op1 * op2;
	return product;
}

double division (int op1, int op2){
	double dividend = 0 ;
	if (op2 == 0 )
		cout << "Error... cannot divide by 0\n";
	else 
		dividend = op1 / op2;
	return dividend;
}
	 
