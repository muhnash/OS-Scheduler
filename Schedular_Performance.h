#ifndef SCHEDULAR_PERFORMANCE_INCLUDED
#define SCHEDULAR_PERFORMANCE_INCLUDED

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




#endif
