const int DEFAULT_CAPACITY = 10;

class VectorException {};

class Vector {
    // Хранилище элементов
    int* ptr;
    // Размеры
    int size, capacity;
public:
    // Конструктор
    explicit Vector(int startCapacity = DEFAULT_CAPACITY);
    // Деструктор
    ~Vector();
    // Конструктор копирования
    Vector(const Vector& vec);
    // Оператор присваивания
    Vector& operator =(const Vector& vec);
    // Оператор индексациид для чтения и записи
    int& operator [](int index);
    // Вставка элемента
    void insert(int element, int index);
    // Вставка элемента в конец массива
    void insert(int elem);
    // Увеличение массива
    void increaseCapacity(int newCapacity);
    // Удаление элемента
    void remove(int index);
    // Получение размера
    int getSize() const;
    // Вывод массива в консоль
    friend std::ostream& operator <<(std::ostream& out, const Vector& arr);
};