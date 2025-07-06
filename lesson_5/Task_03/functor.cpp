#include "functor.h"
#include <vector>

functor::functor() :count_(), sum_() {}//�����������

void functor::operator()(std::vector<int>& v)
{
    for (auto& i : v)//���� foreach ��� �������� � ���������� �������
    {
        if (i % 3 == 0)//����������� ��������� 3
        {
            count_++;//������� ���������,������� 3
            sum_ += i;//������������ �������� ���������,������� 3
        }
    }
}
int functor::get_count()//������� �����
{
    return count_;
}
int functor::get_sum()//������� ������������
{
    return sum_;
}