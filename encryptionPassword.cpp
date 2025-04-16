// Encryption and Decryption
#include<iostream>
#include<string>
#include "passwordGenerator.cpp"
using namespace std;

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

int main()  {
    string Password = passwordGenerator(10,2,1);
    cout<<Password<<endl;
    string data = encryption(Password, 5);
    cout<<data<<endl;
    cout<<decryption(data, 5);
    cout<<endl;
    return 0;
}