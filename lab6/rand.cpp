/*generate random number c+ *Lab6
 * Guess My Number 
 * Raheema Kadwa 
 *
 * Program that generates a random number and allows user to guess the number a maximum amount of times.
 *
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//function to generate a random number
//rfMin = range from min 
//function works with negative numbers! 
int generateNum(int min, int rfMin){
	srand(time(0));
	int number =  rand()%(rfMin - min + 1 ) +  min ;
	return number;
}

//returns 0 if numbers are equal 
//returns 1 if guess is smaller than random number

//returns 2 if guess if larger than random number

int compare(int actual, int check){
	if (actual==check)
		return 0;
	else if (check < actual)
		return 1;
	else 
		return 2;
}

void play (){
	int tries =0 , guess, rand, correct;
	bool cont = true;
	string response;
	const int MIN = -1000 , MAX = 1000 , TRIES = 20 , LUCKY = 10;
	
	rand = generateNum (MIN,MAX);
	//cout << "Rand: " << rand << endl;
	
	while (cont){
		cout << "Enter a number between 1 and 1000: ";
		cin >> guess;

		correct = compare(rand,guess);
		//cout << "correct: " <<correct<<endl;

		if (correct == 0 ){
			cont = false;
			if (tries < LUCKY)
				cout << "Either you are insightful, or you are lucky! \n";
			else if (tries == LUCKY )
				cout << "Wow the lucky " << LUCKY <<"th try! \n";
			else 
				cout << "Really? You can do better than " << tries << " tries! \n ";
		}
		else {
			if (correct == 1) 
				cout << "Too Low. Try Again.\n";
			// the last option is that (correct = 2 )
			else  
				cout << "Too High. Try Again.\n";
			//update number of tries;
			tries++;
			//only allow user guess 10 times
			if (tries > TRIES){
				cont = false;
				cout << "You have exceeded the amount of tries!\n";
			}
			else   
				cout << "You have " << TRIES - tries << " tries left.\n";
		}//close else loop 
	}//close while loop 
}//end function 

main(){
	//function calls: 
	void play();

	//variables
	char response;
	bool cont = false;

	//begin game 
	do {
		cout << "Would you like to play (y/n)?: ";
		cin >> response;
		if (response == 'Y' || response == 'y'){
			cont = true;
			play();
			cout << "Would you like to play again (y/n)?: ";
			cin >> response;
			if (response == 'N' || response == 'n')
				cont = false;	
		}//if response is yes 
	}while (cont ==true);

	cout << "Quitting game ... \n";
}




