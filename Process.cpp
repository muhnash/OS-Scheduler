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

float Process::get_burst()
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
