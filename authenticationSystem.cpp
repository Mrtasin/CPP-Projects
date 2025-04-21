#include<iostream>
#include<string>
#include<fstream>

using namespace std;

// Text Color functions

void Green()         {   cout<<"\033[0;32m";   }
void ResetTextColor(){   cout<<"\033[0m";      }

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
            cin.ignore();
            cout<<"Login Tab....!"<<endl;
            cout<<"--------------------------"<<endl;
            cout<<"Enter user-Name : ";
            getline(cin, uName);
            cout<<"Enter Password : ";
            getline(cin, pass);
            cout<<"--------------------------"<<endl;
            ifstream fin(uName + ".txt");

            if(fin.is_open())   {
                if( getline(fin, fullName) && 
                    getline(fin, emailId)  && 
                    getline(fin, userName) && 
                    getline(fin, password))  {

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

        void registration() {
            cin.ignore();
            cout<<"Registration Tab....!"<<endl;
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
                
                system("clear");
                cout<<"-------------------------------"<<endl;
                cout<<"Registration is Complete"<<endl;
                cout<<"This is a UserName : ";
                Green();
                cout<<userName<<endl;
                ResetTextColor();
                cout<<"This is a Password : ";
                Green();
                cout<<password<<endl;
                ResetTextColor();
            } else {
                cout<<"Registration is not Completed"<<endl;
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
            a1.registration();
    }
    
}
