#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include <string>
#include <iostream>
#include "observer.h"

using namespace std;

class Subject{
    protected:
        vector<Notifier*> notifiers;  
    public:
        Subject();
        ~Subject();
        void add_observer(Notifier *observer);
        void delete_observer(Notifier *observer);
        void nofify_observer();
        vector<Notifier*> get_notifier() const;
};


class Product:public Subject{
    private:
        string name;
        double price;
    public:
        Product();
        Product(const string &name, const double &price);
        void set_name(const string &name);
        string get_name() const;
        void set_price(const double &price);
        double get_price() const;
        void info_change();
};
#endif