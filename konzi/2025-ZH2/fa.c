#include <stdlib.h>

typedef struct fa  {
    int i;

    // Bármi egyéb adat amit tárolnánk

    struct fa *bal, *jobb; // <- Csak emiatt lesz fa a fa
} fa;

fa* beszur(fa* gyoker, int elem) {
    if (gyoker == NULL) {
        gyoker = malloc(sizeof(fa));
        gyoker->bal = NULL;
        gyoker->jobb = NULL;
        gyoker->i = elem;
        return gyoker;
    }

    if (gyoker->i < elem) gyoker->jobb = beszur(gyoker->jobb, elem);
    if (gyoker->i > elem) gyoker->bal = beszur(gyoker->bal, elem);

    return gyoker;
}

fa* keres(fa* gyoker, int elem) {
    if (gyoker == NULL) return NULL;
    if (gyoker->i == elem) return gyoker;
    
    if (gyoker->i < elem) return keres(gyoker->jobb, elem);
    if (gyoker->i > elem) return keres(gyoker->bal, elem);
}

void felszabadit(fa* gyoker) {
    if (gyoker == NULL) return; // Leállási feltétel
    
    felszabadit(gyoker->bal);
    felszabadit(gyoker->jobb);
    free(gyoker); 
}

