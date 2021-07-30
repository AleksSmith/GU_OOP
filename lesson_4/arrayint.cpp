#include "arrayint.h"

#include <cassert> // для assert()

ArrayInt::ArrayInt(): m_length(0), m_data(nullptr){ }

ArrayInt::ArrayInt(int length): m_length(length)
{
    assert(length >= 0);

    if (length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;
}

ArrayInt::~ArrayInt()
{
    delete[] m_data;
}

void ArrayInt::erase()
{
    delete[] m_data;

    // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
    m_data = nullptr;
    m_length = 0;
}
    
int ArrayInt::getLength() { return m_length; }

int& ArrayInt::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

// Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
void ArrayInt::resize(int newLength) 
{
    // Если массив уже нужной длины — return
    if (newLength == m_length)
        return;

    // Если нужно сделать массив пустым — делаем это и затем return
    if (newLength <= 0)
    {
        erase();
        return;
    }

    // Теперь знаем, что newLength >0
    // Выделяем новый массив
    int *data = new int[newLength];

    // Затем нужно разобраться с количеством копируемых элементов в новый массив
    // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
    if (m_length > 0)
    {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;

        // Поочередно копируем элементы
        for (int index=0; index < elementsToCopy ; ++index)
            data[index] = m_data[index];
    }

    // Удаляем старый массив, так как он нам уже не нужен
    delete[] m_data;

    // И используем вместо старого массива новый! Обратите внимание, m_data указывает
    // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
    // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
    m_data = data;
    m_length = newLength;
}

