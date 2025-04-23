// Student Grade System 

#include<iostream>
#include<string>
#include<map>
using namespace std;

char calculateGrade(int mark)   {
    if(mark >= 90)
        return 'A';
    else if(mark >= 80)
        return 'B';
    else if(mark >= 70)
        return 'C';
    else if(mark >= 60)
        return 'D';
    else if(mark >= 50)
        return 'E';
    else 
        return 'F';
}

void studentGradeSystem()   {
    string studentName;
    cout<<"Enter Student Name : ";
    getline(cin ,studentName);

    int totalNumberOfSub = 4;

    map<string, float> studentmarks;
    string subName;
    float subMark;
    float totalMarks = 0;
    for(int x = 0; x < totalNumberOfSub; x++)   {
        cout<<endl;
        cout<<"Enter Subject Name : ";
        cin>>subName;
        cout<<"Enter Subject Mark : ";
        cin>>subMark;
        studentmarks[subName] = subMark;
        totalMarks += subMark;
    }

    cout<<"\n-------------------------"<<endl;
    cout<<"Student Result :- "<<endl;
    for(auto sub : studentmarks)    {
        cout<<sub.first<<"  : "<<sub.second<<" --> "<<calculateGrade(sub.second)<<endl; 
    }
    cout<<"Total Marks : "<<totalMarks<<endl;
}

int main()  {
    studentGradeSystem();
    cout<<endl;
    return 0;
}