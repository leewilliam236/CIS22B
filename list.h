#ifndef LIST_H
#define LIST_H
#include "Customer.h"

class list
{
private:
    Customer* head;
    Customer* tail;
    public:
        list() : head(nullptr), tail(nullptr)
        {}
};

#endif // LIST_H
