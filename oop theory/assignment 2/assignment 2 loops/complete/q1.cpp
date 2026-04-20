#include<iostream>
using namespace std;
int main(){
    string word="";
    string code="";
    cout<<"Enter a word:\t";
    cin>>word;
    //convert string to uppercase
    for( int i = 0 ; word[i] != '\0' ; i++){
        if(word[i]>=97){
            word[i]=word[i]-32;
        }
    }
    
    //convert according to table
    for ( int i = 0 ; word[i] != '\0' ; i++){
        if(i == 0){
            code=word[i];
        }
        else if(word[i] == 'A' || word[i] == 'E' || word[i] == 'I'|| word[i] == 'O'|| word[i] == 'U'|| word[i]=='H'|| word[i]=='Y'){
            code+='0';
        }
        else if(word[i] == 'B' || word[i] == 'F' || word[i] == 'P'|| word[i] == 'V'){
            code+='1';
        }
        else if(word[i] == 'C' || word[i] == 'G' || word[i] == 'J'|| word[i] == 'K'|| word[i] == 'Q'|| word[i]=='S'|| word[i]=='X'|| word[i]=='Z'){
            code+='0';
        }
        else if(word[i]=='D' || word[i]=='T'){
            code+='3';
        }
        else if(word[i]=='M' || word[i]=='N'){
            code+='4';
        }
        else if(word[i]=='L'){
            code+='5';
        }
        if(word[i]=='r'){
            code+='6';
        }
    }
    //remove duplicate letters
    string removeDuplicates = "";
    for (int i = 0; code[i] != '\0' ; i++){
        if( code[i] == code[i+1] ){
            i++;
        }
        removeDuplicates+=code[i];
    }
    string removeZeros = "";
    for (int i = 0 ; removeDuplicates[i] != '\0'; i++){
        if(removeDuplicates[i]!='0'){
            removeZeros+=removeDuplicates[i];
        }
    }
    int length = 0;
    for (int i = 0; removeZeros[i]!='\0'; i++){
        length = length+1;
    }
    string finalCode = "";
    if(length > 4){
        for (int i = 0; i < 4 ; i++){
            finalCode += removeZeros[i];
        }
        cout<<"The code for your name is "<<finalCode;
    }
    else if(length<4){
        while( length<4){
            removeZeros+='0';
            length++;
        }
        cout<<"The code for your name is "<<removeZeros;
    }
    
}