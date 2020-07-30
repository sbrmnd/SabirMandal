// CPlusPlusConcept.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Concepts_Templates.h"
#include "CopyConstructor.h"
#include "WorkOnSLT.h"
#include <vector>

using namespace std;

int main()
{
	WorkOnSLT *stl = new WorkOnSLT();
	stl->TestMaps();
	delete stl;

	MyString *myString = new MyDriveClass();

	MyDriveClass *myDrive = dynamic_cast<MyDriveClass*>(myString);

	if(myDrive)
		myDrive->display();
	//std::cout << myString->();


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

	//Non-Type Parameters.
	StaticArray<int, 12> intArray;

	// Fill it up in order, then print it backwards
	for (int count = 0; count < 12; ++count)
		intArray[count] = count;

	for (int count = 11; count >= 0; --count)
		std::cout << intArray[count] << " ";
	std::cout << '\n';

}
