#include<iostream>
using namespace std;

void miniCalculator()   {
    cout<<"Welcome to Calculator"<<endl;
    cout<<"------------------------"<<endl;

    int num1, num2;
    char choice;

    while (true)    {
        cout<<"Enter < + > for addition"<<endl;
        cout<<"Enter < - > for subtraction"<<endl;
        cout<<"Enter < * > for subtraction"<<endl;
        cout<<"Enter < / > for division"<<endl;
        cout<<"Enter < % > for remainder"<<endl;
        cout<<"Enter < E > for Exit..!"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        system("clear");

        cout<<"------------------------"<<endl<<endl;

        switch(choice)  {
            case '+':
                cout<<"Enter tow numbers : ";
                cin>>num1>>num2;
                cout<<"Sum of "<<num1<<" and "<<num2<<" is : "<<num1 + num2;
                break;
            case '-':
                cout<<"Enter two numbers : ";
                cin>>num1>>num2;
                cout<<"Sub of "<<num1<<" and "<<num2<<" is : "<<num1 - num2;
                break;
            case '*':
                cout<<"Enter two numbers : ";
                cin>>num1>>num2;
                cout<<"Mul of "<<num1<<" and "<<num2<<" is : "<<num1 * num2;
                break;
            case '%':
                cout<<"Enter two numbers : ";
                cin>>num1>>num2;
                cout<<"Mod of "<<num1<<" and "<<num2<<" is : "<<num1 % num2;
                break;
            case '/':
            {
                float num1,num2;
                cout<<"Enter two numbers : ";
                cin>>num1>>num2;
                cout<<"Div of "<<num1<<" and "<<num2<<" is : "<<num1 / num2;
                break;
            }
            case 'E':
                cout<<"Thank you"<<endl;
                exit(0);
            default:
                cout<<"Enter valid choice"<<endl;
        }
        cout<<endl<<endl;
    }
}
 
int main()  {
    miniCalculator();
    return 0;
}