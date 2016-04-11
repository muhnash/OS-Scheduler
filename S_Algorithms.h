#pragma once
#ifndef S_ALGORITHMS_H_
#define S_ALGORITHMS_H_

#include"Process.h"
#include <list>

list<Process> sjf_non_preemptive(list<Process> input);

list<Process> sjf_preemptive(list<Process> input);

list<Process> round_robin(list<Process> input, int quantum);

#endif