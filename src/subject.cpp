#include "../include/subject.h"
#include "../include/observer.h"


Subject::Subject(){

}

Subject::~Subject(){

}

void Subject::add_observer(Notifier *observer){
    notifiers.push_back(observer);
}

void Subject::delete_observer(Notifier *observer){
    for(int i = 0; i < notifiers.size(); i++){
        if(notifiers[i]== observer) {
            delete notifiers[i];
            notifiers.erase( notifiers.begin() + i );
            break;
        }
    }
}

void Subject::nofify_observer(){
    for(int i = 0; i < notifiers.size(); i++){
        notifiers[i] -> notify();
    }
}

vector<Notifier*> Subject::get_notifier() const{
    return notifiers;
}

//===================================================================================
Product::Product(){
    this -> name = "NULL";
    this -> price = 0.0;
    
}

Product::Product(const string &name, const double &price){
    this -> name = name;
    this -> price = price;
   
}

void Product::set_name(const string &name){
    this -> name = name;
    info_change();
}

string Product::get_name()const{
    return this -> name;
}

void Product::set_price(const double &price){
    this -> price = price;
    info_change();
}

double Product::get_price()const{
    return this -> price;
}

void Product::info_change(){
    nofify_observer();
}


