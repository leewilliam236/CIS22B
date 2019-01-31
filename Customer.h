#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Customer
{
    private:
        string lastname;
        string firstname;
        string id;
        Customer* next;
        Customer* prev;
    public:
        Customer()
        {
            cout << "Called it." << endl;
        }
};

#endif // CUSTOMER_H
