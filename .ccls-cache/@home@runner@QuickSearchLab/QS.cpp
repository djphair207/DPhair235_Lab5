#include "QS.h"
/* * * * * * * * * * * * * * * */
bool QS::createArray(int capacity){
	//cout << capacity << endl;			//DEBUG
	size = capacity;
	if(capacity <= 0){
		return false;
	}
	if(ptr != 0){
		delete [] ptr;
		ptr = new int[capacity];
	}
	else{
		ptr = new int[capacity];
		//cout << "created new int array" << endl;		//DEBUG
		//cout << "size of ptr: " << size << endl;		//DEBUG
	}
	//cout << "created array contents: ";			//DEBUG
	//for(int i = 0; i < capacity; i++){			//*
		//cout << *(ptr+i) << " ";						//*
	//}																				//*
	//cout << endl;														//*
	return true;
}
/* * * * * * * * * * * * * * * */
bool QS::addToArray(int value){
	if(currPos < size){
		//cout << "currPos: " << currPos << ", ";		//DEBUG
		*(ptr+currPos) = value;
		//cout << "ptr[currPos]: " << ptr[currPos] << endl;		//DEBUG
		currPos++;
		return true;
	}
	return false;
}
/* * * * * * * * * * * * * * * */
string QS::getArray() const {
	stringstream ss;
	string arrayStr;
	bool end = false;
	ss << "{";
	//cout << "Size of array shown by ptr in bits: " << sizeof(ptr) << endl;
	//cout << "Size of a single int in bits: " << sizeof(int) << endl;
	//cout << "max val of i: " << (sizeof(ptr) / sizeof(int)) << endl;
	for(int i = 0; i < size; i++){
		//cout << "In loop " << i << endl;
		//cout << "Value of 'ptr' at " << i <<": "<< ptr[i] << endl;
		if(i == size - 1){
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
/* * * * * * * * * * * * * * * */
int QS::getSize() const {
	return currPos;
}
/* * * * * * * * * * * * * * * */
void QS::clear() {
	delete[] ptr;
	ptr = NULL;
	currPos = 0;
}
/* * * * * * * * * * * * * * * */
int QS::medianOfThree(int left, int right) {
	int middle;
	if(ptr == NULL){
		return -1;
	}
	else if(left < 0 || left >= size){
		return -1;
	}
	else if(right < 0 || right >= size){
		return -1;
	}
	else if(left > right){
		return -1;
	}
	else{
		middle = (left + right)/2;
		//cout << "Middle index is " << middle << endl;		//DEBUG
	}
	do{
		if(*(ptr+middle) < *(ptr+left)){
			swap(*(ptr+middle),*(ptr+left));
		}
		else if(*(ptr+right) < *(ptr+middle)){
			swap(*(ptr+right),*(ptr+middle));
		}
		else{
			//DO NOTHING
		}
		//cout << "{" << *(ptr+left) << ", " << *(ptr+middle) << ", " << *(ptr+right) << "}\n";	//DEBUG
	} while (*(ptr+middle) < *(ptr+left) || *(ptr+right) < *(ptr+middle));
	return middle;
}
/* * * * * * * * * * * * * * * */
int QS::partition(int left, int right, int pivotIndex){
	if(ptr == NULL || left < 0 || left >= currPos || right < 0 || right >= currPos || right < left || pivotIndex < left || pivotIndex > right){
		//cout << "bad inputs or empty array\n";			//DEBUG
		return -1;
	}
	swap(*(ptr+left),*(ptr+pivotIndex));
	int up = left + 1;
	int down = right;
	do{
		while(*(ptr+up) <= *(ptr+left) && up < (right - 1)){
			up++;
		}
		while(*(ptr+down) > *(ptr+left) && down > left){
			down--;
		}
		if(up < down){
			swap(*(ptr+up),*(ptr+down));
		}
	} while(up < down);
	swap(*(ptr+left),*(ptr+down));
	return down;
}
/* * * * * * * * * * * * * * * */
void QS::recursiveSort(int left, int right){
	//DEBUG: make sure no inf. loop
	/*
	counter++;
	if(counter > 10){
		return;	//stop the madness
	}*/

	if(ptr == NULL){
		return;	//DO NOTHING
	}
	else if(currPos == 1){
		return;	//DO NOTHING
	}
	else{
		int pivot = this->partition(left,right,this->medianOfThree(left,right));
		cout << "Pivot is: " << pivot << endl;
		cout << "\tresult of partition:\t";
		cout << this->getArray() << endl;
		
		this->recursiveSort(left, pivot-1);
		this->recursiveSort(pivot+1,right);

		/*
		cout << "\nChecking the order\n";
		for(int i = 0; i < size-1; i++){
			cout << "Loop " << i << ":";
			cout << "\t" << this->getArray() << endl;
			if(*(ptr+i) < *(ptr+(i+1))){
				cout << "\t" << i << " and " << i+1 << " in order\n\n";
				//DO NOTHING
			}
			else{
				
			}
		}*/ //DEBUG: for checking the order, not complete
	}
}
/* * * * * * * * * * * * * * * */
void QS::sortAll() {
	//cout << "currPos is: " << currPos << endl;
	this->recursiveSort(0,currPos-1);
}


