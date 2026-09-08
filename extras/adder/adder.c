#include <stdio.h>
#include <assert.h>


int x = 0; //!< X regiszter
int y = 0; //!< Y regiszter
int c = 0; //!< C (carry) flag
int e = 0; //!< E (eredmény) regiszter

int z = 0; //!< Z (zero) flag

// Bemeneti tömbök
const int inp_a[] = {0, 1, 0, 7, 8, 9};
const int inp_b[] = {0, 0, 0, 4, 5, 6};
// Bemenet mérete
const int size = 6; 

// Kimenet (legalább bemenet méretű + 1)
int out[7] = { 0, 0, 0, 0, 0, 0 }; 
int out_i = 5;

// Összeadás parancs
void add() {
    assert(x >= 0 && x <= 9);
    assert(y >= 0 && y <= 9);
    c = (x + y) / 10;
    e = (x + y) % 10;

    z = (c == 0) && (e == 0);
}

// A bemeneti szám lekérése helyiérték indexeléssel
int a(int idx) {
    assert("OVERFLOW" && idx >= 0 && size >= idx);
    return inp_a[size - idx - 1];
}

// B bemeneti szám lekérése helyiérték indexeléssel
int b(int idx) {
    assert("OVERFLOW" && idx >= 0 && size >= idx);
    return inp_b[size - idx - 1];
}

// Eredmény elmentése
void write(int n) {
    assert("UNDERFLOW" && out_i >= 0);
    out[out_i] = n;
    out_i--;
}

int main() { 
    // Példa a használatra, egyesek helyiértékével
    int i = 0;

    x = a(i);
    y = b(i);
    add();
    write(e);
    
    // TODO

    // Eredmény kiírása
    for (int i = 0; i < size; i++) 
        printf("%d", out[i]);
    printf("\n");
    return 0;
}
