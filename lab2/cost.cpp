#include <iostream>

using std::cout;
using std::cin;
using std::string;

main(){
	double cost;
	int changeTemp=0;
	cout<<"enter price: ";
	cin>>cost;
	cout <<"\nPlease pay "<<int(cost)<<" dollars, ";
	cout << ((cost-int(cost))*100)/25 << " quarters, ";
	changeTemp = changeTemp - ((changeTemp/25)*25);
	cout <<"\ntest: "<<changeTemp<<"\n";
	cout << changeTemp/10 <<" dimes, ";
	changeTemp = changeTemp - ((changeTemp/10)*10);
	cout << "\ntest: "<<changeTemp;
	cout << "\n"<<changeTemp/5 <<" nickels. ";

	
	/*cout <<((cost%1.0)%.25)/.10<<" dimes, "<<(((cost%1.0)%.25)%.10.0)/.01;
	cout <<"pennies. \n";*/
}	
