#ifndef PROJECT_ALGORITHM_INCLUDED
#define PROJECT_ALGORITHM_INCLUDED

#include <iostream>
#include <list>
#include <string>
#include "Process.h"
#include "Priority_Preemptive.cpp"
#include "Priority_Non_Preemptive.cpp"
#include "First_Come_First_Served.cpp"
#include "Shortest_Job_First_Preemptive.cpp"
#include "Shortest_Job_First_Non_Preemptive.cpp"



using namespace std;


void Priority_Preemptive(list<Process>buffer,list<Process>&executing);

void Priority_Non_Preemptive(list<Process>buffer,list<Process>&executing);

void First_Come_First_Served(list<Process>buffer,list<Process>&executing);

void Shortest_Job_First_Preemptive(list<Process>buffer,list<Process>&executing);


void Shortest_Job_First_Non_Preemptive(list<Process>buffer,list<Process>&executing);










#endif // PROJECT_ALGORITHM_INCLUDED
