#include<iostream>
using namespace std;
int knapsack(vector<int> &weights,vector<int> &values,int n,int W){
    vector<vector<int> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(weights[i-1]<=w){
                dp[i][w]=max(dp[i-1][w],values[i-1]+dp[i-1][w-weights[i-1]]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
}
int main(){
    intn,W;
    cin>>n>>W;
    vector<int>weights(n),values(n);
    for(int i=0;i<n;i++){
        cin>>weights[i]>>values[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<W;j++){
            if(weights[i]<=j){
                cout<<values[i]+dp[i-1][j-weights[i]]<<"";
            }
        }
    }
    cout<<knapsack(weights,values,n,W)<<endl;
    return 0;

}
            }
            }
        }
    }
}