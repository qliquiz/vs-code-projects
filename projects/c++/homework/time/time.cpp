#include <iostream>
#include <string>
#include <ctime>

#include "time.h"


int main() {
    setlocale(LC_ALL, "rus");

    Datetime date1, date2;
    date1.setDate("2024-03-22T13:14:40");
    
    date1.printDate(1); // Вывод формата "01.01.2001"
    date1.printDate(2); // Вывод формата "1/01/2001"
    date1.printDate(3); // Вывод формата "1 января 2001"

    date1.getDayOfWeek();

    if (date1.isValidate()) std::cout << "Дата корректна!" << std::endl;
    else throw DatetimeException();

    return 0;
}

Datetime::Datetime(int y = 2000, int m = 1, int d = 1, double fd = 0.0) : year(y), month(m), day(d), fractionalDay(fd) {}

void Datetime::setDate(std::string date) {
    std::string strYear = "", strMonth = "", strDay = "", strHour = "", strMin = "", strSec = "";

    for (int i = 0; i < date.length(); i++) {
        if (i < 4) strYear += date[i];
        else if (4 < i && i < 7) strMonth += date[i];
        else if (7 < i && i < 10) strDay += date[i];
        if (date.length() > 11) {
            if (10 < i && i < 13) strHour += date[i];
            else if (13 < i && i < 16) strMin += date[i];
            else if (16 < i && i < 19) strSec += date[i];
        }
    }

    year = std::stoi(strYear);
    month = std::stoi(strMonth);
    day = std::stoi(strDay);

    hour = std::stoi(strHour);
    min = std::stoi(strMin);
    sec = std::stoi(strSec);

    /* if (date.length() > 11) {
        // fractionalDay
    } */
}

void Datetime::printDate(int format) {
    if (format == 1) {
        if (day < 10) std::cout << '0' + std::to_string(day);
        else std::cout << day;
        std::cout << '.';
        if (month < 10) std::cout << '0' + std::to_string(month);
        else std::cout << month;
        std::cout << '.' << year << std::endl;
    }
    else if (format == 2) std::cout << day << '/' << month << '/' << year << std::endl;
    else switch (month)
    {
    case 1:
        std::cout << day << " Января " << year << std::endl;
        break;
    case 2:
        std::cout << day << " Февраля " << year << std::endl;
        break;
    case 3:
        std::cout << day << " Марта " << year << std::endl;
        break;
    case 4:
        std::cout << day << " Апреля " << year << std::endl;
        break;
    case 5:
        std::cout << day << " Мая " << year << std::endl;
        break;
    case 6:
        std::cout << day << " Июня " << year << std::endl;
        break;
    case 7:
        std::cout << day << " Июля " << year << std::endl;
        break;
    case 8:
        std::cout << day << " Августа " << year << std::endl;
        break;
    case 9:
        std::cout << day << " Сентября " << year << std::endl;
        break;
    case 10:
        std::cout << day << " Октября " << year << std::endl;
        break;
    case 11:
        std::cout << day << " Ноября " << year << std::endl;
        break;
    case 12:
        std::cout << day << " Декабря " << year << std::endl;
        break;
    default:
        throw DatetimeException();
        break;
    }
}

void Datetime::calculateDifference(Datetime date2) {
    //
}

std::string Datetime::getDayOfWeek() {
    int result = (6 + year % 100 + (year % 100 / 4)) % 7 + day;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) 
        switch (month)
        {
        case 1:
            result += static_cast<int>(LeapMonths::January);
            break;
        case 2:
            result += static_cast<int>(LeapMonths::February);
            break;
        case 3:
            result += static_cast<int>(LeapMonths::March);
            break;
        case 4:
            result += static_cast<int>(LeapMonths::April);
            break;
        case 5:
            result += static_cast<int>(LeapMonths::May);
            break;
        case 6:
            result += static_cast<int>(LeapMonths::June);
            break;
        case 7:
            result += static_cast<int>(LeapMonths::July);
            break;
        case 8:
            result += static_cast<int>(LeapMonths::August);
            break;
        case 9:
            result += static_cast<int>(LeapMonths::September);
            break;
        case 10:
            result += static_cast<int>(LeapMonths::October);
            break;
        case 11:
            result += static_cast<int>(LeapMonths::November);
            break;
        case 12:
            result += static_cast<int>(LeapMonths::December);
            break;
        default:
            throw DatetimeException();
            break;
        }
    else
        switch (month)
        {
        case 1:
            result += static_cast<int>(Months::January);
            break;
        case 2:
            result += static_cast<int>(Months::February);
            break;
        case 3:
            result += static_cast<int>(Months::March);
            break;
        case 4:
            result += static_cast<int>(Months::April);
            break;
        case 5:
            result += static_cast<int>(Months::May);
            break;
        case 6:
            result += static_cast<int>(Months::June);
            break;
        case 7:
            result += static_cast<int>(Months::July);
            break;
        case 8:
            result += static_cast<int>(Months::August);
            break;
        case 9:
            result += static_cast<int>(Months::September);
            break;
        case 10:
            result += static_cast<int>(Months::October);
            break;
        case 11:
            result += static_cast<int>(Months::November);
            break;
        case 12:
            result += static_cast<int>(Months::December);
            break;
        default:
            throw DatetimeException();
            break;
        }
    result %= 7;
    switch (result)
    {
    case 1:
        std::cout << "Понедельник" << std::endl;
        break;
    case 2:
        std::cout << "Вторник" << std::endl;
        break;
    case 3:
        std::cout << "Среда" << std::endl;
        break;
    case 4:
        std::cout << "Четверг" << std::endl;
        break;
    case 5:
        std::cout << "Пятница" << std::endl;
        break;
    case 6:
        std::cout << "Суббота" << std::endl;
        break;
    case 7:
        std::cout << "Воскресенье" << std::endl;
        break;
    default:
        throw DatetimeException();
        break;
    }
}

bool Datetime::isValidate() {
    if (day < 1 || day > 31 || month < 1 || month > 12) // год, думаю, может быть меньше нулевого и больше 2024
        return false;
    return true;
}

Datetime Datetime::calculateEasterDate() {
    return Datetime();
}

void Datetime::setTime(std::string time) {
    std::string strHour = "", strMin = "", strSec = "";

    for (int i = 0; i < time.length(); i++) {
        if (i < 2) strHour += time[i];
        else if (2 < i && i < 5) strMin += time[i];
        else if (5 < i && i < 8) strSec += time[i];
    }

    hour = std::stoi(strHour);
    min = std::stoi(strMin);
    sec = std::stoi(strSec);
}

void Datetime::printTime() { std::cout << hour << ':' << min << ':' << sec << std::endl; }