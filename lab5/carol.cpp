/*LAB5
 * Twelve Days of Christmas
 *
 * Raheema Kadwa 
 *
 * Program that allows user to print the 12 days of Christmas as many times 
 * as they want.
 * The program will use loops to sing the song.
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

main(){
	string previous, current="", day;
	bool cont;
	char response;

	// B(order)
	const string B = "~ . ~ . ~ . ~ . ~ . ~ . ";	

	cout<<B<<endl<<"Would you like to sing the carol (y/n)?: ";
	cin>>response;

	if (response=='Y'||response=='y'){
		cout << "generating... "<<endl;
		cont = true;
	}
	
	else {
		cout <<"OK, Thanks. \n";
		cont = false;
	}
	
	while (cont){
		cout <<B<<B<<B<<endl;	
		for (int counter=1; counter<=12; counter++){
			switch (counter){
				case (1):
					day = "first";
					current = "A partridge in a pear tree";
					break;
				case(2):
					day = "second";
					current = "two turtle doves, and ";
					break;
				case(3):
					day = "third";
					current = "three french hens,\n";
					break;
				case(4):
					day = "fourth";
					current = "four calling birds, ";
					break;
				case(5):
					day ="fifth";
					current = "five golden rings, ";
					break;
				case(6):
					day ="sixth";
					current = "six geese-a-laying,\n";
					break;
				case(7):
					day ="seventh";
					current = "seven swans-a-swimming, ";
					break;	
				case(8):
					day = "eigth";
					current= "eigth maids-a-milking, ";
					break;		
				case (9) :							
					day = "ninth";
					current = "nine ladies dancing, ";
					break;								
				case(10):
					day = "tenth";
					current = "ten lords-a-leaping,\n";							            		                  break;
				case(11):
					day = "eleventh";
					current = "eleven pipers piping, ";
					break;
				case(12):
					day = "twelvth";
					current = "twelves drummers drumming,";
					break;
			}
			//cout << "previous:" << previous <<endl;
			//cout <<"current: "<<current<<endl;;
		
			current += previous;
			previous= current;
		
			//cout <<"new previous: "<<previous<<endl;
			cout << "On the "<<day<<" day of Christmas, my true love sent to me \n";
			cout <<current<<".\n"<<"**"<<"\n";		
			
		}		
		cout << B<<endl<<"continue (y/n)?: ";
		cin >> response;
		if (response=='N'||response=='n'){
			cont = false;
			cout << B<<B<<B<<endl;
		}
	}

	cout <<"Happy Holidays! Goodbye... "<<endl<<B<<endl;
}
