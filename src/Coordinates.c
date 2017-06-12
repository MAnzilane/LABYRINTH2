//
//  Coordinates.h
//  coordinates
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#include "Coordinates.h"


Coordinates *initCoord() {
    Coordinates * coord = malloc(sizeof(coord));
    if (coord == NULL) {
        fprintf(stderr, "error malloc \n");
        exit(MALOCERRO);
    }
    return coord;
}

Coordinates *createCoord(int x, int y) {
    Coordinates *coord = initCoord();
    coord->x = x;
    coord->y = y;
    return coord;
}

int getXCoord(const Coordinates *coord) {
    assert (coord != NULL);
    return coord->x;
}

int getYCoord(const Coordinates *coord) {
    assert(coord != NULL);
    return coord->y;
}

int calcCoordX(int pos, int w) {
    return pos%w;
}

int calcCoordY(int pos, int h) {
    return pos/h;
}


void destroyCoord(Coordinates * coord) {
    assert(coord != NULL);
    free(coord);
    coord = NULL;
}

int testCoodintes() {
    //initialisation
    int x = 2;
    int y = 1;
    Coordinates *coord = NULL;

    coord = createCoord(x, y);

    printf("coord x  = %d\n coord y = %d\n", getXCoord(coord), getYCoord(coord));

    destroyCoord(coord);

    printf("coord x  = %d\n coord y = %d\n", getXCoord(coord), getYCoord(coord));

    printf("test assert int getXCoord getYCoord \n");
    destroyCoord(coord);

}
