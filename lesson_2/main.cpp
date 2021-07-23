// Aleksey Kuznetsov <alek-kuzne@yandex.ru>

// ООП Урок 2. Наследование

#include <iostream>
#include "classes.h"

/*
1.============================================================================================================
Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени,
изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. Определить
методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов.
В функции main() создать несколько студентов. По запросу вывести определенного человека.
*/
int Student::students = 0;
void printStudent(const Student &student)
{
    std::cout << student.getName() << ", " << student.getAge() << ", " << student.getSex() << ", " << student.getWeight() << ", " << student.getBeginOfStudy() << ", " << student.getEndOfStudy() << std::endl;
}
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

int main(int argc, char const *argv[])
{
    // Task 1.
    std::cout << "Task 1:" << std::endl;

        Student maxim("Maxim", 2012, 2011); // Экземпляры Student
        Student alex("Alex", 2010, 2013);
        Student denis("Denis", 2009, 2012);
       
        std::cout << "number of students: " << Student::students << std::endl;
        printStudent(maxim);
        maxim.setAge(22);  // Устанавливаем возраст 22
        maxim.extension(); // Увеличиваем год окончания на 1.
        printStudent(maxim);
        
    std::cout << std::endl;

    // Task 2.
    std::cout << "Task 2:" << std::endl;

        Apple a("red");
        Banana b;
        GrannySmith c;

        std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
        std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
        std::cout << std::endl;

    return 0;
}