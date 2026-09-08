# Decimális összeadó

A feladat az első gyakorlat harmadik feladatának egy nehezített változata.

Implementáljunk két szám írásbeli összeadását egy speciális számítógépen: ez a számítógép csak 0-9 közötti számokat tud kezelni, ezért a számok összeadásánál nemcsak arra kell figyelni, hogy a helyiértékeket megfelelően kezeljük, hanem arra is, hogy a maradékokat hogyan kezeljük.

A feladathoz kiindulásként elérhető egy egyszerű C nyelven írt keretrendszer:
- `X` és `Y` bemeneti regiszterek
- az `add()` parancs, ami összeadja a regiszterek értékét, és beállítja a kimeneti értékeket
- `C` (carry) és `Z` (zero) flag-ek (jelzők), valamint az `E` (eredmény) regiszter
- a `write()` parancs, amellyel a kimenet elmenthető
- az `a()` és `b()` segédfüggvények a helyiérték alapú indexeléshez

A feladat során a keretrendszer segítségével (és annak bármilyen módosítása nélkül) kell megvalósítani az összeadás műveletét úgy, hogy az működjön két tetszőleges számra 1-9999 között.
