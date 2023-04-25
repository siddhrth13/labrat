#include<iostream>
using namespace std;

//FCFS without arrival time//

int main(){
    int proc;

    cout<<"Enter the number of processes: ";
    cin>>proc;

    int burstTime[20];
    int waitTime[20];
    int turnaroundTime[20];
    int processId[20];

    for(int i=0;i<proc;i++){
        cout<<"Enter processId: ";
        cin>>processId[i];
        cout<<"Enter burstTime: ";
        cin>>burstTime[i];
    }

    for(int i=0;i<proc;i++){
        waitTime[i]=0;
        turnaroundTime[i]=0;
        for(int j=0;j<i;j++){
            waitTime[i]=waitTime[i]+burstTime[j];
        }
        turnaroundTime[i]=waitTime[i]+burstTime[i];
    }

    int totalturnaroundTime;
    int totalwaitTime;

    for(int i=0;i<proc;i++){
        totalturnaroundTime=totalturnaroundTime+turnaroundTime[i];
        totalwaitTime=totalwaitTime+waitTime[i];
    }

    float a1;
    float a2;

    a1=totalturnaroundTime/proc;
    a2=totalwaitTime/proc;

    cout<<"Avg Turnaround Time: "<<a1<<endl;
    cout<<"Avg Wait Time: "<<a2<<endl;

    return 0;
}