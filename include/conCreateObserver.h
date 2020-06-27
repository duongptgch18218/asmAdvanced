#ifndef _CONCREATEOBSERVER_H_
#define _CONCREATEOBSERVER_H_

#include <vector>
#include <string>
#include <iostream>
#include "observer.h"
#include "subject.h"



class PhoneNotify : public Notifier
{
private:
        Product *p;

public:
        PhoneNotify(const string &name, Product *p);
        void notify();
        ~PhoneNotify();
};

class FacebookNotify : public Notifier
{
private:
        Product *p;

public:
        FacebookNotify(const string &name, Product *p);
        void notify();
        ~FacebookNotify();
};

class EmailNotify : public Notifier
{
private:
        Product *p;

public:
        EmailNotify(const string &name, Product *p);
        void notify();
        ~EmailNotify();
};

#endif