#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector vec(4);

    for (int i = 0; i < 4; i++) vec.insert(i + 1);
    cout << vec << endl;
    for (int i = 0; i < 8; i += 2) vec.insert(10 + i, i);
    cout << vec << endl;
    for (int i = 1; i < 8; i += 2) vec[i] = 20 + i;
    cout << vec << endl;
    for (int i = 6; i >= 0; i -= 3) vec.remove(i);
    cout << vec << endl;

    return 0;
}

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
    for (int j=index; j<size-1; j++)
    ptr[j]=ptr[j+1];
    ptr[size-1]=0;
    size--;
}

int Vector::getSize() const { return size; }

ostream& operator <<(ostream& out, const Vector& vec) {
    out << "Total size: " << vec.getSize() << endl;
    for (int i = 0; i < vec.size; i++) out << vec.ptr[i] << endl;
    return out;
}