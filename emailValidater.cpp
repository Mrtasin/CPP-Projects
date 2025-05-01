#include<iostream>
#include<string>
#include<regex>

using namespace std;

bool isValidEmail(const string& email)  {
    const regex valid(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)");
    return regex_match(email, valid);
}

int main()  {
    string email;
    cout<<"Enter Email Id : ";
    getline(cin, email);

    if(isValidEmail(email)) {
        cout<<"Valid email : "<<email<<endl;
    } else  {
        cout<<"Invalid email : "<<email<<endl;
    }
    return 0;
}