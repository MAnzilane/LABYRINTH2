//
//  IhmSdl.h
//  IhmSdl
//
//  Created by MMADI Anzilane
//  on 14/04/2017.
//  Copyright © 2017 MMADI Anzilane
//  All rights reserved.
//

#include "IhmSdl.h"

FILE * openFilename(char * filname) {
    FILE * file = NULL;
    if ((file = fopen(filname, "r")) == NULL) {
        fprintf(stderr, "error open fic \n");
        exit(ERROACCESSFILE);
    }
    return file;
}

// int * typeOfDesign(FILE * file) {
//     int * typeOfDesign;
//     int ok = 1;
//     do {
//         fscanf(file, "%s", buf0);
//         if (strcmp(buf0, "#level") == 0) {
//             printf("je rentre la \n");
//             typeOfDesign = typeOfDesignFromFile(file);
//             // printf("%s\n", buf0);
//         }
//         printf("%s\n", buf0);
//         if (strcmp(buf0, "#endlevel") == 0) {
//             ok = 0;
//         }
//     } while(ok);
//     return typeOfDesign;
// }

SDL_Surface * initScreenISdl(int w, int h) {
    SDL_Surface * screen = NULL;
    if ((screen = SDL_SetVideoMode(w, h, 32,
    SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE)) == NULL) {
        fprintf(stderr, "sory the scree don't init : %s\n", SDL_GetError());
        exit(-1);
    }
    return screen;
}

IhmSdl * initISdl() {
    IhmSdl * ihmSdl = malloc(sizeof(IhmSdl));
    return ihmSdl;
}

IhmSdl * CreateISdl(char * level) {
    IhmSdl * ihmSdl = initISdl();
    SDL_Surface * tilset = IMG_Load("/home/manzilane/Documents/Labyrith2/LABYRINTH2/data/mondeForet.png");
    FILE * file = openFilename(level);
    int * typeOfDesign;
    int ok = 1;
    // char c = 0;
    char buf0[CASHSIZE];

    do {
        fscanf(file, "%s", buf0);
        // printf("%s\n", buf0);
        // scanf("%c", &c);
        if (strcmp(buf0, "#tilsetprop") == 0) {
            fscanf(file, "%s", buf0);
            ihmSdl->tilset = IMG_Load(buf0);
            ihmSdl->clip = cuttingISdl(ihmSdl->tilset, file);
        }
        if (strcmp(buf0, "#level") == 0) {
            printf("je rentre la \n");
            // scanf("%c", &c);
            typeOfDesign = typeOfDesignFromFile(file);
        }
        if (strcmp(buf0, "#endlevel") == 0) {
            ok = 0;
        }
    } while(ok);
    ihmSdl->wldGame = createWldGame(typeOfDesign);
    ihmSdl->screen = initScreenISdl(WIDTHGMAE, HEIGHTGMAE);
    ihmSdl->wWindScroll = WIDTHGMAE;
    ihmSdl->hWindScroll = HEIGHTGMAE;
    ihmSdl->xScroll = 0;
    ihmSdl->yScroll = 0;
    fclose(file);
    free(typeOfDesign);
    return ihmSdl;
}

//we are cutting the tilset
TileProp * cuttingISdl(SDL_Surface * tilset, FILE * file) {
    TileProp * clip = malloc(sizeof(TileProp)*NBTILESET);
    int numTilset = 0;
    char buf0[CASHSIZE];
    char buf1[CASHSIZE];
    for (size_t i = 0; i < NBTILESET; i++) {
        clip[numTilset].rect.h = HBOX;
        clip[numTilset].rect.w = WBOX;
        clip[numTilset].rect.x = i*WBOX;
        clip[numTilset].rect.y = 0;
        fscanf(file,"%s %s" ,buf0, buf1);
        // printf("%s %s\n",buf0, buf1);
        clip[numTilset].solid = 0;
        if (strcmp(buf1, "solid") == 0) {
            clip[numTilset].solid = 1;
        }
        numTilset++;
    }
    // printf("%s %s\n",buf0, buf1);
    return clip;
}

void applayISdl(int x, int y, SDL_Surface * src, SDL_Surface * dest, SDL_Rect * clip) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, clip, dest, &offset);
}

void eventment() {
    SDL_Event event;
    int ok = 1;
    while (ok) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                ok = 0; //stop game
                break;
        }
    }
}

int ** DesignISdl(const IhmSdl * ihmSdl) {
    int ** dis = malloc(sizeof(int*)*(getHWldGame(ihmSdl->wldGame)));
    for (size_t i = 0; i < getHWldGame(ihmSdl->wldGame); i++) {
        dis[i] = malloc(sizeof(int)*getWWldGame(ihmSdl->wldGame));
    }
    int i = 0;

    for (size_t j = 0; j < getHWldGame(ihmSdl->wldGame); j++) {
        for (size_t k = 0; k < getWWldGame(ihmSdl->wldGame); k++) {
            // printf("w %d \n", getHWldGame(ihmSdl->wldGame));
            dis[j][k] = getTypeOfObj(ihmSdl->wldGame->obj[i++]);
            // printf("%d\n", dis[j][k]);
        }
    }
    return dis;
}


void printISdl(IhmSdl * ihmSdl) {

    // //background
    SDL_FillRect(ihmSdl->screen, &(ihmSdl->screen)->clip_rect, SDL_MapRGB( ihmSdl->screen->format, 0xFF, 0xFF, 0xFF ) );

    int ** dis = DesignISdl(ihmSdl);
    int x = 0; int y = 0;
    int xmin = ihmSdl->xScroll / WBOX-1;
    int ymin = ihmSdl->yScroll / HBOX-1;
    int xmax = (ihmSdl->xScroll + ihmSdl->wWindScroll) / WBOX;
    int ymax = (ihmSdl->yScroll + ihmSdl->hWindScroll) / HBOX;

    printf("je sort de la fonction design\n");
    printf("xmin = %d\n", xmax);
    // int c;
    // scanf("%d", &c);
    int numtule = 0;
    for (size_t i = xmin; i < xmax; i++) {
        for (size_t j = ymin; j < ymax; j++) {
            x = i*WBOX - ihmSdl->xScroll;
            y = j*HBOX - ihmSdl->yScroll;
            printf("x = %d   y = %d\n", x, y);
            if (i < 0 || i >= getWWldGame(ihmSdl->wldGame)*WBOX || j < 0
             || j >= getHWldGame(ihmSdl->wldGame)*HBOX)
                numtule = 0;
            else
                numtule = dis[i][j];
            applayISdl(x, y, ihmSdl->tilset, ihmSdl->screen, &(ihmSdl->clip[numtule].rect));
        }
    }
    SDL_Flip(ihmSdl->screen);
    destroyDis(dis, getHWldGame(ihmSdl->wldGame));
}


void destroyDis(int ** dis, int size) {
    for (size_t i = 0; i < size; i++) {
        free(dis[i]);
    }
    free(dis);
}

void destroyISdl(IhmSdl * ihmSdl) {
    destroyWldGame(ihmSdl->wldGame);
    SDL_FreeSurface(ihmSdl->tilset);
    SDL_FreeSurface(ihmSdl->screen);
    free(ihmSdl->clip);
    free(ihmSdl);
}
// void destroyClipISdl(TileProp * clip) {
//
// }
