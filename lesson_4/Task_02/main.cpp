#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include <cstdint>
#include "Windows.h"
#include <exception>
#include "mylist.h"

/*struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};

class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    //Проверка размер списка равен ли нулю или нет
    bool Empty() { return m_size == 0; }

    //Показать размер списка
    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};*/

//юнит-тест
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
