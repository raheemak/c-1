/*Raheema Kadwa
 *
 * Lab9
 *
 * Program that uses array block to store integers, performs operations on
 * integers entered, displays elements, and manipulates elements through 
 * specific functions.
 */

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::setw;
using std::left;

main(){
	const int SENTINAL = -999, SIZE = 20;
	void display (const int[], int), statistics (const int[],int&,int&,int&,double&,int);
	int  input (int[], int, int), search(const int[], int, int), count (const int[], int, int);
	int  array [SIZE], numElements,min,max,sum, replace(int[],int,int,int);
	int temp, amount, index, update; 
	bool modify (int[], int, int, int), clear (int[], int, int),cont = true, modified;
	double avg;
	char choice;

	cout << "\nWelcome to the world of Arrays!!!\n";
	numElements = input(array, SIZE, SENTINAL);
	cout <<endl;	
	while (cont){
		cout << "****"<<endl;
		cout <<"To input values into the array, enter i or I.\n";
		cout <<"To see statistic, enter s or S.\n";
		cout << "To count an element, type c or c.\n";
		cout << "To search for an element, type e or E.\n";
		cout << "To replace a number, type r or R.\n";
		cout << "To modify a given index, type M or m.\n";
		cout << "To clear either the entire array, or a given index, type l or L.\n";
		cout <<"To quit program, type q or Q.\n";
		cout << "****"<<endl;

		cout << endl << "Enter choice: ";
		cin >> choice;
		cout << "----\n";
		switch (choice){
		
		case 'i':
		case 'I':
			numElements = input (array, SIZE, SENTINAL);	
			cout << "You have entered: \n";
			display (array, numElements);
			break;
		case 's':
		case 'S':	
			statistics(array, min, max, sum, avg, numElements);
			cout << "Min: " <<min <<endl;
			cout <<"Max: " <<max<< endl;
			cout <<"Sum: " <<sum <<endl;
			cout <<"Average: " <<avg <<endl<<endl;
			break;
		case 'c':
		case 'C':
			cout << "Enter element you would like to search for: ";
			cin >> temp;	
			amount = count(array, numElements, temp);
			cout << temp <<" appears " << amount <<" times." <<endl;			
			break;
		case 'e':
		case 'E':
			cout << "Enter element you would like to search for: ";
			cin >> temp;
			amount = search (array, numElements, temp);
			cout << temp << " appears first at the " <<  amount << " position.\n";
			break;
		case 'r':
		case 'R':
			cout <<"Enter what number you want replaced: ";	
			cin >> temp;
			cout << "Enter new number: ";
			cin >> update;
			amount  = replace (array, numElements, temp, update);
			cout << temp << " was updated " << amount  << " times."<< endl;
			display (array, numElements);
			break;
		case 'm':
		case 'M':
			modified = false;
			while (!modified){
				cout <<"Enter a number between 1 and " <<numElements <<" to modify: ";
				cin >> index;
				cout <<"Enter a new value: ";
				cin >> update;
				modified = modify (array, numElements, index, update);
				if (!modified ) 	
					cout << "Invalid index... "<<endl;
			}
			display (array, numElements);
			break;
		case 'l':	
		case 'L':
			modified = false; 
			while (!modified){
				cout << "Enter -1 to clear entire array or number from 1 and " <<SIZE << ": ";
				cin >> index;
				modified = clear (array, numElements, index);
				if (!modified) 
					cout << "Invalid index... " <<endl;
			}
			display(array, numElements); 	 
			break;
		case 'q':
		case 'Q':
			cout << "Thank you...\nQuitting...\n\n";
			cont = false;
			break;
		default: 
			cout << "Unrecongized command... \n";
		}
	}
}

int input(int array [], int size, int sentinal){
	int numElements = 0 ;
	cout << endl;
	cout << "Enter -999 to stop.\n";
	for (int i = 0 ; i <size ; i ++	){
		cout << "Enter element " << i+1 << ": ";
		cin >> array[i];
		if (array[i]==sentinal)
			break;
		numElements++;
	}
	return numElements;
}

void display (const int array [], int max){
	cout << "\nPosition\tValue\n--------\t--------\n";
	for (int i=0; i<max; i++)
		cout <<left<<setw(6)<<i+1<<"\t\t"<< array[i]<<endl;	
	cout << endl;
}

void statistics(const int array [], int& min, int& max, int& sum, double & avg, int numElements){
	int current = min = max = sum =  array[0]; ;
	for (int i = 1; i <numElements ; i++){
		current = array[i];		
		if (current<min)
			min = current;
		else if (current>max)
			max = current;
		sum += current;
	}
	avg = sum / (numElements +1); 
}

int count  (const int array[], int max, int search){
	int counter =0 ;
	for (int i = 0 ; i < max ; i++)
	 	if (array[i]==search)
			counter++;
	return counter; 
}

int search (const int array[], int max, int search){
	int pos = -1;
	for (int i =0 ; i < max ; i++)
		if (array[i]==search){
			pos = i;
			break;
		}
	return pos;
}

int replace (int array[], int max, int old, int updated){
	int counter = 0;
	for (int i=0; i<max; i++)
		if (array[i]==old){
			array[i]=updated;
			counter++;
		}
	return counter;
}

bool modify (int array[], int numElements, int index, int updated){
	bool replaced = false;
	if (index > 0 && index <= numElements){
		array[index-1]=updated;
		replaced = true;
	}
	return replaced;
}


bool  clear (int array[], int numElements, int clear){
	bool changed = false;
	if (clear==-1){
		for (int i = 0; i < numElements ; i++)
			array[i] = 0;
		changed = true;
	}
	else if (clear > 0 && clear <= numElements){ 
		changed = true;
		array [clear-1]=0;
	}
	return changed;
}	

