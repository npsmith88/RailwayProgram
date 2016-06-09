/*CIST 2362
Nic Smith
Railway Program */
#include "CarList.h"

int main()
{
	CarList list;
	
	// Build the list with some values.
	list.appendNode("Black", "Coal");
	list.appendNode("BP", "Oil");
	list.appendNode("Silver", "Steel");
	
	// Display the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;


	system("pause");
	return 0;
}