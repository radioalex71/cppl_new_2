// Neto_05_3_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SmartArray2.h"
#include "Windows.h"

int main(int argc, char** argv) 
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        SmartArray smartArray1(3);
        
        smartArray1.addElement(1);
        smartArray1.addElement(4);
        smartArray1.addElement(155);
        //smartArray1.addElement(15);
        std::cout << "Массив 1:" << std::endl;
        smartArray1.printSmartArray();

        //std::cout << smartArray1.getElement(2) << std::endl;

        SmartArray smartArray2(3);
        
        smartArray2.addElement(2);
        smartArray2.addElement(44);
        smartArray2.addElement(144);
        //smartArray2.addElement(15);
        std::cout << "Массив 2:" << std::endl;
        smartArray2.printSmartArray();

        //std::cout << smartArray2.getElement(3) << std::endl;

        std::cout << "Копирование 1 массива:";
        SmartArray smartArray3(smartArray1);
        smartArray3.printSmartArray();

        std::cout << "Копирование 2 массива:";
        SmartArray smartArray4(smartArray2);
        smartArray4.printSmartArray();

    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}