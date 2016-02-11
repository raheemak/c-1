/*midterm lab
 * Raheema Kadwa
 *
 * Program that allows user to create a rectangle based on the size they want, 
 * either hollow or filled, with the character of their choice. 
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

main(){
	char response, type, border,fill;
	int height=0, length=0, total=1, numH=0, numF=0;
	bool cont=false;
	int tempArea=0, tempPerimeter=0;
	double avgArea=0, avgPerimeter=0;

	cout <<"Would you like to draw a rectangle (y/n)?: ";
	cin >> response;
	
	//if user wants to display rectangle
	if (response=='Y'||response=='y')
		cont = true;			
	//if user does not want to display a rectangle
	else if (response=='N'||response=='n'){
		cout <<"OK Coward! Come back when you are ready.\n";
		cont = false;
	}
	//if command not recognized 
	else{
		cout <<"You are stupid for not following directions!\n";
		cont= false;
	}


	while (cont){
		cout <<"What type of rectangle would you like to draw?"<<endl;
		cout <<"(H)ollow or (F)illed: ";
		cin >> type;

		//ask for dimensions
		cout << "dimensions must be between 10 and 40!" <<endl;
		cout << "Enter length: ";
		cin>>length;
		cout << "Enter height: ";
		cin>>height;

		//will only draw rectangle if within range
		if (height>=10||height<=40){
			cout << "Enter border character: ";
			cin >> border;

			//temp area and perimeter calculated:
			tempArea = length * height;
			tempPerimeter = 2*length + 2*height;

			//update average perimeter and area sums (no division yet)
			avgArea += tempArea;
			avgPerimeter += tempPerimeter;
		
			//increment total number of boxes
			total++;

			if (type=='H'||type=='h'){
		
				//increment the amount of hollow boxes by 1
				numH++;
				//the fill charater will be a space 
				fill = ' ';
			}
			else {
				//increment the amount of filled characters by 1
				numF++;
				cout <<"Enter fill character: ";
				cin >>fill;
			}
				
			cout <<"\n";
			for (int row=0; row< height ; row++){
				cout << border;
				for (int column = 1; column < length-1; column++){
					if (row==0||row==height-1)
						cout <<border;
					else 
						cout <<fill;	
				}
				cout <<border;
				cout <<"\n";		
			}	
		
		}	
		cout <<"Would you like to draw another rectangle(y/n)? ";
		cin >> response;
		//continue unless user explicitly says they do not want to 	
		if (response=='n'||response=='N')
			cont = false;
		else 
			cont = true;
		
	}

	//total is intiallized as 1 so there is no error in division if user does not draw any boxes
	//remove the intial 1 
	if (total>1)
		total -=1;
	//display stats	
	cout << "Filled: " <<numH<<endl;
	cout << "Hollow: " <<numF<<endl;
	cout <<"Total: " <<total<<endl;
	cout <<"Average Area: "<<avgArea/total<<endl;;	
	cout <<"Average Perimeter: "<<avgPerimeter/total<<endl;;

}

