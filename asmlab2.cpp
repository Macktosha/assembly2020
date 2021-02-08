#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()

{
    int choice=0;
    unsigned long num = 0, N;
    unsigned short  M = 0,res=0;
    printf("For what number would you like to change binary pairs?\n1 -  64-bit\n2 -  16-bit\n");
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1: scanf_s("%lu", &N);
        __asm {
            mov edx, N
            xor ebx, ebx
            L1 :
            mov eax, edx
                and eax, 3
                shl ebx, 2
                or ebx, eax
                shr edx, 2
                or edx, edx
                cmp edx, 0
                jnz L1
                mov num, ebx
        }
        printf("%lu", num);
        break;
    case 2: scanf_s("%hu", &M);
        __asm {
            mov dx, M
            xor bx, bx
            L2 :
            mov ax, dx
            and ax, 3
            shl bx, 2
            or bx, ax
            shr dx, 2
            or dx, dx
            cmp dx, 0
            jnz L2
            mov res, bx
        }
        printf("%hu", res);
        break;
    default:
        break;
    }
     
    return 0;
}

