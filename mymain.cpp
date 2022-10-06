#include <iostream>

#include "QS.h"

using namespace std;

int main() {
	QS *qsptr = new QS;
	int array[] = {3,5,2,6,4,7,9,1};
	
	qsptr->createArray(8);		//Create array

	//cout << "Num of items added: " << qsptr->getSize() << endl;	//Check getSize
	//cout << qsptr->getArray() << endl;
	
	for(int i = 0; i < 8; i++){		//Add items to array
		qsptr->addToArray(array[i]);
	}

	/*
	cout << "\nFinished the for loop\n";												//Check getSize
	cout << "Num of items added: " << qsptr->getSize() << endl;
	cout << qsptr->getArray() << endl;

	qsptr->clear();
	cout << "\nChecking clear";																	//Check clear
	cout << "\nNum of items added: " << qsptr->getSize() << endl;
	cout << qsptr->getArray() << endl;
	*/

	qsptr->medianOfThree(0,7);
	cout << qsptr->getArray() << endl;
}