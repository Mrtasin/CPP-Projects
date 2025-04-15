// Password Generator

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string passwordGenerator(int size, int num = 0, int symb = 0)   {
    string resultPassword = "";
    string numbers = "1234567890";
    string alphabets = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string symbols = "!~#$&_-=?/";
    srand(time(0));

    while (size)    {
        resultPassword += alphabets[rand() % alphabets.size()];
        size--;

        if(num && size) {
            resultPassword += numbers[rand() % 10];
            size--;
            num--;
        }

        if(symb && size) {
            resultPassword += symbols[rand() % symbols.size()];
            size--;
            symb--;
        }
    }
    return resultPassword;
}

int main() {
    cout<<passwordGenerator(8);
    cout<<endl;
    return 0;
}