//game of life
#include<iostream>
using namespace std;
void allocateMemory(int **&arr,int numberOfRows,int numberOfColumns);
void deallocateMemory(int **arr,int numberOfRows);
int main(){
    int arrHeight;
    int arrWidth;
    // int arr[arrHeight][arrWidth]={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    // int newArr[arrHeight][arrWidth];
    cout<<"Enter number of rows:\t";
    cin>>arrHeight;
    cout<<"Enter number of cols:\t";
    cin>>arrWidth;
    int **arr;
    int **newArr;
    allocateMemory(arr,arrHeight,arrWidth);
    allocateMemory(newArr,arrHeight,arrWidth);
    cout<<"Enter elements of arr\nEach cell can be either alive or dead\n";
    for(int i=0;i<arrHeight;i++){
        for(int j=0; j<arrWidth ;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"initial state of arr of conways game of life\n";
    for(int i=0;i<arrHeight;i++){
        for(int j=0; j<arrWidth ;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<arrHeight;i++){
        for(int j=0; j<arrWidth ;j++){
            int state=0;
            int neighbourAliveCount=0;
            state=arr[i][j];
            //check all 8 indexes
            for(int dx = -1; dx <= 1; dx++) {
                for(int dy = -1; dy <= 1; dy++) {
                    int x = i + dx;
                    int y = j + dy;
                    if(x >= 0 && x < arrHeight && y >= 0 && y < arrWidth && !(dx == 0 && dy == 0)) {
                        neighbourAliveCount += arr[x][y];
                    }
                }
            }

            //rules of the game
            if(state==1){
                if(neighbourAliveCount>3 || neighbourAliveCount<2) 
                newArr[i][j]=0;
                else newArr[i][j]=1;
            }
            else if(state==0) {
                if (neighbourAliveCount==3){
                    newArr[i][j]=1;
                } 
                else{
                    newArr[i][j]=0;
                }
            }
        }
        }
        deallocateMemory(arr,arrHeight);
    /////next state displayed
    cout<<endl;
    cout<<"next state of arr of conway's game of life\n";
    for(int i=0;i<arrHeight;i++){
        for(int j=0; j<arrWidth ;j++){
            cout<<newArr[i][j]<<" ";
        }
        cout<<endl;
    }
    deallocateMemory(newArr,arrHeight);

}
void allocateMemory(int **&arr,int numberOfRows,int numberOfColumns){
    arr = new int*[numberOfRows];
    for (int i = 0; i < numberOfRows; i++) {
        arr[i] = new int[numberOfColumns];
    }    
}
void deallocateMemory(int **arr, int numberOfRows){
    for (int i = 0; i < numberOfRows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    }