#include <list>
#include "Process.h"
#include "S_Algorithms.h"
#include <algorithm>

list<Process>sjf_non_preemptive(list<Process> input)
{
	/*
	Shortest Job First (non-preemptive algorithm)
	----------------------------------------------
	- sort by arrival
	- push 1st process in temp list ... pop 1st process from input
	- time = burst of 1 process
	- sort by burst (CPU time)

	- while input isn't empty

		 -loop through the input (sorted by cpu time)
				if (process is arrived)
				push back it to temp
	  			erase it from input
				update time = time + burst of process
	
	UPDATE FOR HANDLING GAPS
		 - get the min arrival time of the remaining processes
		 - if time < min_arrival_time ===> this is a gap coming
		 - so update time to be equal to that min_arrival time


	- return temp
	*/

	int time = 0;
	list<Process> temp;
	list<Process>::iterator it;

	input.sort(lessBurst);

	while (!input.empty())
	{
		for (it = input.begin(); it != input.end(); it++)
		{

			if (is_arrived(*it, time))
			{
				Process next = *it;
				input.erase(it);

				next.set_beginning(time);
				next.set_finish(time + next.get_burst());
				
				temp.push_back(next);
				time += next.get_burst();
				break;
			}
		}

		list<Process>::iterator first_new;
		first_new = min_element(input.begin(), input.end(), isEarlier); // if input is empty -- it returns input.end()
		if (first_new != input.end()) // if there's at least one element remaining in input
		{
			if (time < first_new->get_arrival()) // check for potential gap
			{
				time = first_new->get_arrival(); // jump over the gap
			}
		}
	}

	return temp;
}

list<Process> sjf_preemptive(list<Process> input)
{
	int time = 0;
	list<Process>temp;

	return temp;
}

list<Process> round_robin(list<Process> input, int quantum)
{
	// input is sorted by arrival time 
	// sort(input.begin(), input.end(), isEarlier);
	int time = input.front().get_arrival();

	list<Process> output ,request_queue;
	list<Process>::iterator it, it2;
	
	bool remaining = false;
	Process remaining_proc("NULL",0,0);

	while (!(input.empty() && request_queue.empty()) )
	{
		
		// from the input to the request queue
		while (!input.empty())
		{
			it = input.begin();
			if (is_arrived(*it, time))
			{
				request_queue.push_back(*it);
				input.pop_front();
			}
			else
			{
				break;
			}

		}



		// remaining process to the request queue
		if (remaining)
		{
			request_queue.push_back(remaining_proc);
			remaining = false;
		}


		
		//--- from request queue to the output 
		for (it2 = request_queue.begin();it2 != request_queue.end();it2++)
		{
			if (it2->get_burst() <= quantum)
			{
				it2->set_beginning(time);
				it2->set_finish(time + it2->get_burst());
				output.push_back(*it2);
				request_queue.pop_front();
				break;
			}
			else
			{
				it2->set_beginning(time);
				it2->set_finish(time + quantum);
				output.push_back(*it2);
				

				Process temp(it2->get_name(), time + quantum, it2->get_burst() - quantum );
				remaining_proc = temp;
				remaining = true;
				request_queue.pop_front();
				break;
			}

		}


		time += quantum;
	}



	return output;
}


