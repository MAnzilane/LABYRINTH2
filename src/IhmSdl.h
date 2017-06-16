//
//  IhmSdl.h
//  IhmSdl
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef IhmSdl_h
#define IhmSdl_h

#include "Constant.h"
#include "WorldGame.h"

// /**\brief
// @param r :
// @param solid
// */
typedef struct sTileProp {
    SDL_Rect rect;
    int solid;
    //we can add, what we want
}TileProp;

typedef struct sIhmSdl {
	TileProp* clip;
	int xScroll,yScroll;
	WorldGame * wldGame;
    SDL_Surface * tilset;
    SDL_Surface * screen;
    int wWindScroll;
    int hWindScroll;
}IhmSdl;


IhmSdl * CreateISdl(char * level);

FILE * openFilename(char * filname);

SDL_Surface * initScreenISdl(int w, int h);

IhmSdl * initISdl();


/**\brief
@param tilset
@return clip
*/
TileProp * cuttingISdl(SDL_Surface * tilset, FILE * file);

/**\brief to blit surface with precision
@param x :
@param y :
@param src :
@param dest :
@param clip
*/
void applayISdl(int x, int y, SDL_Surface * src, SDL_Surface * dest, SDL_Rect * clip);

void eventment();

void destroyDis(int ** dis, int size);
int ** DesignISdl(const IhmSdl * ihmSdl);

void printISdl(IhmSdl * ihmSdl);

void destroyISdl(IhmSdl * ihmSdl);

void destroyClipISdl(TileProp * clip);

#endif /* IhmSdl_h */
