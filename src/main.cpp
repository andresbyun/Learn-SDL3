#define SDL_MAIN_USE_CALLBACKS  // Use SLD callbacks
// Window dimensions
#define WNDW_W 640
#define WNDW_H 480

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window* window;
static SDL_Renderer* renderer;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("[ERROR] - Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    const SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

    if (!SDL_CreateWindowAndRenderer("LearnSDL3", WNDW_W, WNDW_H, flags, &window, &renderer)) {
        SDL_Log("[ERROR] Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_SetRenderLogicalPresentation(renderer, WNDW_W, WNDW_H, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    SDL_SetRenderDrawColorFloat(renderer, 0.2f, 0.3f, 0.3f, SDL_ALPHA_OPAQUE_FLOAT);

    SDL_RenderClear(renderer);      // Clear window
    SDL_RenderPresent(renderer);    // Update screen

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    // close the window on request
    if (event->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    if (result == SDL_APP_FAILURE) {
        SDL_Log("[ERROR]: %s", SDL_GetError());
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}