#include <iostream>

#include "QS.h"

using namespace std;

int main() {
	QS *qsptr = new QS;
	int array[] = {3,5,2,6,1,7,9,4};

	qsptr->createArray(7);
	for(int i = 0; i < 7; i++){
		qsptr->addToArray(array[i]);
	}

	cout << qsptr->getArray() << endl;
}