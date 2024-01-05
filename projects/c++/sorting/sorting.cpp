#include <iostream>

using namespace std;

void InsertSort(int *arr) {
    int buf, i, j, size = sizeof(arr);
    for (i = 1; i < size; i++) {
        buf = arr[i];
        for (j = i - 1; j >= 0 && buf < arr[j]; j--) arr[j + 1] = arr[j];
        arr[j + 1] = buf;
    }
}

void HeapSort(int *arr) {
    int buf, size = sizeof(arr);
    for (int i = size; i > 1; i--) {
        // построение двоичного дерева
        bool flag = false;
        int sh = 0; // смещение
        for (int j = 0; j < i / 2; ) {
            int largest = j, left = 2 * j + 1, right = 2 * j + 2;
            if(arr[left] > arr[largest]) {
                buf = arr[left];
                arr[left] = arr[largest];
                arr[largest] = buf;
                flag = true;
            }
            if (right < i) {
                if (arr[right] > arr[largest]) {
                    buf = arr[right];
                    arr[right] = arr[largest];
                    arr[largest] = buf;
                    flag = true;
                }
            }
            if (flag && j > 0) {
                // возврат к корню для упорядочения ветки
                j = (j - 1) / 2;
                sh++;
                flag = false;
            } else {
                // продолжение построения дерева
                j = j + 1 + sh;
                sh = 0;
            }
        }
        // перестановка первого и последнего элементов
        buf = arr[i - 1];
        arr[i - 1] = arr[0];
        arr[0] = buf;
    }
}

void QuickSort(int *arr, int first, int last) {
    int i = first, j = last, buf, comp;
    comp = arr[(first + last) / 2];
    do{
        while (arr[i] < comp && i < last) i++;
        while (arr[j] > comp && j > first) j--;
        if (i <= j) {
            if (arr[i] > arr[j]) {
                buf = arr[i];
                arr[i] = arr[j];
                arr[j] = buf;
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (first < j) QuickSort(arr, first, j);
    if (i < last) QuickSort(arr, i, last);
}

void BucketSort(int *arr, int n) {
    int **b = new int*[n];
    int *k = new int[n];
    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
        k[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x = arr[i] / 10;
        b[x][k[x]++] = arr[i];
    }
    for (int i = 0; i < n; i++)
        InsertSort(arr);
        // QuickSort(b[i], 0, k[i] - 1);
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k[i]; j++)
            arr[index++] = b[i][j];
}

void MergeSort(int *arr) {
    int size = sizeof(arr);
    int i; // BlockSizeIterator
    int j; // BlockIterator
    int lbi; // LeftBlockIterator
    int rbi; // RightBlockIterator
    int mi; // MergeIterator
    int lb; // LeftBorder
    int mb; // MidBorder
    int rb; // RightBorder
    for(i = 1; i < size; i *= 2) {
        for (j = 0; j < size - i; j += 2 * i) {
            // Производим слияние с сортировкой пары блоков, начинающихся с j. Левый размером i, правый - i или меньше
            lbi = 0;
            rbi = 0;
            lb = j;
            mb = j + i;
            rb = j + 2 * i;
            rb = (rb < size) ? rb : size;
            int* SortedBlock = new int[rb - lb];
            // Пока в обоих массивах есть элементы, выбираем меньший из них и заносим в отсортированный блок
            while (lb + lbi < mb && mb + rbi < rb) {
                if (arr[lb + lbi] < arr[mb + rbi]) {
                    SortedBlock[lbi + rbi] = arr[lb + lbi];
                    lbi++;
                } else {
                    SortedBlock[lbi + rbi] = arr[mb + rbi];
                    rbi++;
                }
            }
            // Заносим оставшиеся элементы из левого или правого блока
            while (lb + lbi < mb) {
                SortedBlock[lbi + rbi] = arr[lb + lbi];
                lbi++;
            }
            while (mb + rbi < rb) {
                SortedBlock[lbi + rbi] = arr[mb + rbi];
                rbi++;
            }
            for (mi = 0; mi < lbi + rbi; mi++) arr[lb + mi] = SortedBlock[mi];
            delete SortedBlock;
        }
    }
}

int main()
{
    int arr[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    
    /* Сортировка вставками. 
    Метод хорош для сортировки данных, получаемых из входного потока.
    Наилучший случай: О(n). Средний, наихудший случаи: O(n^2). */
    // InsertSort(arr);
    
    /* Пирамидальная сортировка.
    Краткое описание алгоритма:
    1. Подготовка (просеивание) – вершина дерева должна быть больше любого элемента в поддеревьях.
    2. Выбор – выкидываем вершину.
    3. Повтор – переходим к 1 с меньшим количеством вершин.
    Наилучший, средний, наихудший случаи: O(n*log(n)) */
    // HeapSort(arr);

    /* Быстрая сортировка.
    1. Выбираем опорный элемент x:=a[(l+r) / 2]
    2. i=l
    3. j=r
    4. Двигаясь вправо, просматриваем поочерёдно все элементы массива, пока не встретим некоторый a[i] ≥ x.
    5. Двигаясь влево, просматриваем поочерёдно все элементы массива, пока не встретим некоторый a[j] ≤ x.
    6. Если i ≤ j,
        a) меняем местами a[i] и a[j],
        b) i увеличиваем на единицу, продвигаясь на 1 шаг вправо,
        c) j уменьшаем на единицу, продвигаясь на 1 шаг влево.
    7. Если i > j, то цель достигнута, иначе перейти к пункту 4
    Наилучший и средний случаи: (n*log(n)), наихудший случай: 0(n^2) */
    // QuickSort(arr, 0, 7);

    /* Блочная сортировка (Карманная сортировка, корзинная сортировка) — алгоритм сортировки, в котором сортируемые элементы распределяются между конечным числом 
    отдельных блоков (карманов, корзин) так, чтобы все элементы в каждом следующем по порядку блоке были всегда больше (или меньше), чем в предыдущем. 
    Каждый блок затем сортируется отдельно, либо рекурсивно тем же методом, либо другим. Затем элементы помещаются обратно в массив. 
    Этот тип сортировки может обладать линейным временем исполнения. */
    // BucketSort(arr, 3); // не работает

    /* Сортировка слиянием.
    1. Используется для эффективной сортировки данных, которые хранятся во внешнем файле.
    2. Алгоритм имеет индуктивный характер
        a) Разобьём массив пополам
        b) Отсортируем каждую из половин тем же способом
            1. Один ключ отсортирован автоматически
        c) Сольём две отсортированные половины вместе
    3. Слияние половин
        a) Для каждой половины заводим индекс, вначале он указывает на наименьший элемент
        b) Выбираем больший элемент из двух, переносим в результирующий массив
        c) Увеличиваем индекс и повторяем процедуру 

    sort(А)
        if А имеет меньше 2 элементов then
            return А
        else if А имеет два элемента then
            Обменять элементы А, если они не в порядке
            return А
        sub1 = sort(left half of A)
        sub2 = sort(right half of A)
        Объединить sub1 и sub2 в новый массив В
        return В
    end */
    // MergeSort(arr);

    for (int i = 0; i < 8; i++) cout << arr[i];

    return 0;
}