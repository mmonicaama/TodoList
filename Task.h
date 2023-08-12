#ifndef TASK_H
#define TASK_H

#include<string>
#include<ctime>

class Task
{
public:
	Task();
	Task(const std::string&, time_t);

	void setCompleted();
	void setDeadline(time_t);
	bool isCompleted() const;
	void printTaskInfo() const;
	void modifyInfo(const std::string&);

private:
	std::string description;
	bool completed;
	time_t deadline;
};

#endif