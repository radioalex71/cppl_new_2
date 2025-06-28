#pragma once

#include <iostream>


class SmartArray //создаем класс умного массива
{
public:
	SmartArray(const size_t size);//поле для создания массива
	
	SmartArray(const SmartArray& other);
	
	SmartArray& operator=(const SmartArray& other);
	
	~SmartArray();
	
	void addElement(const int value);//поле для добавления элемента в массив
	
	int getElement(const size_t index);//поле для получения элемента по индексу
	
	void printSmartArray();//поле для вывода элементов массива

private:
	int* sm_arr = nullptr;
	size_t sizeArr = 0;
	size_t countOver = 0;
};