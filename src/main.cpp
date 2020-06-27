#include <iostream>
#include "../include/observer.h"
#include "../include/subject.h"
#include "../include/conCreateObserver.h"
#include "../include/menu.h"
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
	Product *p;
	Menu test;
	test.run();

	while (true)
	{
		test.print_menu();
		int choice = test.get_choice(0, 5);
		test.do_task(choice);
		if(choice == 0){
			break;
		}
		
	}
}