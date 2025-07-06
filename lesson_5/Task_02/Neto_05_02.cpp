// Neto_05_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "05_02.h"

int main()
{
    setlocale(LC_ALL, "rus");
    const int Rows = 3;//задаем число строк
    const int Cols = 5;//задаем число столбцов

    Table <int> table{ Rows, Cols };
    table.get_size();
    try
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                table[i][j] = (i + 1) * (j + 1);
                std::cout << table[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
    catch (const std::out_of_range& ex)
    {
        std::cout << "ОШИБКА ДИАПАЗОНА!!!" << ex.what() << std::endl;
    }
    //вывод значения заданной ячейки
    auto test = table[2][2];
    std::cout << "Значение заданной ячейки: " << test << std::endl;
    return 0;
}

