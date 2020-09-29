#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class OrderedArray : public Array<T>
{
public:

	// Constructor
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			this->m_maxSize = size;
			this->m_array = new T[this->m_maxSize]; // Dynamically allocating an array to m_maxSize
			memset(this->m_array, 0, sizeof(T) * this->m_maxSize); // Explicitly allocating memory based on the type T

			this->m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	// Destructor
	~OrderedArray()
	{
		if (this->m_array != NULL)
		{
			delete[] this->m_array;
			this->m_array = NULL;
		}
	}
	// Insertion - Big O = O(N)
	int push(T val)
	{
		assert(this->m_array != NULL);	// Debugging purposes
		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}
		int i, k;
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
				break;
		}

		for (k = this->m_numElements; k > i; k--)
		{
			this->m_array[k] = this->m_array[k-1];
		}
		this->m_array[i] = val;
		this->m_numElements++;
		return i;
	}
	// Searching -- Binary Search Big O = O(log N)
	int search(T searchKey)
	{
		// Call to the binarySearch recursive function
		return binarySearch(searchKey, 0, this->m_numElements - 1);
	}
	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(this->m_array != NULL && index < this->m_numElements);
		return this->m_array[index];
	}
private:
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(this->m_array != NULL);
		assert(lowerBound >= 0);
		assert(upperBound < this->m_numElements);

		int current = (lowerBound + upperBound) >> 1;

		if (this->m_array[current] == searchKey)
		{
			return current;
		}
		else if(lowerBound > upperBound)
		{
			return -1;
		}
		else
		{
			if (this->m_array[current] < searchKey)
			{
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}
		return -1;
	}
};
