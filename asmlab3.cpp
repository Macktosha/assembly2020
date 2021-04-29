#include <iostream>
using namespace std; /*if(a<b<c) P=1 else P=0*/

int main() {
	int A, B, C, P;
	A = B = C = P = 0; 
	cout << "Enter A,B,C separately to get the solution:  " << endl;

	cin >> A >> B >> C;

	__asm 
	{
		mov eax, A
		mov ebx, B
		mov ecx, C

		cmp eax, ebx
		jl  Less1
		mov P, 0
		jmp N
		
		Less1:
		cmp ebx,ecx
		jl  Less2

		mov P, 0
		jmp N

		Less2:
		mov P,1
		N:  
		}
	cout << "P = " << P << endl;
	return 0;
}