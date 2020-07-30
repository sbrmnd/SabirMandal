#pragma once
#include <iostream>

using namespace std;
/*
In C++, function templates are functions that serve as a pattern for creating other similar functions.
The basic idea behind function templates is to create a function without having to specify the exact type(s) of some or all of the variables.
Instead, we define the function using placeholder types, called template type parameters. 
Once we have created a function using these placeholder types, we have effectively created a “function stencil”.

When you call a template function, the compiler “stencils” out a copy of the template, replacing the placeholder types with the actual
variable types from the parameters in your function call! Using this methodology, the compiler can create multiple “flavors” of a function
from one template! We’ll take a look at this process in more detail in the next lesson.
*/

#pragma region Template functions.

class Templates_Method
{
	/*1.  we need to tell the compiler two things: First, that this is a template definition, and second, that T is a placeholder type.
	template <typename T> // this is the template parameter declaration
	T max(T x, T y)
	{
		return (x > y) ? x : y;
	}

	//2. If the template function uses multiple template type parameter, they can be separated by commas:
	template <typename T1, typename T2>
	T1 max(T1 x, T2 y)
	{
		return (x > y) ? x : y;

	}*/

	/*3. Because the function argument passed in for type T could be a class type, and it’s generally not a good idea to pass classes by value,
	it would be better to make the parameters and return types of our templated function const references:*/

	//Disadvantage.
	/*template functions can increase your compile time and code size, as a single template might be “realized”
	and recompiled in many files (there are ways to work around this one).*/
public:
	template <typename T>
	const T& max(const T& x, const T& y)
	{
		return (x > y) ? x : y;
	}

	template<class T>
	T average(T* array, int length)
	{
		T sum(0);

		for (int count{ 0 }; count < length; ++count)
		{
			sum += array[count];
		}
		sum /= length;

		return sum;
	}


	void Display(const char* ptr);
};

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents)
	{

	}
	//Need to override the > operator to support template function for Cents.
	//Cents bigger{ tem.max(nickle, dime) };
	friend bool operator>(const Cents &c1, const Cents &c2)
	{
		return (c1.m_cents > c2.m_cents);
	}

	//Need to override operation<< to be used cents in Template for the following statement.
	//cout << tem.average(array3, 3);
	friend ostream& operator<< (ostream &out, const Cents &cents)
	{
		out << cents.m_cents << " cents ";
		return out;
	}

	//Need to Override Operator += to support avarage template methord for Cent.
	Cents&  operator+=(const Cents& cents)
	{
		m_cents += cents.m_cents;
		return *this;
	}

	//Need to Override /= to support average template function for Cents.
	Cents& operator/=(int value)
	{
		m_cents /= value;
		return *this;
	}

};

//Usage of Template function.
/*

int main()
{
	std::cout << "Hello World!\n";
	Templates_Method tem;
	tem.max(3,5);
	tem.max(9.6, 7.8);
	tem.Display("Hello this string.");

	//User defined type to be used as Template fuction parameter.
	Cents nickle{ 5 };
	Cents dime{ 10 };

	Cents bigger{ tem.max(nickle, dime) };

	//Calling average funtion.
	int array1[]{5,3,2,1,4};
	cout << tem.average(array1, 5);
	double array2[]{3.12,3.45,9.25,6.34};
	cout << tem.average(array2, 5);

	//User defined objects, Need to override the all the operators used in the temlate functions to support Cents objects.
	Cents array3[]{ nickle ,dime ,bigger };
	cout << tem.average(array3, 3);
}

*/


#pragma endregion

#pragma region Template classes

// . Template non-type parameters

template <class T, int size> // size is the non-type parameter
class StaticArray
{
private:
	// The non-type parameter controls the size of the array
	T m_array[size];
public:
	T* getArray();

	T& operator[](int index)
	{
		return m_array[index];
	}
};

// Showing how a function for a class with a non-type parameter is defined outside of the class
template<class T, int size>
T* StaticArray<T,size>::getArray()
{
	return m_array;
}

#pragma endregion


