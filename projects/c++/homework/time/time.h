#include <iostream>
#include <string>


class Datetime {
private:
    int year, month, day, hour, min, sec;
    double fractionalDay;
public:
    // Конструктор
    Datetime(int y = 2000, int m = 1, int d = 1, double fd = 0.0);
    // Деструктор
    ~Datetime();
    // Методы для работы с датой и временем
    void setDate(std::string date);
    void printDate(int format);
    void calculateDifference(Datetime date2);
    std::string getDayOfWeek();
    bool isValidate();
    // Метод определения даты Пасхи
    Datetime calculateEasterDate();
    // Mетоды для работы с временем
    void setTime(std::string time);
    void printTime();
};

class DatetimeException {};