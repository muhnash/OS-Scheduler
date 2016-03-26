#ifndef PROJECT_ALGORITHM_INCLUDED
#define PROJECT_ALGORITHM_INCLUDED

#include <iostream>
#include <list>
#include <string>
#include "Process.h"


using namespace std;


void Priority_Preemptive(list<Process>buffer,list<Process>executing)
{
    /***********************************************************************************/
    /*INPUT:list of processes SORTED according to time of Arrival(list<Process>buffer)*/
    /*OUTPUT:list of process executed in the processor(list<Process>executing)*/
    /***********************************************************************************/
    list<Process> waiting;
    list<Process>::iterator iBuffer;
    list<Process>::iterator iExecuting;
    int clock=0;
    iBuffer=buffer.begin();
    iExecuting=executing.begin();

    while(iBuffer!=buffer.end() || clock==0||!waiting.empty() ) //------>MAIN PROGRAM WHILE LOOP
    {
       /*Organizting the flow of the input data from the buffer list to the waiting list */
       /*This section is handling the following*/
       /*1) Entrance of the data with the respect to it's Arrival Time
         2) Handling the case of empty process "GAP" */

      /////////////////////////////////////////////////////////////////////////////////////////
        if(iBuffer!=buffer.end())
        {
            while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
            {
            waiting.push_back(*iBuffer);
            iBuffer++;
            }
            if(waiting.empty()&&iBuffer->get_arrival()>clock)
            {

              Process p1("GAP",clock,0);
              p1.set_priority(9999);
              executing.push_back(p1);
              iExecuting++;

            }

        }

        /*MAIN CORE OF THE ALGORITHM*/
        /////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(!waiting.empty())
        {
            waiting.sort(lessPrior);
            waiting.begin()->set_remaining_time();
            waiting.begin()->set_end_time(clock+1);
            if(clock==0)
            {
              executing.push_back(*waiting.begin());
              iExecuting++;
            }

           else if(waiting.begin()->get_name()!=iExecuting->get_name())
            {
            executing.push_back(*waiting.begin());
            iExecuting++;
            }
            else
            {
              *iExecuting=*waiting.begin();
            }

            if(waiting.begin()->get_remaining_time()==0)
                  waiting.erase(waiting.begin());
        }
        clock++;
    }

    /*Printing the output of the executing list*/
    //////////////////////////////////////////////////////////////////
     list<Process>::iterator j;
        cout<<"Name"<<"        "<<"Arrival"<<"        "<<"Priority"<<"        "<<"Remaining"<<"        "<<"End Time"<<endl;
        for(j=executing.begin();j!=executing.end();j++)
        {
        cout<<j->get_name()<<"            "<<j->get_arrival()<<"            "<<j->get_priority()<<"               "<<j->get_remaining_time()<<"               "<<j->get_end_time()<<endl;
        }
    /////////////////////////////////////////////////////////////////


}

void Priority_Non_Preemptive(list<Process>buffer,list<Process>executing)
{
/***********************************************************************************/
    /*INPUT:list of processes SORTED according to time of Arrival(list<Process>buffer)*/
    /*OUTPUT:list of process executed in the processor(list<Process>executing)*/
    /***********************************************************************************/
    list<Process> waiting;
    list<Process>::iterator iBuffer;
    list<Process>::iterator iExecuting;
    int clock=0;
    bool flag=false;
    Process temp("temp",0,0);
    iBuffer=buffer.begin();
    iExecuting=executing.begin();

    while(iBuffer!=buffer.end() || clock==0||!waiting.empty() ) //------>MAIN PROGRAM WHILE LOOP
    {
       /*Organizting the flow of the input data from the buffer list to the waiting list */
       /*This section is handling the following*/
       /*1) Entrance of the data with the respect to it's Arrival Time
         2) Handling the case of empty process "GAP" */

      /////////////////////////////////////////////////////////////////////////////////////////
        if(iBuffer!=buffer.end())
        {

            if(waiting.empty())
            {
            while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
            {
            waiting.push_back(*iBuffer);
            iBuffer++;
            waiting.sort(lessPrior);
            }
            }
            else
            {
                temp=*waiting.begin();
                waiting.erase(waiting.begin());
                 while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
                 {
                     waiting.push_back(*iBuffer);
                     iBuffer++;
                     waiting.sort(lessPrior);
                 }

                 waiting.push_front(temp);

            }


            if(waiting.empty()&&iBuffer->get_arrival()>clock)
            {

              flag=(true);
              Process p1("GAP",clock,0);
              p1.set_priority(9999);
              executing.push_back(p1);
              iExecuting++;

            }

        }

        /*MAIN CORE OF THE ALGORITHM*/
        /////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(!waiting.empty())
        {

            waiting.begin()->set_remaining_time();
            waiting.begin()->set_end_time(clock+1);
            if(clock==0)
            {
              executing.push_back(*waiting.begin());
              iExecuting++;
            }

           else if(waiting.begin()->get_name()!=iExecuting->get_name())
            {
            executing.push_back(*waiting.begin());
            iExecuting++;
            }
            else
            {
              *iExecuting=*waiting.begin();
            }

            if(waiting.begin()->get_remaining_time()==0)
            {
                  waiting.erase(waiting.begin());
                  //waiting.sort(lessPrior);
            }

        }
        clock++;
    }

    /*Printing the output of the executing list*/
    //////////////////////////////////////////////////////////////////
     list<Process>::iterator j;
        cout<<"Name"<<"        "<<"Arrival"<<"        "<<"Priority"<<"        "<<"Remaining"<<"        "<<"End Time"<<endl;
        for(j=executing.begin();j!=executing.end();j++)
        {
        cout<<j->get_name()<<"            "<<j->get_arrival()<<"            "<<j->get_priority()<<"               "<<j->get_remaining_time()<<"               "<<j->get_end_time()<<endl;
        }
    /////////////////////////////////////////////////////////////////

}

