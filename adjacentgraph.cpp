#include <iostream>
#include <vector>
using namespace std;

class graph {
    public:
    int v, e;
    int a[10][10];
    vector<pair<int, int>> adjList[10]; // Adjacency List

    graph() {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                a[i][j] = 0;
            }
        }
    }

    void edge() {
        int x, y, weight;
        cout << "Enter number of vertices: ";
        cin >> v;
        cout << "Enter number of edges: ";
        cin >> e;
        
        for(int i = 0; i < e; i++) {
            cout << "Enter edge " << i + 1 << ": " << endl;
            cout << "Enter source: ";
            cin >> x;
            cout << "Enter destination: ";
            cin >> y;
            cout << "Enter distance: ";
            cin >> weight;
            
            a[x][y] = weight;
            a[y][x] = weight;
            
            adjList[x].push_back({y, weight});
            adjList[y].push_back({x, weight});
        }
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                cout << a[i][j] << "    ";
            }
            cout << endl;
        }
        
        cout << "\nAdjacency List:\n";
        for(int i = 0; i < v; i++) {
            cout << "Vertex " << i << " -> ";
            for(auto edge : adjList[i]) {
                cout << "( " << edge.first << ", " << edge.second << " ) ";
            }
            cout << endl;
        }
    }

    void displayDistance(int x, int y) {
        if (a[x][y] != 0) {
            cout << "Distance between city " << x << " and city " << y << " is: " << a[x][y] << endl;
        } else {
            cout << "No direct path between city " << x << " and city " << y << endl;
        }
    }

    void calculatecost(int x, int y) {
        if (a[x][y] != 0) {
            int cost = a[x][y] * 2;
            cout << "Travel cost between city " << x << " and city " << y << " is: " << cost << endl;
        } else {
            cout << "No direct path between city " << x << " and city " << y << endl;
        }
    }
};

int main() {
    graph g;
    g.edge();
    g.display();

    int choice;
    do{
        cout << "Enter Choice\n";
        cout << "\n 1. Find Distance\n 2. Calculate Travel Cost\n 3. Exit\n: ";
        cin >> choice;
        switch(choice){
            case 1:
                int city1, city2;
                cout << "Enter two cities to find the distance between them: ";
                cin >> city1 >> city2;
                g.displayDistance(city1, city2);
                break;
            
            case 2:
                int city3, city4;
                cout << "Enter two cities to calculate travel cost: ";
                cin >> city3 >> city4;
                g.calculatecost(city3, city4);
                break;
            
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}
