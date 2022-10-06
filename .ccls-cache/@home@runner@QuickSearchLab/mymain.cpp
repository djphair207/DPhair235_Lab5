#include <iostream>

#include "QS.h"

using namespace std;

int main() {
	QS *qsptr = new QS;
	const int NUM_ITEMS = 7;	//This is actually the num corresdonding to the max index
	int array[] = {3,5,2,6,4,7,9,1};
	//int array[] = {5,4,7,9,6};
	//int array[] = {5,4,3,2,1};
	
	qsptr->createArray(NUM_ITEMS+1);		//Create array

	//cout << "Num of items added: " << qsptr->getSize() << endl;	//Check getSize
	//cout << qsptr->getArray() << endl;
	
	for(int i = 0; i <= NUM_ITEMS; i++){		//Add items to array
		qsptr->addToArray(array[i]);
	}

	//cout << qsptr->getArray() << endl << endl;
	
	/*
	cout << "\nFinished the for loop\n";												//Check getSize
	cout << "Num of items added: " << qsptr->getSize() << endl;
	cout << qsptr->getArray() << endl;

	qsptr->clear();
	cout << "\nChecking clear";																	//Check clear
	cout << "\nNum of items added: " << qsptr->getSize() << endl;
	cout << qsptr->getArray() << endl;
	*/

	/*
	int tempPiv = qsptr->partition(0,NUM_ITEMS,qsptr->medianOfThree(0,NUM_ITEMS));
	cout << "Pivot point is " << tempPiv << endl;
	cout << qsptr->getArray() << endl;

	int tempPivL = qsptr->partition(0,tempPiv-1,qsptr->medianOfThree(0,tempPiv-1));
	cout << "L partition result:" << "\n\t" << qsptr->getArray() << endl;

	int tempPivLL = qsptr->partition(0,tempPivL-1,qsptr->medianOfThree(0,tempPivL-1));
	cout << "LL partition result:" << "\n\t" << qsptr->getArray() << endl;

	int tempPivLH = qsptr->partition(tempPivL+1,tempPiv-1,qsptr->medianOfThree(tempPivL+1,tempPiv-1));
	cout << "LH partition result:" << "\n\t" << qsptr->getArray() << endl;
	
	int tempPivH = qsptr->partition(tempPiv+1,NUM_ITEMS,qsptr->medianOfThree(tempPiv+1,NUM_ITEMS));
	cout << "H partition result:" << "\n\t" << qsptr->getArray() << endl;

	int tempPivHL = qsptr->partition(tempPiv+1,tempPivH-1,qsptr->medianOfThree(tempPiv+1,tempPivH-1));
	cout << "HL partition result:" << "\n\t" << qsptr->getArray() << endl;

	int tempPivHH = qsptr->partition(tempPivH+1,NUM_ITEMS,qsptr->medianOfThree(tempPivH+1,NUM_ITEMS));
	cout << "HH partition result:" << "\n\t" << qsptr->getArray() << endl;
	*/	//Recursion by hand
	
	//cout << "\n\n";
	

	qsptr->sortAll();
	cout << qsptr->getArray() << endl;

}