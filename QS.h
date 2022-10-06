#ifndef QS_H_
#define QS_H_

#include <sstream>
#include "QSInterface.h"

using namespace std;

class QS : QSInterface {
protected:
	int* ptr;
	int currPos = 0;
	int size = 0;
	string arrayStr;
public:
	~QS() {}
	void sortAll() {}
	int medianOfThree(int left, int right);		//DONE
	int partition(int left, int right, int pivotIndex)
	{ int done;
		return done; }
	string getArray() const;				//DONE
	int getSize() const;						//DONE
	bool addToArray(int value);			//DONE
	bool createArray(int capacity);	//DONE
	void clear();
};



#endif 