#include<iostream>
#include<thread>
#include<chrono>
#include<iomanip>

using namespace std;
using namespace this_thread;
using namespace chrono;

void countdown(int sec)  {
    while (sec > 0) {
        int hh = sec / 3600;
        int mm = (sec % 3600) / 60;
        int ss = sec % 60;

        cout<<"Count Down : "
        <<setfill('0')<<setw(2)<<hh<<":"
        <<setw(2)<<mm<<":"
        <<setw(2)<<ss<<endl;

        // cout<<hh<<":"<<mm<<":"<<ss<<endl;

        sleep_for(seconds(1));
        sec--;
        system("clear");
    }
    cout<<"00:00:00"<<endl;
    cout<<"time! out"<<endl;
}

int main()  {

    int totalSeconds;
    cout<<"Enter count down time in seconds : ";
    cin>>totalSeconds;
    countdown(totalSeconds);

    return 0;
}