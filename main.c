#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL2/SDL.h"

#define width 40
#define height 25


struct vec
{
    int x,y;
};



int main (int argc, char* args[]){
    SDL_Window* window;
    SDL_Renderer* render;
    SDL_Event e;

    //intilazing
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow( "SIN&COS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,width*10,height*10, SDL_WINDOW_SHOWN );
    render= SDL_CreateRenderer(window,-1,0);

    int len=width*height;
    struct vec* obj=malloc(sizeof(int)*2*len);
    struct vec* forWriting=malloc(sizeof(int)*2*len);
    int x=0,y=0,ind=0,arr=0;
    Uint32 buttons;
    FILE *f;

    f=fopen("boop.txt","w");

    for(int i=0;i<len;i++){
        struct vec temp={0,0};
        obj[i]=temp;
    }


    while(1){
        SDL_PumpEvents();
        buttons=SDL_GetMouseState(&x,&y);
        if ((buttons & SDL_BUTTON_LMASK) != 0) {
            int tx=x/10;int ty=y/10;
            int index=tx+ty*width;
            if(obj[index].x == 0 && obj[index].y==0){
                obj[index].x=tx*10;obj[index].y=ty*10;
                forWriting[arr].x=tx*10;forWriting[arr].y=ty*10;
                arr++;
            }
        }
        SDL_SetRenderDrawColor(render,0,0,0,255);
        
        
        
        
        //drawing
        for(int i=0;i<len;i++){
            if(obj[i].x==0 && obj[i].y==0){continue;}
            SDL_SetRenderDrawColor(render,255,255,255,255);
            SDL_Rect temp={obj[i].x,obj[i].y,400/width,(height*10)/height};
            SDL_RenderDrawRect(render,&temp);
        }
        SDL_RenderPresent(render);
        SDL_ShowWindow(window);
        //doopie 
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            break;
        }   
    }

    for(int i=0;i<arr;i++){
        //if(obj[i].x==0 && obj[i].y==0){continue;}
        fprintf(f,"%i,%i,",forWriting[i].x/10,forWriting[i].y/10);
        if(ind>7){ind=0;fprintf(f,"\n");}
        ind+=2;
    }    
    fclose(f);
    free(obj);
    free(forWriting);
	return 0;
}
