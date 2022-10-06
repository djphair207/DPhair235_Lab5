#include "QS.h"

bool QS::createArray(int capacity){
	if(capacity <= 0){
		return false;
	}
	if(ptr != 0){
		delete [] ptr;
		ptr = new int[capacity];
	}
	else{
		ptr = new int[capacity];
		//cout << "created new int array" << endl;
		cout << "size of ptr: " << sizeof(ptr) << endl;
	}
	return true;
}

bool QS::addToArray(int value){
	if(currPos <= (sizeof(ptr) / sizeof(int))){
		cout << "currPos: " << currPos << ", ";
		ptr[currPos] = value;
		cout << "ptr[currPos]: " << ptr[currPos] << endl;
		currPos++;
		return true;
	}
	return false;
}

string QS::getArray() const {
	stringstream ss;
	string arrayStr;
	bool end = false;
	ss << "{";
	cout << "Size of array shown by ptr in bits: " << sizeof(ptr) << endl;
	cout << "Size of a single int in bits: " << sizeof(int) << endl;
	cout << "max val of i: " << (sizeof(ptr) / sizeof(int)) << endl;
	for(int i = 0; i < (sizeof(ptr) / sizeof(int)); i++){
		cout << "In loop " << i << endl;
		cout << "Value of 'ptr' at " << i <<": "<< ptr[i] << endl;
		if(i == ((sizeof(ptr) / sizeof(int)) - 1)){
			end = true;
			ss << ptr[i] << "}";
		}
		if(!end){
			ss << ptr[i] << ",";
			//ss >> arrayStr;
		}
	}
	arrayStr = ss.str();
	return arrayStr;
}