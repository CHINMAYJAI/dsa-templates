#include<bits/stdc++.h>
using namespace std;

// recursive
int josephusRec(int n, int k) {
    if (n==1) return 1;
    return (josephusRec(n-1,k)+k-1)%n+1;
}

// iterative
int josephusIterative(int n, int k) {
    int i=1,ans=0;
    while (i<=n) {
        ans=(ans+k)%i;
        i++;
    }
    return ans+1;
}

int main () {
    cout<<josephusRec(7,3);
    cout<<josephusIterative(5,2);
    return 0;
}