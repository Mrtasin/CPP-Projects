#include<iostream>
#include<chrono>
#include<thread>
#include<iomanip>

using namespace std;

int main()  {
    while (true)    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm* localTime = localtime(&currentTime);

        // system("cls"); for windows

        system("clear");

        cout<< put_time(localTime, "%H:%M:%S")<<endl;

        this_thread::sleep_for(chrono::seconds(1));
    }
    
    return 0;
}