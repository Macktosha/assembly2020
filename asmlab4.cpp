#include <iostream>
#include <cstdlib>
#include <ctime>
#define K 10 //размерность массивов
#define M 20
using namespace std;

int main()
{
	srand(time(NULL));
	int arrayA[K],arrayB[M];

	cout << "arrayA {";
		for (int i = 0; i < K; i++) {
			arrayA[i] = rand() % 100;
			cout<<arrayA[i] << " ";
		}
	cout << "}\n" << endl;
	cout << "arrayB {";
	for (int i = 0; i < M; i++) {
		arrayB[i] = rand() % 100;
		cout << arrayB[i] << " ";
	}
	cout << "}\n" << endl;
	int min = 9999;
	int cnt = 0;//счетчик наличия мин элемента 
	
	__asm {
     mov eax,0 //находим минимальный элемент 
	 mov ecx,K
	 mov ebx,0
	 L:
	 mov eax,arrayA[ebx]
	 cmp eax,min
	 jl L2
	 add ebx,type arrayA
	 mov eax, arrayA[ebx]
	 jmp L3
	 
	 L2:
	 mov min, eax
	 add ebx,type arrayA
	 mov eax, arrayA[ebx]
	 jmp L4
	 L3:
     L4:
	 dec ecx
	 cmp ecx,0
	 jne L



	 mov eax,0 //сравниваем минимальный с элементами из второго массива, если находим, то увеличиваем счетчик
	 mov ecx,M
	 mov ebx,0
	 mov edx,cnt
	 G:
	 mov eax, arrayB[ebx]
	 cmp eax, min
	 je G2
	 add ebx, type arrayB
	 mov eax, arrayB[ebx]
	 jmp G3
	
	 G2:
	 inc edx
	 add ebx,type arrayB
	 mov eax, arrayB[ebx]
	 jmp G4
	 G3:
     G4:
	 dec ecx
	 cmp ecx,0
	 jne G

     mov cnt,edx
	}
	cout << "Min elem in arrayA = " << min << endl << endl;;
	if (cnt > 0)
		cout << "Min elem from arrayA occurs " << cnt << " times in arrayB" << endl;
	else
		cout << "Min elem from arrayA doesn't occur in arrayB" << endl;
	return 0;
}
