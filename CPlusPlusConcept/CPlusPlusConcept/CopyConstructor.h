#pragma once
#include <iostream>

using namespace std;
class MyString
{
protected:
	char* m_data;
	int m_length;
	void deepCopy(const MyString& source);
public:
	MyString(const char *source = "");
	MyString(const MyString& source);
	MyString& operator=(const MyString& source);

	~MyString() // destructor
	{
		// We need to deallocate our string
		delete[] m_data;
	}

	virtual char* getString() { return m_data; }
	int getLength() { return m_length; }
};

class  MyDriveClass: public MyString
{
public:
	MyDriveClass() {};
	~MyDriveClass() {};

	char* getString() {
		char* drive = new char[10] {"In Drive"};
		return drive;
	}

	void display()
	{
		cout << "In Display drive..";
	}

private:

};

