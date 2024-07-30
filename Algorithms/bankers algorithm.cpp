#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int r = 3;
    int alloc[n][r] = {{0,0,1},   // Allocation Matrix
                      {3,0,0},
                      {1,0,1},
                      {2,3,2},
                      {0,0,3}
    };

    int max[n][r]= {{7,6,3},   // Max Need matrix
                      {3,2,2},
                      {8,0,2},
                      {2,1,2},
                      {5,2,3}
    };

    int available[r]={2,3,2};
    int need[n][r];
    for (int i = 0 ; i<n ; i++){
        for(int j=0 ; j<r ; j++){
            need[i][j] = max[i][j]-alloc[i][j];
        }
    }

    int f[n],ans[n],index=0;

    for(int k = 0 ; k < n ; k++){
        f[k] = 0;

    }

    for(int i = 0 ; i < n ; i++){
        for(int i=0 ; i<n ; i++){
            if(f[i]==0){
                int flag = 0;
                for(int j=0 ; j<r ; j++){
                    if(need[i][j]>available[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    ans[index++]=i;
                    for(int j=0 ; j<r ; j++){
                        available[j]+=alloc[i][j];
                    }
                    f[i]=1;
                }
            }
        }
    }

    cout<<"Safe Sequence is : "<<endl;
    for(int i = 0 ; i < n-1 ; i++){
        cout<<"P"<<ans[i]<<"->";
    }
    cout<<"P"<<ans[n-1];
    return 0;
}