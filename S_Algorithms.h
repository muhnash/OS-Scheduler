#pragma once
#ifndef S_ALGORITHMS_H_
#define S_ALGORITHMS_H_

#include"Process.h"
#include <list>

list<Process> sjf_non_preemptive(list<Process> input);

list<Process> sjf_preemptive(list<Process> input);

list<Process> round_robin(list<Process> input, int quantum);



void Priority_Preemptive(list<Process>buffer, list<Process>&executing);

void Priority_Non_Preemptive(list<Process>buffer, list<Process>&executing);

void First_Come_First_Served(list<Process>buffer, list<Process>&executing);

void Shortest_Job_First_Preemptive(list<Process>buffer, list<Process>&executing);


void Shortest_Job_First_Non_Preemptive(list<Process>buffer, list<Process>&executing);



#endif