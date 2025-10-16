---
theme: gaia
_class: lead
backgroundColor: #fff
backgroundImage: url('https://marp.app/assets/hero-background.svg')
marp: true


style: |
  section.qr {
    display: flex;
    flex-direction: column;
    justify-content: center;
    text-align: center;
    font-size: 50px;
  }
  section.big { font-size: 90px; }
  p.small { font-size: 30px; }
---

# **Prog 1 ZH1 konzi**

VIEEAA00 - 2025 
Török Zsombor

https://go.zsotroav.dev/konzi

---

## ZH Információk

- **JELENTKEZNI KELL INFOC-N**
  - iMSc feladat: 70% felett javítva, extra pont
- 2025-10-21 - 18:00
- Terembeosztás InfoC-n

## Anyag:
- Pointerek, Stringekig bezárólag minden
- Rendezés már nem

---

## ZH Menete

- Három feladat: 10+10+20 pont, 90 perc
  - Első két feladat kis ZH jellegű és méretű
  - Harmadik feladat nagyobb, összetettebb
- **PAPÍR ALAPÚ!**
  - Ceruzával lehet, sőt ajánlott írni! (_Puha ceruza + radír_)
  - Olvashatóan, javító értse meg mi van leírva!

**Arcképes igazolvány mindenkinél legyen!**

---

## Segédeszközök

ZH-n csak a hivatalos [C puska](https://infoc.eet.bme.hu/jegyzet/) használható, nyomtatott formában.

Asztalon csak a szükséges dolgok legyenek;
Csalás, puskázás, mobilozás **instant bukás!**

Pótlap nincs, minden férjen a ZH papírra! 
Nem lesz idő átmásolni ha saját lapra írod!

---

## Általános tanácsok

- Gyakorolj sokat!
  - Autocomplete sokat segít, de attól nem fogod megérteni
- Olvassuk végig, értsük meg a feladatot mielőtt elkezdjük!
  - Gyakran vannak tippek a megfogalmazásban, feladat végén.
  - Legyen nagyvonalú terv mielőtt elkezdünk kódot írni.
  - Gondold végig, akár rajzold/írd le az algoritmus működését

---

## Feladatot oldjuk meg

```c
// Írj programot
#include <stdio.h>

int main(void) {
    //...
}

// Írj függvényt
bool prim_e(int p) {
    // Írj kódrészletet
    int oszto = 2;

    while (p > 0) 
    //...
}
```

---

## Hiba keresés

Két nagy hiba és egy kicsi hiba van ebben a kódban:

```c
// Eldönti prím szám-e a p paraméter
bool prim(int p) {
    int osztok, n = 2;
    while (p >= n) {
        if (p % n == 0) osztok++;
        n++;
    }

    return (osztok == 1);
}
```

---

## Hiba 1: Kezdeti érték

Változóban "memória szemét" lesz ha nem adunk meg neki értéket
```c
// Eldönti prím szám-e a p paraméter
bool prim(int p) {
    int osztok = 0, n = 2;
    while (p >= n) {
        if (p % n == 0) osztok++;
        n++;
    }

    return (osztok == 1);
}
```

---

## Hiba 2: Eldöntés, nem megsznámolás

Eldöntés a feladat, fölösleges megszámlálást végezni

```c
// Eldönti prím szám-e a p paraméter
bool prim(int p) {
    int n = 2;
    while (p >= n) {
        if (p % n == 0) return false;
        n++;
    }

    // A program minden ágon térjen vissza
    return true;
}
```

---

## Javítás: A helyes ciklus féle

Két határérték között megyünk ciklussal, erre lett kitalálva a for

```c
// Eldönti prím szám-e a p paraméter
bool prim(int p) {

    for (int i = 2; p >= i; i++) {
        if (p % i == 0) return false;
    }

    return true;
}
```

---

## Elvi hibák: Instant -5 pont

Lásd: [InfoC Követelmények](https://infoc.eet.bme.hu/kovetelmenyek/#8)

- A: Sorminta
- B: Return helyett I/O
- C: Tömb és pointer keverése
- D: Adatszerkezetek (tömb/lista/bin.fa) keverése
- E: Pointer, mint fura lokális változó
- F: Bitműveletek és lebegőpontos aritmetika

---
## Feladat: Armstrong-számok
Készíts programot, mely Armstrong-számokat keres 10-10000 között, és a találatkat megjeleníti a képernyőn! N-jegyű Armstrong számoknak nevezzük azokat a számokat, melyek számjegyei N-dik hatványainak összege éppen a számot adja. Például: egy négyjegyű Armstrong-szám a 1634, mivel: 1634=1⁴+6⁴+3⁴+4⁴.

Valósítsd meg a szükséges alprogramokat, élj a top-down tervezési móddal!

<p class="small">
Pl. Írj függvényt, amely megmondja egy számról, hogy hány számjegyű, stb.!
Olyan függvényt is írj, amely hatványozást végez egész számokon, mert nincs ilyen a könyvtárban!
</p>

---
## Feladat: Bankautómata II.
Pénzvisszaadós automatába kell egy olyan programrészt írnunk, amelyik a visszajárót számolja ki. Azonban az automata rekeszei végesek, tárold el azt is, hogy melyik bankjegyből és érméből épp mennyi van! 

Írj programot mohó algoritmussal, amely egy adott pénzösszegről kiírja, hogy hogyan lehet azt a legkevesebb papírdarabbal és fémkoronggal kiadni, miközben ezt figyelembe veszi!

---
<!-- _class: lead big --> 
## **Kérdések**
---
## Konzisite
<!-- _class: qr -->
![Konzi](./konzi.png)