void First_Come_First_Served(list<Process>buffer,list<Process>executing)
{
   /***********************************************************************************/
    /*INPUT:list of processes SORTED according to time of Arrival(list<Process>buffer)*/
    /*OUTPUT:list of process executed in the processor(list<Process>executing)*/
    /***********************************************************************************/
    list<Process> waiting;
    list<Process>::iterator iBuffer;
    list<Process>::iterator iExecuting;
    int clock=0;
    bool flag=false;
    Process temp("temp",0,0);
    iBuffer=buffer.begin();
    iExecuting=executing.begin();

    while(iBuffer!=buffer.end() || clock==0||!waiting.empty() ) //------>MAIN PROGRAM WHILE LOOP
    {
       /*Organizting the flow of the input data from the buffer list to the waiting list */
       /*This section is handling the following*/
       /*1) Entrance of the data with the respect to it's Arrival Time
         2) Handling the case of empty process "GAP" */

      /////////////////////////////////////////////////////////////////////////////////////////
        if(iBuffer!=buffer.end())
        {

            if(waiting.empty())
            {
            while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
            {
            waiting.push_back(*iBuffer);
            iBuffer++;
            //waiting.sort(lessPrior);
            }
            }
            else
            {
                temp=*waiting.begin();
                waiting.erase(waiting.begin());
                 while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
                 {
                     waiting.push_back(*iBuffer);
                     iBuffer++;
                     //waiting.sort(lessPrior);
                 }

                 waiting.push_front(temp);

            }


            if(waiting.empty()&&iBuffer->get_arrival()>clock)
            {

              flag=(true);
              Process p1("GAP",clock,0);
              p1.set_priority(9999);
              executing.push_back(p1);
              iExecuting++;

            }

        }

        /*MAIN CORE OF THE ALGORITHM*/
        /////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(!waiting.empty())
        {

            waiting.begin()->set_remaining_time();
            waiting.begin()->set_end_time(clock+1);
            if(clock==0)
            {
              executing.push_back(*waiting.begin());
              iExecuting++;
            }

           else if(waiting.begin()->get_name()!=iExecuting->get_name())
            {
            executing.push_back(*waiting.begin());
            iExecuting++;
            }
            else
            {
              *iExecuting=*waiting.begin();
            }

            if(waiting.begin()->get_remaining_time()==0)
            {
                  waiting.erase(waiting.begin());
                  //waiting.sort(lessPrior);
            }

        }
        clock++;
    }

    /*Printing the output of the executing list*/
    //////////////////////////////////////////////////////////////////
     list<Process>::iterator j;
        cout<<"Name"<<"        "<<"Arrival"<<"        "<<"Priority"<<"        "<<"Remaining"<<"        "<<"End Time"<<endl;
        for(j=executing.begin();j!=executing.end();j++)
        {
        cout<<j->get_name()<<"            "<<j->get_arrival()<<"            "<<j->get_priority()<<"               "<<j->get_remaining_time()<<"               "<<j->get_end_time()<<endl;
        }
    /////////////////////////////////////////////////////////////////




}


