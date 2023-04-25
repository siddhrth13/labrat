#include<iostream>
using namespace std;


int main(){
    int proc;
    int processId[20];
    int burstTime[20];

    cout<<"Enter the number of processes: ";
    cin>>proc;

    for(int i=0;i<proc;i++){
        cout<<"Enter process id: ";
        cin>>processId[i];
        cout<<"Enter burst time: ";
        cin>>burstTime[i];
    }

    //sorting the processes on the basis of burst times (using bubblesort)//

    for(int i=0;i<proc;i++){
        for(int j=0;j<proc-i-1;j++){
            int temp1;
            int temp2;
            if(burstTime[j]>burstTime[j+1]){
                //sorting on the basis of burst time//
                temp1=burstTime[j];
                burstTime[j]=burstTime[j+1];
                burstTime[j+1]=temp1;

                /*Since the process have been sorted their process id also need to be sorted respectively*/

                temp2=processId[j];
                processId[j]=processId[j+1];
                processId[j+1]=temp2;

            }
        }
    }

    int waitTime[20];
    int turnaroundTime[20];

    for(int i=0;i<proc;i++){
        waitTime[i]=0;
        turnaroundTime[i]=0;
        for(int j=0;j<i;j++){
            waitTime[i]=waitTime[i]+burstTime[j];
            //adding the previous process's bursttime to the wait time of the next process//
        }

        turnaroundTime[i]=waitTime[i]+burstTime[i];
        //turnaround time=wait time+ burstTime//
    }

    //calculating totalwait time and total turnaround time//
    int totalwaitTime;
    int totalturnarounTime;

    for(int i=0;i<proc;i++){
        totalwaitTime=totalwaitTime+waitTime[i];
        totalturnarounTime=totalturnarounTime+turnaroundTime[i];
    }

    float a1;
    float a2;

    a1=totalwaitTime/proc;
    a2=totalturnarounTime/proc;

    cout<<"Average wait time: "<<a1;
    cout<<"Average turnaround time: "<<a2;
    

    return 0;


}