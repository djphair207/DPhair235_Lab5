#ifndef QS_H_
#define QS_H_

#include <sstream>
#include "QSInterface.h"

using namespace std;

class QS : QSInterface {
protected:
	int *ptr;
	int currPos = 0;
	string arrayStr;
public:
	~QS() {}
	void sortAll() {}
	int medianOfThree(int left, int right) 
{ int done;
	return done; }
	int partition(int left, int right, int pivotIndex)
{ int done;
	return done; }
	string getArray() const;
	int getSize() const
{ int done;
	return done; }
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear() {}
};



#endif 