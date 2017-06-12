//
//  WorldGame.h
//  WorldGame
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef WorldGame_h
#define WorldGame_h

#include "Constant.h"
#include "Object.h"
/**\brief the structure world game
@param w : width of WorldGame
@param h : height of WorldGame
@param box : box table to build WorldGame*/
typedef struct sWorldGame {
    int w;
    int h;
    Object ** obj;
}WorldGame;

/**\brief
@param w :
@param h :
@return WorldGame
*/
WorldGame * initWldGame(int w, int h);

/**\brief
@param wldGame : // a voir
@param typeOfDesign :
@return WorldGame
*/
WorldGame * createWldGame(int * typeOfDesign);

/**\brief
@param wldGame
@return heigth of world
*/
int getHWldGame(const WorldGame * wldGame);

/**\brief
@param wldGame
@return width of world
*/
int getWWldGame(const WorldGame * wldGame);

/**\brief
@param wldGame
@return size of world
*/
int getSizeWldGame(const WorldGame * wldGame);

int * typeOfDesignFromFile(char * filname);

void printWldGame(const WorldGame * wldGame);

/**\brief
@param wldGame
*/
void destroyWldGame(WorldGame * wldGame);

int testWorldGame();
#endif /* WorldGame_h */
