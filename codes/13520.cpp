#include<iostream>
#include"function.h"
using namespace std;
int& Darray::operator[](int num)
{
	return this -> data[num];
}
void Darray::pushback(int x)
{
	if(size >= capacity) resize();//////=!!can resize at any time!!!
	//size++;
	this -> data[size++] = x;
}
void Darray::clear(void)
{
	this -> size = 0;
}
int Darray::length(void)
{
	return this -> size;
}
void Darray::resize(void)
{
	int *newone = new int[capacity*2];
	for(int i = 0; i < capacity; i++)
	{
		newone[i] = this -> data[i];
	}
	delete []this -> data;
	data = newone;//////
	//pushback();
	capacity *= 2;/////!
}
Darray::~Darray()
{
	delete []this->data;
}
