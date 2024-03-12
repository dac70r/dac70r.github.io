#include <iostream>
using namespace std;

int main(){
//declaration of 'arr' as multidimensional array 
//must have bounds for all dimensions except the first
int arr[][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

for(int i = 0; i<4;i++){for (int j = 0; j<3; j++){cout<<arr[i][j]<<" ";}
cout<<endl;

}

    



    
    return 0;
}