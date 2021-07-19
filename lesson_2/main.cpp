// Aleksey Kuznetsov <alek-kuzne@yandex.ru>

// ООП Урок 2. Наследование

#include <iostream>
#include <cassert>

using namespace std;
/*
1.============================================================================================================
Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени,
изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. Определить
методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов.
В функции main() создать несколько студентов. По запросу вывести определенного человека.
*/
class Person
{
protected:
    string m_name{};
    int m_age{};
    string m_sex{};
    int m_weight{};

public:
    Person(string, int, string, int);
    void setName(string);
    string getName() const;
    void setAge(int);
    int getAge() const;
    void setWeight(int);
    int getWeight() const;
    ~Person();
};

Person::Person(string name = "none" , int age = 0, string sex = "none", int weight = 0) : m_name(name), m_age(age), m_sex(sex), m_weight(weight){};

void Person::setName(string name) { m_name = name; }

string Person::getName() const { return m_name; }

void Person::setAge(int age) { m_age = age; }

int Person::getAge() const { return m_age; }

void Person::setWeight(int weight) { m_weight = weight; }

int Person::getWeight() const { return m_weight; }

Person::~Person() {}



class Student : public Person
{
private:
    int begin_year;
    int end_year;

public:
    static int students;

    Student(string name, int y_begin, int y_end) : Person(name), begin_year(y_begin), end_year(y_end)
    {
        if (y_begin >= y_end)
        { // Если год начала больше года окончания меняем их местами
            begin_year = y_end;
            end_year = y_begin;
        }
        students++;
    }
    void setYearsOfStudies(int y_begin, int y_end)
    {
        if (y_begin >= y_end)
        { // Если год начала больше года окончания меняем их местами
            begin_year = y_end;
            end_year = y_begin;
        }
        else
        {
            begin_year = y_begin;
            end_year = y_end;
        }
    }
    int getBeginOfStudy() const { return begin_year; }
    int getEndOfStudy() const { return end_year; }
    void extension() { end_year++; } // Метод увеличения года окончания на 1
    ~Student() { students--; }
};

int Student::students = 0;

/*
2.=============================================================================================================
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). У Fruit есть две
переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.

        int main()
        {
            Apple a("red");
            Banana b;
            GrannySmith c;

            std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
            std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
            std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

            return 0;
        }
Код, приведенный выше, должен давать следующий результат:

            My apple is red.
            My banana is yellow.
            My Granny Smith apple is green.

*/
class Fruit
{
protected:
    string m_name;
    string m_color;

public:
    Fruit() {}
    string getName() const { return m_name; }
    string getColor() const { return m_color; }
    ~Fruit() {}
};
class Apple : public Fruit
{
public:
    Apple(string color = "green")
    {
        m_name = "Apple";
        m_color = color;
    }
    ~Apple() {}
};
class Banana : public Fruit
{
public:
    Banana(string color = "yellow")
    {
        m_name = "Banana";
        m_color = color;
    }
    ~Banana() {}
};
class GrannySmith : public Apple
{
public:
    GrannySmith()
    {
        m_name = "GrannySmith";
    }
    ~GrannySmith() {}
};

int main(int argc, char const *argv[])
{
    //1.

    Student maxim("Maxim", 2012, 2011); // Экземпляры Student
    Student alex("Alex", 2010, 2013);
    Student denis("Denis", 2009, 2012);
    cout << "number of students: " << Student::students << endl;
    cout << "student: " << maxim.getName() << " begin: " << maxim.getBeginOfStudy() << " end: " << maxim.getEndOfStudy() << endl;
    maxim.setAge(22);  // Устанавливаем возраст 22
    maxim.extension(); // Увеличиваем год окончания на 1.
    cout << maxim.getName() << " age: " << maxim.getAge() << " end: " << maxim.getEndOfStudy() << endl
         << endl;
    //2.

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    cout << endl;

    return 0;
}