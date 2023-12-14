#include <iostream>
#include <string>
#include <map>

using namespace std;

// Функция для кодирования текста в азбуку Морзе
string encodeToMorse(const string &text) {
    map<char, string> morseAlphabet{
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."},
        {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
        {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}
    };

    string morseText;
    for (char ch : text) {
        if (morseAlphabet.find(toupper(ch)) != morseAlphabet.end()) {
            morseText += morseAlphabet[toupper(ch)] + " ";
        } else if (ch == ' ') {
            morseText += "/ ";
        }
    }
    return morseText;
}

// Функция для декодирования последовательности точек и тире в текст
string decodeFromMorse(const string &morseCode) {
    map<string, char> morseAlphabet{
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, {"..-.", 'F'},
        {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
        {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},
        {"...", 'S'}, {"-", 'T'}, {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
        {"-.--", 'Y'}, {"--..", 'Z'},
        {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'},
        {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}, {"-----", '0'}
    };

    string decodedText;
    string word;
    string morseWord;
    for (char ch : morseCode) {
        if (ch == ' ' || ch == '/') {
            if (!morseWord.empty()) {
                if (morseAlphabet.find(morseWord) != morseAlphabet.end()) {
                    decodedText += morseAlphabet[morseWord];
                } else if (morseWord == "/") {
                    decodedText += " ";
                }
                morseWord.clear();
            }
        } else {
            morseWord += ch;
        }
    }
    if (!morseWord.empty() && morseAlphabet.find(morseWord) != morseAlphabet.end()) {
        decodedText += morseAlphabet[morseWord];
    }
    return decodedText;
}

int main() {
    string inputText;
    cout << "Input text: ";
    getline(cin, inputText);

    string morseCode = encodeToMorse(inputText);
    cout << "Result: " << morseCode << endl;

    string inputMorse;
    cout << "Input code: ";
    getline(cin, inputMorse);

    string decodedText = decodeFromMorse(inputMorse);
    cout << "Result: " << decodedText << endl;

    return 0;
}
