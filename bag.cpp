#include <iostream>
#include "BagInterface.h"
#include "ArrayBag.h"
using namespace std;



void displayBag(ArrayBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
		<< " items:" << endl;
	vector<string> bagItems = bag.toVector();
	
	int numberOfEntries = (int)bagItems.size();
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}
	cout << endl << endl;
}

void bagTester(ArrayBag<string>& bag)
{
	cout << "isEmpty: returns" << bag.isEmpty()
		<< "; should be 1 (true)" << endl;
	displayBag(bag);
	
	string items[] = {"one", "two", "three", "four", "five", "one"};
	cout << "Add 6 items to the bag: " << endl;
	for (int i = 0; i < 6; i++)
	{
		bag.add(items[i]);
	}
	
	displayBag(bag);
	
	cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 0 (false)" << endl;
	cout << "getCurrentSize: returns " << bag.getCurrentSize()
		<< "; should be 6" << endl;
	
	cout << "Try to add another entry: Add(\"extra\") returns "
		<< bag.add("extra") << endl;
}


int main(){
	ArrayBag<string> bag;
	cout << "Testing the Array-Based Bag:" << endl;
	cout << "The initial bag is empty." << endl;
	bagTester(bag);
	cout << "All Done!" << endl;
}