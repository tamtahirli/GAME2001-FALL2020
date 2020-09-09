// "Generic" classes or functions
// Compare 2 things. Return smallest. Return largest
#include <iostream>
using namespace std;

// Check 2 "things". Return the smallest

template <class T>
T min_func(T lVal, T rVal)
{
	if (lVal > rVal)
		return rVal;
	return lVal;

}

// Check 2 "things". Return the largest
template <class T>
T max_func(T lVal, T rVal)
{
	if (lVal < rVal)
		return rVal;
	return lVal;
}

// Implement a template class here
template <class T>
class TemplateClass
{
public: 
	TemplateClass(T val)
	{
		m_val = val;
	}
	// Missing something here;
	bool operator<(TemplateClass& rVal)
	{
		return m_val < rVal.GetVal();
	}
	bool operator>(TemplateClass& rVal)
	{
		return m_val > rVal.GetVal();
	}
	T GetVal()
	{
		return m_val;
	}
private:
	T m_val;
};

// Main

int main()
{
	cout << "Template Example" << endl << endl;
	cout << "Min = " << min_func('c', 'd') << endl;
	cout << "Max = " << max_func(36.1, 43.6) << endl;

	// Create 2 "TemplateClass" objects and compare them.
	cout << "Max (objects) = " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).GetVal();
	return 0;
}
