#include <iostream>
#include <list>
#include <string>
#include "Process.h"
#include "Project_Algorithm.h"


using namespace std;
list<Process>buffer;
list<Process>executing;

void Fetching_Data(int n)
{
  for(int i=0;i<n;i++)
     {   string name;
     cout<<"Enter the process name:";
     cin>>name;
     cout<<endl;
         int arrival_time;
    cout<<"Enter the arrival_time:";
    cin>>arrival_time;
    cout<<endl;
         int burst;
    cout<<"Enter the Process_Burst:";
    cin>>burst;
    cout<<endl;
         int priority;
     cout<<"Enter the priority:";
     cin>>priority;
     cout<<endl;
         Process p1(name,arrival_time,burst);
         p1.set_priority(priority);

       buffer.push_back(p1);
     }

}


void Print_Process_List(list<Process> executing)
{
    list<Process>::iterator j;
    cout<<"Name"<<"        "<<"Arrival"<<"        "<<"Priority"<<"        "<<"Remaining"<<endl;
    for(j=executing.begin();j!=executing.end();j++)
    {
    cout<<j->get_name()<<"            "<<j->get_arrival()<<"            "<<j->get_priority()<<"               "<<j->get_remaining_time()<<endl;
    }
}

int main()
{



Fetching_Data(1);
Priority_Preemptive(buffer,executing);
Print_Process_List(executing);






    return 0;
}
