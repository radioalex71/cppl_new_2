// Neto_05_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "functor.h"

int main()
{
    setlocale(LC_ALL, "rus");
    functor f;//вызов класса
    std::vector<int> v = { 4,1,3,6,25,54 };//инициализация вектора
    f(v);
    std::cout << "[IN]: ";
    for (auto& num : v)//цикл foreach для вывода элементов вектора
    {
        std::cout << num << "  ";
    }
    std::cout << std::endl;
    std::cout << "[OUT]: get_sum() = " << f.get_sum() << std::endl;//вывод суммы
    std::cout << "[OUT]: get_count() = " << f.get_count() << std::endl;//вывод результата счета
    return 0;
}