/*
assignment 4: You are a job seeker preparing for interviews at different locations. You have a list of cities where interviews are scheduled,
and you want to find the shortest path to visit all the interview locations starting from your current location.
The objective is to minimize the total travel distance and time while ensuring you reach each interview location on time.
Use appropriate data structures and algorithms to implement it.
*/
#include <iostream>
#include <string>
using namespace std;

class InterviewScheduler {
public:
    int numCities, numEdges;
    string cityNames[10];
    int adjMatrix[10][10];
    void input();
    void primAlgorithm();
    void displayMatrix();
};

InterviewScheduler scheduler;

void InterviewScheduler::input() {
    cout << "Enter Total Cities: ";
    cin >> numCities;
    for (int i = 0; i < numCities; i++) {
        cout << "Enter City Name: ";
        cin >> cityNames[i];
    }
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            adjMatrix[i][j] = (i == j) ? 0 : 999;
        }
    }
    cout << "Enter Total Edges: ";
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        string city1, city2;
        int weight;
        cout << "Enter Edge " << i + 1 << " (City1, City2, Weight): ";
        cin >> city1 >> city2 >> weight;
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < numCities; j++) {
            if (cityNames[j] == city1) idx1 = j;
            if (cityNames[j] == city2) idx2 = j;
        }
        if (idx1 != -1 && idx2 != -1) {
            adjMatrix[idx1][idx2] = weight;
            adjMatrix[idx2][idx1] = weight;
        } else {
            cout << "Invalid cities entered. Please try again." << endl;
            i--;
        }
    }
}

void InterviewScheduler::primAlgorithm() {
    bool visited[10] = {false};
    int parent[10];
    int weight[10];
    int mstWeight = 0;
    weight[0] = 0;
    parent[0] = -1;
    for (int i = 1; i < numCities; i++) {
        weight[i] = 999;
    }
    for (int count = 0; count < numCities - 1; count++) {
        int min = 999, u;
        for (int v = 0; v < numCities; v++) {
            if (!visited[v] && weight[v] < min) {
                min = weight[v];
                u = v;
            }
        }
        visited[u] = true;
        for (int v = 0; v < numCities; v++) {
            if (!visited[v] && adjMatrix[u][v] && adjMatrix[u][v] < weight[v]) {
                parent[v] = u;
                weight[v] = adjMatrix[u][v];
            }
        }
    }
    cout << "\nEdge \tWeight\n";
    for (int i = 1; i < numCities; i++) {
        cout << cityNames[parent[i]] << " -> " << cityNames[i] << " \t" << adjMatrix[i][parent[i]] << "\n";
        mstWeight += adjMatrix[i][parent[i]];
    }
    cout << "Total Distance of MST: " << mstWeight << endl;
}

void InterviewScheduler::displayMatrix() {
    cout << "\nAdjacency Matrix (Distances between Cities):\n";
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    scheduler.input();
    scheduler.displayMatrix();
    scheduler.primAlgorithm();
    return 0;
}
