#include <iostream>
using namespace std;

#define n 100

class Stack{
	
	private:
	int* arr;
	int top;
	
	public:
	Stack(){
		arr = new int[n];
		top = -1;
		
	}		
	
//	#Functions
//	#Adding Elements
	void push (int x){
		
		if (top >= n-1){
			cout<<"Stack overflow"<<endl;
			return;
		}
		
		top++;
		arr[top]=x;	
	}
	
//	#Removing Elements
	void pop (){
		
		if (top ==-1){
			cout<<"Nothing to Pop"<<endl;
			return;
		}
		
		top--;
	}
	
//	#Top Function
	int Top(){
		
		if (top ==-1){
			cout<<"Stack Empty"<<endl;
			return -1;
		}
		
		return arr[top];
	}
	
//	#Boolean function
	bool empty(){
		return top==-1;
		}
	
};


int main(){
	
	Stack st;
	st.push(20);
	st.push(14);
	st.push(2);
	st.push(11);
	st.push(23);
	cout<<st.Top()<<endl;
	st.pop();
	st.pop();
	cout<<st.Top()<<endl;
	st.pop();
	cout<<st.Top()<<endl;
	cout<<st.empty()<<endl;

	
	return 0;
}