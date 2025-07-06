#pragma once
#include <iostream>
#include <vector>

class functor //создание класса functor
{
public:
	functor();
	void operator()(std::vector<int>& v);
	int get_count();
	int get_sum();

private:
	int count_ = 0;
	int sum_ = 0;
};