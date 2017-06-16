//
//  EventSdl.h
//  EventSdl
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef EventSdl_h
#define EventSdl_h

#include "Constant.h"
typedef struct{
    char key[SDLK_LAST];
    int mousex,mousey;
    int mousexrel,mouseyrel;
    char mousebuttons[8];
    char quit;
} Input;


void UpdateEvents(Input* in);

void InitEvents(Input* in);


#endif /* EventSdl_h */
