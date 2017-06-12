//
//  Box.h
//  Box
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef Box_h
#define Box_h
#include "Constant.h"
#include "Coordinates.h"
/** \brief this structure contans the game's object
@param postion : the box position
@param w : width of box
@param h : height of box
*/
typedef struct sBox {
    Coordinates *position;
    int w;
    int h;
}Box;

/**\brief constructor of box
@param coord : position of box
@param w : width of box
@param h : heigth of box
@return Box
*/
Box * createBox(Coordinates * coord, int w, int h);

/**\brief to have Coordinates of box
@param box : box of work
*/
Coordinates * getPositionBox(const Box *box);

/**\brief to weigth of box
@param box : box of work
*/
int getHBox(const Box * box);

/**\brief to have width of box
@param box : box of work
*/
int getWBox(const Box * box);

/**\brief free box
@param box
*/
void destroyBox(Box * box);


void testBox();
#endif /* Box_h */
