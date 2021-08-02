#ifndef PAIR_H
#define PAIR_H

#include <string>

//========================================================================
//  class Pair1
//------------------------------------------------------------------------
template<typename T>
class Pair1
{
private:
    T m_frst{};
    T m_scnd{};
public:
    Pair1(const T &frst, const T &scnd);
    T first()const;
    T second()const;
};

//========================================================================
//  Реализация методов class Pair1
//------------------------------------------------------------------------
template<typename T>
Pair1<T>::Pair1(const T &frst, const T &scnd): m_frst(frst), m_scnd(scnd){};

template<typename T>
T Pair1<T>::first()const {return m_frst;}
   
template<typename T>
T Pair1<T>::second()const {return m_scnd;}

//========================================================================
//  class Pair
//------------------------------------------------------------------------
template<typename T1,typename T2>
class Pair
{
protected:
    T1 m_frst{};
    T2 m_scnd{};
public:
    Pair(const T1 &frst, const T2 &scnd);
    T1 first()const;
    T2 second()const;
};

//========================================================================
//  Реализация методов class Pair
//------------------------------------------------------------------------
template<typename T1, typename T2>
Pair<T1,T2>::Pair(const T1 &frst, const T2 &scnd): m_frst(frst), m_scnd(scnd){};

template<typename T1, typename T2>
T1 Pair<T1,T2>::first()const {return m_frst;}
   
template<typename T1, typename T2>
T2 Pair<T1,T2>::second()const {return m_scnd;}

//========================================================================
// частично специализированный шаблон class Pair
//------------------------------------------------------------------------
template<typename T>
class Pair<std::string,T>
{
protected:
    std::string m_frst{};
    T m_scnd{};
public:
    Pair(const std::string &frst, const T &scnd);
    std::string first()const;
    T second()const;
};

//========================================================================
//  Реализация методов специализированного шаблона class Pair
//------------------------------------------------------------------------
template<typename T>
Pair<std::string,T>::Pair(const std::string &frst, const T &scnd): m_frst(frst), m_scnd(scnd){};

template<typename T>
std::string Pair<std::string,T>::first()const {return m_frst;}
   
template<typename T>
T Pair<std::string,T>::second()const {return m_scnd;}

//========================================================================
//  class StringValuePair
//------------------------------------------------------------------------
template<typename T2>
class StringValuePair: public Pair<std::string,T2>
{
    
public:
    StringValuePair(const std::string &frst, const T2 &scnd): Pair<std::string, T2>::Pair(frst, scnd){};
  };


#endif