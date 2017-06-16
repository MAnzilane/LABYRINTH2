//
//  Trap.c
//  Trap
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#include "Trap.h"

Trap * createTrap(Object * obj, Type typeTrap) {
    assert(obj);
    Trap * trap = malloc(sizeof(Trap));
    if (trap == NULL) {
        fprintf(stderr, "error malloc\n");
        exit(MALOCERRO);
    }
    trap->obj = obj;
    trap->typeTrap = typeTrap;
    trap->condition = INACTIVE;
    return trap;
}

Trap * setConditionTrap(Trap * trap, Type cond) {
    assert(trap);
    trap->condition = cond;
    return trap;
}

Object * getObjTrap(const Trap * trap) {
    assert(trap);
    return trap->obj;
}

Type getTypTrap(const Trap * trap) {
    assert(trap);
    return trap->typeTrap;
}

Type getCondTrap(const Trap * trap) {
    assert(trap);
    return trap->condition;
}

DesignType getTypeOfTrap(const Trap * trap) {
    return getTypeOfObj(getObjTrap(trap));
}

void destroyTrap(Trap * trap) {
    assert(trap);
    free(trap);
    trap = NULL;
}

void printTrap(const Trap * trap) {
    printf("Object = trap\n");
    printObj(getObjTrap(trap));
    printf("\ncondition of trap %d\n", getCondTrap(trap));
    printf("type of trap MOBILE or FIXED %d\n", getTypTrap(trap));
}

void testTrap() {
    /* initialisation */
    int x = 3; int y = 0; int w = 10; int h = 15; Type typeObj = TRAP;
    Type typeTrap = MOBILE;
    Coordinates * coord = createCoord(x, y);

    Box * box = createBox(coord, w, h);

    Object * obj = createObj(box, typeObj, TRAP1);

    Trap * trap = createTrap(obj, typeTrap);
    printf("\ntype of trap %d\n", getTypeOfTrap(trap));
    printTrap(trap);
    setConditionTrap(trap, ACTIVE);
    printf("trap active\n");
    printTrap(trap);

    destroyTrap(trap);
    destroyObj(obj);
    destroyBox(box);
    destroyCoord(coord);
}
