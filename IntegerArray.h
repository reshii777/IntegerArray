#pragma once
#include <exception>
#include "BadRange.h"
#include "BadLength.h"

using namespace std;
#ifndef INTARRAY_H
#define INTARRAY_H

class IntegerArray {
private:
	int m_length;
	int* m_data;
	
public:
	IntegerArray(int length);
	~IntegerArray();

	void erase();
	int& operator[](const int& index);
	void reallocate(int newLength);
	void resize(int newLength);
	void insertBefore(int value, int index);
	void remove(int index);
	void insertAtBegin(int value);
	void insertAtEnd(int value);
	void search(int value);
	int getLength() const;
	void printArray();
};
#endif
