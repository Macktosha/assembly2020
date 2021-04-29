#include <iostream>
using namespace std;

int define_progression(long value)
{
    int step = 0;
    int first = 0;
    int var1 = 0;
    int var2 = 0;
    __asm
    {
        mov eax,value    
        and eax, 0xff
        mov first,eax
        ror value,8

        mov eax, value
        and eax, 0xff
        sub eax,first
        mov step,eax
        ror value,8

        mov eax, value
        and eax, 0xff
        mov ebx,step
        imul ebx,2
        sub eax,ebx
        mov var1,eax
        ror value,8

        mov eax, value
        and eax, 0xff
        mov ebx,step
        imul ebx,3
        sub eax,ebx
      
        mov var2,eax

}
    if (var1==var2) return 1;
    else return 0;
}

int main()
{
   cout << "\tEnter the number to define the arithmetical progression among the bytes of long integer value" << endl;
    cout << "\t\tWarning! Do not enter 16-bit number, because the solution will be trivial." << endl;
   unsigned long long_value = 0;

    cin >> long_value;

    printf("In <%lu>: %s\n", long_value, define_progression(long_value) ? "Arithmetical progression detected" : "Progression doesn't occurs");

    return 0;
}


/* byte = value & 0xff;
 int first0 = byte;
 value >>= 8;

 byte = value & 0xff;
 int step = byte - first0;
 value >>= 8;

 byte = value & 0xff;
int  var1 = byte - 2 * step;
 value >>= 8;

 byte = value & 0xff;
 int var2 = byte - 3 * step;
 */