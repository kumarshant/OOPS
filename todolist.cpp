#include <iostream>
#include <vector>
#include <string>
 using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// ToDoList class
class ToDoList {
private:    vector<Task> tasks;

public:
    // Add a task to the list
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    // Mark a task as completed
    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task completed: " << tasks[index].description <<endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    // Remove a task from the list
    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Task removed: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task number." <<endl;
        }
    }

    // List all tasks
    void listTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
               cout << "[X] ";
            } else {
               cout << "[ ] ";
            }
           cout << tasks[i].description <<endl;
        }
    }
};

int main() {
    ToDoList todo;

    while (true) {
        cout << "\n==== To-Do List ====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Complete Task" << endl;
        cout << "3. Remove Task" << endl;
        cout << "4. List Tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear input buffer
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                todo.addTask(description);
                break;
            }
            case 2: {
                cout << "Enter task number to complete: ";
                int index;
                cin >> index;
                todo.completeTask(index - 1);
                break;
            }
            case 3: {
                cout << "Enter task number to remove: ";
                int index;
                cin >> index;
                todo.removeTask(index - 1);
                break;
            }
            case 4: {
                todo.listTasks();
                break;
            }
            case 5: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
