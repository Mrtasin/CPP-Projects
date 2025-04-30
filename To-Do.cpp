#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

// Encryption and Decryption
string encryption(string password, int key, int digit = 0) {
    string encryptData = "";
    if(digit == 0)
        digit = key;
    for (auto chr : password)   {
        if('A' <= chr && 'Z' >= chr)    {
            encryptData += (65 + (chr - 65 + key) % 26);
        } else if('a' <= chr && 'z' >= chr) {
            encryptData += (97 + (chr - 97 + key) % 26);
        } else if('0' <= chr && '9' >= chr) {
            encryptData += ('0' + (chr - '0' + digit) % 10);
        } else  {
            encryptData += chr;
        }
    }
    return encryptData;
}

string decryption(string password, int key) {
    return encryption(password, 26 - key, 10 - key);
}

// use color function
void Red()      {   cout << "\033[31m";     }
void Green()    {   cout << "\033[32m";     }
void Yellow()   {   cout << "\033[33m";     }
void Blue()     {   cout << "\033[34m";     }
void Magenta()  {   cout << "\033[35m";     }
void Cyan()     {   cout << "\033[36m";     }
void White()    {   cout << "\033[37m";     }
void Reset()    {   cout << "\033[0m" ;     }   

struct Task {
    int id;
    string title;
    string description;
    bool status = false;
    int priority;
};

ostream& operator<<(ostream& os, const Task& task) {
    Green();
    cout<<"---------------------------------"<<endl;
    cout<<" Task ID          : "<<task.id<<endl;
    cout<<" Task Title       : " << task.title<<endl;
    cout<<" Task Description : " << task.description<<endl;
    cout<<" Task Status      : " << (task.status ? "Completed" : "Pending")<<endl; 
    cout<<" Task Priority No : " << task.priority<<endl;
    Reset();
    return os;
}

istream& operator>>(istream& is, Task& task) {
    Magenta();
    cout<<"---------------------------------"<<endl;
    cout<<"Enter Task Title       : ";
    getline(is, task.title);
    cout<<"Enter Task Description : ";
    getline(is, task.description);
    cout<<"Enter Priority No      : ";
    is >> task.priority;
    Reset();
    return is;
}

class taskCompare {
    public:
        bool operator()(Task &a, Task &b) {
            return a.priority > b.priority;
        }
};

class ToDoManager {
    private:
        priority_queue<Task, vector<Task>, taskCompare> listOfTasks;
    protected:
        int taskIdCounter = 0;
        string userName;
        string password;
        void loadTasks();
        void saveTasks();
    public:
        void mainMenu();
        void addTask();
        void deleteTask();
        void searhTaskById();  
        void printAllTask();  
        void printAllTaskPending(); 
        void printAllTaskCompleted(); 
        void changeStatusOfTask();
        void updateTask();
};

void ToDoManager::loadTasks() {
    ifstream file(userName + ".txt");

    if (file.is_open()) {
        Task task;
        file>>userName>>password>>taskIdCounter;
        file.ignore();
        while (getline(file, task.title)) {
            getline(file, task.description);
            file>>task.id>>task.status>>task.priority;
            file.ignore();
            listOfTasks.push(task);
        }
        file.close();
    }
}

void ToDoManager::saveTasks() {
    ofstream file(userName + ".txt");

    if (file.is_open()) {
        file<<userName<<" "<<password<<" "<<taskIdCounter<<endl;

        while (!listOfTasks.empty()) {
            Task task = listOfTasks.top();
            listOfTasks.pop();
            file << task.title << endl;
            file << task.description << endl;
            file << task.id<<" "<<task.status<<" "<<task.priority<<endl;
        }
        file.close();
    }
    else
        cout << "Error opening file!" << endl;
}

void ToDoManager::mainMenu() {
    int choice;
    do {
        Blue();
        cout<<"|-----------------------------|"<<endl;
        cout<<"|         Main Menu           |"<<endl;
        cout<<"| 1. Add Task                 |"<<endl;
        cout<<"| 2. Delete Task              |"<<endl;
        cout<<"| 3. Search Task by ID        |"<<endl;
        cout<<"| 4. Print All Tasks          |"<<endl;
        cout<<"| 5. Print Pending Tasks      |"<<endl;
        cout<<"| 6. Print Completed Tasks    |"<<endl;
        cout<<"| 7. Change Task Status       |"<<endl;
        cout<<"| 8. Update Task              |"<<endl;
        cout<<"| 9. Exit                     |"<<endl;
        cout<<"|-----------------------------|"<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cin.ignore();
        system("clear");
        Reset();

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                searhTaskById();
                break;
            case 4:
                printAllTask();
                break;
            case 5:
                printAllTaskPending();
                break;
            case 6:
                printAllTaskCompleted();
                break;
            case 7:
                changeStatusOfTask();
                break;
            case 8:
                updateTask();
                break;
            case 9:
                saveTasks();
                break;
            default:
                Red();
                cout << "Invalid choice! Please try again." << endl;
                Reset();
        }
    } while (choice != 9);
}

void ToDoManager::addTask() {
    Task tempTask;
    cin>>tempTask;
    tempTask.id = ++taskIdCounter;
    listOfTasks.push(tempTask);
    Green();

    cout << "Task added successfully!" << endl;
    cout << "Task ID : " << tempTask.id << endl;
    Reset();
}

void ToDoManager::deleteTask() {
    int id;
    cout << "Enter Task ID to delete : ";
    cin >> id;
    priority_queue<Task, vector<Task>, taskCompare> tempQueue;

    while (!listOfTasks.empty()) {
        Task task = listOfTasks.top();
        listOfTasks.pop();
        if (task.id != id) {
            tempQueue.push(task);
        }
    }
    listOfTasks = tempQueue;
    Green();
    cout << "Task deleted successfully!" << endl;
    Reset();
}

