#include<iostream>
using namespace std;

class OBST{
    int n;
    string key[10];
    float p[10], q[11];
    float W[11][11], C[11][11];
    int R[11][11];

    public:
    void accept();
    void display();
    void calculate();
    void showTree(int i, int j, string parent, string direction);


    void OBST::accept(){
        cout<<"enter number of keys: ";
        cin>>n;
        cout<<"enter keys in sorted order: ";
        for(int i=0; i<n; i++){
            cin>>key[i];
        }
        cout<<"enter keys in sorted order: ";
        for(int i=0; i<n; i++){
            cin>>p[i];
        }
        cout<<"enter keys in sorted order: ";
        for(int i=0; i<=n; i++){
            cin>>q[i];
        }

        void OBST::calculate(){
            for(int i=0;i<n;i++){
                W[i][i]=q[i];
                C[i][i]=0;
                R[i][i]=0;
            }
                for(int gap=1; gap<=n; gap++){
                    for(int i=0; i<=n- gap; i++){
                        int j=i+gap;
                        W[i][j]=W[i][j-1]+p[j-1]+q[j];
                        float min= 9999;
                        int root=0;

                        for(int k=0; k<=n; k++){
                            float cost = C[i][k-1]+C[k][j];
                            if(cost<min){
                                cost=min;
                                root=k;
                            }
                        }
                        C[i][j]=Q[i][j]+min;
                        R[i][j]=root;
                    }
                }
            }

    void OBST::display(){
        cout<<"weight matrix: ";
        for(int gap=1; gap<=n; gap++){
            for(int i=0; i<=n- gap; i++){
                int j=i+gap;
                cout<<W[i][j]<<" ";
            }
            cout<<endl;
    }

    cout<<"cost matrix: ";
        for(int gap=1; gap<=n; gap++){
            for(int i=0; i<=n- gap; i++){
                int j=i+gap;
                cout<<C[i][j]<<" ";
            }
            cout<<endl;
    }

    cout<<"root matrix: ";
        for(int gap=1; gap<=n; gap++){
            for(int i=0; i<=n- gap; i++){
                int j=i+gap;
                cout<<R[i][j]<<" ";
            }
            cout<<endl;
    }

    cout<<"minimum cost: "<<C[0][n]<<endl;
    cout<<"optimal binary search tree structure"<<endl;
    showTree(0, n, "root", "left");

    void OBST::showTree(int i, int j, string parent, string direction){
        int rootIndex= R[i][j];
        if(rootIndex == 0 || rootIndex == -1)
        return;

    string currKey = key[rootIndex -1];
    cout<<currKey<<"is the" <<direction<<"of"<<parent<<endl;

    showTree(i, rootIndex - 1, currKey, "Left")
    }



};

int main(){
    OBST t;
    t.accept();
    t.calculate();
    t.display();
    return 0;

}