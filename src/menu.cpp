#include "../include/menu.h"
#include "../include/observer.h"
#include "../include/conCreateObserver.h"
#include "../include/subject.h"
#include <unistd.h>

using namespace std;

Menu::Menu()
{
}

void Menu::run()
{
    string name;
    double price;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|                Declare product              |" << endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << " " << endl;
    cout << "Input name product: ";
    getline(cin, name);
    cout << "Input price of product: ";
    check_price(price);
    cout << "************************************************" << endl;
    p = new Product(name, price);
    Notifier *phone = new PhoneNotify("phone", p);
    Notifier *fb = new FacebookNotify("fb", p);
    Notifier *email = new EmailNotify("email", p);
    cout << "Create product successfull!" << endl;
    usleep(2000000);
    system("cls");
}

void Menu::print_menu() const
{
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|                  ASM Program                |" << endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << "|  Choice |             Function              |" << endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << "|    " <<CHANGE_NAME <<  "    |        Change name product        |"<< endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << "|    "<< CHANGE_PRICE << "    |        Change price product       |"<< endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << "|    "<<STATUS << "    |                Status             |" << endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << "|    "<< DELETE_NOTIFY << "    |          Delete notifier          |" << endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << "|    "<<CREATE_NOTIFY << "    |            Add notifier           |" << endl;
    cout << "+---------+-----------------------------------+" << endl;
    cout << "|    " <<EXIT << "    |                Exit               |" << endl;
    cout << "+---------+-----------------------------------+" << endl;
}

void Menu::check_price(double &price){
    while(!(cin >> price)){
        cout << "Invalid input, please input again!" << endl;
        cin.clear();
        fflush(stdin);
    }
}

int Menu::get_choice(const int &min, const int &max) const
{
    int choice;
    cout << "Your choice: ";
    while (!(cin >> choice))
    {
        cout << "[-] Input invalid, please input again" << endl;
        cin.clear();
        fflush(stdin);
    }
    while (true)
    {
        if (choice >= min && choice <= max)
        {
            break;
        }
        else
        {
            cout << "[-] Choice must greater than " << min << " and smaller than " << max << endl;
        }
    }
    return choice;
}

void Menu::do_task(const int &choice)
{
    switch (choice)
    {
    case CHANGE_NAME:
        system("cls");
        change_name();
        break;
    case CHANGE_PRICE:
        system("cls");
        change_price();
        break;
    case STATUS:
        system("cls");
        status();
        break;
    case DELETE_NOTIFY:
        system("cls");
        delete_observer();
        break;
    case CREATE_NOTIFY:
        add_observer();
        break;
    case EXIT:
        cout << "[+] Good bye" << endl;
        break;
    default:
        cout << "[-] Invalid choice" << endl;
    }
}

void Menu::change_name()
{
    string new_name;
    cout << "Input new name: ";
    fflush(stdin);
    getline(cin, new_name);
    p->set_name(new_name);
    usleep(3000000);
}

void Menu::change_price()
{
    double new_price;
    cout << "Input new price: ";
    fflush(stdin);
    check_price(new_price);
    p->set_price(new_price);
    usleep(3000000);
}

void Menu::delete_observer()
{  
    system("cls");
    cout << "+---------------------------------------------+" << endl;
    cout << "|              List notifier added            |" << endl;
    cout << "+---------------------------------------------+" << endl;
    const vector<Notifier *> list_notifier = p->get_notifier();
    show_list_notifier();
    cout << "==> What notifier do you want to delete " << endl;
    int choice = get_choice(1, list_notifier.size());
    p->delete_observer(list_notifier[choice - 1]);
    cout << "[+] Delete successfull" << endl;
    usleep(2000000);
}

void Menu::status() const
{
    system("cls");
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|            Product Information              |" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "Name: " << p->get_name() << endl;
    cout << "Price: " << p->get_price() << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|            List notifier added              |" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    show_list_notifier();
    cout << "===============================================" << endl;
    cout << endl;
    usleep(3000000);
}

void Menu::show_list_notifier() const
{
    const vector<Notifier *> list_notifier = p->get_notifier();
    for (int i = 0; i < list_notifier.size(); i++)
    {
        cout << i + 1 << " . " << list_notifier[i]->get_name() << endl;
    }
}

void Menu::add_observer()
{
    system("cls");
    cout << "+-----------------------+---------------------+" << endl;
    cout << "|               Add notifier                  |" << endl;
    cout << "+-----------------------+---------------------+" << endl;
    cout << "1 . Add Facebook notifier" << endl;
    cout << "2 . Add Email notifier" << endl;
    cout << "3 . Add Phone notifier" << endl;
    cout << "0. Exit" << endl;
    while (true)
    {
        bool flag = true;
        int x = get_choice(0, 3);
        string name = "";
        if (x == 0)
        {
            break;
        }

        if (x == 1)
        {
            name = "fb";
        }
        else if (x == 2)
        {
            name = "email";
        }
        else
        {
            name = "phone";
        }

        vector<Notifier *> list = p->get_notifier();
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i]->get_name() == name)
            {
                cout << "Notifier already exist, please choose again" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            if (name == "fb")
            {
                Notifier *aha  = new FacebookNotify(name,p);
            }
            else if (name == "phone")
            {
                Notifier *aha  = new PhoneNotify(name,p);
            }
            else
            {
                Notifier *aha  = new EmailNotify(name,p);
            }
            cout << "Add successfull" << endl;
            usleep(3000000);
            break;
        }
    }
}
