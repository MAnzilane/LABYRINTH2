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


/* error defiene */
#define MALOCERRO -1
#define ERROACCESSFILE -2
#define ERROCREATEFILE -3
#define ERRORNULLPOINTER -4

/* constante dufine */
#define SIZENAME 30
#define NBLIFE 5
#define SIZEBOX 30

typedef enum eDesigneWorld {EMPTY, WBD, WBU, WMD, WMU, WED, WEU, WM, BOX, KEY,
                            DDC, DUC, DDO, DUO, BRIGEB, BRIGEE, ROCK, VEGETABLE,
                            PIKETRAP,HOLE} DesignType;
                            
typedef enum eType {FIXED, MOBILE, TRAP, ACTIVE, INACTIVE} Type;



#endif /* Constant_h */
