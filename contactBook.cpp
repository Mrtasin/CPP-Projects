// Contact Book 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

// Text Color functions
void Red ()          {   cout<<"\033[1;31m";   }
void Yellow()        {   cout<<"\033[1;33m";   }
void Blue()          {   cout<<"\033[0;34m";   }
void Green()         {   cout<<"\033[0;32m";   }
void Purple()        {   cout<<"\033[0;35m";   }
void White()         {   cout<<"\033[0;37m";   }
void Cyan()          {   cout<<"\033[0;36m";   }
void ResetTextColor(){   cout<<"\033[0m";      }

class Contact  {
    public:
        string name;
        string phoneNo;
        string emailId;
        
        void printContact() {
            Purple();
            cout << "-----------------------------" << endl;
            cout << "Name         : " << name << endl;
            cout << "Phone Number : " << phoneNo << endl;
            cout << "Email ID     : " << emailId << endl;
            ResetTextColor();
        }
};

class contactBook   {
    private:
        vector<Contact> listOfContacts;
    protected:
        void storeContactInFile();
        void readCcontactFromFile();
    public:
        void mainMenu();
        void addNewContact();
        void viewAllContact();
        void searchContactByName();
        void deleteContactByName();
        void updateContact();
};

void contactBook::storeContactInFile()  {
    ofstream fout("Contacts.txt");
    if (fout.is_open()) {
        for (const auto& contact : listOfContacts) {
            fout<<contact.name<<"\n";
            fout<<contact.phoneNo<<"\n";
            fout<<contact.emailId<<"\n";
        }
        fout.close();
    } else {
        Red();
        cout << "File not found" << endl;
        ResetTextColor();
    }
}

void contactBook::readCcontactFromFile()  {
    ifstream fin("Contacts.txt");
    if (fin.is_open()) {
        Contact contact;
        listOfContacts.clear();

        while (getline(fin, contact.name)) {

            getline(fin, contact.phoneNo);
            getline(fin, contact.emailId);

            listOfContacts.push_back(contact);
        }
        fin.close();
    } else {
        Red();
        cout <<"File not found"<< endl;
        ResetTextColor();
    }
}

void contactBook::mainMenu()  {
    int choice;
    readCcontactFromFile();
    cout<<"Welcome to Contact Book"<<endl;

    do {
        Green();
        cout<<"--------------------------"<<endl;
        cout<<"1. Add New Contact" << endl;
        cout<<"2. View All Contacts" << endl;
        cout<<"3. Search Contact By Name" << endl;
        cout<<"4. Delete Contact By Name" << endl;
        cout<<"5. Update Contact" << endl;
        cout<<"6. Exit" << endl;
        cout<<"Enter your choice: ";
        cin >> choice;
        ResetTextColor();
        cin.ignore(); 
        system("clear"); 
        switch (choice) {
            case 1:
                addNewContact();
                break;
            case 2:
                viewAllContact();
                break;
            case 3:
                searchContactByName();
                break;
            case 4:
                deleteContactByName();
                break;
            case 5:
                updateContact();
                break;
            case 6:
                cout << "Exiting..." << endl;
                storeContactInFile();
                break;
            default:
                Red();
                cout << "Invalid choice, please try again." << endl;
                ResetTextColor();
        }
    } while (choice != 6);
}

void contactBook::addNewContact()  {
    Contact newContact;
    Blue();
    cout<<"----------------------------------"<<endl;
    cout<<"Enter Name : ";
    getline(cin, newContact.name);
    cout<<"Enter Phone Number : ";
    getline(cin, newContact.phoneNo);
    cout<<"Enter Email ID : ";
    getline(cin, newContact.emailId);
    ResetTextColor();
    listOfContacts.push_back(newContact);
    Green();
    cout << "Contact added successfully!" << endl;
    ResetTextColor();
}

void contactBook::viewAllContact()  {
    
    if(listOfContacts.empty())  {
        Red();
        cout << "No contacts available!" << endl;
        ResetTextColor();

    } else {
        int count = 1;
        for (auto& contact : listOfContacts) {
            Yellow();
            cout<<endl;
            cout<<"Contact No   : "<<setfill('0')<<setw(2)<<count++<<endl;
            contact.printContact();
        }
    }
        
}

void contactBook::searchContactByName()  {
    string name;
    cout<<"----------------------------------"<<endl;
    cout<<"Enter the name to search : ";
    getline(cin, name);
    bool found = false;

    for (auto& contact : listOfContacts) {
        if (contact.name == name) {
            contact.printContact();
            found = true;
            break;
        }
    }

    if (!found) {
        Red();
        cout << "Contact not found!" << endl;
        ResetTextColor();
    }
}

void contactBook::deleteContactByName()  {
    string name;
    cout<<"----------------------------------"<<endl;
    cout<<"Enter the name to delete : ";
    getline(cin, name);
    bool found = false;

    for (auto it = listOfContacts.begin(); it != listOfContacts.end(); ++it) {
        if (it->name == name) {
            listOfContacts.erase(it);
            found = true;
            Green();
            cout << "Contact deleted successfully!" << endl;
            ResetTextColor();
            break;
        }
    }

    if (!found) {
        Red();
        cout << "Contact not found!" << endl;
        ResetTextColor();
    }
}

void contactBook::updateContact()  {
    string name;
    cout<<"----------------------------------"<<endl;
    cout<<"Enter the name to update : ";
    getline(cin, name);
    bool found = false;

    for (auto& contact : listOfContacts) {
        if (contact.name == name) {
            cout << "Updating contact..." << endl;
            cout << "Enter new Phone Number : ";
            getline(cin, contact.phoneNo);
            cout << "Enter new Email ID : ";
            getline(cin, contact.emailId);
            found = true;
            cout << "Contact updated successfully!" << endl;
            break;
        }
    }

    if (!found) {
        Red();
        cout << "Contact not found!" << endl;
        ResetTextColor();
    }
}


int main()  {
    contactBook cb;
    cb.mainMenu();
    return 0;
}