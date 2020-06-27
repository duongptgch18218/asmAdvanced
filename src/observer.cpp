#include "../include/subject.h"
#include "../include/observer.h"
#include "../include/conCreateObserver.h"

Notifier::Notifier()
{
}

Notifier::~Notifier()
{
}

string Notifier::get_name()
{
    return this->name;
}

PhoneNotify::PhoneNotify(const string &name, Product *p_para)
{
    this->name = name;
    p = p_para;
    p->add_observer(this);
}
PhoneNotify::~PhoneNotify()
{
    p->delete_observer(this);
}

void PhoneNotify::notify()
{
    cout << "+---------------------------+-----------------------+" << endl;
    cout << "|   Notify all subscribers via Phone with new data  |" << endl;
    cout << "+---------------------------+-----------------------+" << endl;
    cout << "Name: " << p->get_name() << endl;
    cout << "Price: " << p->get_price() << endl;
}

FacebookNotify::FacebookNotify(const string &name, Product *p_para)
{
    this->name = name;
    p = p_para;
    p->add_observer(this);
}
FacebookNotify::~FacebookNotify()
{
    p->delete_observer(this);
}

void FacebookNotify::notify()
{
    cout << "+---------------------------+-----------------------+" << endl;
    cout << "| Notify all subscribers via Facebook with new data |" << endl;
    cout << "+---------------------------+-----------------------+" << endl;
    cout << "Name: " << p->get_name() << endl;
    cout << "Price: " << p->get_price() << endl;
}
EmailNotify::EmailNotify(const string &name, Product *p_para)
{
    this->name = name;
    p = p_para;
    p->add_observer(this);
}
EmailNotify::~EmailNotify()
{
    p->delete_observer(this);
}

void EmailNotify::notify()
{

    cout << "+---------------------------+-----------------------+" << endl;
    cout << "|  Notify all subscribers via Email with new data   |" << endl;
    cout << "+---------------------------+-----------------------+" << endl;
    cout << "Name: " << p->get_name() << endl;
    cout << "Price: " << p->get_price() << endl;
}