// Neto_05_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "05_01.h"


int main()
{
    auto a = 5;//инициализация переменной для возведения в квадрат
    std::vector<int> b{ 5,10,15,20,25 };//инициализация вектора для возведения в квадрат
    
    std::cout << "[IN]: " << a << std::endl;
    std::cout << "[OUT]: " << quadro(a) << std::endl;
    std::cout << "[IN]: ";
    print_vector(b);
    quadro(b);
    std::cout << std::endl;
    std::cout << "[OUT]: ";
    print_vector(b);
    
    return 0;
}