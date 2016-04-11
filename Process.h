#pragma once
#ifndef PROCESS_H_
#define PROCESS_H_

#include<string>
#include<list>
using namespace std;

class Process
{
private:
	string p_name;
	int beginning=0, finish;
	int arrival_time = 0, priority = 0, cpu_burst, remaining_time,end_time;


public:
	Process(string name, int time, int burst);

    void set_arrival(int t);
	void set_priority(int prior);

	void set_beginning(int beg);
	void set_finish(int fin);
	int get_burst();

	void set_end_time(int t);
	void set_remaining_time();

	string get_name();
	int get_arrival();
	int get_priority();

	int get_beginning();
	int get_finish();

	int get_end_time();
	int get_remaining_time();

};

bool isEarlier(Process a, Process b);
bool lessBurst(Process a, Process b);

bool is_arrived(Process x, int t);

bool lessPrior(Process a, Process b);
bool lessCpuBurst(Process a, Process b);

#endif
