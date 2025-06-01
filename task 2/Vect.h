///////////////////////////////////////////////////////////
// Vect.h
#ifndef _VECT_
#define _VECT_

#include <iostream>
#include <string>
#include "VectError.h"

// ��������� ����� �������
template<class T>
class Vect {
public:
    // ������������
    explicit Vect() : first(0), last(0) {}  // ������ ������
    explicit Vect(size_t _n, const T& _v = T()) {  // ������ � _n ����������
        Allocate(_n);
        for (size_t i = 0; i < _n; ++i)
            *(first + i) = _v;
    }

    // ����������� �����������
    Vect(const Vect& other) {
        size_t n = other.size();
        Allocate(n);
        for (size_t i = 0; i < n; ++i)
            *(first + i) = *(other.first + i);
        markName = "Copy of " + other.markName;
#ifdef DEBUG
        std::cout << "Copy constructor: " << markName << std::endl;
#endif
    }

    // �������� ������������
    Vect& operator=(const Vect& other) {
        if (this == &other) return *this;
        Destroy();
        size_t n = other.size();
        Allocate(n);
        for (size_t i = 0; i < n; ++i)
            *(first + i) = *(other.first + i);
        return *this;
    }

    // ����������
    ~Vect() {
#ifdef DEBUG
        std::cout << "Destructor of " << markName << std::endl;
#endif
        Destroy();
        first = 0; last = 0;
    }

    // ������ ����������
    void mark(std::string name) { markName = name; }  // ��������� �����
    std::string mark() const { return markName; }      // ��������� �����

    size_t size() const {  // ��������� �������
        if (first > last) throw VectError();
        return (0 == first ? 0 : last - first);
    }

    T* begin() const { return first; }  // ��������� �� ������ �������
    T* end() const { return last; }    // ��������� �� ��������� �������

    // �������� � ����������
    T& operator[](size_t i) {  // ������ �� �������
        if (i < 0 || i >(size() - 1))
            throw VectRangeErr(0, last - first - 1, i);
        return (*(first + i));
    }

    void insert(T* _p, const T& _x);  // ������� ��������
    void push_back(const T& _x);      // ���������� � �����
    void pop_back();                  // �������� ����������

    void show() const;  // ����� �����������

protected:
    void Allocate(size_t _n) {  // ��������� ������
        first = new T[_n];
        last = first + _n;
    }

    void Destroy() {  // ������������ ������
        for (T* p = first; p != last; ++p) p->~T();
        delete[] first;
    }

private:
    T* first;           // ��������� �� ������ �������
    T* last;            // ��������� �� ��������� �������
    std::string markName;  // ��� ��� �������
};

// ���������� ������� �������

// ������� �������� � ������� _p
template<class T>
void Vect<T>::insert(T* _p, const T& _x) {
    size_t n = size() + 1;  // ����� ������
    T* new_first = new T[n];
    T* new_last = new_first + n;
    size_t offset = _p - first;

    // �������� �������� �� ������� �������
    for (size_t i = 0; i < offset; ++i)
        *(new_first + i) = *(first + i);

    // ��������� ����� �������
    *(new_first + offset) = _x;

    // �������� ���������� ��������
    for (size_t i = offset; i < n - 1; ++i)
        *(new_first + i + 1) = *(first + i);

    Destroy();
    first = new_first;
    last = new_last;
}

// ���������� �������� � �����
template<class T>
void Vect<T>::push_back(const T& _x) {
    if (!size()) {
        Allocate(1);
        *first = _x;
    }
    else
        insert(end(), _x);
}

// �������� ���������� ��������
template<class T>
void Vect<T>::pop_back() {
    if (last == first)
        throw VectPopErr();
    T* p = end() - 1;
    p->~T();
    last--;
}

// ����� ����������� �������
template<class T>
void Vect<T>::show() const {
    std::cout << "\n===== Contents of " << markName << " =====" << std::endl;
    size_t n = size();
    for (size_t i = 0; i < n; ++i)
        std::cout << *(first + i) << " ";
    std::cout << std::endl;
}

#endif /* _VECT_ */
///////////////////////////////////////////////////////////