/*
 * Raheema Kadwa
 * Lab 2
 * Pizza Pizza
 *
 * This is a virtual pizzeria which gives customers the option to order 
 * a pizza of their choosing. The customer can pay their balance, if they don't
 * their order is canceled. Customers can choose whether or not to see their 
 * receipt. 
	 
*/

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

main(){

	/*variables */
	string name, seeReceipt;
	int smallPizzas, largePizzas;
	double amtPaid=0, cost=0 ,change=0; 
	bool paid;
		
	cout << "\n------\nWelcome to Little Italy Pizzeria!\n";
	cout << "My name is Raheema and I am happy to take your order.\n\n";

	cout << "Please enter your name: ";
	cin >> name;
	cout <<"Thank you "<<name<<",\n";

	cout << "How many small pizzas would you like to order today? ";
	cin >> smallPizzas;

	cout << "How many large pizzas would you like to toder today? ";
	cin >> largePizzas;

	/*calculating cost by multipling cost of each pizza with amount wanted*/
	cost= 12.39* smallPizzas + 15.98* largePizzas;

	cout << "Thank you for your order " << name << ", the total amount due is: ";
	cout << cost << endl ;
	
	cout <<"Please make a payment: ";
	cin >> amtPaid;

	change = amtPaid-cost;
	
	/*check if cost is not paid in full */
	paid = cost<amtPaid;
		
	/*if the cost is paid then continue with order */
	if (paid){
	
		cout <<"Thank you " << name << ", your change is: " <<change;
		cout << "\nWould you like to view your receipt?\nType YES to view.  ";
		cin >> seeReceipt;
	
		/*if user wants to see recipt (if boolean is true), then print receipt*/	
		if (seeReceipt=="YES" or seeReceipt=="yes" ){
			cout <<"\n-------------------------------\n";
			cout <<"Receipt by Little Italy Pizza\n";
			cout << "-------------------------------\n";
			cout <<"Order for: "<<name<<endl<<endl<<"\t\tQuan    Price\n";
			if (smallPizzas>0)
				cout << "12-inch pizza    "<<smallPizzas<<"      "<<smallPizzas*12.39;
			if (largePizzas>0)
				cout << "\n14-inch pizza    " <<largePizzas << "      "<<largePizzas *15.98;
			cout << "\n-------------------------------";
			cout << "\nTotal\t\t        "<<cost;
			cout <<"\nAmount Recieved         "<<double(amtPaid);
			cout <<"\nChange\t\t        "<<change;
			cout <<"\n\nCashier: Raheema"<<endl;
			cout <<"-------------------------------\n\n";
		
	}	

		cout <<"\n Thank you for visiting. Please come back soon! \n"; 
	}

	/*else cancel the order and kick customer out */
	
	else{ 
		cout << "YOU ARE BEING KICKED OUT AND YOUR ORDER HAS BEEN CANCELED DUE TO ";
		cout <<"\nNONCOMPLIANCE TO PAY THE BILL IN TOTAL.\n";
	}
}

