#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class dij{
    
    public:
        int n;
        vector<int> nodes;
        vector<vector<int>> adj;

        void inp(){
            cout<<"Enter the number of vertices: ";
            cin>>n;
            adj.resize(n, vector<int>(n, 0));
            
            cout<<"Enter nodes: ";
            for(int i=0; i<n; i++){
                int x;

                cin>>x;
                nodes.push_back(x);
            }

            for(int i=0; i<n;i++){

                for(int j=i; j<n; j++){
                    if(i==j){
                        adj[i][j]=0;
                    }
                    else{
                        cout<<"Enter the weight of edge from "<<nodes[i]<<" to "<<nodes[j]<<" : ";
                        int x;
                        cin>>x;
                        adj[i][j]=x;
                        adj[j][i]=x;
                    }
                }
            }
        }

        int finmin(vector<bool> visited, vector<int> src){
            int res = -1, min = INT_MAX, ind = -1;

            for(int i=0;i<n;i++){

                if(!visited[i] && src[i]<min){
                    ind = i;
                    min = src[i];
                }
            }
            return ind;
        }

        void dijkstra(int start){

            //failsafes
            if (n == 0) {
                cout << "Graph not created yet.\n";
                return;
            }

            //algo
            vector<int> dist(n, INT_MAX);
            // vector<int> src = adj[start];
            vector<bool> visited(n, false);

            dist[start] = 0;
            int count = 0;//to count number of visited nodes

            while(count<n){
                
                //find minimum unvisited node from start
                int u = finmin(visited,adj[start]);
                if(u == -1){
                    break;
                }
                
                //mark u as visited now
                visited[u]=true;
                for(int i=0;i<n;i++){

                    if(!visited[i] && adj[u][i] &&
                        dist[u] != INT_MAX &&
                        dist[u] + adj[u][i] < dist[i])
                    {
                        dist[i] = dist[u] + adj[u][i];
                    }
                }
                count++;
            }

            cout<<"Distance From "<<nodes[start];
            for(int i=0;i<n;i++){

                cout<<"\nTo "<<nodes[i]<<"is "<<dist[i];
            }
        }
};


int main(){
    
    dij g;
    g.inp();
    int start;
    cout<<"Enter the starting node: ";
    cin>>start;
    g.dijkstra(start);
    
    return 0;
}