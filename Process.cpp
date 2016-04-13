#include "Process.h"
#include <string>


Process::Process(string name, int time, int burst)
{
	Process::p_name = name;
	Process::arrival_time = time;
	Process::cpu_burst = burst;
	Process::remaining_time=cpu_burst;
}



int Process::get_arrival()
{
	return Process::arrival_time;
}

void Process::set_priority(int prior)
{
	Process::priority = prior;
}

void Process::set_end_time(int t)
{
    Process::finish=t;
}
void Process::set_remaining_time()
{
    remaining_time=remaining_time-1;
}
void Process::set_arrival(int t)
{
   arrival_time=t;
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


int Process::get_beginning()
{
	return Process::beginning;
}

int Process::get_finish()
{
	return Process::finish;
}




int Process::get_end_time()
{
    return Process::finish;
}
int Process::get_remaining_time()
{
     return remaining_time;
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


bool is_arrived(Process x, int t)
{
	if (x.get_arrival() <= t)
		return true;
	else
		return false;
}

bool lessPrior(Process a,Process b)
{
     if(a.get_priority()<b.get_priority()) return true;
     else return false;

}
bool lessCpuBurst(Process a, Process b)
{
   if(a.get_burst()<b.get_burst()) return true;
     else return false;
}
