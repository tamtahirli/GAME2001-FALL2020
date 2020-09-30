#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class OrderedArray : public Array<T>
{
public:

	// Constructor
	OrderedArray(int size, int growBy = 1) : Array<T>(size, growBy)
	{

	}

	// Destructor
	~OrderedArray()
	{

	}

	// Insertion - Big O = O(N)
	int push(T val)
	{
		assert(this->m_array != NULL);	// Debugging purposes

		int i, k;
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val)
			{
				//std::cout << "Found duplicate value. Returning." << "\n";
				return -1;
			}

			if (this->m_array[i] > val)
				break;
		}

		// Moved this to only expand after not having duplicate array value
		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
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