#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; 

int main(){

int a, i = 0; 
string text, old, password1, password2, pass, name, password0, age, user, word, word1;

string credentials[2], cp[2];

cout<<"    Security system"<<endl; 


cout<<"____________________________"<<endl<<endl;
cout<<"|      1.Register          |"<<endl;
cout<<"|      2.Login             |"<<endl;
cout<<"|      3.Change Password   |"<<endl;
cout<<"|      4.End Program       |"<<endl;
cout<<"____________________________"<<endl<<endl;

do{

    cout<<endl<<endl;
    cout<<"Enter your choice:- ";
    cin>>a; 
    switch(a){
        case 1: {
            cout<< "___________________________"<<endl<<endl;
            cout<<"|---------Register----------|"<<endl;
            cout<<"|___________________________|"<<endl<<endl;
            cout<<"Please enter username:-  ";
            cin>>name;
            cout<<"Please enter a password:-  ";
            cin>>password0;
            cout<<"Please enter your age:-  ";
            cin>>age;

        ofstream of1;
        of1.open("file.txt");
        if(of1.is_open()){

            of1<<name<<"\n";
            of1<<password0;
            cout<<"Registration successfull"<<endl;
        }
        break;
        }
        case 2: {
    i = 0;

    cout << "_____________________________" << endl << endl;
    cout << "|----------Login------------|" << endl;
    cout << "|___________________________|" << endl;

    ifstream of2;
    of2.open("file.txt");
    cout << "Please enter a username: ";
    cin >> user;
    cout << "Please enter the password: ";
    cin >> pass;

    if (of2.is_open()) {
        while (getline(of2, text)) {
            istringstream iss(text);
            iss >> word;
            credentials[i] = word;
            i += 1;
        }

        if (user == credentials[0] && pass == credentials[1]) {
            cout << "---Log in successful--- " << endl;

            cout << " Details: " << endl;
            cout << "Username: " + user << endl;  // Use "user" instead of "name"
            cout << "Password: " + pass << endl;
            cout << "Age: " + age << endl;
        } else {
            cout << endl << endl;
            cout << "Incorrect credentials" << endl;
            cout << "|    1. Press 2 to Login                 |" << endl;
            cout << "|    2. Press 3 to change the password   |" << endl;
        }
    }

    of2.close(); // Close the file after reading its contents

    break;
}
case 3: {
    i = 0;

    cout << "-------------Change password-------------" << endl;

    ifstream of0;
    of0.open("file.txt");
    cout << "Enter the old password: ";
    cin >> old;
    if (of0.is_open()) {
        while (getline(of0, text)) {
            istringstream iss(text);
            iss >> word1;
            cp[i] = word1;
            i++;
        }

        if (old == cp[1]) {
            of0.close();

            ofstream of1;
            of1.open("file.txt"); // Open the file for writing

            if (of1.is_open()) {
                cout << "Enter your new password: ";
                cin >> password1;
                cout << "Enter your password again: ";
                cin >> password2;

                if (password1 == password2) {
                    of1 << cp[0] << "\n";
                    of1 << password1;
                    cout << "Password changed successfully" << endl;
                } else {
                    of1 << cp[0] << "\n";
                    of1 << old;
                    cout << "Passwords do not match" << endl;
                }
            } else {
                cout << "Error opening the file for writing." << endl;
            }

            of1.close(); // Close the file after writing to it
        } else {
            cout << "Please enter a valid password" << endl;
        }
    } else {
        cout << "Error opening the file." << endl;
    }

    break;
}

            case 4: 
            {
                cout<<"______________Thank you!_______________"<<endl;
                break;
            }

            default:{

                cout<<"Enter a valid choice";
            }
    
    }
}
while(a!=4);
return 0;




}