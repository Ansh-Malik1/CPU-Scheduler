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
void findCompletionTime(Process proc[],int n){
    proc[0].completion_time = proc[0].burst_time;
    int a=1;
    while(a<n){
        cout<<"id: "<< proc[a].process_id<<endl;
        proc[a].completion_time = proc[a-1].completion_time+proc[a].burst_time;
        a++;
    }
}

void findTurnAroundTime(Process proc[],int n){
    int i = 0;
    while(i<n){
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
        i++;
    }
}

void findWaitingTime(Process proc[],int n){
    int i = 0;
    while(i<n){
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
        i++;
    }
}

void fcfsAlgorithm(Process proc[],int n){
    findCompletionTime(proc,n);
    findTurnAroundTime(proc,n);
    findWaitingTime(proc,n);
}
int main(){
    int n = 5;
    Process p[n]={{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
    fcfsAlgorithm(p,n);
    cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t\t"<<"Turn Around Time"<<"\t"<<"Waiting Time"<<endl;
    for (int i = 0 ; i<n ; i++){
        cout<<p[i].process_id<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t\t"<<p[i].turn_around_time<<"\t\t\t"<<p[i].waiting_time<<endl;
    }
}