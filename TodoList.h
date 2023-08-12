#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>
#include <ctime>

#include "Task.h"

class TodoList
{
public:
	TodoList();

	void addTask(const std::string&, time_t);
	void changeDescription(size_t, const std::string&);
	void deleteTask(size_t);
	void markAsCompleted(size_t);
	void changeDeadline(size_t, time_t);
	void print() const;

private:
	std::vector<Task> tasks;
};

#endif