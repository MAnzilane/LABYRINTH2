//
//  Character.h
//  Character
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.

#include "Character.h"

Character * createCharac(Object * obj, char *name) {
    Character * charac = malloc(sizeof(Character));
    if (charac == NULL) {
        fprintf(stderr, "error malloc\n");
        exit(MALOCERRO);
    }
    charac->name = malloc(sizeof(char)*(strlen(name)+1));
    if (charac->name == NULL) {
        fprintf(stderr, "error malloc\n");
        exit(MALOCERRO);
    }
    strcpy(charac->name, name);
    assert(obj);
    charac->obj = obj;
    charac->life = NBLIFE;
    return charac;
}

char * getNameCharac(const Character * charac) {
    assert(charac);
    return charac->name;
}

Character * setLifeCharac(Character * charac, int life) {
    assert(charac);
    charac->life = life;
    return charac;
}

int getLifeCharac(const Character * charac) {
    assert(charac);
    return charac->life;
}

Object * getObjCharac(const Character * charac) {
    assert(charac);
    return charac->obj;
}

void destroyCharac(Character * charac) {
    assert(charac);
    free(charac);
    charac = NULL;
}

void printCharac(const Character * charac) {
    assert(charac);
    printf("name of Character %s\n", getNameCharac(charac));
    printf("information of charac \n");
    printObj(charac->obj);

    printf("\nremaning life %d ", getLifeCharac(charac));
}

void testCharac() {
    /* initialisation */
    int x = 3; int y = 0; int w = 10; int h = 15; Type typeObj = MOBILE;
    Coordinates * coord = createCoord(x, y);

    Box * box = createBox(coord, w, h);

    Object * obj = createObj(box, typeObj, EMPTY);

    Character * charac  = createCharac(obj, "Anzilane");

    printCharac(charac);

    destroyCharac(charac);
    destroyObj(obj);
    destroyBox(box);
    destroyCoord(coord);
}
