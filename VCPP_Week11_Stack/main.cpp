#include "y_stack.h"
#include <iostream>
using namespace std;

int main() {
	y_Stack s;  
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);

	cout << s.pop() << " 스텍에서 제거 \n";
	cout << s.pop() << " 스텍에서 제거 \n";

	cout << "현재 Top은 " << s.peek() << "입니다." << endl; // 현재 top 요소 조회

	//push의 개수만큼
	for (int i = 0; i < 6; i++) { 
		int result;
		result = s.pop();
		cout << result << endl;
	}

	return 0;
}