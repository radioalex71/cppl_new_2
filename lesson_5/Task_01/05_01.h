#pragma once


template <class T>//��������� ������� ���������� ����� � �������
T quadro(T a)
{
    return a * a;
}

template<class V>//��������� ������� ���������� ������� � �������
void quadro(std::vector<V>& b)
{
    for (V& num : b)
    {
        num *= num;
    }
}

template<class W>//��������� ������� ������ ������� � �������
void print_vector(std::vector<W>& b) 
{
    for (size_t i = 0; i < b.size(); ++i)
    {
        if (i < b.size() - 1)
        {
            std::cout << b[i] << ", ";
        }
        else
        {
            std::cout << b[i];
        }
    }
}