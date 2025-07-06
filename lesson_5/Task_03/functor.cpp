#include "functor.h"
#include <vector>

functor::functor() :count_(), sum_() {}//конструктор

void functor::operator()(std::vector<int>& v)
{
    for (auto& i : v)//цикл foreach для операций с элементами вектора
    {
        if (i % 3 == 0)//определение кратности 3
        {
            count_++;//подсчет элементов,кратных 3
            sum_ += i;//суммирование значений элементов,кратных 3
        }
    }
}
int functor::get_count()//функция счета
{
    return count_;
}
int functor::get_sum()//функция суммирования
{
    return sum_;
}