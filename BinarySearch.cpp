#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int arr[N];

int bin_search (int l, int h, int x){
    int mid = (l+h)/2;
    while(l<h){
        if (arr[mid]< x) l = mid + 1;
        else mid = h;
        mid = (l+h)/2;
    }
    return mid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

int n, q;
cin >> n >> q;

for(int i = 0; i < n; i++) cin >> arr[i]; 

while(q--){
    int a;
    cin >> a;
    int bin = bin_search(0, n - 1, a);
    if(arr[bin] == a) cout << bin << '\n';
    else cout << "-1\n";

}

return 0;
}