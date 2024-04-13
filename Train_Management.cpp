#include <iostream>
#include <string>

using namespace std;

// Structure for a train node
struct TrainNode {
    int trainNumber;
    string trainName;
    string departureTime;
    string destination;
    TrainNode* next;

    // Constructor to initialize node
    TrainNode(int number, const string& name, const string& time, const string& dest)
        : trainNumber(number), trainName(name), departureTime(time), destination(dest), next(nullptr) {}
};

// Train Management System Class
class TrainManagementSystem {
private:
    TrainNode* head; // Head of the linked list

public:
    // Constructor
    TrainManagementSystem() : head(nullptr) {}

    // Destructor
    ~TrainManagementSystem() {
        TrainNode* current = head;
        while (current != nullptr) {
            TrainNode* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Function to add a new train
    void addTrain(int number, const string& name, const string& time, const string& dest) {
        TrainNode* newNode = new TrainNode(number, name, time, dest);
        if (head == nullptr) {
            head = newNode;
        } else {
            TrainNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Train added successfully." << endl;
    }

    // Function to display all trains
    void displayTrains() {
        if (head == nullptr) {
            cout << "No trains available." << endl;
            return;
        }
        TrainNode* current = head;
        cout << "Train Number\tTrain Name\tDeparture Time\tDestination" << endl;
        while (current != nullptr) {
            cout << current->trainNumber << "\t\t" << current->trainName << "\t\t" << current->departureTime << "\t\t" << current->destination << endl;
            current = current->next;
        }
    }

    // Function to delete a train by train number
    void deleteTrain(int number) {
        TrainNode* current = head;
        TrainNode* prev = nullptr;

        // If the train to be deleted is the head
        if (current != nullptr && current->trainNumber == number) {
            head = current->next;
            delete current;
            cout << "Train with number " << number << " deleted successfully." << endl;
            return;
        }

        // Search for the train to be deleted
        while (current != nullptr && current->trainNumber != number) {
            prev = current;
            current = current->next;
        }

        // If the train was not found
        if (current == nullptr) {
            cout << "Train with number " << number << " not found." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = current->next;
        delete current;
        cout << "Train with number " << number << " deleted successfully." << endl;
    }

    // Function to delete a train by train name
    void deleteTrain(const string& name) {
        TrainNode* current = head;
        TrainNode* prev = nullptr;

        // If the train to be deleted is the head
        if (current != nullptr && current->trainName == name) {
            head = current->next;
            delete current;
            cout << "Train with name \"" << name << "\" deleted successfully." << endl;
            return;
        }

        // Search for the train to be deleted
        while (current != nullptr && current->trainName != name) {
            prev = current;
            current = current->next;
        }

        // If the train was not found
        if (current == nullptr) {
            cout << "Train with name \"" << name << "\" not found." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = current->next;
        delete current;
        cout << "Train with name \"" << name << "\" deleted successfully." << endl;
    }

    // Function to delete a train from the middle by train number
    void deleteTrainFromMiddle(int number) {
        TrainNode* current = head;
        TrainNode* prev = nullptr;

        // If the train to be deleted is the head
        if (current != nullptr && current->trainNumber == number) {
            head = current->next;
            delete current;
            cout << "Train with number " << number << " deleted successfully." << endl;
            return;
        }

        // Search for the train to be deleted
        while (current != nullptr && current->trainNumber != number) {
            prev = current;
            current = current->next;
        }

        // If the train was not found
        if (current == nullptr) {
            cout << "Train with number " << number << " not found." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = current->next;
        delete current;
        cout << "Train with number " << number << " deleted successfully." << endl;
    }

    // Function to update the information of a train by train number
    void updateTrain(int number, const string& newName, const string& newTime, const string& newDest) {
        TrainNode* current = head;

        // Search for the train to be updated
        while (current != nullptr && current->trainNumber != number) {
            current = current->next;
        }

        // If the train was not found
        if (current == nullptr) {
            cout << "Train with number " << number << " not found." << endl;
            return;
        }

        // Update the train information
        current->trainName = newName;
        current->departureTime = newTime;
        current->destination = newDest;
        cout << "Train with number " << number << " updated successfully." << endl;
    }
};

int main() {
    TrainManagementSystem tms;

    // Adding some sample trains
    tms.addTrain(101, "Express", "08:00", "New York");
    tms.addTrain(202, "Local", "09:30", "Chicago");
    tms.addTrain(303, "Superfast", "10:45", "Los Angeles");

    // Displaying all trains
    cout << "All Trains:" << endl;
    tms.displayTrains();
    cout << endl;

    // Deleting a train by train number
    tms.deleteTrain(202);

    // Displaying all trains after deletion
    cout << "All Trains after deletion:" << endl;
    tms.displayTrains();
    cout << endl;

    // Deleting a train by train name
    tms.deleteTrain("Express");

    // Displaying all trains after deletion
    cout << "All Trains after deletion by name:" << endl;
    tms.displayTrains();
    cout << endl;

    // Updating a train information
    tms.updateTrain(303, "Superfast Express", "11:00", "San Francisco");

    // Displaying all trains after updating
    cout << "All Trains after updating:" << endl;
    tms.displayTrains();
    cout << endl;

    return 0;
}
