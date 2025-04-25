#include <iostream>
using namespace std;

class Hashtable {
public:
    string name, id, history, treatment;

    Hashtable() {
        name = "empty";
        id = "empty";
        history = "empty";
        treatment = "empty";
    }
};

// Insert a record into the hash table
void insert(Hashtable h[], string name, string id, string history, string treatment, int status[], int n) {
    int val = 0;
    for (char c : id) val += (int)c;
    val %= n;

    int i = 0, k = 0;
    while (status[val] == 0) { // Handle collisions using quadratic probing
        k++;
        val = (val + k * k) % n;
        if (k == n) {
            cout << "Hashtable is full!" << endl;
            return;
        }
    }

    h[val].name = name;
    h[val].id = id;
    h[val].history = history;
    h[val].treatment = treatment;
    status[val] = 0;
    cout << "Inserted at index: " << val << endl;
}

// Search for a record by ID
void search(Hashtable h[], int status[], int n, string id) {
    int val = 0;
    for (char c : id) val += (int)c;
    val %= n;

    int k = 0;
    while (status[val] != -1) {
        if (status[val] == 0 && h[val].id == id) {
            cout << "Record Found:\n";
            cout << "Name: " << h[val].name << ", ID: " << h[val].id << ", History: " << h[val].history << ", Treatment: " << h[val].treatment << endl;
            return;
        }
        k++;
        val = (val + k * k) % n;
        if (k == n) break;
    }
    cout << "Record not found!" << endl;
}

// Update a record by ID
void update(Hashtable h[], int status[], int n, string id) {
    int val = 0;
    for (char c : id) val += (int)c;
    val %= n;

    int k = 0;
    while (status[val] != -1) {
        if (status[val] == 0 && h[val].id == id) {
            cout << "Enter new details:\n";
            cout << "Name: "; cin >> h[val].name;
            cout << "History: "; cin >> h[val].history;
            cout << "Treatment: "; cin >> h[val].treatment;
            cout << "Record updated!" << endl;
            return;
        }
        k++;
        val = (val + k * k) % n;
        if (k == n) break;
    }
    cout << "Record not found!" << endl;
}

// Delete a record by ID
void deleteRecord(Hashtable h[], int status[], int n, string id) {
    int val = 0;
    for (char c : id) val += (int)c;
    val %= n;

    int k = 0;
    while (status[val] != -1) {
        if (status[val] == 0 && h[val].id == id) {
            status[val] = -2; // Mark as deleted
            cout << "Record deleted!" << endl;
            return;
        }
        k++;
        val = (val + k * k) % n;
        if (k == n) break;
    }
    cout << "Record not found!" << endl;
}

// Display all records
void display(Hashtable h[], int status[], int n) {
    for (int i = 0; i < n; i++) {
        if (status[i] == 0) {
            cout << "Index " << i << ": Name: " << h[i].name << ", ID: " << h[i].id
                 << ", History: " << h[i].history << ", Treatment: " << h[i].treatment << endl;
        }
    }
}

// Display records by history
void displayByHistory(Hashtable h[], int status[], int n, string history) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (status[i] == 0 && h[i].history == history) {
            cout << "Index " << i << ": Name: " << h[i].name << ", ID: " << h[i].id
                 << ", History: " << h[i].history << ", Treatment: " << h[i].treatment << endl;
            found = true;
        }
    }
    if (!found) cout << "No records found with history: " << history << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter the size of the hash table: ";
    cin >> n;

    Hashtable* h = new Hashtable[n];
    int* status = new int[n];
    for (int i = 0; i < n; i++) status[i] = -1; // Initialize all slots as empty

    int choice;
    string name, id, history, treatement;

    do {
        cout << "\n1. Insert\n2. Search\n3. Update\n4. Delete\n5. Display\n6. History of client\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name, ID, History, Treatment: ";
                cin >> name >> id >> history >> treatment;
                insert(h, name, id, history, treatment, status, n);
                break;
            case 2:
                cout << "Enter ID to search: ";
                cin >> id;
                search(h, status, n, id);
                break;
            case 3:
                cout << "Enter ID to update: ";
                cin >> id;
                update(h, status, n, id);
                break;
            case 4:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteRecord(h, status, n, id);
                break;
            case 5:
                display(h, status, n);
                break;
            case 6:
                cout << "Enter History to display: ";
                cin >> history;
                displayByHistory(h, status, n, history);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    delete[] h;
    delete[] status;
    return 0;
}