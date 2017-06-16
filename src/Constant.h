//
//  Constant.h
//  constant
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#ifndef Constant_h
#define Constant_h
/* game include  */
#include <stdlib.h>
#include <stdio.h>
#include <mm_malloc.h>
#include <assert.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/* error defiene */
#define MALOCERRO -1
#define ERROACCESSFILE -2
#define ERROCREATEFILE -3
#define ERRORNULLPOINTER -4

/* constante dufine */
#define CASHSIZE 50
#define SIZENAME 30
#define NBLIFE 5
#define WBOX 60
#define HBOX 45
#define NBTILESET 31
#define WIDTHGMAE 700
#define HEIGHTGMAE 600

typedef enum eDesigneWorld {EMPTY, CHEST, WBD, WMD, WED, WBU, WMU, WEU, BRB, BRE,
    WM, BOX, FLR, ROCK, SIGN1, SIGN2, SIGN3, TRAP1, TRAP2, TRAP3, TRAP4_0, TRAP4_1,
     DDC, DUC, DDO, DUO, SIGN4, MINION, CHESTO, KEY} DesignType;

typedef enum eType {FIXED, MOBILE, TRAP, ACTIVE, INACTIVE} Type;



#endif /* Constant_h */
