#include <iostream>
#include <cstring> 
#include <cctype>  
using namespace std;

bool isonlyEnglish(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!::isalpha(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true; 
}

void bubblesort(char **arr , int size){
    for(int i = 0 ; i < (size-1) ; i++){
        for(int j = 0 ; j < (size-i-1) ; j++){
            
            int len0 = strlen(arr[j]);
            int len1 = strlen(arr[j+1]);

            char x0 = arr[j][len0 - 1];
            char x1 = arr[j+1][len1 - 1];

            if((int)x0 > (int)x1){
                char* temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){

    int student_num, max_namelength;
    char buffer[256];

    cout << "how many students?";

    while(true){      
        if(cin >> student_num and student_num > 0){
            break;
        }
        else{
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "輸入為非正整數 請重新輸入";
        }
    }

    cout << "what's the max name length";

    while(true){      
        if(cin >> max_namelength && max_namelength > 0){
            break;
        }
        else{
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "輸入為非正整數 請重新輸入";
        }
    }

    char** arr = new char*[student_num];

    for(int i = 0 ; i < student_num ; i++){
        arr[i] = new char[max_namelength + 1];
    }

    for(int i = 0; i < student_num; i++){
        cout << "what's your student name? ";

        while(true){
            cin >> buffer;
            if(!(isonlyEnglish(buffer))){
                cout << "非純英文字母 請重新輸入";
            }
            else if(strlen(buffer) > max_namelength){
                cout << "超過字數限制 請重新輸入";
            }
            else{
                break;
            }
        }
        strcpy(arr[i], buffer);
    }

    bubblesort(arr, student_num);

    cout << " - 學生名單 - " << endl;

    for(int i = 0; i < student_num; i++){
        cout << "Student " << (i + 1) << " : " << arr[i] << "\n";
    }

    for (int i = 0; i < student_num; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
};
