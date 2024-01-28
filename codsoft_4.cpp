#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    Node* next;
    string task, importance, status;

    Node()
    {
        next = NULL;
        task = importance = status = "";
    }
};

class List
{
private:
    Node* head, * tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void addTask(string t, string i)
    {
        if (head == NULL)
        {
            head = new Node();
            head->task = t;
            head->importance = i;
            head->status = "Incomplete";
            tail = head;
        }
        else
        {
            Node* temp = new Node();
            tail->next = temp;
            temp->task = t;
            temp->importance = i;
            temp->status = "Incomplete";
            tail = temp;
        }
    }

    void deleteTask(int taskNumber)
    {
        if (head == NULL)
        {
            system("CLS");
            cout << "To-Do list is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        int currentNumber = 1;

        while (temp != NULL)
        {
            if (currentNumber == taskNumber)
            {
                if (prev == NULL)
                {
                    Node* nextNode = temp->next;
                    delete temp;
                    head = nextNode;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                }
                system("CLS");
                cout << "Task #" << taskNumber << " deleted successfully." << endl;
                return;
            }

            prev = temp;
            temp = temp->next;
            currentNumber++;
        }
        system("CLS");
        cout << "Invalid task number. No task deleted." << endl;
    }

    void viewTask()
    {
        if (head == NULL)
        {
            cout << "To-Do list is empty." << endl;
            return;
        }
        Node* temp = head;
        int n = 1;
        while (temp != NULL)
        {
            cout << "Task #" << n << endl << "To do: " << temp->task << endl << "Importance: " << temp->importance << endl << "Status: " << temp->status << endl;
            n++;
            temp = temp->next;
        }
    }

    void markAsCompleted(int taskNumber)
    {
        Node* temp = head;
        int currentNumber = 1;

        while (temp != NULL)
        {
            if (currentNumber == taskNumber)
            {
                temp->status = "Completed";
                system("CLS");
                cout << "Task #" << taskNumber << " marked as completed." << endl;
                return;
            }

            temp = temp->next;
            currentNumber++;
        }

        system("CLS");
        cout << "Invalid task number. No task marked as completed." << endl;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
};

void view_list(List& ToDo)
{
    system("CLS");
    ToDo.viewTask();
}

void add_task(List& ToDo)
{
    system("CLS");

    string task, importance;

    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, task);
    cout << "Enter the importance of the task: ";
    getline(cin, importance);

    ToDo.addTask(task, importance);
}

void delete_task(List& ToDo)
{
    system("CLS");

    if (ToDo.isEmpty())
    {
        cout << "The list is empty!" << endl;
        return;
    }

    int taskNumber;

    view_list(ToDo);

    while (true)
    {
        cout << "Enter the task number to delete: ";
        cin >> taskNumber;
        if (taskNumber > 0)
        {
            ToDo.deleteTask(taskNumber);
            break;
        }

        cin.ignore();
        cout << "Invalid input. Please enter a valid task number: ";
    }
}

void mark_completed(List& ToDo)
{
    system("CLS");

    if (ToDo.isEmpty())
    {
        cout << "The list is empty!" << endl;
        return;
    }

    int taskNumber;

    view_list(ToDo);

    while (true)
    {
        cout << "Enter the task number to mark as completed: ";
        cin >> taskNumber;
        if (taskNumber > 0)
        {
            ToDo.markAsCompleted(taskNumber);
            break;
        }

        cin.ignore();
        cout << "Invalid input. Please enter a valid task number: ";
    }
}

int main()
{
    List ToDo;
    int choice = -1;
    while (true)
    {
        cout << "---- To-Do List ----" << endl;
        cout << "1.View To-Do List"
            << "\n2.Add Task"
            << "\n3.Delete Task"
            << "\n4.Mark as Completed"
            << "\n0.Exit"
            << "\nChoice:";
        cin >> choice;

        if (choice == 1)
        {
            view_list(ToDo);
            cout << "\n1. Return\n0. Exit\nChoice: ";
            cin >> choice;
            if (choice == 0)
                return 10;
            else if (choice == 1)
            {
                system("CLS");
                continue;
            }
            else
            {
                while (choice != 1)
                {
                    view_list(ToDo);
                    cout << "\n1. Return\n2. Exit";
                    cin >> choice;
                    if (choice == 0)
                        return 10;
                    else if (choice == 1)
                    {
                        system("CLS");
                    }
                }
            }
        }
        else if (choice == 2)
        {
            add_task(ToDo);
            system("CLS");
            cout << "Task added successfully!" << endl;
        }
        else if (choice == 3)
        {
            delete_task(ToDo);
        }
        else if (choice == 4)
        {
            mark_completed(ToDo);
        }
        else if (choice == 0)
        {
            return 0;
        }
        else
        {
            system("CLS");
            cout << "You entered an invalid choice!\nTry again!" << endl;
        }
    }

    return 0;
}