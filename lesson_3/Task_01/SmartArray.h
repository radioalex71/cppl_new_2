#pragma once

#include <iostream>


class smart_array //создаем класс умного массива
{
public:
	smart_array(const size_t size);//поле для создания массива

	~smart_array();
	
	void addElement(const int value);//поле для добавления элемента в массив
	
	int getElement(const size_t index);//поле для получения элемента по индексу
	
	//void printSmartArray();//поле для вывода элементов массива

private:
	int* sm_arr = nullptr;
	size_t sizeArr = 0;
	size_t countOver = 0;
};
