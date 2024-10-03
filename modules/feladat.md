# Modulokra bontás - fakultatív labor feladat

Adott: Egy `main.c` és egy `fuggvenyek.c` fájl.

## Feladat
- Értelmezd és írj kommentet a kódhoz, használj doxygen docblock-okat is!
- Szedd szét a `fuggvenyek.c` fájl tartalmát egy `matek` és egy `szoveg`
modulra (azaz két-két c és h fájlra) úgy hogy a `main.c` fájl minden módosítás
nélkül leforduljon és helyes kimenetet adjon!
  - A `fuggveny.c` fájlból minden sor csak egyszer fog kelleni. Hogy a kettő
közül melyik fájlba, azt neked kell megállapítanod. 
  - Az include guardokat ne felejtsd el!
- Egészítsd ki a `matek.h` és `matek.c` fájlokat egy függvénnyel ami egy
másodfokú egyenletnek a három változója (a, b, és c; mind egész) alapján
megmondja hány megoldása van.
- Készíts egy `keres` modult amibe implementálj egy minimum és egy maximum
kereső függvényt. A függvény vegyen paraméternek egy int tömböt és a tömb
hosszát, visszatérési értéke pedig legyen a legnagyobb/kisebb elem értéke.
- Az elkésztett függvények használatát mutasd is be a main.c kiegészítésével
vagy egy másik fájlban, egy másik main függvény elkésztésével.

## Emlékesztető
Korábbi laborokon csináltunk már nagyon hasonló program részleteket és
függvényeket. Érdemes lehet ezeket megnézni ha elakadnál, de gyakorlásnak jó
ha újra megírod őket.

Az include guardokat ne felejtsd le a header fájlokból!

## Elvárt megoldás
Hét fájl:
- matek.h
- matek.c
- szoveg.h
- szoveg.c
- matek.h
- matek.c
- main.c / demo.c -- függvény használat bemutatás

## Fájlok tartalma:
Ezeket megtalálod külön fájlokként is, nem feltétlen innen kell kimásolni őket.

### `main.c`

```c
#include "matek.h"
#include "szoveg.h"

int main() {
    hello();

    echo("text");

    num(pw(2, 3));

    num(fac(3));

    return 0;
}

```

### `fuggvenyek.c`

```c
#include <stdio.h>

void hello() {
    echo("Hello, world!");
}

void border(int s) {
    printf("+");
    for (int i = 0; i < s; ++i) printf("-");
    printf("+\n");
}

int pw(int b, int p) {
    int re = b;
    for (int i = 0; i < p; ++i) re *= b;
    return re;
}

void echo(char* string) {
    border(string_length(string));
    printf("|%s|\n", string);
    border(string_length(string));
}

void num(int n) {
    printf("%d\n", n);
}

int string_length(char* string) {
    int l = 0;
    while (string[l] != '\0') l++;
    return l;
}

int fac(int a) {
    int re = 1;
    for (int i = a; i > 0; --i) re *= i;
    return re;
}
```

### Elvárt kimenet
```
+-------------+
|Hello, world!|
+-------------+
+----+
|text|
+----+
16
6
```