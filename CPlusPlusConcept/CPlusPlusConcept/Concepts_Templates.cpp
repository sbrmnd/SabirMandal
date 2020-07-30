#include "Concepts_Templates.h"
#include <string.h>
#include <iostream>

using namespace std;

 void Templates_Method::Display(const char * ptr)
 {
	 int len = strlen(ptr);
	 char* ptr1 = new char[len];

	 for (int i = 0; i < len; i++)
	 {
		 ptr1[i] = ptr[i];
	 }
	 ptr1[len - 1] = '\0';
	 cout << ptr1;

	 delete[] ptr1;
 }
