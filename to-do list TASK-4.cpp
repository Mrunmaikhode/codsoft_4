//to-do list TASK-4
#include <iostream>
#include <string>
using namespace std;
class Todo_List {
private:
    static const int max_task = 10;

    string tasks[max_task];
    bool taskStatus[max_task];
    int numTasks;

public:
    Todo_List() : numTasks(0) {}

    void addTask(const std::string& description) {
        if (numTasks < max_task) {
            tasks[numTasks] = description;
            taskStatus[numTasks] = false;
            numTasks++;
            cout << "Task added successfully!\n";
        } else {
            cout << "Task list is full!\n";
        }
    }

    void viewTasks() const {
            cout << "Tasks:\n";
        for (int i = 0; i < numTasks; ++i) {
                cout << i + 1 << ". ";
            if (taskStatus[i])
                cout << "[Completed] ";
            else
                cout << "[Pending] ";
            cout << tasks[i] << std::endl;
        }
    }

    void markTaskAsCompleted(int index) {
        if (index >= 1 && index <= numTasks) {
            taskStatus[index - 1] = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task index!\n";
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= numTasks) {
            for (int i = index - 1; i < numTasks - 1; ++i) {
                tasks[i] = tasks[i + 1];
                taskStatus[i] = taskStatus[i + 1];
            }
            numTasks--;
            cout << "Task removed successfully!\n";
        } else {
                cout << "Invalid task index!\n";
        }
    }
};

int main() {
    Todo_List todoList;
    int choice;

    do {
        cout << "\n==== To-Do List Manager ====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline in buffer

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                todoList.viewTasks();
                break;
            }
            case 3: {
                int index;
                cout << "Enter the task number to mark as completed: ";
                cin >> index;
                todoList.markTaskAsCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the task number to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}