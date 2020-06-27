#ifndef _MENU_H_
#define _MENU_H_
#include "subject.h"

#define CHANGE_NAME 1
#define CHANGE_PRICE 2
#define STATUS 3
#define DELETE_NOTIFY 4
#define CREATE_NOTIFY 5
#define EXIT 0

using namespace std;

class Menu
{
private:
    Product *p;

public:
    void run();
    Menu();
    void print_menu() const;
    int get_choice(const int &min, const int &max) const;
    void do_task(const int &choice);

private:
    void change_name();
    void change_price();
    void delete_observer();
    void add_observer();
    void status() const;
    void show_list_notifier() const;
    void check_price(double &price);
};

#endif


