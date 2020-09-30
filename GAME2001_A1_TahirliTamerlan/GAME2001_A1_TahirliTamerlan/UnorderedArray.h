#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class UnorderedArray : public Array<T> {
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy)
	{

	}

	// Destructor
	~UnorderedArray()
	{

	}
	// Insertions
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	void push(T val)
	{
		assert(this->m_array != NULL);	// Debugging purposes
		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		this->m_array[this->m_numElements] = val;
		this->m_numElements++;
	}
	// Searching (Linear search) -- Big O = O(N)
	int search(T val)
	{
		assert(this->m_array != NULL);
		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val)
				return i;
		}

		return -1;
	}
};