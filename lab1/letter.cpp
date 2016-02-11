#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

main(){
	string urName, friendName, friend2name, yourLoc, friendLoc, feeling;
	/*food*/
	
	cout<<"\n---------\nHello, I will help you write a letter today.\n";
	cout<<"PLEASE NOTE: when entering information do NOT include spaces, as this will \nresult in error. Thanks!"<<"\n---------"<<endl;

	cout<<"\nPlease enter your name: ";
	cin>>urName;
	cout<<"Enter the name of your letter's recipient: ";
	cin>>friendName;
	cout<<"Enter your city name: ";
	cin>>yourLoc;
	cout<<"Enter recipient's location: ";
	cin>>friendLoc;
	cout<<"Enter name of another friend: ";
	cin>>friend2name;
	cout<<"Enter how you are feeling: ";
	cin>>feeling;
	cout<<"\n----\nThank You, Your letter is being generated!\n----\n\n";
 		
	cout<<"Dear "<<friendName<<endl<<'\t';
	cout<<"Hi! How are you? "<<"I'm feeling "<<feeling<<". ";
	cout<<yourLoc<<" doesn't seem the same since you";
	cout<<" moved \nto "<< friendLoc << ". How's "<<friend2name<<" doing? ";
	cout<<"It's been a while. Well, I hope you are well. Please write";
	cout<<endl<<"back soon. I know "<<friendLoc<<" is busy.\n\t\t\t\t\tSincerely, \n\t\t\t\t\t "<<urName;
	cout<<endl;

 
}


