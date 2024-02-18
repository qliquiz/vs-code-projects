template <class T> class Vector {
    // Хранилище элементов
    T* ptr;
    // Размеры
    int size, capacity;
public:
    // Индексация
    T& operator[](int index);
    // Вставка элемента
    void insert(T& elem, int index);
    // Удаление элемента
    void remove(int index);
};