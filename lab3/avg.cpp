/*Fun With Numbers
 * Raheema Kadwa
 * LAB 3
 *
 *Game that asks user to enter three number, and the asks questions, checks for accuracy
 * and returns the correct answers along with score. 
 * User can choose no to play the game. 
 * 
 * Checks for min, max, avg, and sum. 
 */

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;

main(){
	string name, status;
	int  num1, num2, num3, userSum, min, max, userMin, userMax, sum, score, userAvg, roundedAvg;
	char space; 
	double avg;
	bool inRange;

	cout << "----"<<endl;	
	cout << "Welcome to Math Challenge CISC 1600!"<<endl;
	cout << "My name is Raheema and I challenge you to test ";
	cout <<"your math skills. \nType START to begin or END to quit: ";
	cin >>status;

	if (status == "START" || status == "start"){	
		cout <<"You are a brave soul! Who am I playing with?: ";
		cin >>name;
		cout << "-----\nOK Here we go "<<name<< "!"<<endl;
		cout <<"Enter three numbers in the form ## ## ## in the range 0 to  1000 : ";	
		cin >> num1 >>  num2 >>  num3;
		
		//check to see if the numbers entered are within the specified range 
		inRange= num1>0 && num1<1000 && num2>0 && num2<1000 && num3>0 && num3<1000;
		//if they are, then continue with the game 
		if (inRange){
			cout << endl<<"Thank You "<<name <<", you entered ";
			cout << num1 << ", " << num2 << ", " << num3 << endl;
		
			//ask user for values
			cout <<"Guess the sum? ";
			cin >> userSum;
			cout << "Guess the average to the nearest WHOLE number: ";
			cin >> userAvg;
			cout << "Guess the max? ";
			cin >> userMax;
			cout << "Guess the min? ";
			cin >> userMin;;
		
			// do calculationa	
			sum = num1 + num2 + num3;
			avg = sum/3.0;

			// this is done because user precision will not match program precision for avg
			// integers can be compared, so an integer is asked for 
			roundedAvg = sum/3;
			
			//find max 
			if (num2>=num1 && num2 >= num3)
				max = num2;
			else 
			if (num1 >= num3 && num1 >= num2 )		
				max = num1;
			else
				max = num3;
	
			//find min 
			if (num2<=num1 && num2<=num3)
			min = num2;
			else 
			if (num1 <= num3 && num1 <= num2)
			min = num1;
			else 
				min = num3;
	
			//calculate how many right 
			score=0;
			if (userSum == sum)
			score++;
			if (userAvg == roundedAvg)
				score++;
			if (userMin == min)
				score++;
			if (userMax == max) 
				score++;			
		
			//display correct answers
			cout << "------\n";
			cout << "The sum is " << sum << "." << endl;
			cout << "The  average is ";
			cout << std::setprecision(2)<< std::fixed;
			cout << avg <<". "<< endl;
			cout << "The maximum is "<<max  << "." <<endl;
			cout << "The minimum is " << min << "." << endl ; 		
			
			//display message according to performance score 
			cout << "----\n";
			if (score==0)
				cout << ":( ";
			else
			if (score==1)
				cout << "Make an effort";	
			else
			if (score==2)	
				cout << "You did an OK job.";
			else
			if (score ==3)
				cout << "Good job!";
			else
				cout << "Excellent!"; 
		
			cout << endl<< "You got a score of " << score << " out of "  << "4. ";                  	       	    cout << endl << "Thank you for being and brave playing! " << endl;
			cout << "----"<<endl;
		}
		//if numbers are not within range 
		else {	
			cout <<"-----\n";
			cout <<"Quitting program... the numbers you entered were not within the range ... \n";
		}
	}
	else 
		cout << "----\nQuitting game ....\n---- "<< endl;

}
