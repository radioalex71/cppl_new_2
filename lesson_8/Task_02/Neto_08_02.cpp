// Neto_08_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <set>
#include <list>

template <typename T> //шаблонная функция для печати содержимого контейнера
void print_container(const T& container)
{
    for (auto& elem : container)
    {
        std::cout << elem << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    std::set<std::string> test_set{ "one", "two", "three", "four" };
    std::cout << "Контейнер [test_set]: ";
    print_container(test_set); //вызов функции для печати контейнера
    std::cout << std::endl;

    std::list<std::string> test_list{ "one", "two", "three", "four" };
    std::cout << "Контейнер [test_list]: ";
    print_container(test_list); //вызов функции для печати контейнера
    std::cout << std::endl;

    std::vector<std::string> test_vector{ "one", "two", "three", "four" };
    std::cout << "Контейнер [test_vector]: ";
    print_container(test_vector); //вызов функции для печати контейнера
    std::cout << std::endl;

    return 0;
}
