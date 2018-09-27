/**
Ass#1
William Lee
Code::Blocks (Windows 10 Pro)
GNU GCC Compiler
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

void manipulator(ofstream&);
double taxing(string, double, ofstream&);

const float tax = 0.09;

int main()
{
    ifstream shoplist;
    ofstream reciept;
    string readfirstline, item;
    double price, grandtotal = 0;
    shoplist.open("C:\\Users\\Student\\Documents\\22B\\Ass#1\\shopping_list.txt");
    if(!shoplist)
    {
        cout << "Can't open file";
        exit(0);
    }
    getline(shoplist, readfirstline);
    reciept.open("C:\\Users\\Student\\Documents\\22B\\Ass#1\\reciept.txt");
    manipulator(reciept);
    do
    {
        reciept << fixed << showpoint << setprecision(2);
        shoplist >> item >> price;
        grandtotal += taxing(item, price, reciept);
    }
    while (!shoplist.eof());
    reciept << right << setw(40) << "--------" << endl;
    reciept << setw(33) << "Total ";
    reciept << setw(7) << grandtotal << endl;
    shoplist.close();
    reciept.close();
    return 0;
}

double taxing(string i, double p, ofstream& r)
{
    double subtotal = 0;
    if(i == "water" || i == "banana")
    {
        subtotal += p;
        r << left << setw(12) << i;
        r << right << setw(10) << p;
        r << setw(8) << tax*0;
        r << setw(10) << p << endl;
    }
    else
    {
        subtotal = (p*tax) + p;
        r << left << setw(12) << i;
        r << right << setw(10) << p;
        r << setw(8) << p*tax;
        r << setw(10) << subtotal << endl;
    }
    return subtotal;
}
void manipulator(ofstream& r)
{
    r << left << setw(12) << "Item";
    r << right << setw(10) << "Cost";
    r << setw(8) << "Tax";
    r << setw(10) << "Subtotal" << endl;
    r << left << setw(12) << "-----------";
    r << right << setw(10) << "------";
    r << setw(8) << "-----";
    r << setw(10) << "--------" << endl;
}
