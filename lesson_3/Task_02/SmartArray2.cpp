#include <iostream>
#include "SmartArray2.h"

//конструктор, принмающий количество элементов, которое будет хранить массив
SmartArray::SmartArray(const size_t size) {
	sizeArr = size;
	sm_arr = new int[size] {};
}

//деструктор
SmartArray::~SmartArray() {
	delete[] sm_arr;
}

SmartArray::SmartArray(const SmartArray& other) {
	this->sizeArr = other.sizeArr;
	this->countOver = other.countOver;
	sm_arr = new int[other.sizeArr];
	for (int i = 0; i < other.sizeArr; i++)
	{
		this->sm_arr[i] = other.sm_arr[i];
	}
	std::cout << std::endl;
}

SmartArray& SmartArray::operator=(const SmartArray& other) {
	if (this != &other) {
		delete[] sm_arr;
		this->sizeArr = other.sizeArr;
		this->countOver = other.countOver;

		sm_arr = new int[other.sizeArr];
		for (int i = 0; i < other.sizeArr; i++)
		{
			this->sm_arr[i] = other.sm_arr[i];
		}
		std::cout << std::endl;
	}
	return *this;
}

//функция для вывода элементов массива
void SmartArray::printSmartArray()
{
	for (int i = 0; i < sizeArr; i++)
		std::cout << sm_arr[i] << " ";
        std::cout << std::endl;
};

//функция добавления элемента в массив
void SmartArray::addElement(const int value)
{
	if (countOver >= sizeArr)
	{
		throw std::out_of_range("Size of array is smaller!");
	}
	sm_arr[countOver++] = value;
};

//функция получения элемента массива по индексу
int SmartArray::getElement(const size_t index)
{
	if (index >= countOver)
	{
		throw std::out_of_range("The getting element is out of array range!");
	}
	return sm_arr[index];
};