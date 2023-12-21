#include<iostream>
using namespace std;
int dp[100][100];
int trace[100][100];
int knapsack ( int val[],int w[],int item, int cap){

for(int i=0;i<1;i++){
    for(int j=0;j<item;j++){
        dp[i][j]=0;
        dp[j][0]=0;
    }
}

for(int i=1;i<item+1;i++){
    for(int j=1;j<cap+1;j++){

            if(w[i]<=j){
           int M=val[i]+dp[i-1][j-w[i]];
           int N=dp[i-1][j];
           if(M>N){
            dp[i][j]=M;
            trace[i][j]=1;
           }else{
           dp[i][j]=N;
           trace[i][j]=0;
            }
      }else{
          dp[i][j]=dp[i-1][j];
           trace[i][j]=0;
      }

    }
}
return dp[100][100];
}
int Trace(int trace[100][100], int val[], int w[], int item, int cap) {
    if (item == 0 || cap == 0){
        return 0;
    }
    if (trace[item][cap] == 1) {
        cout<<" traced index " <<item <<",";
        Trace(trace, w, val, item - 1, cap - w[item]);
    } else {
        Trace(trace, w, val, item - 1, cap);
    }
}

int main(){


int cap,item;
cout<<"enter capacity and item number ";
cin>>cap>>item;
int val[item+1],w[item+1];
for(int i=1;i<item+1;i++){
    cout<<"enter item weight ";
    cin>>w[i];
}for(int i=1;i<item+1;i++){
    cout<<"enter item value ";
    cin>>val[i];
}


knapsack(val,w,item,cap);

        cout<<" Maximum "<<dp[item][cap];
        cout<<endl;

Trace(trace,val,w,item,cap);




}



