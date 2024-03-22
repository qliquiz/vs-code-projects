#include <iostream>
#include <string>


class Datetime {
private:
    int year, month, day, hour, min, sec;
    double fractionalDay;
public:
    // Конструктор
    Datetime(int y = 2000, int m = 1, int d = 1, double fd = 0.0) : year(y), month(m), day(d), fractionalDay(fd) {}
    // Деструктор
    // ~Datetime();
    // Методы для работы с датой и временем
    void setDate(std::string date);
    void printDate(int format);
    void calculateDifference(Datetime date2);
    void printWeekDay();
    bool isValidate();
    // Метод определения даты Пасхи
    Datetime calculateEasterDate();
    // Mетоды для работы с временем
    void setTime(std::string time);
    void printTime();
};

class DatetimeException {};

enum class Months {January = 1, February = 4, March = 4, April = 0, May = 2, June = 5, July = 0, August = 3, September = 6, October = 1, November = 4, December = 6};

enum class LeapMonths {January = 0, February = 3, March = 4, April = 0, May = 2, June = 5, July = 0, August = 3, September = 6, October = 1, November = 4, December = 6};