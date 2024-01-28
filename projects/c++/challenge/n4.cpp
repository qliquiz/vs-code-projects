#include <iostream>

using namespace std;

bool equals1(char* word1, char* word2, int wordLen) {
    bool flag;
    for(int i = 0; i<wordLen; i++) {
        flag = false;
        for(int j = 0; j<wordLen; j++) {
            if(word1[i] == word2[j]) {
                flag = true;
                break;
            }
        }
        if(not flag) return flag;
    }
    return true;
}

int* countAlpha(char* word, int wordLen) {
    int* result = new int[26];

    for(int i = 0; i<26; i++) result[i] = 0;

    for(int i = 0; i<wordLen; i++) {
        result[word[i]-'A'] += 1;
    }

    return result;
}

bool equals2(char* word1, char* word2, int wordLen) {
    int* wordAlpha1 = new int[26];
    wordAlpha1 = countAlpha(word1, wordLen);
    int* wordAlpha2 = new int[26];
    wordAlpha2 = countAlpha(word2, wordLen);
    for(int i = 0; i<26; i++) {
        if(wordAlpha1[i] != wordAlpha2[i]) return false;
    }
    return true;
}

int myHash(char* word, int wordLen) {
    int summ = 0;
    for(int i = 0; i<wordLen; i++) {
        summ += (int)(word[i]);
    }
    int result = 0;
    for(int i = 0; i<wordLen; i++) {
        result += (int)(word[i]) * (summ-(int)(word[i]));
    }
    return result;
}

bool equals3(char* word1, char* word2, int wordLen) {
    return (myHash(word1, wordLen) == myHash(word2, wordLen));
}

int main() {
    // 1. Группировка
    // 2. Метод сравнения слов
    int wordCounts;
    cout << "Enter count of words: ";
    cin >> wordCounts;
    char** words = new char*[wordCounts];

    int wordLen;

    cout << "Enter word lenght: ";
    cin >> wordLen;
    for(int i = 0; i<wordCounts; i++) {
        cout << "Enter your word: ";
        words[i] = new char[wordLen];
        cin >> words[i];
    }


    cout << "Your words is: \n";
    for(int i = 0; i<wordCounts; i++) {
        for(int j = 0; j<wordLen; j++) cout << words[i][j];
        cout << '\n';
    }

    cout << equals1(words[0], words[1], wordLen) << '\n';
    cout << equals2(words[0], words[1], wordLen) << endl;
    cout << equals3(words[0], words[1], wordLen) << endl;

    int wordHash;
    int groupCount = 0;
    for(int i = 0; i<wordCounts; i++) {
        if(words[i][0] == '0') continue;
        wordHash = myHash(words[i], wordLen);
        cout << "Group number " << ++groupCount << ": ";
        for(int j = 0; j<wordCounts; j++) {
            if(myHash(words[j], wordLen) == wordHash) {
                cout << words[j] << ' ';
                words[j][0] = '0';
            }
        }
        cout << endl;
    }


    return 0;
}