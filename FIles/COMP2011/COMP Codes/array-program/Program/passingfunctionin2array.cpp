#include<iostream>
using namespace std;

float mean(float score[], int size){
    float sum_score = 0.0;
    for(int j = 0;j<size;j++)
    {
        sum_score = sum_score + score[j];
    }
    return sum_score/size;
}
float max(float score[], int size){

    float max_score = score[0];

    for(int i=1;i<size;i++){
        max_score = (max_score>score[i])? max_score : score[i];
    }

    return max_score;
}

int main(){

    const int size = 5;
    
    float score[size] = {};
    for(int k=0; k<size;k++){
        cin>>score[k];

    }

    cout<<"Mean score for the class is: "<<mean(score,size)<<endl;
    cout<<"Max score for the class is: "<<max(score,size)<<endl;





    return 0;
}