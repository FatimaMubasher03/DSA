#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
	int temp;
	
for (int i=0; i< n-1; i++){
    for (int j=0; j<n-i-1; j++){
        if (arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
for (int i = 0 ;i < n; i++)
	cout << arr[i] << " ";
}
int main(){
    int arr[10]={25,23,43,23,87,5,34,22,86,78};
    bubbleSort(arr,10);

    cout << "Original Array:\n";
    for (int i = 0; i< 10; i++){
        cout << arr[i] << " ";
    }

    cout << "\nSorted Array:\n";
//    for (int i = 0; i<sortedarr.size(); i++){
//        cout << sortedarr[i] << "at position" << i+1 << endl;
//    }

    return 0;

}

