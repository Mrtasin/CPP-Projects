#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>  // For Windows
#else
    #include <termios.h>
    #include <unistd.h>
    char getch() {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Disable buffered I/O and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
        return ch;
    }
#endif


// Text Color functions
void red ()     {   cout<<"\033[1;31m";   }
void yellow()   {   cout<<"\033[1;33m";   }
void Blue()     {   cout<<"\033[0;34m";   }
void Green()    {   cout<<"\033[0;32m";   }
void Purple()   {   cout<<"\033[0;35m";   }
void White()    {   cout<<"\033[0;37m";   }
void Cyan()     {   cout<<"\033[0;36m";   }
void reset ()   {   cout<<"\033[0m";      }


class ticTacToe {
    private:
        char Arr[3][3];
        string palyerName1;
        string palyerName2;
        int inputKey = 0;
        vector<int> winPalyerData; 
    protected:
        void inputPalyerName();
        void setDataTicTacArray();
        void printPalyersName();
        void printData();
        void userInput();
        void checkElement(char choice);
        void checkWiningGame();
        void palyer(string);
        void displayResult();
        void restartGame();
    public:
        void mainMune();
                
};

void ticTacToe::mainMune() {
    int choice;
    while("TasiNCoder") {
        
        Green();
        cout<<"\n---------------------------\n";
        cout<<"Enter 1 For Play Game\n";
        cout<<"Enter 2 For Exit This Game\n";
        cout<<"Enter Your Choice : ";
        cin>>choice;
        cout<<"---------------------------\n";
        reset();
        
        switch(choice)   {
            case 1:
                inputPalyerName();
                system("clear");
                printPalyersName();
                printData();
                userInput();
                break;
            case 2:
                system("clear");
                Cyan();
                cout<<endl<<"     |---------------|";
                cout<<endl<<"     |   Thank you   |";
                cout<<endl<<"     |---------------|"<<endl;
                reset();
                exit(0);
            default:
                red();
                cout<<endl<<"Your Choice Invalid...!"<<endl;
                reset();
        }
    }
}

void ticTacToe::inputPalyerName() {
    yellow();
    cin.ignore();
    cout<<"----------------------------"<<endl;
    red();
    cout<<"Enter 1st palyer name : ";
    getline(cin,palyerName1);
    Blue();
    cout<<"Enter 2nd palyer name : ";
    getline(cin,palyerName2);
    yellow();
    cout<<"----------------------------"<<endl;
    reset();
    setDataTicTacArray();
}

void ticTacToe::setDataTicTacArray()   {
    char count = '1';
    for(int x = 0; x < 3; x++)
        for(int z = 0; z < 3; z++)
            Arr[x][z] = count++;
}

void ticTacToe::printPalyersName() {
    cout<<endl;
    red();
    cout<<"|-------------------------------|"<<endl;
    cout<<"|  "<<palyerName1<<" Player X"<<endl;
    cout<<"|-------------------------------|"<<endl;
    Blue();
    cout<<"|-------------------------------|"<<endl;
    cout<<"|  "<<palyerName2<<" Player O"<<endl;
    cout<<"|-------------------------------|"<<endl;
    reset();
} 

void ticTacToe::printData()    {
    cout<<endl;
    cout<<" _________________ "<<endl;
    for(int x = 0; x < 3; x++) {
        cout<<"|     |     |     |"<<endl;
        for(int z = 0; z < 3; z++)  {
            cout<<"|  ";
            if(Arr[x][z] == 'X')
                red();
            else if(Arr[x][z] == 'O')
                Blue();
            cout<<Arr[x][z]<<"  ";
            reset();
        }
        cout<<"|"<<endl;
        cout<<"|_____|_____|_____|"<<endl;
    }
}

void ticTacToe::userInput() {
    char choice;
    cout<<endl;
    choice = getch();

    if(choice>='1' && choice<='9')
        checkElement(choice);

    system("clear");
    printPalyersName();
    printData();
    userInput();
}

void ticTacToe::checkElement(char choice) {
    int c = choice % 49;

    if(Arr[c/3][c%3] == choice) {
        inputKey++;
        Arr[c/3][c%3] = (inputKey % 2) ? 'X' : 'O';
        checkWiningGame();                
    }               

    if(inputKey==9) {
        system("clear");
        printPalyersName();
        printData();
        Purple();
        cout<<"\n         |-----------|";
        cout<<"\n         | Game Drow |";
        cout<<"\n         |-----------|\n\n";
        reset();
        restartGame();
    }
    printData();
}

void ticTacToe::checkWiningGame()  {
    char temp = 'N';
    if( (Arr[2][0] == Arr[1][1]) && (Arr[2][0] == Arr[0][2]) )  {
        temp = Arr[2][0];
        winPalyerData = {6,4,2};
    
    } else if( (Arr[0][0] == Arr[1][1]) && (Arr[1][1] == Arr[2][2]) ) {
        temp = Arr[0][0];
        winPalyerData = {0,4,8};
    
    } else
        for(int x = 0; x<3; x++)    {
            if(Arr[x][0] == Arr[x][1] && Arr[x][0] == Arr[x][2])    {
                temp = Arr[x][0];
                for(int z = 0; z <3; z++)
                    winPalyerData.push_back(((x * 3) + z));
            
            } else if(Arr[0][x] == Arr[1][x] && Arr[0][x] == Arr[2][x])   {
                temp = Arr[0][x];
                for(int z = 0; z <3; z++)
                    winPalyerData.push_back(((z * 3) + x));
            }
        }
    if(temp == 'X')
        palyer(palyerName1);
    else if(temp == 'O')
        palyer(palyerName2);
}

void ticTacToe::palyer(string name)  {
    system("clear");
    Green();
    cout<<endl<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
    cout<<endl<<"| Congratulation, "<<name<<" Win the Game";
    cout<<endl<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    reset();
    displayResult();
    restartGame();
}

void ticTacToe::displayResult()    {
    cout<<endl;
    cout<<" _________________ "<<endl;
    int count = 0;

    for(int x = 0,temp = 0; x < 3; x++) {
        cout<<"|     |     |     |"<<endl;

        for(int z = 0; z < 3; z++, temp++)  {
            
            cout<<"|  ";
            if(winPalyerData[count] == temp)    {
                Green();
                count++;
                cout<<Arr[x][z]<<"  ";
            }
            else    {
                red();
                cout<<Arr[x][z]<<"  ";
            }
            reset();
        }
        cout<<"|"<<endl;
        cout<<"|_____|_____|_____|"<<endl;
    }
}

void ticTacToe::restartGame()  {
    int choice;
    while("TasiNCoder") {
        
        Green();
        cout<<"\n---------------------------\n";
        cout<<"Enter 1 For Replay Game"<<endl;
        cout<<"Enter 2 For Exit This Game\n";
        cout<<"Enter Your Choice : ";
        cin>>choice;
        cout<<"---------------------------\n";
        reset();
        
        switch(choice)   {
            case 1:
                setDataTicTacArray();
                winPalyerData.clear();
                inputKey = 0;
                printPalyersName();
                printData();
                userInput();
                break;

            case 2:
                system("clear");
                Cyan();
                cout<<endl<<"     |---------------|";
                cout<<endl<<"     |   Thank you   |";
                cout<<endl<<"     |---------------|"<<endl;
                reset();
                exit(0);

            default:
                red();
                cout<<endl<<"Your Choice Invalid...!"<<endl;
                reset();
        }
    }
}

int main()  {
    ticTacToe t1;
    t1.mainMune();
    cout<<endl;
    return 0;
}