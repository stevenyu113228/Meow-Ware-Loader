#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr;
    char *sc;
    char *sc_meow;

    fptr = fopen("src.txt","r");
    fseek(fptr,0,SEEK_END);
    int size = ftell(fptr);
    fseek(fptr,0,SEEK_SET);

    sc = (char *)malloc(size);
    fscanf(fptr,"%s", sc);
    sc_meow = (char *)malloc(size*4 +1);

    int j = 0;
    for (int i = 0; i < size; i++){
        switch (sc[i]){
        case '0':
            strcpy(sc_meow + j, "meow");
            break;
        case '1':
            strcpy(sc_meow + j, "meoW");
            break;
        case '2':
            strcpy(sc_meow + j, "meOw");
            break;
        case '3':
            strcpy(sc_meow + j, "meOW");
            break;
        case '4':
            strcpy(sc_meow + j, "mEow");
            break;
        case '5':
            strcpy(sc_meow + j, "mEoW");
            break;
        case '6':
            strcpy(sc_meow + j, "mEOw");
            break;
        case '7':
            strcpy(sc_meow + j, "mEOW");
            break;
        case '8':
            strcpy(sc_meow + j, "Meow");
            break;
        case '9':
            strcpy(sc_meow + j, "MeoW");
            break;
        case 'a':
            strcpy(sc_meow + j, "MeOw");
            break;
        case 'b':
            strcpy(sc_meow + j, "MeOW");
            break;
        case 'c':
            strcpy(sc_meow + j, "MEow");
            break;
        case 'd':
            strcpy(sc_meow + j, "MEoW");
            break;
        case 'e':
            strcpy(sc_meow + j, "MEOw");
            break;
        case 'f':
            strcpy(sc_meow + j, "MEOW");
            break;
        }
        j += 4;
    }
    sc_meow[j-4+1]=0;

    printf("%s", sc_meow);

}