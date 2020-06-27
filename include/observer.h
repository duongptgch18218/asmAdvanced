#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Notifier
{
protected:
        string name;
public:
        Notifier();
        virtual void notify() = 0;
        ~Notifier();
        string get_name();
};
#endif