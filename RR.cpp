#include<iostream>
using namespace std;

int findwaitTime(int processId[],int burstTime[],int waitTime[],int n,int qtm){
    int rem_bt[20];

    for(int i=1;i<=n;i++){
        rem_bt[i]=burstTime[i];
    }

    int elapsedTime=0;

    while(true){
        
        bool done=true;

        for(int i=1;i<=n;i++){
            
            if(rem_bt[i]>0){

                done=false;
                //indicates that the process is still not complete//

                if(rem_bt[i]>qtm){
                    /*if the burst time of the process is greater than the time quantum then also the process will only
                    the process will execute for the time quantum only*/
                    
                    rem_bt[i]=rem_bt[i]-qtm;
                    //subtracting timequantum from the remaining burst time//
                    
                    elapsedTime=elapsedTime+qtm;
                    //adding timequantumto the elapsed time//
                }

                else{

                    elapsedTime=elapsedTime+rem_bt[i];
                    /*if the remaining time is less than the time quantum then the process would execute completely and the remaining time
                    would be added to the elapsed time*/

                    waitTime[i]=elapsedTime-burstTime[i];

                    rem_bt[i]=0;
                    //since the process fully executes the remaining bursttime reduces to zero//
                }
            }

            
        }
        if(done==true){
                break;
            }
    }
}

void findturnaroundTime(int processId[],int burstTime[],int waitTime[],int turnaroundTime[],int n){

    for(int i=1;i<=n;i++){
        turnaroundTime[i]=burstTime[i]+waitTime[i];
    }
}

void findavgTime(int processId[],int burstTime[],int n,int qtm){
    int waitTime[20];
    int turnaroundTime[20];
    int totalwaitTime;
    int totalturnaroundTime;
    float a1;
    float a2;

    findwaitTime(processId,burstTime,waitTime,n,qtm);

    findturnaroundTime(processId,burstTime,waitTime,turnaroundTime,n);

    for(int i=1;i<=n;i++){
        totalwaitTime=totalwaitTime+waitTime[i];
        totalturnaroundTime=totalturnaroundTime+turnaroundTime[i];
        cout<<"PROCESS: "<<processId[i]<<" WT: "<<waitTime[i]<<" TT: "<<turnaroundTime[i]<<endl;
    }

    cout<<endl;
    
    a1=totalwaitTime/n;
    a2=totalturnaroundTime/n;
    cout<<"avg wt: "<<a1<<" "<<"avg bt: "<<a2;


}

int main(){
    int burstTime[20];
    int processId[20];
    int proc;
    int timeQtm;

    cout<<"Enter the number of processes: ";
    cin>>proc;

    for(int i=1;i<=proc;i++){
        cout<<"Enter processId: ";
        cin>>processId[i];
        cout<<"Enter bursttime: ";
        cin>>burstTime[i];
    }

    cout<<"Enter the time quantum: ";
    cin>>timeQtm;

    findavgTime(processId,burstTime,proc,timeQtm);

    return 0;


}