//
//  Coordinates.h
//  coordinates
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef Coordinates_h
#define Coordinates_h
#include "Constant.h"

/**\brief struct game of Coordinates
@param x coord x
@param y coord y
*/
typedef struct sCoordinates {
    int x;
    int y;
}Coordinates;

/* constructor */
/**\brief init Coordinates
@return Coordinates
*/
Coordinates *initCoord();


/**\brief init Coordinates
@return Coordinates
@param x : point x
@param y : point y
*/
Coordinates *createCoord(int x, int y);

/* get fonction */
/**\brief
@return coord x;
@param const coord : use to get x coord
*/
int getXCoord(const Coordinates *coord);

/* get fonction */
/**\brief
@return coord y;
@param const coord : use to get y coord
*/
int getYCoord(const Coordinates *coord);

/**\brief
@param pos
@param w
@return coordX
*/
int calcCoordX(int pos, int w);

/**\brief
@param pos
@param h
@return coordY
*/
int calcCoordY(int pos, int h);

/**\brief free coordinate
@param coord : to free
*/
void destroyCoord(Coordinates * coord);

/**\brief module test
@return the test observation
*/
int testCoodintes();

#endif /* Coordinates */
