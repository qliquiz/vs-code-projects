#include <iostream>
#include "LineList.h"

using namespace std;

template <class T> class LineListElem {
    T data;
    LineListElem* next;
public:
    LineListElem(const T& adata,
    LineListElem* anext);
    const T& getData() const;
    LineListElem* getNext();
    // В объявлениях друзей
    // template повторяется
    template <class T> friend class LineList;
};