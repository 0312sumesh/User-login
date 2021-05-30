#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIN(){
    string username, password, un, pw;
    cout << "Enter username:";cin >> username;
    cout << "Enter password:";cin >> password;

    ifstream read("c:\\"+username+".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int choice;

    cout << "1: Rergister\n2: Login\n\n Your choice";cin >> choice;
    if(choice == 1){
        string username,password;

        cout << "select a username:";cin >> username;
        cout << "select a password:";cin >> password;

        
        ofstream file("c:\\"+username+".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2){
        bool status = IsLoggedIN();

        if (!status){
            cout << "False Login!" << endl;
            system("PAUSE");
            return 0;
        }
        else{
            cout << "Successfully Logged In!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}