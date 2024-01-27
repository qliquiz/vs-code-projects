#include <iostream>
#include <memory>

using namespace std;

/* 
 * auto_ptr
 * unique_ptr
 * shared_ptr
 * weak_ptr
*/

int main()
{
    /* auto_ptr не работает
    auto_ptr<int> sp1(new int(5));
    auto_ptr<int> sp2(sp1); */

    /* unique_ptr
    unique_ptr<int> sp1(new int(5)); // хранится 5
    unique_ptr<int> sp2; // пустой

    sp2 = move(sp1); // как и с auto_ptr, указатели поменяются данными 
    sp2 = swap(sp1); // то же самое

    int *p = sp1.get(); // вернёт обычный указатель

    int *p = new int(5);
    unique_ptr<int> p1(p);
    p1.reset(); // сотрёт данные в p и сделает пустым р1
    p1.release(); // оставит данные в р и сделает пустым р1
    */

    /* shared_ptr
    shared_ptr<int> sp1(new int(5));
    shared_ptr<int> sp2(sp1); // оба смогут ссылаться на одну переменную */

    // weak_ptr какая-то пезда

    /* Работа с массивами
    int *arr = new int[5] {1, 5, 3, 9, 7};
    shared_ptr<int[]> ptr(arr);

    shared_ptr<int[]> ptr(new int[5] {1, 5, 3, 9, 7}); // более короткая запись */

    return 0;
}