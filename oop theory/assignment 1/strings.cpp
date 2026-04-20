#include<iostream>
using namespace std;
void allocateMemory(char *&arr,int length);
void deallocateMemory(char *arr);
int getLength(string str);
bool compare(const char* a, const char* b);
int getLength(string str);
int main(){
    string patternStr = "", str = "", matchedStr="";
    cout<<"Enter a string:\t";
    cin>>str;
    cout<<"\nEnter a pattern:\t";
    cin>>patternStr;
    int lengthOfStr= getLength(str);
    int k=0,j=0,i=0;
    while(i<lengthOfStr){
        if(patternStr[j]!='*'){
            if(str[i]==patternStr[j] || patternStr[j]=='#'){
                matchedStr+=str[i];
                cout<<"element that matches is "<<str[i]<<endl;
                cout<<matchedStr;
            }
            j++;
        }
        else{
            cout<<"* occurs"<<endl;
            matchedStr+=str[i];
            cout<<"element that matches is "<<str[i]<<endl;
            cout<<matchedStr;
            char c;
            c=str[i];
            while(str[i]==c){
                i++;
            }
            i--;
            j++;   
        }
        i++;
    }
    cout<<"Characters that match in both arrays are "<<matchedStr;
    return 0;
}
void allocateMemory(char *&arr,int length){
    arr = new char[length];
}
void deallocateMemory(char *arr) {
    delete[] arr;
}
int getLength(string str){
    int length=0;
    for(int i=0 ; str[i]!='\0';i++){
        length++;
    }
    return ++length;//for \0
}