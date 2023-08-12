#include "TodoList.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Task.h"

TodoList::TodoList()
{
	tasks.resize(0);
}

void TodoList::addTask(const std::string& str, time_t t)
{
	tasks.emplace_back(str, t);
}

void TodoList::changeDescription(size_t index, const std::string& str)
{
	if (index < tasks.size()) {
		tasks[index].modifyInfo(str);
	}
	else {
		std::cout << "Error: Invalid task index." << std::endl;
	}
}

void TodoList::deleteTask(size_t index)
{
	if (index < tasks.size()) {
		tasks.erase(tasks.begin() + index);
	}
	else {
		std::cout << "Error: Invalid task index." << std::endl;
	}
}

void TodoList::markAsCompleted(size_t index)
{
	if (index < tasks.size()) {
		tasks[index].setCompleted();
	}
	else {
		std::cout << "Error: Invalid task index." << std::endl;
	}
}

void TodoList::changeDeadline(size_t index, time_t t)
{
	if (index < tasks.size()) {
		tasks[index].setDeadline(t);
	}
	else {
		std::cout << "Error: Invalid task index." << std::endl;
	}
}

void TodoList::print() const
{
	int count{};
	int index = 1;
	std::cout << "Tasks:\n\n";
	for (const auto& task : tasks) {
		std::cout << "Task " << index++ << ":\n";
		task.printTaskInfo();
		if (task.isCompleted()) {
			++count;
		}
	}
	std::cout << std::endl;
	std::cout << "Completed tasks : " << count << std::endl;
	std::cout << "Not completed tasks : " << tasks.size() - count << std::endl;
}