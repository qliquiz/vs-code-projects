#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector(int startCapacity) {
    if (startCapacity <= 0) capacity = DEFAULT_CAPACITY;
    else capacity = startCapacity;
    ptr = new int[capacity];
    size = 0;
}

Vector::~Vector() { delete[] ptr; }

Vector::Vector(const Vector& vec) {
    ptr = new int(vec.capacity);
    size = vec.size;
    capacity = vec.capacity;
    for (int i = 0; i < size; i++) ptr[i] = vec.ptr[i];
}

Vector& Vector::operator =(const Vector& vec) {
    if (this == &vec) return *this;
    if (capacity != vec.capacity) {
        delete [] ptr;
        ptr = new int[vec.capacity];
        capacity = vec.capacity;
    }
    size = vec.size;
    for (int i = 0; i < size; i++) ptr[i] = vec.ptr[i];
    return *this;
}

int& Vector::operator [](int index) {
    if (index >= size || index < 0) throw VectorException();
    else return ptr[index];
}

int Vector::begin() {
    return *ptr;
}

int Vector::end() {
    return *(ptr + size - 1);
}

void Vector::insert(int element, int index) {
    if (index < 0 || index > size) throw VectorException();
    if (size == capacity) increaseCapacity(size * 2); // Если index==size, этот цикл не выполнится ни разу
    for (int j = size - 1; j >= index; j--) ptr[j + 1] = ptr[j];
    size++;
    ptr[index] = element;
}

void Vector::insert(int element) {
    insert(element, size);
}

void Vector::increaseCapacity(int newCapacity) {
    capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
    int* newPtr = new int[capacity];
    for (int i = 0; i < size; i++) newPtr[i] = ptr[i];
    delete [] ptr;
    ptr = newPtr;
}

void Vector::remove(int index) {
    if (index < 0 || index >= size) throw VectorException();
    for (int j=index; j<size-1; j++) ptr[j]=ptr[j+1];
    ptr[size-1]=0;
    size--;
}

int Vector::getSize() const { return size; }

ostream& operator <<(ostream& out, const Vector& vec) {
    out << "Total size: " << vec.getSize() << endl;
    for (int i = 0; i < vec.size; i++) out << vec.ptr[i] << endl;
    return out;
}