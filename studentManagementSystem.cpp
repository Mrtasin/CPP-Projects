#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

// Text Color functions
void Red ()          {   cout<<"\033[1;31m";   }
void Yellow()        {   cout<<"\033[1;33m";   }
void Blue()          {   cout<<"\033[0;34m";   }
void Green()         {   cout<<"\033[0;32m";   }
void Purple()        {   cout<<"\033[0;35m";   }
void White()         {   cout<<"\033[0;37m";   }
void Cyan()          {   cout<<"\033[0;36m";   }
void ResetTextColor(){   cout<<"\033[0m";      }

struct studentData  {
    string name;
    string rollNo;
    string branch;
    string course;
    string emailId;

    void printStudentData() {
        Purple();
        cout<<endl;
        cout<<"Student Name is    : "<<name<<endl;       
        cout<<"Student RollNo is  : "<<rollNo<<endl;
        cout<<"Student Branch is  : "<<branch<<endl;
        cout<<"Student course is  : "<<course<<endl;
        cout<<"Student emailId is : "<<emailId<<endl;
        cout<<"---------------------------------"<<endl<<endl;
        ResetTextColor();
    }
};

class studentManagementSystem   {
    private:
        vector<studentData> listOfStudents;
    protected:
        void readStudentsRecordFromFile();
        void storeStudentRecordInFile();
    public:
        void mainMenu();
        void addStudentData();
        void displayStudentRecords();
        void searchStudentUsingRollNo();
        void editStudentRecord();
        void deleteStudentRecord();
};

void studentManagementSystem::readStudentsRecordFromFile()  {
    ifstream fin("Student.txt");
    studentData record;

    if (fin.is_open())  {

        while(  getline(fin, record.name)   && 
                getline(fin, record.rollNo) && 
                getline(fin, record.branch) && 
                getline(fin, record.course) && 
                getline(fin, record.emailId)    )

            listOfStudents.push_back(record);

        fin.close();        
    } else  {
        Red();
        cout<<"Student.txt file is not found"<<endl;
        ResetTextColor();
    }
}

void studentManagementSystem::storeStudentRecordInFile()    {
    ofstream fout("Student.txt");
    if (fout.is_open()) {
        
        for(auto record : listOfStudents)   {
            fout<<record.name<<"\n";
            fout<<record.rollNo<<"\n";
            fout<<record.branch<<"\n";
            fout<<record.course<<"\n";
            fout<<record.emailId<<"\n";
        }
        fout.close();
        
    } else {
        Red();
        cout<<"Error: Unable to open file!"<<endl;
        ResetTextColor();
    }
}

void studentManagementSystem::mainMenu()    {
    int choice;
    readStudentsRecordFromFile();
    while (true)    {
        Yellow();
        cout<<"-------------------------------------"<<endl;
        cout<<"Enter 1 For Add Student"<<endl;
        cout<<"Enter 2 For Print all Student Records"<<endl;
        cout<<"Enter 3 For Search Student"<<endl;
        cout<<"Enter 4 For Edit Student Record"<<endl;
        cout<<"Enter 5 For Delete Student Record"<<endl;
        cout<<"Enter 6 For Exit this App"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        ResetTextColor();
        system("clear");
        switch (choice) {
        case 1:
            addStudentData();
            break;
        case 2:
            displayStudentRecords();
            break;
        case 3:
            searchStudentUsingRollNo();
            break;
        case 4:
            editStudentRecord();
            break;
        case 5:
            deleteStudentRecord();
            break;
        case 6:
            storeStudentRecordInFile();
            exit(0);
        default:
            cout<<"Enter valid choice"<<endl;
        }
    }
    
}

