#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include <cstdio>
#include <iomanip>
#include"Process.h"
#include"S_Algorithms.h"
#include "Q_operations.h"

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	list <Process> runqueue;
	list <Process> ::iterator it;
	int process_num;

	//Getting input
	int choice;
	bool valid=true;
	cout << "-> Enter Number of Processes: " << endl;
	cin >> process_num;

	//TODO : handle invalid input values for process_num

	cout << endl;
	cout <<"-> Choose a scheduling algorithm from the following:"<< endl;
	cout <<"	1- First Come First Served (FCFS)" << endl;
	cout <<"	2- Shortest-Job-First (SJF) - Non-Preemptive" << endl;
	cout << "	3- Shortest-Job-First (SJF) - Preemptive" << endl;
	cout <<"	4- Priority - Non-Preemptive " << endl;
	cout << "	5- Priority - Preemptive" << endl;
	cout <<"	6- Round - Robin " << endl;
	cout <<"-> Enter your choice number: " ;
	cin >> choice;
	//TODO : handle invalid input values for choice

	cout << endl;

	int quant;
	for (int i = 0; i < process_num; i++)
	{
		cout << "======================{ "<<i+1<<" }======================" << endl;
		string temp_name;
		cout <<"Process name: ";
		cin >> temp_name;

		int temp_time;
		cout << "Arrival Time: ";
		cin >> temp_time;

		int temp_burst;
		cout << "CPU Burst: ";
		cin >> temp_burst;

		Process temp(temp_name, temp_time, temp_burst);
		if(choice==4 || choice ==5)
		{
			// Priority
			int temp_priority;
			cout <<"Priority: ";
			cin >> temp_priority;
			temp.set_priority(temp_priority);
		}
		else if (choice == 6 && i==process_num-1)
		{
			// Robin
			cout << "-------------" << endl;
			cout << "Quantum: ";
			cin >> quant;

		}
		runqueue.push_back(temp);
	}

	runqueue.sort(isEarlier);

	// NOW all processes are stored in the list named "runqueue"  , sorted by arrival time

	list<Process> output;


	switch (choice)
	{
		case 1 :
		{
			First_Come_First_Served(runqueue, output);
			break;
		}
		case 2 :
		{
			output = sjf_non_preemptive(runqueue);
			//Shortest_Job_First_Non_Preemptive(runqueue, output);
			break;
		}
		case 3 :
		{
			Shortest_Job_First_Preemptive(runqueue, output);
			break;
		}
		case 4:
		{
			Priority_Non_Preemptive(runqueue, output);
			break;
		}
		case 5:
		{
			Priority_Preemptive(runqueue, output);
			break;
		}
		case 6 :
		{
			output = round_robin(runqueue, quant);
			break;
		}

	default:
	    {
	        cout<< "INVALID CHOICE!"<<endl;
		break;
	    }
	}

	cout <<"==================={ OUTPUT }================="<<endl;

	cout << endl;
	cout << "Gantt chart :" << endl;
	gantt(output);
	cout << endl << "Average Waiting time = " <<calc_waiting(output)<< endl;
    cout << endl << "Turn Around time = "<<Turn_Around_Time(output)<<endl;
	cout << endl;
	system("pause");
	return 0;
}


