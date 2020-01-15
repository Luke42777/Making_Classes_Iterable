#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

//////////////////////////////////////////////////////
template<typename T>
class ring
{
	int position;
	int buffer_size;
	T* ptr_values = nullptr;

public:
	ring(int elements) : position(0)
	{
		buffer_size = elements;
		ptr_values = new T[buffer_size];
	}
	//*****************************************************
	ring(initializer_list<int> numbers,int elements) :position(0)
	{
		buffer_size = elements;
		ptr_values = new T[buffer_size];
		
		initializer_list<int>::iterator it = numbers.begin();
		for (int i = 0; i < elements;i++,it++)
		{
		*(ptr_values + i) = *it;
		}
	}
	~ring()
	{
		delete[]ptr_values;
	}
	//****************************************************
	void add(T t)
	{
		*(ptr_values + position) = t; //

		position++;
		if (position == buffer_size)//very important we don't want to add anything after end of the buffer
		{
			position = 0;
		}
	}
	//***************************
	int size()
	{
		return buffer_size;
	}
	//*************************
	T& get(int i) //return reference because STL containers normally returns references(it's more efficient)
	{
		return *(ptr_values + i); // or ptr_values[i]
	}

	///*****************to make this class iterable*****************************************************

	class iterator;

	iterator begin()
	{
		return iterator(0, *this);
	}
	//***********************************
	iterator end()
	{
		return iterator(buffer_size, *this);
	}

};
/////////////////////////////////////////////////////////////////
template<typename T>
class ring<T>::iterator
{
	int m_pos;
	ring& m_ring;
public:

	iterator(int pos, ring& buf) :m_pos(pos), m_ring(buf) {}
	//**************************************************
	iterator operator++(int)
	{
		m_pos++;
		return *this;
	}
	//********************************************
	iterator operator++()
	{
		m_pos++;
		return *this;
	}
	//************************************
	T& operator*()
	{
		return m_ring.get(m_pos);
	}

	bool operator!=(const iterator& other)
	{
		return (m_pos != other.m_pos);
	}
};


