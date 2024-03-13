#include <iostream>


using namespace std;


template <class t> class LineListElem {
    t data;
    LineListElem* next;
public:
    LineListElem(const t& adata, LineListElem* anext);

    const t getData() const;
    LineListElem* getNext();

    template <class T> friend class LineList;
};


template <class T> class LineList {
    LineList(const LineList& list);
    LineListElem<T>* start;
    LineList& operator =(const LineList& list);
public:
    LineList();
    ~LineList();

    LineListElem<T>* getStart();
    void deleteFirst();
    void deleteAfter(LineListElem<T>* ptr);
    void insertFirst(const T& data);
    void insertAfter(LineListElem<T>* ptr, const T& data);
    
    template <class t> friend ostream& operator <<(ostream& out, LineList& list);
};


class LineListException {};


template <class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext) {
    data = adata;
    next = anext;
}

template <class T> LineListElem<T>* LineListElem<T>::getNext() { return next; }

template <class T> LineListElem<T>* LineList<T>::getStart() { return start; }

template <class t> const t LineListElem<t>::getData() const { return data; }

template <class T> LineList<T>::LineList() { start = 0; }

template <class T> void LineList<T>::deleteFirst() {
    if (start) {
        LineListElem<T>* temp = start->next;
        delete start;
        start = temp;
    } else throw LineListException();
}

template <class T> LineList<T>::~LineList() { while (start) deleteFirst(); }

template <class T> void LineList<T>::insertFirst(const T& data) {
    LineListElem<T>* second = start;
    start = new LineListElem<T>(data, second);
}

template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr) {
    if (ptr && ptr->next) {
        LineListElem<T>* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    } else throw LineListException();
}

template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data) {
    if (ptr) {
        LineListElem<T>* temp = ptr->next;
        ptr->next = new LineListElem<T>(data, temp);
    }
}

template <class T> ostream& operator <<(ostream& out, LineList<T>& list) {
    LineListElem<T>* ptr = list.getStart();
    if (!ptr) out<<"EMPTY ";
    else while (ptr) {
        out<<ptr->getData()<<' ';
        ptr = ptr->getNext();
    }
    return out;
}

int main(void)
{
    LineList<int> list; // Указываем, список какого типа
    cout << "Начало: " << list << endl;
    list.insertFirst(10);
    LineListElem<int>* ptr = list.getStart();
    list.insertAfter(ptr, 15);
    list.insertAfter(ptr -> getNext(), 12);
    list.insertFirst(7);
    cout << "Шаг 1: " << list << endl;
    // …
    return 0;
}