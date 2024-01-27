#include <iostream>
#include <unordered_map>

using namespace std;

int romanToArabic(const string& roman) {
    unordered_map<char, int> romanMap{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    for (int i = roman.size() - 1; i >= 0; i--) {
        int currentValue = romanMap[roman[i]];
        
        if (currentValue < prevValue) result -= currentValue;
        else result += currentValue;

        prevValue = currentValue;
    }
    return result;
}

string arabicToRoman(int number) {
    if (number < 1 || number > 3999) return "Enter a correct number";

    unordered_map<int, string> romanMap{
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
        {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
        {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
    };

    int arabic[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int i = 12;
    string result = "";

    while (number > 0) {
        int div = number / arabic[i];
        number = number % arabic[i];
        while (div--) result += romanMap[arabic[i]];
        i--;
    }
    return result;
}

int main() {
    string romanNumeral;
    cout << "Enter a roman number: ";
    cin >> romanNumeral;

    int arabicNumber = romanToArabic(romanNumeral);
    cout << "Arabic interpretation: " << arabicNumber << endl;

    int arabicNumeral;
    cout << "Enter an arabic number (from 1 to 3999): ";
    cin >> arabicNumeral;

    string romanNumber = arabicToRoman(arabicNumeral);
    cout << "Roman interpretation: " << romanNumber << endl;

    return 0;
}