void ToDoManager::searhTaskById() {
    int id;
    cout << "Enter Task ID to search : ";
    cin >> id;
    priority_queue<Task, vector<Task>, taskCompare> tempQueue;
    bool found = true;
    Task task;

    while (!listOfTasks.empty()) {
        task = listOfTasks.top();
        listOfTasks.pop();
        if (task.id == id) {
            cout << task;
            found = false;
        }
        tempQueue.push(task);
    }
    listOfTasks = tempQueue;
    
    if(found) {
        Red();
        cout << "Task not found!" << endl;
        Reset();
    }
}

void ToDoManager::printAllTask() {
    
    if(listOfTasks.empty()) {
        Red();
        cout << "No tasks available!" << endl;
        Reset();
    }
    else {
        priority_queue<Task, vector<Task>, taskCompare> tempQueue;
        cout << "All Tasks :" << endl;
        while (!listOfTasks.empty()) {
            Task task = listOfTasks.top();
            listOfTasks.pop();
            cout << task;
            tempQueue.push(task);
        }
        listOfTasks = tempQueue;
    }
   
}

void ToDoManager::printAllTaskPending() {
    if(listOfTasks.empty()) {
        Red();
        cout << "No tasks available!" << endl;
        Reset();
    }
    else {
        priority_queue<Task, vector<Task>, taskCompare> tempQueue;
        cout << "All Pending Tasks :" << endl;
        while (!listOfTasks.empty()) {
            Task task = listOfTasks.top();
            listOfTasks.pop();
            if(!task.status) {
                cout << task;
            }
            tempQueue.push(task);
        }
        listOfTasks = tempQueue;
    }
}

void ToDoManager::printAllTaskCompleted() {
    if(listOfTasks.empty()) {
        Red();
        cout << "No tasks available!" << endl;
        Reset();
    }
    else {
        priority_queue<Task, vector<Task>, taskCompare> tempQueue;
        cout << "All Completed Tasks :" << endl;
        while (!listOfTasks.empty()) {
            Task task = listOfTasks.top();
            listOfTasks.pop();
            if(task.status) {
                cout << task;
            }
            tempQueue.push(task);
        }
        listOfTasks = tempQueue;
    }
}

void ToDoManager::changeStatusOfTask() {
    int id;
    cout << "Enter Task ID to change status : ";
    cin >> id;
    priority_queue<Task, vector<Task>, taskCompare> tempQueue;
    bool found = true;
    Task task;

    while (!listOfTasks.empty()) {
        task = listOfTasks.top();
        listOfTasks.pop();
        if (task.id == id) {
            task.status = !task.status;
            cout << "Task status changed successfully!" << endl;
            found = false;
        }
        tempQueue.push(task);
    }
    listOfTasks = tempQueue;

    if(found) {
        Red();
        cout << "Task not found!" << endl;
        Reset();
    }
}

void ToDoManager::updateTask() {
    int id;
    cout << "Enter Task ID to update : ";
    cin >> id;
    priority_queue<Task, vector<Task>, taskCompare> tempQueue;
    bool found = true;
    Task task;

    while (!listOfTasks.empty()) {
        task = listOfTasks.top();
        listOfTasks.pop();
        if (task.id == id) {
            cout << "Enter new details for the task:" << endl;
            cin >> task;
            found = false;
        }
        tempQueue.push(task);
    }
    listOfTasks = tempQueue;

    if(found) {
        Red();
        cout << "Task not found!" << endl;
        Reset();
    }
}


class Authentication : public ToDoManager {
    public:
        void authMainMenu();
        void login();
        void registerUser();
};

void Authentication::authMainMenu() {
    int choice;
    do {
        Magenta();
        cout<<"|------------------------------|"<<endl;
        cout<<"|         Authentication       |"<<endl;
        cout<<"| 1. Register User             |"<<endl;
        cout<<"| 2. Login User                |"<<endl;
        cout<<"| 3. Exit                      |"<<endl;
        cout<<"|------------------------------|"<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cin.ignore();
        system("clear");
        Reset();

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                break;
            default:
                Red();
                cout << "Invalid choice! Please try again." << endl;
                Reset();
        }
    } while (choice != 3);
    cout << "Exiting..." << endl;
}

void Authentication::registerUser(){
    string inputUserName;
    string inputPassword;
    Magenta();
    cout<<"---------------------------------"<<endl;
    cout<<"|         Register User         |"<<endl;
    cout << "Enter your username : ";
    cin >> inputUserName;
    cout << "Enter your password : ";
    cin >> inputPassword;
    Reset();
    ifstream file(inputUserName + ".txt");
    if(file.is_open()) {
        cout << "User already exists!" << endl;
        file.close();
    }
    else {
        userName = inputUserName;
        password = encryption(inputPassword, inputPassword.size());
        saveTasks();
        cout<< "User registered successfully!" << endl;
    }
};

void Authentication::login() {
    string inputUserName;
    string inputPassword;
    Magenta();
    cout<<"---------------------------------"<<endl;
    cout<<"|         Login User           |"<<endl;
    cout << "Enter your username : ";
    cin >> inputUserName;
    cout << "Enter your password : ";
    cin >> inputPassword;
    Reset();
    userName = inputUserName;
    loadTasks();
    if(userName == inputUserName && password == encryption(inputPassword, inputPassword.size())) {
        cout << "Login successful!" << endl;
        mainMenu();
    }
    else {
        Red();
        cout << "Invalid username or password!" << endl;
        Reset();
    }
}

int main() {
    Authentication auth;
    auth.authMainMenu();
    return 0;
}