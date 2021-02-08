#include <iostream>
					//D=B^2-4AC
using namespace std;
	int main()
	{ 
		unsigned A, B, C, D;
			A = B = C = D = 0;
			cout << "Enter A,B,C separately to get the solution:  " << endl;
	
			cin >> A;
			cin >> B;
			cin >> C;
	
	     __asm
				{
					mov eax, B
				    mul eax
					mov B, eax
			
					mov eax, A
					mov ebx, 4
					mul ebx
					mov A, eax
					mov eax, C
					mov ebx, A
					mul ebx
					mov C, eax
					mov eax, C
					mov ebx, B
					sub ebx, eax
					mov D, ebx


		}
		cout << "Your result(D=)" << D << endl;
		return 0; 
	}
