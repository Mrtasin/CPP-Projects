#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

string OTPGenerator(int size)   {
    srand(time(0));

    string numbers = "1234567890";
    string result = "";
    while (size--) {
        result += numbers[rand() % 10];
    }   // 0121

    return result;
    
}

int main()  {
    int inputData = 4;
    string OTP;
    if(inputData == 4 || inputData == 6)
        OTP = OTPGenerator(inputData);

    cout<<OTP<<endl;
    return 0;

    // string OTP = OTPGenerator((inputData == 4 || inputData == 6) ? inputData : 0);

}