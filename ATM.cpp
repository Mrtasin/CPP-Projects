#include<iostream>
#include<string>
#include<fstream>
#include "bankAccount.cpp"

class ATM :public bankAccount {
    private:
        string atmCardNumber;
        string atmPin;
        double atmBalance;
        string atmExpiryDate;
        string atmCVV;
        string AccountNumber;
    public:
        void MainMenuATM();
        void checkATMCard();
};

void ATM::MainMenuATM() {
    int choice;
    loadFromFile();
    do {
        cout << "----------------------------------" << endl;
        cout << " Enter 1 for Check Balance " << endl;
        cout << " Enter 2 for Withdraw Money from ATM " << endl;
        cout << " Enter 3 for Deposit Money to ATM " << endl;
        cout << " Enter 4 for mini statment " << endl;
        cout << " Enter 5 for Logout " << endl;
        cout << "----------------------------------" << endl;
        cout << " Enter your choice : ";
        cin >> choice;
        cin.ignore();
        system("clear");

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                withdrawMoney();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                allTransactionHistory();
                break;
            case 5:
                cout << "Logging out...!" << endl;
                savetoFile();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
}


void ATM::checkATMCard() {

    string cardNumber;
    string pin;
    cout<<"Enter ATM Card Number: ";
    getline(cin, cardNumber);
    cout<<"Enter ATM Card Pin: ";
    getline(cin, pin);

    ifstream file(cardNumber + ".txt");
    if (file.is_open()) {
        getline(file, atmCardNumber);
        getline(file, AccountNumber);
        getline(file, atmExpiryDate);
        getline(file, atmCVV);
        getline(file, atmPin);
        file.close();

        if(atmCardNumber == cardNumber && atmPin == pin) {
            accountNumber = AccountNumber;
            MainMenuATM();
        } else {
            cout << "Invalid ATM Card Number or Pin!" << endl;
        }
    } else {
        cout << "File Invalid ATM Card Number or Pin!" << endl;
    }
}

int main() {
    ATM atm;
    atm.checkATMCard();    
    return 0;
}