void Shortest_Job_First_Preemptive(list<Process>buffer,list<Process>executing)
{

 /***********************************************************************************/
    /*INPUT:list of processes SORTED according to time of Arrival(list<Process>buffer)*/
    /*OUTPUT:list of process executed in the processor(list<Process>executing)*/
    /***********************************************************************************/
    list<Process> waiting;
    list<Process>::iterator iBuffer;
    list<Process>::iterator iExecuting;
    int clock=0;
    iBuffer=buffer.begin();
    iExecuting=executing.begin();

    while(iBuffer!=buffer.end() || clock==0||!waiting.empty() ) //------>MAIN PROGRAM WHILE LOOP
    {
       /*Organizting the flow of the input data from the buffer list to the waiting list */
       /*This section is handling the following*/
       /*1) Entrance of the data with the respect to it's Arrival Time
         2) Handling the case of empty process "GAP" */

      /////////////////////////////////////////////////////////////////////////////////////////
        if(iBuffer!=buffer.end())
        {
            while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
            {
            waiting.push_back(*iBuffer);
            iBuffer++;
            }
            if(waiting.empty()&&iBuffer->get_arrival()>clock)
            {

              Process p1("GAP",clock,0);
              p1.set_priority(9999);
              executing.push_back(p1);
              iExecuting++;

            }

        }

        /*MAIN CORE OF THE ALGORITHM*/
        /////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(!waiting.empty())
        {
            waiting.sort(lessCpuBurst);
            waiting.begin()->set_remaining_time();
            waiting.begin()->set_end_time(clock+1);
            if(clock==0)
            {
              executing.push_back(*waiting.begin());
              iExecuting++;
            }

           else if(waiting.begin()->get_name()!=iExecuting->get_name())
            {
            executing.push_back(*waiting.begin());
            iExecuting++;
            }
            else
            {
              *iExecuting=*waiting.begin();
            }

            if(waiting.begin()->get_remaining_time()==0)
                  waiting.erase(waiting.begin());
        }
        clock++;
    }

    /*Printing the output of the executing list*/
    //////////////////////////////////////////////////////////////////
     list<Process>::iterator j;
        cout<<"Name"<<"        "<<"Arrival"<<"        "<<"Priority"<<"        "<<"Remaining"<<"        "<<"End Time"<<endl;
        for(j=executing.begin();j!=executing.end();j++)
        {
        cout<<j->get_name()<<"            "<<j->get_arrival()<<"            "<<j->get_priority()<<"               "<<j->get_remaining_time()<<"               "<<j->get_end_time()<<endl;
        }
    /////////////////////////////////////////////////////////////////


}


void Shortest_Job_First_Non_Preemptive(list<Process>buffer,list<Process>executing)
{
  /***********************************************************************************/
    /*INPUT:list of processes SORTED according to time of Arrival(list<Process>buffer)*/
    /*OUTPUT:list of process executed in the processor(list<Process>executing)*/
    /***********************************************************************************/
    list<Process> waiting;
    list<Process>::iterator iBuffer;
    list<Process>::iterator iExecuting;
    int clock=0;
    bool flag=false;
    Process temp("temp",0,0);
    iBuffer=buffer.begin();
    iExecuting=executing.begin();

    while(iBuffer!=buffer.end() || clock==0||!waiting.empty() ) //------>MAIN PROGRAM WHILE LOOP
    {
       /*Organizting the flow of the input data from the buffer list to the waiting list */
       /*This section is handling the following*/
       /*1) Entrance of the data with the respect to it's Arrival Time
         2) Handling the case of empty process "GAP" */

      /////////////////////////////////////////////////////////////////////////////////////////
        if(iBuffer!=buffer.end())
        {

            if(waiting.empty())
            {
            while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
            {
            waiting.push_back(*iBuffer);
            iBuffer++;
            waiting.sort(lessCpuBurst);
            }
            }
            else
            {
                temp=*waiting.begin();
                waiting.erase(waiting.begin());
                 while(iBuffer->get_arrival()<=clock&&iBuffer!=buffer.end())
                 {
                     waiting.push_back(*iBuffer);
                     iBuffer++;
                     waiting.sort(lessCpuBurst);
                 }

                 waiting.push_front(temp);

            }


            if(waiting.empty()&&iBuffer->get_arrival()>clock)
            {

              flag=(true);
              Process p1("GAP",clock,0);
              p1.set_priority(9999);
              executing.push_back(p1);
              iExecuting++;

            }

        }

        /*MAIN CORE OF THE ALGORITHM*/
        /////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(!waiting.empty())
        {

            waiting.begin()->set_remaining_time();
            waiting.begin()->set_end_time(clock+1);
            if(clock==0)
            {
              executing.push_back(*waiting.begin());
              iExecuting++;
            }

           else if(waiting.begin()->get_name()!=iExecuting->get_name())
            {
            executing.push_back(*waiting.begin());
            iExecuting++;
            }
            else
            {
              *iExecuting=*waiting.begin();
            }

            if(waiting.begin()->get_remaining_time()==0)
            {
                  waiting.erase(waiting.begin());
                  //waiting.sort(lessPrior);
            }

        }
        clock++;
    }

    /*Printing the output of the executing list*/
    //////////////////////////////////////////////////////////////////
     list<Process>::iterator j;
        cout<<"Name"<<"        "<<"Arrival"<<"        "<<"Priority"<<"        "<<"Remaining"<<"        "<<"End Time"<<endl;
        for(j=executing.begin();j!=executing.end();j++)
        {
        cout<<j->get_name()<<"            "<<j->get_arrival()<<"            "<<j->get_priority()<<"               "<<j->get_remaining_time()<<"               "<<j->get_end_time()<<endl;
        }
    /////////////////////////////////////////////////////////////////


}










#endif // PROJECT_ALGORITHM_INCLUDED
