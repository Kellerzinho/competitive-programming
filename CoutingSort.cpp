#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int>& arr){
    int n = arr.size();

    int max_value = arr[0];
    for(int i=1; i<n; ++i){
        if(arr[i] > max_value){
            max_value = arr[i];
        }
    }

    vector<int> count(max_value + 1, 0);

    for(int i=0; i<n; ++i){
        count[arr[i]]++;
    }

    int index = 0;
    for(int i=0; i<=max_value; ++i){
        while(count[i]>0){
            arr[index++]=i;
            count[i]--;
        }
    }
}