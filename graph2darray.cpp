#include <iostream>
using namespace std;

class graph {
    public:
    int v, e;
    int a[10][10];

    graph() {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                a[i][j] = 0;
            }
        }
    }

    void edge() {                                                           
        int x, y;
        cout << "enter number of vertices: ";
        cin >> v;
        cout << "enter number of edges: ";
        cin >> e;
        
        for(int i = 0; i <e; i++) {
            cout << "enter edge " << i + 1 << ": " << endl;
            cout<<"enter source: ";
            cin >> x;
            cout<< "enter destination: ";
            cin >> y;
            a[x][y] = 1;
            a[y][x] = 1;
        }
    }

    void display() {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    graph g;
    g.edge();
    g.display();
    return 0;
}