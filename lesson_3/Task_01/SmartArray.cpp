#include <iostream>﻿
#include "SmartArray.h"

//конструктор, принмающий количество элементов, которое будет хранить массив
smart_array::smart_array(const size_t size) {
	sizeArr = size;
	sm_arr = new int[size] {};
}

//деструктор
smart_array::~smart_array() {
	delete[] sm_arr;
}

//функция для вывода элементов массива
/*void smart_array::printSmartArray()
{
	for (int i = 0; i < sizeArr; i++)
		std::cout << sm_arr[i] << " ";
	std::cout << std::endl;
};*/

//функция добавления элемента в массив
void smart_array::addElement(const int value)
{
	if (countOver >= sizeArr)
	{
		throw std::out_of_range("Size of array is smaller!");
	}
	sm_arr[countOver++] = value;
};

//функция получения элемента массива по индексу
int smart_array::getElement(const size_t index)
{
	if (index >= countOver)
	{
		throw std::out_of_range("The getting element is out of array range!");
	}
	return sm_arr[index];
};