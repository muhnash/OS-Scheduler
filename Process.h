#pragma once
#ifndef PROCESS_H_
#define PROCESS_H_

#include<string>
using namespace std;

class Process
{
private:
	int arrival_time = 0, priority = 0, cpu_burst, remaining_time;
	static int quantum;
	string p_name;

public:
	Process(string name, int time, int burst);

	void set_priority(int prior);
	void set_quantum(int quant);
	float get_burst();
	string get_name();
	int get_arrival();
	int get_priority();
	int get_quantum();
};

bool isEarlier(Process a, Process b);
bool lessBurst(Process a, Process b);



#endif 