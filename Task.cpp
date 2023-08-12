#include "Task.h"

#include<iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <chrono>

Task::Task()
	: description("Default Description")
	, completed(false)
	, deadline(0)
{
}

Task::Task(const std::string& str, time_t t)
	: description(str)
	, completed(false)
	, deadline(t)
{
}

void Task::setCompleted()
{
	completed = true;
}

void Task::setDeadline(time_t t)
{
	deadline = t;
}

bool Task::isCompleted() const
{
	return completed;
}

void Task::printTaskInfo() const
{
	std::cout << description << " " << (completed ? "[completed]" : "[not completed]") 
		<< "\t\tDeadline : ";
	std::tm timeInfo;
	localtime_s(&timeInfo, &deadline);
	std::cout << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "\n";

	auto now = std::chrono::system_clock::now();
	time_t Now = std::chrono::system_clock::to_time_t(now);
	if (!completed) {
		if (deadline - Now <= 0) {
			std::cout << " (Deadline finished)\n";
		}
		else if (deadline - Now < 3600) {
			std::cout << " !!! (Deadline approaching)\n";
		}
		else if (deadline - Now < 24 * 3600) {
			std::cout << " (Till deadline one day left)\n";
		}
	}
}

void Task::modifyInfo(const std::string& str)
{
	description = str;
}