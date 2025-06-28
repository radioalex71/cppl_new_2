#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
//#include <cstdint>

struct ListNode
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
};

//юнит-тест
TEST_CASE("Test_List", "[Test_List]")//unit тесты для проверки функций 
{
        List A;
        A.PushBack(1);//добавление элемента в конец списка
        A.PushBack(2);//добавление элемента в конец списка
        A.PushBack(3);//добавление элемента в конец списка
        //A.PopBack();//удаление элемента из списка(если раскомментировать - сработает функция Size)
        //A.PopBack();//удаление элемента из списка
        //A.PopBack();//удаление элемента из списка
        //A.Clear();//вызов функции очистки(если список очистится - сработает функция Empty)

    SECTION("Проверка работы функции Empty")
    {
        INFO("Пустой список");
        CHECK_FALSE(A.Empty());//если список пустой или очищенный - сообщение "Пустой список"    
    }
    SECTION("Проверка работы функции Size")
    {
        INFO("Размер списка отличается от заданного");
        CHECK(A.Size() == 3);//если размер отличается от заданного(3) - сообщение "Размер списка отличается от заданного" 
    }
    SECTION("Проверка работы функции Clear")
    {
        INFO("Ошибка очистки списка");
        A.Clear();//закомментировать для имитации неочищенного списка
        CHECK(A.Size() == 0);//если список не очищен (размер >0) - сообщение "Ошибка очистки списка" 
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");   
    return Catch::Session().run(argc, argv);
}
