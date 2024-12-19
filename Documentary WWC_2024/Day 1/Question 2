// Write a program to check wether the number is prime or not
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int n,ans;
    ans=1; //will store wether the number is prime or not in boolean form
    cout<<"Enter the number: ";
    cin>>n;
    for (int i=2;i<=n/2;i++){
        if(n%i==0){ //checking wether the number is divisible by other numbers or not
            ans=0;
            break;
        }
    }
    if(ans && n!=1){
        cout<<"Prime";
    }
    else{
        cout<<"Non Prime";
    }
    return 0;
}
