// Neto_06_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <set>
#include <map>


template<class T>
void printC(const T& X, const std::string* str)
{
    std::cout << "[IN]: " << *str << std::endl;
    std::cout << "[OUT]: " << std::endl;
    for (const auto& x : X)
    {
        std::cout << x.second << ":  " << x.first << std::endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    size_t num = 0;
    std::string str = "Hello World!!!";
    std::multimap<size_t, char, std::greater<size_t>> xx;//вывод контейнера с сортировкой по убыванию

    std::set<char> S;//создаем ассоциативный контейнер

    for (size_t i = 0; i < str.length(); i++)
    {
        S.insert(str[i]);//заполняем контейнер строковыми данными
    }
    for (const auto& x : S)//поддержка range based for
    {
        num = std::count(str.begin(), str.end(), x);//подсчет одинаковых символов в указанном диапазоне
        xx.emplace(num, x);//вставка результатов счета
    }
    printC(xx, &str);//вывод результатов подсчета количества одинаковых символов

    return 0;
}