// Password Strength Checker
#include <iostream>
#include <string>

using namespace std;

string passwordStrengthChecker(const string& password)  {
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    bool passwordLength = password.length() >= 8 ? 1 : 0;
    string specialChars = "!@#$%^&*()-+";
    int totalConditionsLength = 0;

    for(auto ch : password) {
        if (islower(ch)) {
            hasLower = true;
        } else if (isupper(ch)) {
            hasUpper = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        } else if (specialChars.find(ch) != string::npos) {
            hasSpecial = true;
        }
    }
    totalConditionsLength = hasLower + hasUpper + hasDigit + hasSpecial + passwordLength;

    if(totalConditionsLength >= 5) {
        return "Strong";
    } else if (totalConditionsLength >= 3) {
        return "Medium";
    } else {
        return "Weak";
    }
}

int main() {
    string password;
    cout << "Enter a password: ";
    cin >> password;

    string strength = passwordStrengthChecker(password);
    cout << "Password strength: " << strength << endl;

    if(!any_of(password.begin(), password.end(), ::isupper )) {
        cout<< "Password must added at least one uppercase letter." << endl;
    }
    else if(!any_of(password.begin(), password.end(), ::islower )) {
        cout<< "Password must added at least one lowercase letter." << endl;
    }
    else if(!any_of(password.begin(), password.end(), ::isdigit )) {
        cout<< "Password must added at least one digit." << endl;
    }
    else if(password.find_first_of("!@#$%^&*()-+") == string::npos) {
        cout<< "Password must added at least one special character." << endl;
    }
    else if(password.length() < 8) {
        cout<< "Password must be at least 8 characters long." << endl;
    }
    return 0;
}