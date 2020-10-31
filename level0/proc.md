A cette ligne on alloue l'espace necessaire aux variables
```gdb
0x08048ec6 <+6>:     sub    esp,0x20
```

3 entier (4*3 octets)
un char * (4 octets)
et un tableau de 2 case de char * (4 octets)


Ici on appelle atoi et on compare sa valeur de retour avec 423
```gdb
0x08048ed1 <+17>:    mov    DWORD PTR [esp],eax
0x08048ed4 <+20>:    call   0x8049710 <atoi>
0x08048ed9 <+25>:    cmp    eax,0x1a7
```
Si elle est egal on set les uid et gid et on ouvre un shell
```gdb
0x08048ef8 <+56>:    call   0x8054680 <getegid>
0x08048efd <+61>:    mov    DWORD PTR [esp+0x1c],eax
0x08048f01 <+65>:    call   0x8054670 <geteuid>
0x08048f06 <+70>:    mov    DWORD PTR [esp+0x18],eax
0x08048f0a <+74>:    mov    eax,DWORD PTR [esp+0x1c]
0x08048f0e <+78>:    mov    DWORD PTR [esp+0x8],eax
0x08048f12 <+82>:    mov    eax,DWORD PTR [esp+0x1c]
0x08048f16 <+86>:    mov    DWORD PTR [esp+0x4],eax
0x08048f1a <+90>:    mov    eax,DWORD PTR [esp+0x1c]
0x08048f1e <+94>:    mov    DWORD PTR [esp],eax
0x08048f21 <+97>:    call   0x8054700 <setresgid>
0x08048f26 <+102>:   mov    eax,DWORD PTR [esp+0x18]
0x08048f2a <+106>:   mov    DWORD PTR [esp+0x8],eax
0x08048f2e <+110>:   mov    eax,DWORD PTR [esp+0x18]
0x08048f32 <+114>:   mov    DWORD PTR [esp+0x4],eax
0x08048f36 <+118>:   mov    eax,DWORD PTR [esp+0x18]
0x08048f3a <+122>:   mov    DWORD PTR [esp],eax
0x08048f3d <+125>:   call   0x8054690 <setresuid>
0x08048f42 <+130>:   lea    eax,[esp+0x10]
0x08048f46 <+134>:   mov    DWORD PTR [esp+0x4],eax
0x08048f4a <+138>:   mov    DWORD PTR [esp],0x80c5348
0x08048f51 <+145>:   call   0x8054640 <execv>
```

Si elle n'est pas égal on affiche un "No" sur stderr

```gdb
0x08048f58 <+152>:   mov    eax,ds:0x80ee170
0x08048f5d <+157>:   mov    edx,eax
0x08048f5f <+159>:   mov    eax,0x80c5350
0x08048f64 <+164>:   mov    DWORD PTR [esp+0xc],edx
0x08048f68 <+168>:   mov    DWORD PTR [esp+0x8],0x5
0x08048f70 <+176>:   mov    DWORD PTR [esp+0x4],0x1
0x08048f78 <+184>:   mov    DWORD PTR [esp],eax
0x08048f7b <+187>:   call   0x804a230 <fwrite>
```