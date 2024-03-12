#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>

using namespace std;

void random(int arr[],int n){

    srand((unsigned)time(NULL));

    for(int i=n-1; i>0; i--){
        int j = rand()%(i+1);

        swap(arr[i],arr[j]);
    }

    return;

}



int main(){



    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    int f=0;
    random(a,25);
    
    for(int k = 0;k<25;k++){

        f++;
        cout.width(2);cout<<a[k]<<" "; 
        if(f%5==0){
            cout<<endl;
        }

    }
    

    

    return 0;
}