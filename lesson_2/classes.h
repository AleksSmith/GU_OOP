#ifndef CLASSES_H
#define CLASSES_H

//==============================================================
// class Person
//--------------------------------------------------------------

class Person
{
protected:
    std::string m_name{};
    int m_age{};
    std::string m_sex{};
    int m_weight{};

public:
    Person(std::string name, int age, std::string sex, int weight);
    void setName(std::string name);
    std::string getName() const;
    void setAge(int age);
    int getAge() const;
    void setSex(std::string sex);
    std::string getSex() const;
    void setWeight(int weight);
    int getWeight() const;
    ~Person();
};

//==============================================================
// class Student
//--------------------------------------------------------------

class Student : public Person
{
private:
    int begin_year{};
    int end_year{};

public:
    static int students;

    Student(std::string name, int y_begin, int y_end);
    void setYearsOfStudies(int y_begin, int y_end);
    int getBeginOfStudy() const;
    int getEndOfStudy() const;
    void extension(); // Метод увеличения года окончания на 1
    ~Student();
};

//==============================================================
// class Fruit
//--------------------------------------------------------------

class Fruit
{
protected:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(std::string name, std::string color);
    std::string getName() const;
    std::string getColor() const;
    ~Fruit();
};

//==============================================================
// class Apple
//--------------------------------------------------------------

class Apple : public Fruit
{
public:
    Apple();
    Apple(const std::string &color);
    ~Apple();
};

//==============================================================
// class Banana
//--------------------------------------------------------------

class Banana : public Fruit
{
public:
    Banana();
    Banana(const std::string &color);
    ~Banana();
};

//==============================================================
// class GrannySmith
//--------------------------------------------------------------

class GrannySmith : public Apple
{
protected:
    std::string m_sort{};

public:
    GrannySmith();
    ~GrannySmith();
    std::string getName() const;
};
#endif //CLASSES_H