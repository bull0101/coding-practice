#include <iostream>
#include <string>
using namespace std;

int main(){

    int student_num, max_namelength;
    
    string student_name;
    cout << "how many students?";
    cin >> student_num;
    cout << "what's the max name length";
    cin >> max_namelength;

    string** arr = new string*[student_num];

    for(int i = 0;i < student_num;i++){
        arr[i] = new string [student_num];
    };

    for(int i = 0;i < student_num;i++){
        cout << "what's your student name?";
        cin >> student_name;

        while(student_name.length() > max_namelength){
            cout << "超過字數限制 請重新數入";
            cin >> student_name;
        };

        arr[i][0] = to_string(i+1);
        arr[i][1] = student_name;
        
    };

    cout << " - 學生名單 - " << endl;

    for(int i = 0;i < student_num;i++){
        for(int j = 0;j < 2;j++){
            cout << arr[i][j] << " ";
        };
        cout << "\n";
    };

    for(int i = 0;i < student_num;i++){
        delete[] arr[i];
    };

    delete[] arr;
}
