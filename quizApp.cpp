#include<iostream>
#include<fstream>
#include<string>
#include<vector>
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


struct Question {
    string question;
    string optionsA;
    string optionsB;
    string optionsC;
    string optionsD;
    string correctAnswer;

    void displayQuestion() {
        Blue();
        cout<<"--------------------------------------------"<<endl;
        cout << question << endl;
        cout << "  A. " << optionsA << endl;
        cout << "  B. " << optionsB << endl;
        cout << "  C. " << optionsC << endl;
        cout << "  D. " << optionsD << endl;
        ResetTextColor();
    }
};

class QuizApp {
    private:
        vector<Question> listOfQuestions;
        int score;
    public:
        QuizApp()   {
            score = 0;
            fileLoad();
        }
        void fileLoad() {
            ifstream fin("Quiz.txt");
            Question ques;
            listOfQuestions.clear();
            if(fin.is_open())   {
                while (getline(fin, ques.question)) {
                    getline(fin, ques.optionsA);
                    getline(fin, ques.optionsB);
                    getline(fin, ques.optionsC);
                    getline(fin, ques.optionsD);
                    getline(fin, ques.correctAnswer);
                    listOfQuestions.push_back(ques);
                }
                fin.close();
            } else{
                Red();
                cout<<"Error File not found"<<endl;
                ResetTextColor();
            }
        }

        void StartQuiz()    {
            for(auto& Q : listOfQuestions)  {

                Q.displayQuestion();
                string answer;
                cout<<"Enter your full Answer : ";
                getline(cin, answer);

                for(int x = 0; x < answer.length(); x++)
                    answer[x] = tolower(answer[x]);
                
                if(answer == Q.correctAnswer)   {
                    Green();
                    score++;
                    cout<<"Correct Answer"<<endl;
                    ResetTextColor();
                } else  {
                    Red();
                    cout<<"Worng! --> Correct Answer is : "<<Q.correctAnswer<<endl;
                    ResetTextColor();
                }
            }
        } 

        void resultDisplay()    {
            system("clear");
            Green();
            cout<<"Total Score : "<<score<<"/"<<listOfQuestions.size()<<endl;
        }
};


int main()  {
    QuizApp qa;
    qa.StartQuiz();
    qa.resultDisplay();
    cout<<endl;
    return 0;
}
