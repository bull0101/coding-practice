#include <iostream>
#include <string>
#include <cctype>  
using namespace std;

bool isonlyEnglish(const string& str) {
    for (char c : str) {
        if (!::isalpha(static_cast<unsigned char>(c)) and c != ' ') {
            return false;
        }
    }
    return true; 
};

int main(){

    int student_num;
    int maxlength = 0;
    int max_firstname_length = 0;
    int firstname_length = 0;
    string student_name;

    cout << "how many students?";

    while(true){      
        if(cin >> student_num && student_num > 0){
            break;
        }
        else{
            cin.clear();
            cin.ignore(10000,'\n');

            cout << "輸入為非正整數 請重新輸入";
        };
    };

    cin.ignore();

    string* temp_names = new string[student_num];

    for(int i = 0;i < student_num;i++){
        cout << "what's your student name?";

        while(true){
            getline(cin,student_name);

            if(!(isonlyEnglish(student_name))){
                cout << "非純英文字母 請重新輸入";
            }
            else{
                break;
            }
        };

        temp_names[i] = student_name;

        if(student_name.length() > maxlength){
            maxlength = student_name.length();
        };

        int space_position = student_name.find(' ');

        if(space_position != string::npos){
            firstname_length = space_position;
        }
        else{
            firstname_length = student_name.length();
        };

        if(firstname_length > max_firstname_length){
            max_firstname_length = firstname_length;
        };
    };

    char** arr = new char*[student_num];

    for(int i = 0; i < student_num; i++){
        arr[i] = new char[maxlength + 1]; 
    }

    for(int i = 0; i < student_num; i++){
        strcpy(arr[i], temp_names[i].c_str());
    }

    for(int i = 0 ; i < student_num ; i++){

        string name = arr[i];
        int space_position = name.find(' ');
        int current_firstname_length;

        if(space_position != string::npos){
            current_firstname_length = space_position;
        }
        else{
            current_firstname_length = name.length();
        };

        int spaceneed = max_firstname_length - current_firstname_length;

        for(int j = 0 ; j < spaceneed ; j++){
            cout << " ";
        };
        cout << name << "\n";

    };

    for(int i = 0; i < student_num; i++){
        delete[] arr[i]; 
    }
    delete[] arr;        
    delete[] temp_names; 

};
