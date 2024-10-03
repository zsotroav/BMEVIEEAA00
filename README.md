# BMEVIEEAA00 aka prog1
- Budapesti Műszaki Egyetem (BME) 
- Villamosmérnöki és Informatikai kar (VIK)
- Elektronikus Esztközök Tanszéke (EET)
- A programozás Alapjai 1 tantárgy

Itt különböző hivatalos és nem hivatalos segéd- és tananyagokat gyűjtöttünk
össze a tanulás segítése érdekében.

## Egyéb segéd anyagok
- [Hivatalos tárgyhonlap](https://infoc.eet.bme.hu)
  - [Hivatalos puska NZH-ra](https://infoc.eet.bme.hu/jegyzet/c_puska.pdf)
  - [Debugmalloc]
  - [econio library](https://infoc.eet.bme.hu/megjelenites/c-econio.zip) 
([mirror](https://github.com/zsotroav/zsotroav/tree/main/LIB/C/econio))

## Ajánlott fejlesztő környezet: CLion
Hallgatók számára ingyenesen igényelhető sok mással együtt: 
[JetBrains](https://www.jetbrains.com/shop/eform/students)

## Compiler flags
`-Wall`, `-Wextra`, `-Wpedantic` :: Különböző warning szintek, -Wall 
bekapcsolása a házihoz és szorgalmikhoz kötelező, a többit átnézni 
végleges beadás előtt ajánlott.

`-Werror` :: Minden warning (amivel még lefutna a kód) hibának kezelése és
ezzel a futtatás megakadályozása.

### Compile flagek CMakeLists.txt -ben
```cmake
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
```