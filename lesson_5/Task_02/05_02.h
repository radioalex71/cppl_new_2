#pragma once
#include <iostream>

template <class T>
class Table
{
public:
    Table(int rows, int cols) :_rows(rows), _cols(cols)
    {
        _arr = new T * [_rows] {};
        for (int i{}; i < _rows; ++i)
        {
            _arr[i] = new T[_cols]{};
        }
    };

    Table(const Table& other)
    {
        this->_rows = other._rows;
        this->_cols = other._cols;
        _arr = new T * [_rows] {};
        for (int i{}; i < _rows; ++i)
        {
            _arr[i] = new T[_cols]{};
        }
        for (int i{}; i < _rows; ++i)
        {
            for (int j{}; j < _cols; ++j)
            {
                _arr[i][j] = other._arr[i][j];
            }
        }
    };
    Table& operator=(const Table&) = delete;

    ~Table()
    {
        for (int i{}; i < _rows; ++i)
        {
            delete[] _arr[i];
        }
        delete[] _arr;
        std::cout << "������� �������\n";
    }

    T* operator[] (int index)
    {
        if (index < 0 || index >= _rows)
        {
            throw std::out_of_range("������ ��� �������\n");
        }
        return _arr[index];
    };

    T* operator[] (int index) const
    {
        if (index < 0 || index >= _rows)
        {
            throw std::out_of_range("������ ��� �������\n");
        }
        return _arr[index];
    };

    void get_size() const
    {
        std::cout << "������� �� " << _rows << " ����� � " << _cols << " ��������\n";
    };

private:
    int _rows;
    int _cols;
    T** _arr;
};