void studentManagementSystem::addStudentData()  {
    studentData inputData;
    cin.ignore();
    cout<<endl<<"--------------------------------"<<endl;
    cout<<"Enter Student Name    : ";
    getline(cin, inputData.name);
    cout<<"Enter Student rollNo  : ";
    getline(cin, inputData.rollNo);
    cout<<"Enter Student branch  : ";
    getline(cin, inputData.branch);
    cout<<"Enter Student course  : ";
    getline(cin, inputData.course);
    cout<<"Enter Student emailId : ";
    getline(cin, inputData.emailId);
    cout<<"--------------------------------"<<endl;
    listOfStudents.push_back(inputData);
}

void studentManagementSystem::displayStudentRecords() {
    if(listOfStudents.empty())  {
        Red();
        cout<<"|----------------------------------|"<<endl;
        cout<<"| Student DataBase Record is Empty |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        ResetTextColor();
    } else  {
        int count = 1;
        for(auto Data : listOfStudents) {
            cout<<"Record No : "<<count++<<endl;
            Data.printStudentData();
        }
            
    }
}

void studentManagementSystem::searchStudentUsingRollNo()    {
    string rollNo;
    bool flag = true;
    cin.ignore();
    cout<<"Enter Student rollNo : ";
    getline(cin, rollNo);

    if(listOfStudents.empty())  {
        Red();
        cout<<"|----------------------------------|"<<endl;
        cout<<"| Student DataBase Record is Empty |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        ResetTextColor();
    } else {
        for(auto data : listOfStudents)
            if(data.rollNo == rollNo)   {
                data.printStudentData();
                flag = false;
                break;
            }

        if(flag)    {
            Red();
            cout<<"|----------------------------------|"<<endl;
            cout<<"| <"<<rollNo<<"> Student Record not found "<<endl;
            cout<<"|----------------------------------|"<<endl;
            ResetTextColor();
        }
    }
}

void studentManagementSystem::editStudentRecord()   {
    string rollNo;
    bool flag = true;
    cin.ignore();
    cout<<"Enter Student rollNo : ";
    getline(cin, rollNo);

    if(listOfStudents.empty())  {
        Red();
        cout<<"|----------------------------------|"<<endl;
        cout<<"| Student DataBase Record is Empty |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        ResetTextColor();
    } else {
        for(int x = 0; x < listOfStudents.size(); x++)

            if(listOfStudents[x].rollNo == rollNo)  {
                cout<<endl<<"--------------------------------"<<endl;
                cout<<"Enter Student Name    : ";
                getline(cin, listOfStudents[x].name);
                cout<<"Enter Student branch  : ";
                getline(cin, listOfStudents[x].branch);
                cout<<"Enter Student emailId : ";
                getline(cin, listOfStudents[x].emailId);
                cout<<"--------------------------------"<<endl;
                flag = false;
                break;
            }

        if(flag)    {
            Red();
            cout<<"|----------------------------------|"<<endl;
            cout<<"| <"<<rollNo<<"> Student Record not found "<<endl;
            cout<<"|----------------------------------|"<<endl;
            ResetTextColor();
        }
    }
}

void studentManagementSystem::deleteStudentRecord() {
    string rollNo;
    bool flag = true;
    cin.ignore();
    cout<<"Enter Student rollNo : ";
    getline(cin, rollNo);

    if(listOfStudents.empty())  {
        Cyan();
        cout<<"|----------------------------------|"<<endl;
        cout<<"| Student DataBase Record is Empty |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        ResetTextColor();
    } else {
        vector<studentData>::iterator it = listOfStudents.begin();
        for( ; it != listOfStudents.end(); it++)
            if(it->rollNo == rollNo)    {
                Red();
                it->printStudentData();
                listOfStudents.erase(it);
                cout<<"Deletion is seccuessful"<<endl;
                ResetTextColor();
                flag = false;
                break;
            }
        if(flag)    {
            cout<<"|----------------------------------|"<<endl;
            cout<<"| <"<<rollNo<<"> Student Record not found "<<endl;
            cout<<"|----------------------------------|"<<endl;
        }
    }
}


int main()  {
    studentManagementSystem s1;
    s1.mainMenu();
    cout<<endl;
    return 0;
}