#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include"Process.h"

using namespace std;

int main()
{
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
	cout <<"	2- Shortest-Job-First (SJF)" << endl;
	cout <<"	3- Priority " << endl;
	cout <<"	4- Round - Robin " << endl;
	cout <<"-> Enter your choice number: " ;
	cin >> choice;
	//TODO : handle invalid input values for choice
	
	cout << endl;

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

		if(choice==3)
		{
			// Priority
			int temp_priority;
			cout <<"Priority: ";
			cin >> temp_priority;
			temp.set_priority(temp_priority);
			runqueue.push_back(temp);
			continue;
		}
		else if (choice == 4 && i==process_num-1)
		{
			// Robin
			int temp_quantum;
			cout << "-------------" << endl;
			cout << "Quantum: ";
			cin >> temp_quantum;
			temp.set_quantum(temp_quantum);
			runqueue.push_back(temp);
		}
		else
		{
			runqueue.push_back(temp);
		}
		
	}

	runqueue.sort(isEarlier);

	// NOW all processes are stored in the list named "runqueue"  , sorted by arrival time 
	

 // sjf non preemptive 
	list<Process> output;
	

	


	//printing all list elements 
	for (it = runqueue.begin(); it != runqueue.end(); it++)
	{
		cout << it->get_name()<<"   "<<it->get_arrival() << "   " <<it->get_burst() <<it->get_priority()<<"   "<<it->get_quantum()<< endl;
		
	}
	

	//system("pause");
	return 0;
}


