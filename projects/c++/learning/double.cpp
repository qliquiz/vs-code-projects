#include <iostream>

using namespace std;

const long long int DENUM = ((long long int)1 << 52);

long long int gcd(long long int a, long long int b);

int main()
{
    double x = 1.0 / 4.0 + 1.0 / 2.0 + 1.0 / 8.0;

    long long int xl = *(long long int*)(&x);
    int sign = (xl >> 63) & 1;
    int exp = (xl >> 52) & 0x7ff;
    exp -= 1023;
    long long int mask = ((long long int)1 << 52) - 1;
    long long int mant = xl & mask;

    cout << hex << xl << endl;
    cout << "sign = " << sign << endl;
    cout << "exp = " << dec << exp - 1023 << endl;
    cout << "mant = " << hex << mant << endl;
    
    long long int z = gcd(DENUM, mant);

    long long int num, denum;

    if (exp < 0.0){
        num = (DENUM + mant) / z;
        denum = (DENUM / z * ((long long int)1 << -exp));
    } else {
        num = ((long long int)1 << exp) * (DENUM + mant) / z;
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