#include <iostream>
#include "IntegerArray.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

try
{
	IntegerArray s_array(10);			//������� ��������� �� 10 ���������
	for (int i{ 0 }; i < 10; ++i)
		s_array[i] = i + 1;

	s_array.reallocate(15);				//�������� ������ ���������� � ��������� ���������
	for (int i{ 0 }; i < 15; ++i)		//��������� ��������� ���������
		s_array[i] = i + 1;
	s_array.printArray();

	s_array.resize(7);					//�������� ������ ���������� � ����������� ���������
	s_array.printArray();

	s_array.insertBefore(20, 5);		//��������� ����� 20 �� ������� 5
	s_array.remove(2);					//������� ������� � �������� 2
	s_array.insertAtEnd(35);			//��������� ����� 35 � ����� ����������
	s_array.insertAtBegin(50);			//��������� ����� 50 � ������ ����������

	cout << "������ �������: " << s_array.getLength() << endl;
	s_array.printArray();

	s_array.search(20);					//����� �������� � ����������
	s_array.search(150);
}

catch (exception& e) {
	cout << e.what();
}
return 0;
}