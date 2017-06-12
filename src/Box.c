//
//  Box
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//
#include "Box.h"

Box * createBox(Coordinates * coord, int w, int h) {
    assert(coord);
    Box * box = malloc(sizeof(Box));
    if (box == NULL) {
        fprintf(stderr, "error malloc\n");
        exit(MALOCERRO);
    }
    box->position = coord;
    box->w = w;
    box->h = h;
    return box;
}

Coordinates * getPositionBox(const Box *box) {
    assert(box);
    return box->position;
}

int getHBox(const Box * box) {
    assert(box);
    return box->h;
}

int getWBox(const Box * box) {
    assert(box);
    return box->w;
}

void destroyBox(Box * box) {
    assert(box);
    free(box);
    box = NULL;
}

void testBox() {
    /* initialisation */
    int x = 5;
    int y = 3;
    int w = 20;
    int h = 20;
    Coordinates *coord = createCoord(x, y);

    Box * box = createBox(coord, w, h);
    printf("h = %d\nw = %d\n",getHBox(box), getWBox(box));
    printf("coordx = %d\ncoordy = %d", getXCoord(getPositionBox(box)),
                                       getYCoord(getPositionBox(box)));

    destroyCoord(coord);
    destroyBox(box);
}
