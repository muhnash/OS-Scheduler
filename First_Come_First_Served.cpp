#include <iostream>
#include <list>
#include <string>
#include "Process.h"
#include "Project_Algorithm.h"





void First_Come_First_Served(list<Process>buffer,list<Process>&executing)
{
   /***********************************************************************************/
    /*INPUT:list of processes SORTED according to time of Arrival(list<Process>buffer)*/
    /*OUTPUT:list of process executed in the processor(list<Process>executing)*/
    /***********************************************************************************/
    list<Process> waiting;
    list<Process>::iterator iBuffer;
    list<Process>::iterator iExecuting;
    int clock=0;
    Process p1("GAP",clock,0);
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
               if(clock==0||waiting.begin()->get_name()!=iExecuting->get_name())
              {
                p1.set_beginning(clock);
                p1.set_priority(0);
                p1.set_end_time(clock+1);
                executing.push_back(p1);
                iExecuting++;
               }

             else

             {

                 waiting.begin()->set_end_time(clock+1);
                *iExecuting=*waiting.begin();
             }
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
              waiting.begin()->set_beginning(clock);
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
    /*
     list<Process>::iterator j;
        cout<<"Name"<<"        "<<"Arrival"<<"        "<<"Priority"<<"        "<<"Remaining"<<"        "<<"End Time"<<endl;
        for(j=executing.begin();j!=executing.end();j++)
        {
        cout<<j->get_name()<<"            "<<j->get_arrival()<<"            "<<j->get_priority()<<"               "<<j->get_remaining_time()<<"               "<<j->get_end_time()<<endl;
        }
    /////////////////////////////////////////////////////////////////
    */



}
