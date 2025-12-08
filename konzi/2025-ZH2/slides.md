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

VIEEAA00/VIHIAA01 - 2025 
Török Zsombor

https://go.zsotroav.dev/konzi

---

## ZH Információk

Mérnökinfósok:
- **JELENTKEZNI KELLETT INFOC-N**
  - iMSc feladat: 70% felett javítva, extra pont
- 2025-10-21 - 18:00
- Terembeosztás InfoC-n

## Anyag:
- **MINDEN** ami a félévben elhangzott - infó és villany is!

---

## ZH Menete

- Három feladat: összesen 40 pont, 90 perc
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

## Elvi hibák: Instant -5 pont

Lásd: [InfoC Követelmények](https://infoc.eet.bme.hu/kovetelmenyek/#8)

- A: Sorminta
- B: Return helyett I/O
- C: Tömb és pointer keverése
- D: Adatszerkezetek (tömb/lista/bin.fa) keverése
- E: Pointer, mint fura lokális változó
- F: Bitműveletek és lebegőpontos aritmetika

---

## Gyakori hibák :: \0

- `\0` nem univerzális lezáró karakter, csak a C stringeknél jó!

```c

char* str = "almafa";
int arr[] = {0, 1, 2, 3, 4};

for (int i = 0; str[i] != '\0'; i++) {
    // jó, mert string
}

for (int i = 0; arr[i] != '\0'; i++) {
    // rossz, mert nem string
}

```

---

## Tanácsok

- Olvasd VÉGIG és ÉRTSD MEG a feladatot mielőtt elkezded!
- Tervezd meg nagyvonalakban a megoldást a fejedben!
  - Először tudd magyarul elmondani mit csinál a program
- Bontsd le kisebb részekre a feladatot!
  - Nem kell túlkomplikálni egy nagy ciklussal, ha több kis ciklussal is megoldható
- Nem a hatékonyság a cél!
- Rajzolj a listáknál, fáknál, állapotgépeknél!

---

## Gyakori hibák :: Szintaktika

```c
int tomb[] = {1, 2, 3, 4, 5}  // hiányzik a pontosvessző
int tomb[] = {1; 2; 3; 4; 5}; // rossz elválasztójelek
int tomb[5] = {1, 2, 3, 4, 5, 6}; // túl sok/kevés elem a tömbben

char c = 'AB'; // csak egy karakter lehet aposztróf (') között
char c = "A"; // dupla idézőjel (") stringet csinál: A és utána \0

char ki[]; // dangling pointer -- hova mutat?

```

---

## Gyakori hibák :: ChatGPT azt mondta jó

A sizeof-os ""trükköt"" nem szeretnénk látni!

Csak akkor működik ha közvetlen a tömb létrejötte mellett használjuk, ugyan abban a függvényben!

```c
void func(int arr[]) {
    sizeof(arr); // = sizeof(int*) = 8 (64 biten)
    sizeof(int); // = 4 a legtöbb rendszeren

    int length = sizeof(arr) / sizeof(int); // = 2 (rossz!)
}
```

---

## Gyakori hibák :: struct a láncolt listában

Láncolt listánál, bináris fánál a struct-on belül a pointer típusát helyesen kell megadni!

```c
typedef struct Pont {
    int x;
    int y;
    struct Pont* kov; // helyes
    Pont* kov; // hibás: 'Pont' nem létrehozott típus még
} Pont;
```

mivel a `typedef ... Pont;` után jön létre a `Pont` típusnév.

---

## Gyakori hibák :: Ha malloc akkor free is kell!

- Mindig szabadítsuk fel a lefoglalt memóriát!

```c
// valami fv ami malloc-olt ad vissza
return (int*)malloc(10 * sizeof(int));

int main() {
    int* p = valami();
    if (p != NULL) { // Hibakezelés legyen!
        // használjuk p-t
        free(p);
    }
    // p már nem használható
}
```

---

## Gyakori hibák :: Use after free

- Ne használjunk felszabadított memóriát!

```c
Lista* eleje = ...;

for (Lista* mozgo = eleje; mozgo != NULL; ) {
    Lista* kov = mozgo->kov; // mentsük el a következőt
    free(mozgo);
    mozgo = kov;
}
```

Lista felszabadításnál a `mozgo = mozgo->kov;` hibás, mert a `mozgo` már felszabadított memória.

---

## Gyakori hibák :: NULL félelem

Ne féljünk (indokolatlanul) a NULL pointertől!


```c
Lista* eleje = ...;

for (Lista* mozgo = eleje; mozgo->kov != NULL; mozgo = mozgo->kov) {
    // csinálunk valamit a mozgo-val
}
```

Az utolsó elemet nem dolgozza fel, mert fél, hogy NULL lesz a mozgo.

---

## Emlékezzünk: Rekurzió kilépési feltétel

Rekurzív függvény esetén mindig az első dolog a kilépési feltétel ellenőrzése!

```c
int fakt(int n) {
    if (n == 0) return 1; // kilépési feltétel
    return n * fakt(n - 1); // rekurzív hívás
}
```

---

<!-- _class: lead big --> 
## **Kérdések**
---
## Konzisite
<!-- _class: qr -->
![Konzi](./konzi.png)

Értékeld a konzit ha tetszett: 
https://konzi.vik.hk/consultations/174

---
## Promo
<!-- _class: qr --> 

Második félév elején lesz gólyakörte, gyertek mindenképpen!

KSZK szívesen vár mindenkit képzésre ha érdekelnek a hálózat, szerverek, kiberbiztonság, vagy a fejlesztés: https://ujonc.kszk.bme.hu
