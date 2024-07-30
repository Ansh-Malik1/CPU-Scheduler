#include <iostream>
using namespace std;
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

void sjfAlgorithm(Process proc[],int n){
    int remaining_time[n];
    for (int i=0 ; i<n ; i++){
        remaining_time[i] = proc[i].burst_time;
    }
    int current_time = 0;
    int completed_processes = 0;
    int shortest_job = 0;
    int min_burst = 9999;

    while(completed_processes<n){
        min_burst = 9999;
        for(int i = 0 ; i<n ; i++){
            if(proc[i].arrival_time<=current_time && remaining_time[i]<min_burst && remaining_time[i]>0){
                min_burst = remaining_time[i];
                shortest_job=i;
            }
        }
        remaining_time[shortest_job]--;
        if(remaining_time[shortest_job]==0){
            completed_processes++;
            proc[shortest_job].completion_time=current_time+1;
            proc[shortest_job].turn_around_time = proc[shortest_job].completion_time-proc[shortest_job].arrival_time;
            proc[shortest_job].waiting_time = proc[shortest_job].turn_around_time - proc[shortest_job].burst_time;
        }
        current_time++;
    }
}

void printProcessDetails(Process p[],int n){
    cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t\t"<<"Turn Around Time"<<"\t"<<"Waiting Time"<<endl;
    for (int i = 0 ; i<n ; i++){
        cout<<p[i].process_id<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t\t"<<p[i].turn_around_time<<"\t\t\t"<<p[i].waiting_time<<endl;
    }
}

int main(){
    int n=5;
    Process p[n] = {{1,0,5},{2,2,3},{3,1,8},{4,4,2},{5,3,4}};
    sjfAlgorithm(p,n);
    printProcessDetails(p,n);
    return 0;
}

