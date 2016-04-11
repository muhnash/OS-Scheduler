#include "Process.h"
#include <string>

int Process::quantum;
Process::Process(string name, int time, int burst)
{
	Process::p_name = name;
	Process::arrival_time = time;
	Process::cpu_burst = burst;
}

/*
Process::Process(string name, int time, int burst, int prior)
{
	Process::p_name = name;
	Process::arrival_time = time;
	Process::cpu_burst = burst;
	Process::priority = prior;
}
*/






int Process::get_arrival()
{
	return Process::arrival_time;
}

void Process::set_priority(int prior)
{
	Process::priority = prior;
}

void Process::set_quantum(int quant)
{
	Process::quantum = quant;
}

void Process::set_beginning(int beg)
{
	Process::beginning = beg;
}

void Process::set_finish(int fin)
{
	Process::finish = fin;
}

int Process::get_burst()
{
	return Process::cpu_burst;
}

std::string Process::get_name()
{
	return Process::p_name;
}

int Process::get_priority()
{
	return Process::priority;
}

int Process::get_quantum()
{
	return Process::quantum;
}

int Process::get_beginning()
{
	return Process::beginning;
}

int Process::get_finish()
{
	return Process::finish;
}

/*
list<Process>::iterator first_come(list<Process> x)
{
	list<Process>::iterator it;
	list<Process>::iterator first;
	int min_time = x.front().get_arrival();
	first = x.begin();
	for (it = next(x.begin()); it != x.end(); it++)
	{
		
		if (it->get_arrival() < min_time)
		{
			min_time = it->get_arrival();
			first = it;
		}
	}


	return first;
}
*/





bool isEarlier(Process a, Process b) 
{
	if (a.get_arrival()<b.get_arrival())
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool lessBurst(Process a, Process b)
{

	if (a.get_burst() < b.get_burst())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_arrived(Process x, int t)
{
	if (x.get_arrival() <= t)
		return true;
	else
		return false;
}
