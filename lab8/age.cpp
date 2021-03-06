/*Another Calculator 
 *
 * Raheema Kadwa
 * Lab 8
 *
 * Calcultor that asks user for current date and birth date and calculates
 * age. 
 * Checks to see if dates entered are valid.
 */
 
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::abs;
main(){
	int tries =0, cday, cmonth, cyear, bday, bmonth, byear, days, months, years;
	bool enterDate(int &, int&, int&), enterBirthday (int, int, int, int&, int&, int&);
	void calcAge (int, int, int, int, int, int,  int&, int&, int&);		
	bool entered, cont = true;
	char ans;
	
	cout << "\nWelcome to the age calculator!\n\n";

	while (cont){
		cout << "Enter today's date.\n";
		entered= enterDate(cday, cmonth, cyear);
		cont = !entered;
		//cout << "entered: " <<entered << "cont: " << cont <<endl;
		tries++;
		if ( tries > 2){
			cont = false;
			cout <<"Follow directions next time... "<<endl;
		}//if
		//cout<<"entered once... \n ";
	}//while
	
	//cout  << "before next check... \n";

	if (entered){
		cout <<"Would you like to calculate your birthday (y/n)?: ";
		cin >> ans;
		if (ans=='y')
			cont = true;
		else{
			cont = false;
			cout << "You are so chicken!\n";
			entered = false;
		}
	}
	
	tries =0;
	
	while (cont){
		cout << "Enter your birthdate. \n";
		entered = enterBirthday(cday, cmonth, cyear, bday, bmonth, byear);
		cont = !entered;
		
		//cout <<"entered: " <<entered <<"Cont: " <<cont<<endl;
		
		if (tries > 2){
			cont = false;
			cout << "Follow directions next time... " <<endl;
		}
	}	
	if (entered){
		calcAge(bday,bmonth,byear,cday,cmonth,cyear,days,months,years);
		cout << "You are " <<days <<" days, " << months << " months, " << " and " <<years << "years old. ";
		cout <<endl<<"Quitting... "<<endl;
	}					 	 
}

bool enterDate( int &day, int &month, int &year){
	//cout << "here: "<<endl;
	char slash;
	bool validDate(int, int, int), valid;
	cout << "Enter in form DD/MM/YYYY: ";
	cin >> month >> slash >> day >> slash >> year;
	valid = validDate (day, month, year);
	
	//cout <<"day: "<<day <<" month: "<<month <<" year: "<<year<<endl;
	//cout << "valid: " <<valid <<endl;
	
	return valid;
}

bool enterBirthday (int cday, int cmonth, int cyear, int & bday, int & bmonth, int & byear){
	bool enterDate(int &, int & ,int &), valid = false;
	bool dateBefore( int, int, int, int, int ,int);
	
	//if the birthday is in correct format, make sure its before currentDate
	if (enterDate (bday, bmonth, byear))
		valid = dateBefore (cday, cmonth, cyear, bday, bmonth, byear);
	return valid;
}

bool validDate (int day, int month, int year){
	bool valid = false;
	if  (month >= 1 && month <= 12){
		switch (month){
			case 2:
				if ( day >= 1 && day <= 28)
					valid = true;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day >= 1 && day <= 31)
					valid = true;
				break;
			default:
				//month 1, 3, 5, 7,8 10, 12		
				if (day >= 1 && day <= 31)
					valid = true;
			}
	}
	return valid;
}


bool dateBefore (int day1, int month1, int year1, int day2, int month2, int year2){
	bool valid = true;

	//if birthyear>currentyear
	if (year2>year1)
		valid = false;

	//if theyre equal, check months and years
	else if (year1==year2){
		if (month1>month2)
			valid = false;
		else if (month1==month2){
			if (day1>day2)	
				valid = false;
		}
	}
	return valid; 
}
						
void calcAge (int day1, int month1, int year1, int day2, int month2, int year2, int& days, int & months, int & years){
	//month1 = bmonth::: month2 = cmonth
	if (month1>month2){
		years = year2-year1-1;
		months = 12-month1-month2;
		days = abs(31-day1-day2);
	}
	else{
		years = year2-year1;
		months = 12 - month1;
		days = abs (31-day1-day2);
	}
}		
