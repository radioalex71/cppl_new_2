// Neto_06_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>

int main()
{
    setlocale(LC_ALL, "russian");
    int number = 0;
    std::cout << "[IN]: " << std::endl;
    std::cin >> number;//ввод количества элементов
    std::set<int, std::greater<int>> val;//создание контейнера
    for (size_t i{ 0 }, v{ 0 }; i < number; i++)
    {
        //заполнение контейнера
        std::cin >> v;
        val.insert(v);
    }
    std::cout << "[OUT]:" << std::endl;
    for (const auto& v : val)
    {
        std::cout << v << std::endl;//вывод элементов без повторов и в порядке убывания
    }
    return 0;
}