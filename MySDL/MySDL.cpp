// MySDL.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <SDL.h>

SDL_Window* window = 0;
SDL_Renderer* render = 0;
SDL_Rect rect;
SDL_Rect target;

bool checkCollision(SDL_Rect& rect, SDL_Rect& target) {
    if (
        ((target.x >= rect.x && target.x <= rect.x + rect.w) ||
            (rect.x >= target.x && rect.x <= target.x + target.w))
        &&
        ((target.y >= rect.y && target.y <= rect.y + rect.h) ||
            (rect.y >= target.y && rect.y <= target.y + target.h))
        ) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Demo",1000,200,640,480, SDL_WINDOW_ALWAYS_ON_TOP);
    render = SDL_CreateRenderer(window, -1, 0);

    /* Rechteck initialisieren */
    rect.x = 50;
    rect.y = 130;
    rect.w = 80;
    rect.h = 50;

    /* Ziel initialisieren */
    target.x = 300;
    target.y = 100;
    target.w = 50;
    target.h = 50;

    /* Deklaration des Event-Objekts */
    SDL_Event event;

    /* Schleife notfalls mittels Strg + Alt + Entf stoppen */
    while (rect.x < 500) {
        /* Hintergrund zeichnen */
        SDL_SetRenderDrawColor(render, 150, 150, 222, 255);
        SDL_RenderClear(render);

        /* Rechtecke zeichnen */
        SDL_SetRenderDrawColor(render, 200, 200, 0, 255);
        SDL_RenderFillRect(render, &rect);
        SDL_SetRenderDrawColor(render, 250, 0, 0, 255);
        SDL_RenderFillRect(render, &target);

        /* Rechteck bewegen */
        rect.x += 1;

        /* Kollisionsabfrage */
        if ( checkCollision(rect,target) ) {
            target.x = -1000;
        }

        /* Variablen für Maus-Koordinaten */
        int mx, my;
        /* alle Events seit dem letzten Delay abrufen */
        while (SDL_PollEvent(&event)) {
            /* Typ des Events prüfen */
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                /* Maus-Position abrufen (call-by-reference) */
                SDL_GetMouseState(&mx, &my);
                target.x = mx;
                target.y = my;
                std::cout << mx << ", " << my << std::endl;
            }
        }

        /* Monitordarstellung */
        SDL_RenderPresent(render);
        SDL_Delay(24);
    }

    SDL_Quit();

    std::cout << "Hello World!\n";
    return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
