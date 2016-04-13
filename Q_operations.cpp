#include "Q_operations.h"
#include <iostream>
using namespace std;

bool Check_Repeat(string Process_Name,list<string> Stopped_Process)
 {
    list<string>:: iterator i;
    for(i=Stopped_Process.begin();i!=Stopped_Process.end();i++)
    {
       if(*i==Process_Name) return 1;

       return 0;
    }

 }


 float Turn_Around_Time(list<Process> executing)
{
 list<Process>::iterator i;
 list<string> Stopped_Process;
 float size=0;
 float sum=0;
 for(i=executing.begin();i!=executing.end();i++)
 {
       if(i->get_name()!="GAP")
       {
          if(i->get_remaining_time()==0 && !Check_Repeat(i->get_name(),Stopped_Process))
          {
          sum=sum+float((i->get_end_time()-i->get_arrival()));
          size++;
          }
          else
          {
              Stopped_Process.push_back(i->get_name());
              sum=float(sum+(i->get_end_time()-i->get_arrival()));
          }
       }
 }
 return sum/size;
}

float calc_waiting(list<Process> x)
{
	list<Process>::iterator i;
	float waiting_sum=0;
	int proc_num = x.size();
	for (i = x.begin(); i !=x.end(); i++)
	{
		waiting_sum += i->get_beginning() - i->get_arrival();
	}

	return waiting_sum / proc_num;
}


void gantt(list<Process> x)
{
	list<Process>::iterator it;

	int len = x.back().get_finish();
	//cout << setfill('-') << setw(1.5*len) << "-" << endl;
	cout << setfill(' ');
	for (it = x.begin();it != x.end();it++)
	{
		cout << setw(3) << "|" << setw(it->get_burst() + 2) << it->get_name() << setw(3) << " ";

	}

	cout << "|" << endl;
	for (it = x.begin();it != x.end();it++)
	{
		cout << setw(3) << it->get_beginning() << setw(it->get_burst() + 2) << "" << setw(3) << " ";

	}
	cout << x.back().get_finish() << endl;
	//cout << setfill('-') << setw(1.5*len) << "-" << endl;
	cout << setfill(' ');
}

