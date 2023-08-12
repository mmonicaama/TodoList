#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "Task.h"
#include "TodoList.h"

int main()
{
    /*
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::minutes oneDay(23);
    std::chrono::system_clock::time_point tomorrow = now + oneDay;
    time_t taskDeadline = std::chrono::system_clock::to_time_t(tomorrow);

    TodoList myList;
    myList.addTask("Finish report", taskDeadline);
    myList.markAsCompleted(0);
    myList.print();
    */

    TodoList myList;
    while (true) {
        std::cout << "1. Add task\n";
        std::cout << "2. Modify task\n";
        std::cout << "3. Delete task\n";
        std::cout << "4. Mark as completed\n";
        std::cout << "5. Show tasks\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;
         
        if (choice == 1) {
            std::string desc;
            std::cout << "Enter task description : ";
            std::cin.get();
            std::getline(std::cin, desc);


            
            std::string userInput;
            std::tm tmDeadline{}; 

            std::cout << "Enter task deadline (YYYY-MM-DD HH:MM:SS) : ";
            std::getline(std::cin, userInput); 

            std::istringstream ss(userInput);
            ss >> std::get_time(&tmDeadline, "%Y-%m-%d %H:%M:%S");

            if (ss.fail()) {
                std::cerr << "Invalid date format." << std::endl;
                return 1;
            }

            time_t dl = std::mktime(&tmDeadline);

            myList.addTask(desc, dl);
        }
        else if (choice == 2) 
        {
            size_t index;
            std::cout << "Enter task index : ";
            std::cin >> index;

            std::string desc;
            std::cout << "Enter task new description : ";
            std::cin.get();
            std::getline(std::cin, desc);

            myList.changeDescription(index, desc);
        }
        else if (choice == 3) {
            size_t index;
            std::cout << "Enter task index : ";
            std::cin >> index;

            myList.deleteTask(index);
        }
        else if (choice == 4) {
            size_t index;
            std::cout << "Enter task index : ";
            std::cin >> index;

            myList.markAsCompleted(index);
        }
        else if (choice == 5) {
            myList.print();
        }
        else if (choice == 6) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Wrong opcode : Enter correct code for operation.\n";
        }
    }

	return 0;
}