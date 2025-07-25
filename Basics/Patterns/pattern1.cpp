/*
4
Your Output
*
**
***
****
*/




#include <bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main() {
	// your code goes here
	int n;
	//cout<<"enter n";
	cin>>n;
	pattern1(n);
	

}
