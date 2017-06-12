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
        coord = createCoord(calcCoordX(i, w), calcCoordY(i, h));
        //contains obj
        box = createBox(coord, SIZEBOX, SIZEBOX);
        //create a new obj
        wldGame->obj[i] = createObj(box, FIXED, typeOfDesign[j]);
        // printf("%d\n", typeOfDesign[i+2]);
        //printObj(wldGame->obj[i-2]);
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

int * typeOfDesignFromFile(char * filname) {
    FILE * file = NULL;
    if ((file = fopen(filname, "r")) == NULL) {
        fprintf(stderr, "error open fic \n");
        exit(ERROACCESSFILE);
    }

    int w = 0; int h = 0;

    fscanf(file, "%d", &w);
    fscanf(file, "%d", &h);
    int val = 0; int i = 2; int cpt = 0;
    int *typeOfDesign = malloc(sizeof(int)*(w*h+3));
    if (typeOfDesign == NULL) {
        fprintf(stderr, "error malloc\n");
        exit(MALOCERRO);
    }
    typeOfDesign[0] = w; typeOfDesign[1] = h;
    while (!feof(file)) {
        fscanf(file,"%d", &val);
        if (val != 32 || val != 13) {
            typeOfDesign[i++] = val;
            // printf("%d \n",typeOfDesign[i-1]);
        }
    }
    assert(file);
    fclose(file);
    file = NULL;
    return typeOfDesign;
}

void printWldGame(const WorldGame * wldGame) {
    for (size_t i = 0; i < getSizeWldGame(wldGame); i++) {
        printObj(wldGame->obj[i]);
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


int testWorldGame() {
    int * typeOfDesign = typeOfDesignFromFile("/home/manzilane/Documents/Labyrith2/LABYRINTH2/data/niveauTest.txt");
    WorldGame * wldGame = createWldGame(typeOfDesign);
    printWldGame(wldGame);
    destroyWldGame(wldGame);
    free (typeOfDesign);
}
