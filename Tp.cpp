#include "pch.h"
#include "GameService.h"

using namespace System;
void showMwnu() {
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    cout << "                                _____ _                           _     _       " << std::endl;
    cout << "                               | ___ (_)                         (_)   | |      " << std::endl;
    cout << "                               | |_/ /_  ___ _ ____   _____ _ __  _  __| | ___  " << std::endl;
    cout << "                               | ___ \\ |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\ " << std::endl;
    cout << "                               | |_/ / |  __/ | | \\ V /  __/ | | | | (_| | (_) |" << std::endl;
    cout << "                               \\____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/ " << std::endl;
    Console::ForegroundColor = ConsoleColor::White;
    cout << "        ----------------------------------------------------------------------------------------------------" << endl;
    Console::ForegroundColor = ConsoleColor::DarkMagenta;
    cout << "                                             [1] Empezar a jugar " << endl;
    Console::ForegroundColor = ConsoleColor::DarkCyan;
    cout << "                                             [2] Instrucciones" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    cout << "        ----------------------------------------------------------------------------------------------------" << endl;

}
int main()
{
    int option;
    showMwnu();
    cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        Console::SetWindowSize(120, 30);
        Console::CursorVisible = false;

        int key;
        GameService* gameService = new GameService();


        while (true) {
            gameService->eraseEntities();
            gameService->shoot();
            gameService->detectCollisions();
            gameService->addEntities();
            gameService->checkGameResult();


            if (_kbhit()) {
                key = _getch();
                key = toupper(key);
                gameService->getMonigote()->move(key);
            }

            gameService->moveEntities();
            gameService->drawEntities();
            _sleep(100);

        }

        delete gameService;
        system("pause>NULL");
        return 0;

  
    }
   
}
