#ifndef SCHEDULAR_PERFORMANCE_INCLUDED
#define SCHEDULAR_PERFORMANCE_INCLUDED
#include <list>
#include <string>
#include <iomanip>
#include"Process.h"


using namespace std;
bool Check_Repeat(string Process_Name,list<string> Stopped_Process);
float Turn_Around_Time(list<Process> executing);
float calc_waiting(list<Process> x);
void gantt(list<Process> x);


#endif
