#ifndef ARRAYINT_H
#define ARRAYINT_H

class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt();
    ArrayInt(int length);
    ~ArrayInt();
    void erase();
    int ArrayInt::getLength();
    int& operator[](int index);
    void resize(int newLength);
};


#endif