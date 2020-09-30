#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"
#include "Array.h"

using namespace std;

int main()
{
	cout << "\n" << "\n" << "\n" << "This is the first assignment." << endl << endl;
	
	OrderedArray<int> array(3);
	array.push(43);
	array.push(6);
	array.push(23);
	array.push(94);
	array.push(17);
	array.push(83);
	array.push(44);
	array.push(28);
	array.push(28);
	array.push(28);
	array.push(28);
	array.push(28);
	array.push(28);

	cout << "Ordered array contents: " << endl;

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}

	cout << "\n" << "Search for 43 was found at index " << array.search(43) << endl;

	cout << "Array is now size: " << array.GetMaxSize() << "\n" << "\n" << "\n" << "\n";

	UnorderedArray<int> uoarray(3);
	uoarray.push(43);
	uoarray.push(6);
	uoarray.push(23);
	uoarray.push(94);
	uoarray.push(17);
	uoarray.push(83);
	uoarray.push(44);
	uoarray.push(28);


	cout << "Unordered array contents: " << endl;

	for (int i = 0; i < uoarray.GetSize(); i++)
	{
		cout << uoarray[i] << " ";
	}

	cout << "\n" << "Search for 43 was found at index " << uoarray.search(43) << endl;

	cout << "Array is now size: " << uoarray.GetMaxSize() << "\n" << "\n" << "\n" << "\n";
	return 0;
}