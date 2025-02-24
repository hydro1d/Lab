#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter array element"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the value u want to search"<<endl;
    int target;
    cin>>target;

    bool found=false;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"found at index: "<<i<<endl;
            found =true;
            break;
        }

    }
    if(!found){
        cout<<"Not found"<<endl;
    }

}
