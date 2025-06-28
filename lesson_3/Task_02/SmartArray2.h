#pragma once

#include <iostream>


class SmartArray //������� ����� ������ �������
{
public:
	SmartArray(const size_t size);//���� ��� �������� �������
	
	SmartArray(const SmartArray& other);
	
	SmartArray& operator=(const SmartArray& other);
	
	~SmartArray();
	
	void addElement(const int value);//���� ��� ���������� �������� � ������
	
	int getElement(const size_t index);//���� ��� ��������� �������� �� �������
	
	void printSmartArray();//���� ��� ������ ��������� �������

private:
	int* sm_arr = nullptr;
	size_t sizeArr = 0;
	size_t countOver = 0;
};