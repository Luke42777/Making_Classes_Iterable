#pragma once


#include <iostream>
#include "ring.h"

using namespace std;

int main()
{
	ring<string>textstring(3);

	textstring.add("One");
	textstring.add("Two");
	textstring.add("Three");
	textstring.add("Four");
	textstring.add("Five");

	for (int i = 0; i < textstring.size(); i++)
	{
		cout << textstring.get(i) << endl;
	}
	cout << endl;
	//we want to make our class iterable so we can use RANGE BASED LOOPS to iterate
	for (ring<string>::iterator it = textstring.begin(); it != textstring.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
	for (auto value : textstring)
	{
		cout << value << endl;
	}

	ring<int> storage({1,2,3,4,4,5},3);
	storage.add(90);
	storage.add(90);

	
	for (int i = 0; i < storage.size(); i++) {
		cout << storage.get(i) << endl;
	}
}
