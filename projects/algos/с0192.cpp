#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct timee {
    int hours;
    int minutes;
    int seconds;
};

bool compare(const timee& left, const timee& right) {
    if (left.hours != right.hours)
        return left.hours < right.hours;
    if (left.minutes != right.minutes)
        return left.minutes < right.minutes;
    return left.seconds < right.seconds;
}

int main()
{
    int N;
    cin >> N;

    vector<timee> vec(N);

    for (int i = 0; i < N; i++) {
        int hours, minutes, seconds;
        cin >> hours >> minutes >> seconds;
        timee strct;
        strct.hours = hours;
        strct.minutes = minutes;
        strct.seconds = seconds;
        vec[i] = strct;
    }

    sort(begin(vec), end(vec), compare);

    for (int i = 0; i < N; i++)
        cout << vec[i].hours << ' ' << vec[i].minutes << ' ' << vec[i].seconds << endl;

    return 0;
}