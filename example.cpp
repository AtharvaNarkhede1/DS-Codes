#include<iostream>
#include<string>
using namespace std;

class MAP{

    public:
    int totalcities;
    int totaledges;
    string cities[10];
    int distance[10][10];
    void insert();
    void prims();
    void display();

};

void MAP::insert(){
    cout<<"enter total cities: ";
    cin>>totalcities;
    for(int i+0; i<totalcities;i++){
        cout<<"enter city name: ";
        cin>>cities[i];
    }

    //for distance matric to a large value (infinity)
    for(int i=0; i<totalcities; i++){
        for(int j=0; j<totalcities; j++){
            distance[i][j] =  (i==j) ? 0 :999;
        }
    }
    //accept the total edges to store

    cout<<"enter total edges: ";
    cin>>totaledges;
    for(int i= 0; i<totaledges; i++){
        string city1,city2;
        int weight;
        cout<<"enter edge "<<i+1<<"(city1,city2,weight): ";
        cin>>city1>>city2>weight;

        //find indexes for the cities
        int index1 = -1, index2 = -1;
        for(int j=0;j<totalcities;j++){
            if(cities[j] == city1) index1 = j;
            if(cities[j] == city2) index2 = j;
        }

        if(index1 != -1 && index2 != -1){
            distance[index1][index2] = weight;
            distance[index2][index1] = weight;
        }else{
            cout<<"invalid cities entered.";
            i--;
        }
    }
}

void MAP::prims(){
    bool visited[10] = {false}; // start as nothing is visited
    int parent[10];
    int weight[10];
    int min, u;
    int mstvalue =0;

    for(int i=0; i<totalcities; i++){
        weight[i]=999;
        parent[i] =-1;

    }

    weight[0] =0;
    
}