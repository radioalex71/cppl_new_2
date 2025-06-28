#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include <cstdint>
#include "Windows.h"
#include <exception>
#include "mylist.h"


TEST_CASE("Test_List", "[Test_List]")//unit тесты для проверки функций 
{
    List A;
       
    SECTION("Проверка работы функции PushBack")
    {
        INFO("Ошибка добавления элемента в конец списка");
        A.Clear();
        A.PushBack(1);
        CHECK(A.Size() == 1);
        A.PushBack(2);
        CHECK(A.Size() == 2);
        A.PushBack(3);
        
        CHECK(A.Size() == 3);
    }
    SECTION("Проверка работы функции PushFront")
    {
        INFO("Ошибка добавления элемента в начало списка");
        A.Clear();
        A.PushFront(1);
        CHECK(A.Size() == 1);
        A.PushFront(2);
        CHECK(A.Size() == 2);
        A.PushFront(3);
        
        CHECK(A.Size() == 3);
    }
    SECTION("Проверка работы функции PopBack")
    {
        INFO("Ошибка удаления элемента из конца списка");
        A.Clear();
        A.PushBack(123);
        A.PopBack();//если функция сработает правильно - произойдет очистка списка и ошибки не будет
        
        CHECK(A.Size() == 0);
        
        REQUIRE_THROWS(A.PopBack());//в случае не правильного срабатывания функции PopBack сгенерируется ошибка 
        
    }
    SECTION("Проверка работы функции PopFront")
    {
        INFO("Ошибка удаления элемента из начала списка");
        A.Clear();
        A.PushFront(11);
        A.PopFront();//если функция сработает правильно - произойдет очистка списка и ошибки не будет
        
        CHECK(A.Size() == 0);
        
        REQUIRE_THROWS(A.PopFront());//в случае не правильного срабатывания функции PopFront сгенерируется ошибка 

    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    return Catch::Session().run(argc, argv);
}
