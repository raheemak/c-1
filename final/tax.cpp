/*
 *
 * Raheema Kadwa
 *
 * Final Lab
 *
 * Program to calculate the taxes that user has to pay based on 
 * marital status and income.
 */

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;

main(){
	//prototypes
	void getTaxData(double&,double&,int&,int&);
	double calculateTaxes(double,double,int,int);
	void displaySummaryInformation(char, double, double);
	
	//main function variables
	int index=0, B_RATE, U_RATE;
	double SINGLE, MARRIED, currIncome, currTax;
	bool cont=true;;
	char SENTINAL = 'e', mStatus;

	//arrays to store information 
	char status [100];
	double income [100];
	double tax[100];
	
	//get information to set rates
	getTaxData(SINGLE,MARRIED,B_RATE,U_RATE);	

	//ask for tax information that needs to be calculated
	//ask until user enters SENTINAL value

	while (cont){
		cout << "Enter marital status or e to exit: ";
		cin >> mStatus;
		
		//is user wants to quit then exit while loop
		if (mStatus=='e'){
			cout << endl;
			cont = false;
			break;
		}

		//ask for income level
		cout <<"Enter income level: ";
		cin >> currIncome;
	
		//based on marital status calculate the taxes due 		
		if (mStatus == 'M')
			currTax = calculateTaxes (currIncome, MARRIED, B_RATE, U_RATE);
		else{ 
			currTax = calculateTaxes (currIncome, SINGLE, B_RATE, U_RATE);
			//cout << "income: "<<currIncome<<", limit: " <<SINGLE<<", bRate: " <<B_RATE;
			//cout <<" uRate: " <<U_RATE<<endl;
		}

		//print the taxes due
		cout << "Taxes due: $ " <<currTax <<endl;
		
		//update arrays in main
		//update counter
		status[index] = mStatus;
		income[index] = currIncome;
		tax[index] = currTax;
		
		cout << endl;
		index++;
	}

	if (index>0){

		cout << "Summary" << endl << "-----" << endl << endl;
		cout <<left<<setw(25)<<"Marital Status";
		cout <<left<< setw(25)<<"Income Level";
		cout <<left<<setw(25)<<"Taxes Due" <<endl;

	
		for (int x=0; x<index; x++){
			mStatus = status[x];
			currIncome = income [x];
			currTax = tax[x];
			displaySummaryInformation (mStatus, currIncome, currTax);
		}	
	}

	cout <<endl;
}

void getTaxData(double&uSingle, double&uMarried, int&baseRate, int&upperRate){

	cout <<endl;
	cout << "Enter upper Income Level for Single filers: ";
	cin >> uSingle;

	cout << "Enter upper Income level for Married Filers: ";
	cin >> uMarried;

	cout << "Enter rate to apply to all income that does not exceed the upper limit: % ";
	cin >> baseRate;

	cout << "Enter rate to apply to portion of income that exceeding upper limit: % ";
	cin >> upperRate;

	cout <<endl;
}

//function that calculates taxes based on upperlimit, rate, and income 
double calculateTaxes(double income, double  upperLimit, int baseRate, int upperRate){
	
	double tax;
	double bRate = baseRate/(double)100;
	double uRate = upperRate/(double)100;

	if (income>upperLimit)
		tax = upperLimit*bRate + uRate*(income-upperLimit);
	else 
		tax = income*bRate;
	return tax;
}	

void displaySummaryInformation (char mStatus, double income, double taxOwed){
	cout << left<< setw(25)<< mStatus;
	cout <<left << setw(25)<<income;
	cout <<left<<  setw(25)<<taxOwed << endl;
}



