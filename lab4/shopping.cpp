/*
 * Let's go shopping! 
 * Lab 4 
 * Raheema Kadwa 
 *
 * Program that allows cutomer to go online shopping. Customer has option to go shopping not. 
 * Customer has a budget and is displayed possibilites based on the amount of money she/he has. 
 * Customer can shop as long as they have money. 
 */

#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::fixed;

main(){
	const double WITCH = 39.00, GHOUL = 50.00, MADONNA = 12.99, TRUMP=24.99;
	double budget;
	string name, response, email; 
	bool contShop = true; 
	int counter; 
	char code; 

	cout << "\n-----\nWelcome to your Halloween Shopping Spree."<<endl;
	cout <<"My name is Raheema and I will be helping you with your order." <<endl;
	cout << "Who do I have the pleasure of assisting today? ";
	cin >> name;
	
	// ask if user wants to continue 
	cout <<"Thank you "<<name<<". Are you ready to spend your money (yes/no)? ";
	cin  >> response;
	cout << "----\n";
		//if no, then quit
	if (response == "NO" || response == "no")
		cout << "Thank you "<<name<<". Come back soon!\n----\n";
	//if yes, then continue 
	else if (response == "YES" || response == "yes"){

		cout <<"OK "<<name<<". How much money do you have to spend? ";
		cin >>  budget ;
 
		// don't begin shopping if there is not enough money to buy the min priced object 
		if (budget < MADONNA){ 
			contShop = false; 
			cout << "----\nYou do not have enough money to go shopping. \n";
			cout <<"Refill your balanace and come back soon!\n----\n";
		}
		while (contShop) {
			counter = 1 ;

			
			if (budget >= MADONNA)  { 
				cout <<"\nOK "<<name<<" here are your choices.\n";
				cout << "  "<<counter <<". A retro Madonna costume, "<<MADONNA<<". Code: 'M'.\n";
				if (budget >= TRUMP ) {
					counter ++ ;
					cout <<"  "<< counter << ". A Donald Trump constume, "<<TRUMP <<". Code: 'T'.\n";
					if (budget >= WITCH ) {
						counter ++ ;
						cout <<"  "<< counter<< ". A witch witch costume, " << WITCH << ". Code: 'W'.\n";
						if  ( budget >= GHOUL){
							counter ++ ;
							cout <<"  "<< counter <<". A gooooulish mask, "<<GHOUL << ". Code 'G'.\n";
						}
					}
				}
			}
			cout << "\nEnter code to purchase: ";
			cin >>code;

			switch (code){
				case 'M':
					cout <<"Feisty! ";
					cout << "You purchased a Madonna costume for " <<MADONNA<< ".\n";
					budget -=MADONNA;	
					break;
				case 'T':
					if (budget >= TRUMP){
						cout <<"Good luck with elections! ";
						cout <<"You purchased a Donald Trump costume for " <<TRUMP <<". \n";
						budget -=TRUMP;
					}else
						cout <<"Nice try! This was not one of your options!\n";
					break;
				case 'W':
					if (budget >= WITCH){
						cout <<"You'll look bewitching! ";
						cout <<"You purchased a witch costume for " << WITCH << ". \n";
						budget -= WITCH;
					}else
						cout <<"Nice try! This was not one of your options!\n";
					break;
				case 'G':
					if (budget >= GHOUL){
						cout <<"Spooooky! ";
						cout <<"You purchased a ghoul mask for "<<GHOUL<< ". \n";
						budget -=GHOUL;
					}else
						cout <<"Nice try! This was not of your options!\n"; 
					break;
				default: 
					cout <<"Not regonized code. \n";
					break;
			}
			
			cout << "Your balance is: " << budget << ".\n";
			if (budget < MADONNA) {
				cout << "You do not have enough money to continue shopping.\n";
				cout << " ---- \nWould you like to be emailed your receipt (yes/no)? ";
				cin >> response;
				if (response == "yes"){
					cout << "Enter your email: ";
					cin >> email;
					cout << "An email has been sent to "<<email<<". "<<endl; 
				}
				cout << "----\nThank you for shopping with us "<<name<<".\n----\n";
				contShop = false; 
			}else { 
				cout << "Would you like to continue shopping (yes/no)? ";
				cin >> response;				 
				if (response=="yes")
					contShop= true;
				else {
					contShop = false;
					cout <<"----\nWould you like to be emailed a receipt (yes/no)? ";
					cin >> response;
					if (response == "yes"){
						cout << "Enter your email: " ;
						cin >> email;
						cout << "An email has been sent to "<< email <<". \n";
					}
					cout << "----\nThank you for shopping with us. \n";
				}
			}
		}
	}
	// if command not recognized, then quit
	else 
		cout << "Not recognized. Quitting...\n----" <<endl;

}
