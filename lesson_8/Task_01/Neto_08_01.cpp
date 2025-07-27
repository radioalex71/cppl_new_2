// Neto_08_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> //шаблонная функция для удаления дубликатов
void remove_duplicates(std::vector<T>& v)
{
    std::sort(v.begin(), v.end()); //сначала сортируем вектор
    auto it = std::unique(v.begin(), v.end()); //удаление дубликатов вектора
    v.erase(it, v.end()); //стирание ненужных элементов (дубликатов)
}

template <class T> //шаблонный класс для вывода вектора в консоль
void print_vector(std::vector<T>& v)
{
    std::vector<int>::iterator itr = v.begin(); //используем итератор
    while (itr != v.end())
    {
        std::cout << *itr << " ";
        itr++;
    }
}
int main()
{
    std::vector<int> v{ 1,1,2,3,1,4,5,5,7,6 };
    std::cout << "[IN]: ";
    print_vector(v); //вызов функции для вывода исходного вектора в консоль
    std::cout << std::endl;
    
    remove_duplicates(v); //вызов функции для удаления дубликатов 
    std::cout << "[OUT]: ";

    print_vector(v); //вызов функции для вывода отформатированного вектора в консоль
    return 0;
}

