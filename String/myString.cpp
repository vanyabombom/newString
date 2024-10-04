#include "MyString.h"
#include <iostream>
using namespace std;


MyString::MyString()
{
	length = 80;
	str = new char[length + 1];
	for (size_t i = 0; i <= length; ++i)
	{
		str[i] = '\0';
	}
}

MyString::MyString(int size)
{
	if (size < 0) size = 0;
	{
		length = size;
		str = new char[length + 1];
	}
	for (int i = 0; i <= length; ++i)
	{
		str[i] = '\0';
	}
}

MyString::MyString(const char* initString)
{
	if (initString == nullptr)
	{
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}
	else
	{
		length = strlen(initString);
		str = new char[length + 1];
		strcpy_s(str, length + 1, initString);
	}


}

MyString::MyString(const MyString& obj2)
{
	length = obj2.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj2.str);
}

MyString::~MyString()
{
	delete[] str;
}
MyString::MyString(initializer_list<char> list)
{
	length = list.size();
	str = new char[length + 1];

	int index = 0;
	for (auto i = list.begin(); i != list.end(); ++i)
	{
		str[index++] = *i;
	}
	str[length] = '\0'; 
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str == nullptr)
	{
		return;
		delete[] obj.str;
	}
	obj.length = length;
	obj.str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		obj.str[i] = str[i];
	}

	obj.str[length] = '\0';
}

bool MyString::MyStrStr(const char* subString)
{
	if (str == nullptr || subString == nullptr)
	{
		return false;
	}

	for (int i = 0; str[i] != '\0'; i++)
	{
		int j = 0;

		while (subString[j] != '\0' && str[i + j] != '\0' && str[i + j] == subString[j])
		{
			j++;
		}
		if (subString[j] == '\0')
		{
			return true;
		}
	}

	return false;
}

int MyString::MyChar(char symbol)
{
	if (str == nullptr)
	{
		return -1;
	}

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == symbol)
		{
			return i;
		}
	}

	return -1;
}

int MyString::MyStrLen()
{
	if (str == nullptr)
	{
		return 0;
	}

	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return length;
}

void MyString::MyStrCat(MyString& q)
{
	if (str == nullptr)
	{
		return;
	}
	if (q.str == nullptr)
	{
		return;
	}
	int newLength = MyStrLen() + q.MyStrLen();
	char* newStr = new char[newLength + 1];

	int i = 0;
	for (; str[i] != '\0'; i++)
	{
		newStr[i] = str[i];
	}

	for (int j = 0; q.str[j] != '\0'; j++, i++)
	{
		newStr[i] = q.str[j];
	}

	newStr[newLength] = '\0';
	delete[] str;
	str = newStr;
	length = newLength;
}

void MyString::MyDelChr(char symbol)
{
	if (str == nullptr)
	{
		return;
	}
	int j = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != symbol)
		{
			str[j++] = str[i];
		}
	}

	str[j] = '\0';
	length = j;
}

int MyString::MyStrCmp(MyString& q)
{
	if (str == nullptr && q.str == nullptr)
	{
		return 0;
	}
	if (str == nullptr)
	{
		return -1;
	}
	if (q.str == nullptr)
	{
		return 1;
	}

	int i = 0;
	while (str[i] != '\0' && q.str[i] != '\0')
	{
		if (str[i] < q.str[i])
		{
			return -1;
		}
		if (str[i] > q.str[i])
		{
			return 1;
		}
		i++;
	}

	if (str[i] == '\0' && q.str[i] == '\0')
	{
		return 0;
	}
	if (str[i] == '\0')
	{
		return -1;
	}
	return 1;
}

void MyString::Print()
{
	if (str == nullptr)
	{
		cout << "null!" << endl;
	}
	else
	{
		cout << str << endl;
	}
}

void MyString::Input()
{
	char buffer[255];
	cout << "Enter your string: ";

	cin.getline(buffer, 255);

	delete[] str;
	length = strlen(buffer);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buffer);
}

MyString::MyString(MyString&& obj)
{
	length = obj.length;
	str = obj.str;
	obj.str = nullptr;
	obj.length = 0;
}

MyString& MyString::operator=(MyString&& obj)
{
	if (this != &obj)
	{
		delete[] str;

		length = obj.length;
		str = obj.str;
		obj.str = nullptr;
		obj.length = 0;
	}
	return *this;
}

ostream& operator<<(ostream& os, MyString obj)
{
	obj.Print();
	return os;
}

istream& operator>>(istream& is, MyString& obj)
{
	obj.Input();
	return is;
}
MyString& MyString::operator+=(const char* addedText)
{
	if (addedText == nullptr)
	{
		return *this;
	}

	int addLength = strlen(addedText);
	char* newStr = new char[length + addLength + 1];
	strcpy_s(newStr, length + 1, str);
	strcat_s(newStr, length + addLength + 1, addedText);

	delete[] str;
	str = newStr;
	length += addLength;
	return *this;
}


