/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>

int main(int nArgs, char** vArgs) {
    SDL_Window* window = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Could not initialise SDL: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow("Hello SDL", 640, 480, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
    glViewport(0, 0, 640, 480);
    bool isRunning = true;
    SDL_Event sdl_event;
    while (isRunning) {
        while (SDL_PollEvent(&sdl_event) != 0) {
            if (sdl_event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            } else if (sdl_event.type == SDL_EVENT_KEY_DOWN) {
                switch (sdl_event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        isRunning = false;
                        break;
                }
            }
            glClear(GL_COLOR_BUFFER_BIT);
            SDL_GL_SwapWindow(window);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
