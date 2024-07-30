#include<iostream>
using namespace std;
struct Process{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
void printProcessDetails(Process p[],int n){
    cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t\t"<<"Turn Around Time"<<"\t"<<"Waiting Time"<<endl;
    for (int i = 0 ; i<n ; i++){
        cout<<p[i].process_id<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t\t"<<p[i].turn_around_time<<"\t\t\t"<<p[i].waiting_time<<endl;
    }
} 

void calculateTurnAroundTime(Process p[],int n){
    for (int i=0 ; i<n ; i++){
        p[i].turn_around_time = p[i].completion_time - p[i].turn_around_time;
    }
}

void calculateWaitingTime(Process p[],int n){
    for (int i=0 ; i<n ; i++){
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    }
}

void calculateTime(Process p[], int n, int q){
    int remaining_time[n];
    for (int i=0 ; i<n ; i++){
        remaining_time[i] = p[i].burst_time;
    }
    int current_time = 0;
    bool allProcessDone = false;
    while(!allProcessDone){
        allProcessDone = true;
        for(int i = 0 ; i<n ; i++){
            if(remaining_time[i]>0){
                allProcessDone = false;
                if(remaining_time[i]>q){
                    current_time = current_time+q;
                    remaining_time[i]-=q;
                }
                else{
                    current_time += remaining_time[i];
                    p[i].completion_time = current_time;
                    remaining_time[i]=0;
                }
            }
        }

    }
}

int main(){
    int n,quantum;
    n=4;
    Process p[n]={{1,0,4},{2,1,3},{3,2,5},{4,3,2}};
    quantum=2;
    calculateTime(p,n,quantum);
    calculateTurnAroundTime(p,n);
    calculateWaitingTime(p,n);
    printProcessDetails(p,n);
     
}