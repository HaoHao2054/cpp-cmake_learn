#include <iostream>
#include <climits>

using namespace std;


int main()
{
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;

    cout << "===========================" << endl;
    cout << "char min: = " << CHAR_MIN << ", max: " << CHAR_MAX << endl;
    cout << "short min: = " << SHRT_MIN << ", max: " << SHRT_MAX << endl;
    cout << "int min: = " << INT_MIN << ", max: " << INT_MAX << endl;
    cout << "long min: = " << LONG_MIN << ", max: " << LONG_MAX << endl;
    cout << "long long min: = " << LLONG_MIN << ", max: " << LLONG_MAX << endl;

    

    return 0;
}
