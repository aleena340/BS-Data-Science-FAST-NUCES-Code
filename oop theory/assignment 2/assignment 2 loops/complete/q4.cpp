#include<iostream>
using namespace std;
bool bracketsAreBalanced(string str);
int stringLength(const char* str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + stringLength(str + 1);
}
int main(){
    string str;
    cout<<"Enter a string to check if string is balanced\n";
    getline(cin,str);
    char chArr[100],ch;
    int index=0;
    for(int i=0;str[i]!='\0';i++){
            if ((str[i] == '(' )|| ( str[i] == '{' ) ||  (str[i] == '[')  ) {
                *(chArr+index) = str[i];
                index++;
            }
            
            else if( (str[i]==')') || (str[i]=='}') || (str[i]== ']') ){
                ch = str[i];
            
            
                
             if ((ch == ')' && *(chArr+index-1) == '(') || (ch == ']' && *(chArr+index-1) == '[') || (ch == '}' && *(chArr+index-1) == '{')) {
                cout<<" balanced\n";
                index--;
            }
            }
    }
    
    if(index!=0) cout<<" not balanced";

return 0;
}
