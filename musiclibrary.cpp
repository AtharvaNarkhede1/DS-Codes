#include <iostream>
using namespace std;

class MusicTrack {
public:
    string name;
    string id;
    string type;

    MusicTrack() {
        name = "empty";
        id = "empty";
        type = "empty";
    }
};

void insert(MusicTrack tracks[], string name, string id, string type, int status[], int n) {
    int val = 0;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;
    int i = 0, j = 1;

    if (status[val] == -1 || status[val] == -2) {
        tracks[val].name = name;
        tracks[val].id = id;
        tracks[val].type = type;
        status[val] = 0;
        cout << "Inserted at: " << val << endl;
    } else {
        while (i != 1) {
            cout << "Collision occurred at: " << val << endl;
            val = (val + 1) % n;
            j++;
            if (status[val] == -1 || status[val] == -2) {
                tracks[val].name = name;
                tracks[val].id = id;
                tracks[val].type = type;
                status[val] = 0;
                cout << "Inserted at: " << val << endl;
                i = 1;
            }
            if (j == n) {
                cout << "Hashtable is full!!!" << endl;
                i = 1;
            }
        }
    }
}

void display(MusicTrack tracks[], int status[], int n) {
    for (int i = 0; i < n; i++) {
        if (status[i] == 0) {
            cout << "Name: " << tracks[i].name << endl;
            cout << "ID: " << tracks[i].id << endl;
            cout << "Type: " << tracks[i].type << endl;
        }
    }
}

void update(MusicTrack tracks[], int status[], int n, string id) {
    int val = 0;
    int i = 0, j = 1;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;

    if (tracks[val].id == id && status[val] == 0) {
        string newName, newType, newId;
        cout << "Enter the new music ID: ";
        cin >> newId;
        cout << "Enter the new music name: ";
        cin >> newName;
        cout << "Enter the new music type: ";
        cin >> newType;
        tracks[val].name = newName;
        tracks[val].id = newId;
        tracks[val].type = newType;
        return;
    }

    while (i != 1) {
        val = (val + 1) % n;
        j++;
        if (tracks[val].id == id && status[val] == 0) {
            string newName, newType, newId;
            cout << "Enter the new music ID: ";
            cin >> newId;
            cout << "Enter the new music name: ";
            cin >> newName;
            cout << "Enter the new music type: ";
            cin >> newType;
            tracks[val].name = newName;
            tracks[val].id = newId;
            tracks[val].type = newType;
            i = 1;
        }
        if (j == n) {
            cout << "Track not found" << endl;
            i = 1;
        }
    }
}

void search(MusicTrack tracks[], int status[], int n, string id) {
    int val = 0;
    int i = 0, j = 1;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;

    if (tracks[val].id == id && status[val] == 0) {
        cout << "Name: " << tracks[val].name << endl;
        cout << "ID: " << tracks[val].id << endl;
        cout << "Type: " << tracks[val].type << endl;
        return;
    }

    while (i != 1) {
        val = (val + 1) % n;
        j++;
        if (tracks[val].id == id && status[val] == 0) {
            cout << "Name: " << tracks[val].name << endl;
            cout << "ID: " << tracks[val].id << endl;
            cout << "Type: " << tracks[val].type << endl;
            i = 1;
        }
        if (j == n) {
            cout << "Record not found!" << endl;
            i = 1;
        }
    }
}

void deleteRecord(MusicTrack tracks[], int status[], int n, string id) {
    int val = 0;
    int i = 0, j = 1;
    for (char c : id) {
        val += (int)c;
    }
    val = val % n;

    if (tracks[val].id == id && status[val] == 0) {
        status[val] = -2;
        cout << "Record deleted!" << endl;
        return;
    }

    while (i != 1) {
        val = (val + 1) % n;
        j++;
        if (tracks[val].id == id && status[val] == 0) {
            status[val] = -2;
            cout << "Record deleted!" << endl;
            i = 1;
        }
        if (j == n) {
            cout << "Track not found" << endl;
            i = 1;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of music tracks you want to insert (Hashtable size): ";
    cin >> n;

    MusicTrack tracks[n];
    int status[n];
    for (int i = 0; i < n; i++) {
        status[i] = -1;
    }

    int choice;
    string name, type, id, idToSearch;

    do {
        cout << "\n1. Insert\n2. Search\n3. Update\n4. Delete\n5. Display\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the music ID: ";
                cin >> id;
                cout << "Enter the music name: ";
                cin >> name;
                cout << "Enter the music type: ";
                cin >> type;
                insert(tracks, name, id, type, status, n);
                break;

            case 2:
                cout << "Enter the ID to search: ";
                cin >> idToSearch;
                search(tracks, status, n, idToSearch);
                break;

            case 3:
                cout << "Enter the ID to update: ";
                cin >> idToSearch;
                update(tracks, status, n, idToSearch);
                break;

            case 4:
                cout << "Enter the ID to delete: ";
                cin >> idToSearch;
                deleteRecord(tracks, status, n, idToSearch);
                break;

            case 5:
                display(tracks, status, n);
                break;

            case 6:
                cout << "Exiting!" << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}