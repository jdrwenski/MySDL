// MySDL.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <SDL.h>

SDL_Window* window = 0;
SDL_Renderer* render = 0;
SDL_Rect rect;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Demo",100,100,640,480, SDL_WINDOW_ALWAYS_ON_TOP);
    render = SDL_CreateRenderer(window, -1, 0);

    /* Rechteck initialisieren */
    rect.x = 50;
    rect.y = 100;
    rect.w = 80;
    rect.h = 50;

    /* Schleife notfalls mittels Strg + Alt + Entf stoppen */
    while (rect.x < 400) {
        /* Hintergrund zeichnen */
        SDL_SetRenderDrawColor(render, 100, 50, 222, 255);
        SDL_RenderClear(render);

        /* Rechteck zeichnen */
        SDL_SetRenderDrawColor(render, 200, 200, 0, 255);
        SDL_RenderFillRect(render, &rect);

        /* Rechteck bewegen */
        rect.x += 2;

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
