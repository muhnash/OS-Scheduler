#pragma once
#ifndef PROCESS_H_
#define PROCESS_H_

#include<string>
#include<list>
using namespace std;

class Process
{
private:
	int arrival_time = 0, priority = 0, cpu_burst, remaining_time;
	
	int beginning, finish;

	static int quantum;
	string p_name;

public:
	Process(string name, int time, int burst);

	void set_priority(int prior);
	void set_quantum(int quant);
	void set_beginning(int beg);
	void set_finish(int fin);

	int get_burst();
	string get_name();
	int get_arrival();
	int get_priority();
	int get_quantum();
	int get_beginning();
	int get_finish();
};

bool isEarlier(Process a, Process b);
bool lessBurst(Process a, Process b);
bool is_arrived(Process x, int t);

//list<Process>::iterator first_come(list<Process> x);

#endif 