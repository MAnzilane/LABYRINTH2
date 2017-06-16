#include "WorldGame.h"
#include <stdio.h>

WorldGame * initWldGame(int w, int h) {
    WorldGame * wldGame = malloc(sizeof(WorldGame));
    wldGame->obj = malloc(sizeof(Object*)*(w*h));
    wldGame->w = w;
    wldGame->h = h;
    return wldGame;
}

WorldGame * createWldGame(int * typeOfDesign) {
    int w = typeOfDesign[0];
    int h = typeOfDesign[1];
    int j = 2;
    WorldGame * wldGame = initWldGame(w, h);
    Coordinates *coord = NULL;
    Box * box = NULL;
    for (size_t i = 0; i < getSizeWldGame(wldGame); i++) {
        //position of obj
        coord = createCoord(calcCoordX(i, w), calcCoordY(i, w));
        // printf("x  = %d   y = %d\n", calcCoordX(i, w), calcCoordY(i, w));
        //contains obj
        box = createBox(coord, WBOX, HBOX);
        //create a new obj
        wldGame->obj[i] = createObj(box, FIXED, typeOfDesign[j++]);
    }
    return wldGame;
}


int getHWldGame(const WorldGame * wldGame) {
    return wldGame->h;
}

int getWWldGame(const WorldGame * wldGame) {
    return wldGame->w;
}

int getSizeWldGame(const WorldGame * wldGame) {
    return (getHWldGame(wldGame)*getWWldGame(wldGame));
}

int * typeOfDesignFromFile(FILE * file) {

    int w = 0; int h = 0;
    fscanf(file, "%d %d", &w, &h);
    // printf("w = %d, h = %d\n", w, h);
    // fscanf(file, "%d", &h);
    int val = 0; int i = 2; int cpt = 0;
    int *typeOfDesign = malloc(sizeof(int)*(w*h+3));
    if (typeOfDesign == NULL) {
        fprintf(stderr, "error malloc\n");
        exit(MALOCERRO);
    }
    typeOfDesign[0] = w; typeOfDesign[1] = h;
    int j = 0;
    while (j < w*h) {
        fscanf(file,"%d", &val);
        if (val != 32 || val != 13) {
            typeOfDesign[i++] = val;
            // printf("%d\n", val);
            j++;
        }
    }
    return typeOfDesign;
}

void printWldGame(const WorldGame * wldGame) {
    for (size_t i = 0; i < getSizeWldGame(wldGame); i++) {
        printObj(wldGame->obj[i]);
        // printf("%d\n", getTypeOfObj(wldGame->obj[i]));
    }
}

void destroyWldGame(WorldGame * wldGame) {
    for (size_t i = 0; i < getSizeWldGame(wldGame); i++) {
        destroyCoord(getPositionBox(getBoxObj(wldGame->obj[i])));
        destroyBox(getBoxObj(wldGame->obj[i]));
        destroyObj(wldGame->obj[i]);
    }
    free(wldGame->obj);
    free (wldGame);
    wldGame = NULL;
}


int testWorldGame(char * filname) {
    FILE * file = NULL;
    char buf0[30];
    char buf1[30];
    if ((file = fopen(filname, "r")) == NULL) {
        fprintf(stderr, "error open fic \n");
        exit(ERROACCESSFILE);
    }
    int * typeOfDesign;
    int ok = 1;
    do {
        fscanf(file, "%s", buf0);
        if (strcmp(buf0, "#level") == 0) {
            printf("je rentre la \n");
            typeOfDesign = typeOfDesignFromFile(file);
            // printf("%s\n", buf0);
        }
        printf("%s\n", buf0);
        if (strcmp(buf0, "#endlevel") == 0) {
            ok = 0;
        }
    } while(ok);
    printf("je sort de la boucle et %d \n", typeOfDesign[0]);
    WorldGame * wldGame = createWldGame(typeOfDesign);
    printWldGame(wldGame);
    destroyWldGame(wldGame);
    free (typeOfDesign);
    fclose(file);
}
