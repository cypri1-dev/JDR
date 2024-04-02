#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL Image Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Charger une image PNG
    SDL_Surface* imageSurface = IMG_Load("example.png");
    if (!imageSurface) {
        printf("Unable to load image! SDL Error: %s\n", IMG_GetError());
        return 1;
    }

    // Créer une texture à partir de la surface de l'image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    if (!texture) {
        printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        SDL_FreeSurface(imageSurface);
        return 1;
    }

    // Libérer la surface, elle n'est plus nécessaire après avoir créé la texture
    SDL_FreeSurface(imageSurface);

    // Effacer le renderer
    SDL_RenderClear(renderer);

    // Dessiner la texture sur le renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Mettre à jour le renderer
    SDL_RenderPresent(renderer);

    // Attendre quelques secondes avant de fermer la fenêtre
    SDL_Delay(2000);

    // Libérer la texture et le renderer
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quitter SDL
    IMG_Quit();
    SDL_Quit();

    return 0;
}
