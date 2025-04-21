#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Authentication    {
    private:
        string userName;
        string password;
        string fullName;
        string emailId;
    public:
        void login()    {
            string uName;
            string pass;
            cout<<"--------------------------"<<endl;
            cout<<"Enter user-Name : ";
            getline(cin, uName);
            cout<<"Enter Password : ";
            getline(cin, pass);
            cout<<"--------------------------"<<endl;
            ifstream fin(uName + ".txt");

            if(fin.is_open())   {
                if(getline(fin,fullName) && 
                    getline(fin, emailId) && 
                    fin>>userName && 
                    fin>>password)  {

                    if (password == pass)   {
                        cout<<"Login"<<endl;
                    }
                    else
                        cout<<"Invalid Password"<<endl;
                }
                fin.close();
            }
            else
                cout<<"worng username";
        }

        void rigestration() {
            cout<<"--------------------------"<<endl;
            cout<<"Enter Full Name : ";
            getline(cin, fullName);
            cout<<"Enter Email Id : ";
            getline(cin, emailId);
            cout<<"Enter user-Name : ";
            getline(cin, userName);
            cout<<"Enter Password : ";
            getline(cin, password);
            cout<<"--------------------------"<<endl;

            ofstream fout(userName + ".txt");
            if(fout.is_open())  {
                fout<<fullName<<"\n";
                fout<<emailId<<"\n";
                fout<<userName<<"\n";
                fout<<password<<"\n";

                fout.close();
            } else {
                cout<<"Error";
            }
        }
};

int main()  {
    Authentication a1;
    while (true)
    {
       int x;
       cout<<"Emter a 1 for login : "<<endl;
       cout<<"Emter a 2 for rigestration : "<<endl;
       cin>>x;
       cin.ignore();
       if(x == 1)
        a1.login();
        else if(x == 2)
            a1.rigestration();
    }
    
}