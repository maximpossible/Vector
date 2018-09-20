#pragma once

#include <iostream>
#include <typeinfo>
#include <malloc.h>

using namespace std;

template <typename T>
class Vector
{
private:
    T *mainVector;
    int vec_size;
    int vec_capacity;
public:
    Vector(int = 15);
    ~Vector();
    void operator=(const Vector&);
    void input();
    void show();
    void push_back(T);
    int capacity();
    int size();
    void insert(const Vector&, int);
    int max();
};


template <typename T>
Vector<T>::Vector(int vec_capacity)
{
    vec_size = 0;
    this->vec_capacity = vec_capacity;
    mainVector = (T*)malloc(vec_capacity * sizeof(T));
}


template <typename T>
Vector<T>::~Vector()
{
    free(mainVector);
}

template <typename T>
void Vector<T>::operator=(const Vector &obj)
{
    realloc(mainVector, obj.vec_size * sizeof(T));
    vec_size = obj.vec_size;

    for (int i = 0; i < obj.vec_size; i++)
    {
        mainVector[i] = obj.mainVector[i];
    }
}

template <typename T>
void Vector<T>::input()
{
    cout << "Input " << vec_size << " elements:\n";
    for (int i = 0; i < vec_size; i++)
    {
        cout << i + 1 << " element: ";
        cin >> mainVector[i];
    }
}

template <typename T>
void Vector<T>::show()
{
    for (int i = 0; i < vec_size; i++) cout << mainVector[i] << " ";
    cout << endl;
}

template <typename T>
void Vector<T>::push_back(T element)
{
    if (vec_size == vec_capacity)
    {
        vec_capacity *= 2;
        T *temp = (T*)malloc(vec_capacity * sizeof(T));
        for (int i = 0; i < vec_capacity / 2; i++)
        {
            temp[i] = mainVector[i];
        }
        free(mainVector);
        mainVector = temp;
    }
    vec_size++;
    mainVector[vec_size - 1] = element;
}

template <typename T>
int Vector<T>::capacity()
{
    return vec_capacity;
}

template <typename T>
int Vector<T>::size()
{
    return vec_size;
}

template <typename T>
void Vector<T>::insert(const Vector &obj, int pos)
{
    if (pos < vec_size)
    {
        while (vec_size + obj.vec_size > vec_capacity) vec_capacity *= 2;

        T *temp = (T*)malloc(vec_capacity * sizeof(T));
        for (int i = 0; i < pos; i++)
        {
            temp[i] = mainVector[i];
        }
        int j = 0;
        for (int i = pos; i < obj.vec_size + pos; i++)
        {
            temp[i] = obj.mainVector[j];
            j++;
        }
        j = pos;
        for (int i = obj.vec_size + pos; i < vec_size + obj.vec_size + 1; i++)
        {
            temp[i] = mainVector[j++];
        }

        free(mainVector);
        vec_size += obj.vec_size;
        mainVector = temp;
    }
}

template <typename T>
int Vector<T>::max()
{
    int maxElement = mainVector[0];
    for (int i = 1; i < vec_size; i++) if (mainVector[i] > maxElement) maxElement = mainVector[i];

    return maxElement;
}
