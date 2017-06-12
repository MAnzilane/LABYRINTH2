//
//  Object.c
//  Object
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#include "Object.h"

Object * initObj() {
    Object * obj = malloc(sizeof(Object)); //malloc
    if (obj == NULL) {
        fprintf(stderr, "errro malloc\n");
        exit(MALOCERRO);
    }
    return obj;
}

Object * createObj(Box *box, Type typeObj, DesignType typeOfObj) {
    Object * obj = initObj();
    assert(box);
    obj->box = box;
    obj->typeOfObj = typeOfObj;
    obj->typeObj = typeObj;
    return obj;
}

Type getTypeObj(const Object * obj) {
    assert(obj);
    return obj->typeObj;
}

Box * getBoxObj(const Object * obj) {
    assert(obj);
    return obj->box;
}

int getTypeOfObj(const Object * obj) {
    return obj->typeOfObj;
}

void destroyObj(Object *obj) {
    assert(obj);
    free(obj);
    obj = NULL;
}

void printObj(const Object *obj){
    assert(obj);
    printf("discribe obj = %d\n", getTypeObj(obj));
    printf("type of obj = %d\n", getTypeOfObj(obj));
    printf("dimension of Object \n");
    printf("h = %d  w = %d\n",getHBox(getBoxObj(obj)), getWBox(getBoxObj(obj)));
    printf("position of object\n");
    printf("coordx = %d\n", getXCoord(getPositionBox(getBoxObj(obj))));
    printf("coordy = %d\n", getYCoord(getPositionBox(getBoxObj(obj))));
}

void testObj() {
    /* initialisation */
    int x = 3; int y = 0; int w = 10; int h = 15; Type typeObj = FIXED;
    Coordinates * coord = createCoord(x, y);

    Box * box = createBox(coord, w, h);

    Object * obj = createObj(box, typeObj, EMPTY);

    printObj(obj);

    destroyObj(obj);
    destroyBox(box);
    destroyCoord(coord);
}
