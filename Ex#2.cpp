#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

const float PI = 3.1416;

int main()
{
    ifstream circlein;
    ofstream circleout;
    string firstname, lastname;
    string first[12];
    int radius, rad[12];
    float r = 0;
    circlein.open("C:\\Users\\Student\\Documents\\22B\\Examples\\Ex#2\\circle.txt");
    if(!circlein)
    {
        cerr << "Can't open file" << endl;
        exit(0);
    }
    int i = 0;
    do
    {
        circlein >> firstname >> lastname >> radius;
        first[i] = firstname;
        rad[i] = radius;
        cout << left << setw(10) << first[i];
        r = static_cast<float>(rad[i]);
        cout << setprecision(2) << fixed << showpoint;
        cout << right << setw(10) << PI*pow(r,2) << endl;
        i++;
    }while(!circlein.eof());
    circlein.close();
    return 0;
}
