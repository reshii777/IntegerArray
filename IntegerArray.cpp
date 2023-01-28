#include <iostream>
#include "IntegerArray.h"
#include "BadRange.h"
#include "BadLength.h"

IntegerArray::IntegerArray(int length) : m_length(length)	//�������� ����������
{
	if (length <= 0) {
		throw BadLength();
	}
	else {
		m_data = new int[length] {};
	}
}

IntegerArray :: ~IntegerArray()
{
	delete[] m_data;
}

void IntegerArray::erase()									//�������� ����������
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntegerArray :: operator[](const int& index)			//������ � ������ �������� ���������� �� �������
{
	if (index <= 0 && index > m_length) {
		throw BadRange();
	}
	return m_data[index];
}

void IntegerArray::reallocate(int newLength)				// ��������� ������� ���������� � ��������� ������������ ���������
{
	if (newLength <= 0) {
		throw BadLength();
	}
	else {
		erase();
		if (newLength <= 0)
			return;
		m_data = new int[newLength];
		m_length = newLength;
		cout << "������ ������� ������� ��: " << newLength << endl;
	}
}

void IntegerArray::resize(int newLength)					// ��������� ������� ���������� � ����������� ������������ ���������
{
	if (newLength <= 0) {
		throw BadLength();
	}
	if (newLength == m_length)
		return;

	if (newLength <= 0) {
		erase();
		return;
	}

	int* data{ new int[newLength] };
	if (m_length > 0) {
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

		for (int index = 0; index < elementsToCopy; ++index)
			m_data[index] = m_data[index];
	}

	delete[] m_data;
	m_data = data;
	m_length = newLength;
	cout << "������ ������� ������� ��: " << newLength << endl;
}

void IntegerArray::insertBefore(int value, int index)		//������� ����� �� �������
{
	if (index < 0 && index > m_length) {
		throw BadRange();
	}

	int* data{ new int[m_length + 1] };

	for (int before{ 0 }; before < index; ++before)			// ����������� ��������� �� �������
		data[before] = m_data[before];
	data[index] = value;

	for (int after = index; after < m_length; ++after)		// ����������� ��������� ����� �������
		data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	++m_length;
	cout << "��������� ����� " << value << " �� ������� " << index << endl;
}


void IntegerArray::remove(int index)						//�������� �������� �� ���������� �� �������
{
	if (index < 0 && index > m_length) {
		throw BadRange();
	}
	else {
		if (m_length == 1) {
			erase();
			return;
		}
		int* data{ new int[m_length - 1] };

		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		for (int after{ index + 1 }; after < m_length; ++after)
			data[after - 1] = m_data[after];

		delete[] m_data;
		m_data = data;
		--m_length;
		cout << "������� ����� � �������� " << index << endl;
	}
}

void IntegerArray::insertAtBegin(int value)					//������� �������� � ������
{
	insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value)					//������� �������� � �����
{
	insertBefore(value, m_length);
}

void IntegerArray::search(int value)						//����� �������� � ����������
{
	int h = 0;
	for (int before = 0; before < m_length; ++before) {
		if (m_data[before] == value) {
			h += 1;
			cout << "����� " << value << " ��������� ��� �������� " << before << endl;
		}
	}
	if (h == 0) cout << "����� " << value << " ��� � ����������" << endl;
}

int IntegerArray::getLength() const
{
	return m_length;
}

void IntegerArray::printArray()								//������� ���������� ���������� �� �������
{
	cout << "�������� �������: ";
	for (int i{ 0 }; i < m_length; ++i)
		cout << m_data[i] << " ";
	cout << "\n\n";
}