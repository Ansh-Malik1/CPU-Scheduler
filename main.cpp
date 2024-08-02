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
void init(Process p[],int n){
    for(int i = 0; i < n; i++){
        int id,at,bt;
        cout << "Enter process id, arrival time and burst time for process "<< i+1 <<endl;
        cin>>id>>at>>bt;
        p[i].process_id=id;
        p[i].arrival_time=at;
        p[i].burst_time=bt;
    }
}
void fcfs(Process proc[],int n){  
    findCompletionTime(proc,n);
    findTurnAroundTime(proc,n);
    findWaitingTime(proc,n);
}
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

int calcProcess(){
    int n;
    cout << "Enter the number of processes: "<<endl;
    cin >> n;
    return n;
}

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

void roundRobin(Process proc[],int n,int q){
    int remaining_time[n];
    for (int i=0 ; i<n ; i++){
        remaining_time[i] = proc[i].burst_time;
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
                    proc[i].completion_time = current_time;
                    remaining_time[i]=0;
                }
            }
        }
    }
    findTurnAroundTime(proc,n);
    findWaitingTime(proc,n);
}


int main(){
    cout<<"Welcome to CPU Scheduller"<<endl;
    cout<<"--------------"<<endl;
    cout<<"Choose an alogrithm"<<endl;
    cout<<"--------------"<<endl;
    cout<<"Press 1 for First Come first serve"<<endl;
    cout<<"Press 2 for Shortest Job First"<<endl;
    cout<<"Press 3 for Round Robin"<<endl;
    cout<<"Press any other button to exit"<<endl;
    cout<<"--------------"<<endl;
    int choice=1;
    while(choice>0 & choice<5){
        cin>>choice;
        if(choice==1){
            int number_of_process=calcProcess();
            Process p[number_of_process];
            init(p , number_of_process);
            fcfs(p,number_of_process);
        }
        else if (choice==2){
            int number_of_process=calcProcess();
            Process p[number_of_process];
            init(p , number_of_process);
            sjfAlgorithm(p,number_of_process);
        }
        else if (choice==3){
            int number_of_process=calcProcess();
            Process p[number_of_process];
            init(p , number_of_process);
            cout<<"Enter Quantum:"<<endl;
            int quantum;
            cin>>quantum;
            roundRobin(p,number_of_process,quantum);
        } 
        else{
            cout<<"Exiting"<<endl;
            break;
        }    
    }
}