# Modulokra bontás - labor kiegészítő anyag

## Tartalomjegyzék
<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Tartalomjegyzék](#tartalomjegyzék)
- [Nagy projekt, kis függvények](#nagy-projekt-kis-függvények)
- [Függvények](#függvények)
  - [Deklaráció vs Implementáció](#deklaráció-vs-implementáció)
    - [Deklaráció](#deklaráció)
    - [Implementáció](#implementáció)
- [Modulok](#modulok)
  - [Mappa struktúra](#mappa-struktúra)
  - [Header fájlok használata](#header-fájlok-használata)
    - [CMakeLists.txt include](#cmakeliststxt-include)
  - [Header fájlok felépítése](#header-fájlok-felépítése)
- [De mégis mire jó ez?](#de-mégis-mire-jó-ez)
  - [Elkerülöd a deklaráció problémákat](#elkerülöd-a-deklaráció-problémákat)
  - [Egyszer megírod, sokszor használod](#egyszer-megírod-sokszor-használod)
  - [A program kisebb, emészthetőbb részekre bomlik szét](#a-program-kisebb-emészthetőbb-részekre-bomlik-szét)
- [Legal & License](#legal--license)

<!-- /code_chunk_output -->

## Nagy projekt, kis függvények
Ahogy nő a projekt mérete, úgy a benne lévő függvények száma is. Ezeket a
függvényeket pedig érdemes külön modulokba szétszedni. Miért? Hogy átlátható
és egyszerűen olvasható/kiegészíthető legyen a kód.

## Függvények
Ökölszabály: Egy függvény férjen el kényelmesen a kijelzőn görgetés nélkül, 
ez körülbelül 30-40 sort jelent maximum. Ha ennél hosszabb függvényeket írunk
akkor már valószínűleg vagy túl bonyolítjuk, vagy nem bontjuk szét rendesen.

### Deklaráció vs Implementáció
Egy függvénynek (C és C++ nyelveken) van külön deklarációja és implementációja.

#### Deklaráció
Azt írjuk le, hogy ez a függvény létezik, nem pedig azt hogy mit csinál.

```c
// Kiírjuk a köszönést
void hello();
```

A deklaráció fölé érdemes leírni, hogy az adott funkció mit csinál, milyen
paramétereket vár, és esetlegesen mit ad vissza. Erre a leggyakoribb és
elterjedtebb formátum a 
[Doxygen docblock](https://www.doxygen.nl/manual/docblocks.html) formátum.

```c
/**
 * Kiírja a megadott szöveget
 * @param string A kiírandó szöveg
 */
void echo(char* string);

/**
 * Megszámolja hány karakter a string
 * @param string A vizsgálandó szöveg
 * @return A szöveg hossza
 */
int strlen(char* string);
```

#### Implementáció
A válasz arra, hogy mit csinál a függvény.

```c
void hello() {
    // A saját kiíró függvénnyel köszönünk a felhasználónak
    echo("Hello, world!");
}

int strlen(char* string) {
    int length = 0;

    // Addig megyünk amíg meg nem találjuk a lezáró nullát
    while (strin[length] != '\0') {
        lenght++;
    }
    return lenght;
}
```

Itt nem írjuk le még egyszer, hogy mit csinál a kód, ide csak a sorokon belül
írunk kommenteket, hogy maga a kód érthető legyen. 

## Modulok
C-ben a **deklaráció** és az **implementáció** általában külön fájlban van:
- `.h` header fájlok: Deklaráció, dokumentáció, a programban közösen használt dolgok
- `.c` forrás fájlok: Függvények implementációja, maga a kód

*Megjegyzés: C++ nagyon hasonló, csak ott `.hpp` és `.cpp` fájlok vannak*

Egy modulba mindig csak összetartozó függvényeket érdemes kigyűjteni. Semmi
értelme a modulokra bontásnak ha utána is csak össze vissza van a kód.

### Mappa struktúra
C/C++ nyelveken nincsen semmilyen megkötés a mappa rendszerre, de ezeket a
modulokat általában az így szokás kezelni:
```
project
├── include
|   ├── szoveg.h
|   └── matek.h
├── lib
|   └── econio
|       |── econio.c
|       ├── econio.h
|       ├── LICENSE
|       └── README.md
├── src
|   ├── main.c
|   ├── szoveg.c
|   └── matek.c
├── CMakeLists.txt
├── LICENSE
├── README.md
└── ...
```

- A gyökér könyvtárban az általános, projekt szintű dolgok (dokumentáció, 
readme, licensz, makefile, IDE dolgok, stb...)
- `include` mappában a `.h` fájlok
- `lib` (library) mappában a mások által írt könyvtárak, saját mappákban
  - Ezen belül a mapa struktúra maradjon az amit a könyvtár hozott
- `src` (Source) mappában a `.c` és egyéb forrás fájlok

### Header fájlok használata
A `.h` fájlokat lehet "include"-olni a fájl elején:

```c
#include <stdio.h>
#include "matek.h"
```

A számítógépen telepített `.h` fájlokat `<file.h>` formátumban, míg csak a
projektben létező `.h` fájlokat `"file.h"` formátumban tudjuk használni.

Egy include pedig nagyon egyszerűen működik: A fordító egyszerűen bemásolja az
includeolt fájlnak a tartalmát az `#include` helyére.

#### CMakeLists.txt include
CMake használata esetén az alábbi sort kell elhelyezni a `CMakeLists.txt`
fájlban, hogy elmondjuk neki hol kell keresni a header fájlokat:

```cmake
include_directories(include)
```

Ennek hiányában a teljes elérési útvonalat ki kell írni:

```c
#include "include/matek.h"
```

### Header fájlok felépítése
Egy header fájl mindig az úgy nevezett include guard-al kezdődik és végződik:

```c
#ifndef HEADER_H
#define HEADER_H

// kód

#endif // HEADER_H
```

Az include guard-ban lévő makró mindig egyezzen meg a fájl nevével!

Ez azért kell, hogy ha több helyen van a header fájl használva, nehogy véletlen
probléma legyen abból, hogy többször definiáljuk a benne lévő dolgokat (ami 
compiler error lenne)

A preprocessor makrók értelmezve:
- `#ifndef HEADER_H` - if not defined - Ha nincsen `HEADER_H` makró definiálva
- `#define HEADER_H` - Definiáljuk a `HEADER_H` makrót
- `#endif` - jelöli, hogy meddig érvényes az if

Azaz egy mondatban: Csak akkor vedd figyelembe ezt a kódot, ha eddig még nem
láttad eddig soha, különben ugord át.

## De mégis mire jó ez?

### Elkerülöd a deklaráció problémákat
Vegyük az előző példát: `hello()` és `echo()` függvények:

```c
void hello() {
    echo("Hello, world!");
}

void echo(char* string) {
    // egy kis varázslat a szép kiíráshoz
    printf(string);
}
```

Ez nem fordulna le csak így, hiszen az `echo()` függvényt hamarabb hívjuk meg,
mint hogy leírtuk volna mit csinál. Ez elkerülhető, ha a fájl tetejére oda
írjuk a deklarációt (hiszen az include is ugyan ezt csinálná), de mi van akkor
ha sok más helyen is kell nekünk az `echo` függvény és nem csak itt? Hamar
káosz tud ebből lenni...

### Egyszer megírod, sokszor használod
Gondolj a jól ismert egyszerű C függvényekre: `printf`, `scanf`

Ha egyszer megírod (vagy te, vagy valaki más) és a gépen telepíted, egy darab
`#include`-al nagyon sok munkát meg lehet spórolni.

### A program kisebb, emészthetőbb részekre bomlik szét
Egy fájlban az összetartozó dolgok vannak: matematikai függvények, szöveg
kezelés, bemenet/kimenet megvalósítása, stb...

Ha rendesen szét van szedve a program, a `main.c` könnyen leegyszerűsíthető
néhány sor kódra ahol beszédes nevű függvények dolgoznak, amiket könnyen meg
is tudunk keresni.

## Legal & License
Készítette: Török Zsombor, 2024. október 3.

Ez a feladat és segád anyag nem hivatalos, egy hivatalos labor kiegészítésének
készült.

Elérhető a Creative Commons Nevezd meg! - Ne add el! - Így add tovább! 4.0
([CC-BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.hu))
Nemzetközi Licensz alapján.