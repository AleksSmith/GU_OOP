// Алексей Кузнецов <alek-kuzne@yandex.ru>

// ООП Урок 1. Именованные состояния

#include <iostream>
#include <cmath>
#include <cstdint>
#include <array>

/*
1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена
    для хранения этих вещественных чисел. Еще создать два метода: один с именем set, который позволит присваивать 
    значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень 
    второго числа. Задать значения этих двух чисел по умолчанию.
*/
class Power
{
private:
    int m_num{};
    int m_pwr{};

public:
    Power(int, int);
    ~Power();
    void setVar(int f, int s);
    int calculate();
};

Power::Power(int num = 0, int pwr = 1) : m_num(num), m_pwr(pwr){};

Power::~Power(){};

void Power::setVar(int num, int pwr)
{
    m_num = num;
    m_pwr = pwr;
}

int Power::calculate()
{
    return (pow(m_num, m_pwr));
}

/*
2.Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue
    и m_alpha (#include cstdint для доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red,
    m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, который позволит
    пользователю передавать значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая
    будет выводить значения переменных-членов.
*/
class RGBA
{
private:
    uint8_t m_red{};
    uint8_t m_green{};
    uint8_t m_blue{};
    uint8_t m_alpha{};

public:
    RGBA(uint8_t, uint8_t, uint8_t, uint8_t);
    ~RGBA();
    void printRGB();
};

RGBA::RGBA(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255) : m_red(r), m_green(g), m_blue(b), m_alpha(a) {}

RGBA::~RGBA() {}

void RGBA::printRGB()
{
    std::cout << "\tRGB: red(" << (int)m_red << ") green(" << (int)m_green << ") blue(" << (int)m_blue << ") alpha(" << (int)m_alpha << ")" << std::endl;
}

/*
3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
    - private-массив целых чисел длиной 10;
    - private целочисленное значение для отслеживания длины стека;
    - public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
    - public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение
       false, если массив уже заполнен, и true в противном случае;
    - public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то
       должно выводиться предупреждение;
    - public-метод с именем print(), который будет выводить все значения стека.

*/
class Stack
{
private:
    static const int stack_size{10};
    std::array<int, stack_size> m_stack{};
    int m_head{-1};

public:
    Stack();
    ~Stack();
    void reset();
    int push(int);
    int pop();
    void print();
};

Stack::Stack() {}

Stack::~Stack() {}

void Stack::reset()
{
    for (size_t i = 0; i < stack_size; i++)
    {
        m_stack.at(i) = 0;
    }
    m_head = -1;
}

int Stack::push(int val)
{
    if (m_head < stack_size - 1)
    {
        m_stack.at(++m_head) = val;
        return true;
    }
    else
        std::cout << "the stack is full" << std::endl;
    return false;
}

int Stack::pop()
{
    if (m_head >= 0)
    {
        return m_stack.at(m_head--);
    }
    else
        std::cout << "the stack is empty" << std::endl;
}

void Stack::print()
{
    std::cout << "\t(";
    for (int i = 0; i <= m_head; i++)
        std::cout << m_stack[i] << " ";
    std::cout << ")" << std::endl;
}

// MAIN =============================================================================

int main(int argc, char const *argv[])
{
    // 1.----------------------

    std::cout << "1.)" << std::endl;

    Power my_pow;
    std::cout << "\t" << my_pow.calculate() << std::endl;

    my_pow.setVar(3, 2);
    std::cout << "\t" << my_pow.calculate() << std::endl;

    // 2.----------------------

    std::cout << "2.)" << std::endl;

    RGBA first_rgb;
    first_rgb.printRGB();

    RGBA second_rgb(11, 22, 33, 128);
    second_rgb.printRGB();

    // 3.----------------------

    std::cout << "3.)" << std::endl;

    Stack stack;

    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}