#include <iostream>
#include "SmartArray2.h"

//�����������, ���������� ���������� ���������, ������� ����� ������� ������
SmartArray::SmartArray(const size_t size) {
	sizeArr = size;
	sm_arr = new int[size] {};
}

//����������
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

//������� ��� ������ ��������� �������
void SmartArray::printSmartArray()
{
	for (int i = 0; i < sizeArr; i++)
		std::cout << sm_arr[i] << " ";
        std::cout << std::endl;
};

//������� ���������� �������� � ������
void SmartArray::addElement(const int value)
{
	if (countOver >= sizeArr)
	{
		throw std::out_of_range("Size of array is smaller!");
	}
	sm_arr[countOver++] = value;
};

//������� ��������� �������� ������� �� �������
int SmartArray::getElement(const size_t index)
{
	if (index >= countOver)
	{
		throw std::out_of_range("The getting element is out of array range!");
	}
	return sm_arr[index];
};