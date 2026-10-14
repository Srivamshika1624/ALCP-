#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int v,vector<vector<int>>&graph,vector<int>&color,int c,int n){
    for (int u=0;u<n;u++){
        if(graph[v][u]==1 && color[u]==c)return false;
    }
    return true;
}
bool colorGraph(int v,vector<vector<int>>&graph,vector<int>&color,
                      int m,int n){
    if(v==n)return true;                  
    for(int c=1;c<=m;c++){
        if(isSafe(v,graph,color,c,n)){
            color[v]=c;                
            if(colorGraph(v+1,graph,color,m,n))return true;
            color[v]=0;                  
        }
    }
    return false;                          
}
int main(){
    int n,m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    cout<<"Enter the "<<n<<"x"<<n<<" adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    cout<<"Enter number of colours m: ";
    cin>>m;
    vector<int>color(n,0);                
    if(colorGraph(0,graph,color,m,n)){
        cout<<"Colouring possible with "<<m<< " colours:\n";
        for(int i=0;i<n;i++)
            cout<<"Vertex " <<i<<" -> Colour " <<color[i]<<endl;
    }else{
        cout<<"Not possible with " << m << " colours." << endl;
    }
    return 0;
}