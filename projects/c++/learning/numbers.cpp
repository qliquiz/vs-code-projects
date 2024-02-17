#include <iostream>

using namespace std;

const long long int DENUM = ((long long int)1 << 52);

long long int gcd(long long int a, long long int b);

int main()
{
    /* int number{0b00001100};   // 12
    std::cout << number << std::endl;

    int a = 2 << 2;          // 10  на два разрядов влево = 1000 - 8
    int b = 16 >> 3;         // 10000 на три разряда вправо = 10 - 2

    int x{3};
    int number{7};
    int result{number << x};    // 7 * 2*2*2 = 56
    std::cout << "Result: " << result << std::endl;
    number = 26;
    result = number >> x;       // 26 / (2*2*2) = 3
    std::cout << "Result: " << result << std::endl;

    int a = 5 | 2;          // 101 | 010 = 111  - 7
    int b = 6 & 2;          // 110 & 010 = 10  - 2
    int c = 5 ^ 2;          // 101 ^ 010 = 111 - 7
    int d = ~9;             // -10
 */

    double x = 7.0 / 8.0;
    long long int xl = *(long long int*)(&x);
    int sign = (xl >> 63) & 1;
    int e = (xl >> 52) & 0x7ff;
    e -= 1023;
    long long int mask = ((long long int)1 << 52) - 1;
    long long int mant = xl & mask;

    cout << hex << xl << endl;
    cout << "sign = " << sign << endl;
    cout << "e = " << dec << e << endl;
    cout << "mant = " << hex << mant << endl;
    
    long long int z = gcd(DENUM, mant);

    long long int num, denum;

    if (e < 0.0){
        num = (DENUM + mant) / z;
        denum = (DENUM / z * ((long long int)1 << -e));
    } else {
        num = ((long long int)1 << e) * (DENUM + mant) / z;
        denum = DENUM / z;
    }
    
    cout << num << " / " << denum;

    return 0;
}

long long int gcd(long long int a, long long int b) {
    long long int r = a % b; // если а больше b TODO сделать проверку что больше
    while (r){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}