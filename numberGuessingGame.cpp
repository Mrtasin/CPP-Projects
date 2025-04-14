#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int randomNumberGenerater(int start, int end)   {

    srand(time(0));
    int randValue = ( rand() % end ) + 1;

    if(start <= randValue && end >= randValue)  {
        return randValue;
    } else  {
        randValue *= start;
        return (randValue % end);
    } 
}

void numberGuessingGame()   {

    int attps = 5;
    int start = 1;
    int end = 100;
    int target;

    int randomNumber = randomNumberGenerater(start, end);
    cout<<"---------------------------------"<<endl;
    cout<<"Welcome to Number Guessing Game"<<endl;
    cout<<"you have "<<attps<<endl;
    cout<<"Range is "<<start<<" to "<<end<<endl;
    cout<<"---------------------------------"<<endl;

    while (attps)   {
        cout<<"Enter guess number : ";
        cin>>target;
       
        if(target == randomNumber)  {
            cout<<"------------------"<<endl;
            cout<<"Correct"<<endl;
            break;
        } else if(target > randomNumber && attps > 1)    {
            cout<<"Too high, !try lower"<<endl;
        } else if(target < randomNumber &&attps > 1){
            cout<<"Too low, !try highly"<<endl;
        }
        attps--;
    }

    if(attps)   {
        cout<<"You Win he game"<<endl;
        cout<<"------------------"<<endl;
    } else  {
        cout<<"------------------"<<endl;
        cout<<"Oops, loss the game"<<endl;
        cout<<"------------------"<<endl;
    }
    
}

int main()  {
    numberGuessingGame();
    cout<<endl;
    return 0;
}