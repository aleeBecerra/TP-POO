#include "pch.h"
#include "GameService.h"
#include "Heart.h"

GameService::GameService() {
	monigote = new Monigote(2, 15, 3, 4, 8, 4);
	timeT = time(0);
	srand(time(NULL));
}

GameService::~GameService() {
	delete monigote;
	deleteEntities();
}



void GameService::deleteEntities() {
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();
}


void GameService::addEntities() {
	int murcielagoCount = 1;
	int heartsCount = 0;

	time_t lastEnemySpawnTime = 0;
	time_t lastTreasuredSpawnTime = 0;

	for (Entity* entity : entities) {
		if (dynamic_cast<Murcielago*>(entity)) {
			murcielagoCount++;
		}
		else if (dynamic_cast<Heart*>(entity)) {
			heartsCount++;
		}
	}

	if (murcielagoCount <2) {
		time_t currentTime = time(0);
		if (currentTime - lastEnemySpawnTime >= 5) {
			int x = 5;
			float y = 5;
			int dx = 1;
			int height = 3;
			int width = 6;

			entities.push_back(new Murcielago(x, y, dx, height, width));
			murcielagoCount++;
			lastEnemySpawnTime = currentTime;

		}
	}

	if (heartsCount < 3) {
		time_t currentTime = time(0);
		if (currentTime - lastTreasuredSpawnTime >= 5) {
			int x = rand() % (Console::WindowWidth - 1) + 1;
			float y = rand() % (Console::WindowHeight - 1) + 1;
			int height = 1;
			int width = 1;

			entities.push_back(new Heart(x, y, width, height));
			heartsCount++;
			lastTreasuredSpawnTime = currentTime;
		}
	}


}

// Reiniciar el juego para el nuevo nivel
void GameService::resetGame() {
	// Reiniciar las vidas, tesoros recogidos, y otras variables del juego
	monigote->setLives(3);
	monigote->setHeartsCollected(0);

	deleteEntities();

	addEntities();
}

// Finalizar el juego por completo
void GameService::endGame() {
	Console::ForegroundColor = ConsoleColor::Cyan;
	system("cls");
	Console::SetCursorPosition(42, 12);
	cout << "--HAS GANADO EL JUEGO--";
	Console::SetCursorPosition(41, 14);
	cout << "Presiona una tecla para salir...";
	_getch();

}


void GameService::checkGameResult() {
	if (monigote->getHeartsCollected() == 3 /*por ejemplo*/) {
		// El jugador ha recogido todos los tesoros requeridos para ganar el nivel actual
		Console::ForegroundColor = ConsoleColor::Green;
		system("cls");
		Console::SetCursorPosition(45, 12);
		cout << "--GANASTE EL NIVEL--";
		Console::SetCursorPosition(41, 14);
		cout << "Presiona una tecla para continuar...";
		_getch();
		system("cls");

	}

	if (monigote->getLives() == 0) {
		// El jugador ha perdido todas sus vidas
		Console::ForegroundColor = ConsoleColor::Red;
		system("cls");
		Console::SetCursorPosition(38, 12);
		cout << "--TERMINO EL JUEGO--";
		Console::SetCursorPosition(41, 14);
		cout << "Presiona una tecla para salir...";
		_getch();

	}
}

void GameService::eraseEntities() {
	monigote->erase();

	for (Entity* entity : entities) {
		entity->erase();
	}

}

void GameService::moveEntities() {
	for (Entity* entity : entities) {
		if (dynamic_cast<Murcielago*>(entity)) {
			dynamic_cast<Murcielago*>(entity)->move();
		}
	}
}

void GameService::drawEntities() {
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(109, 1);
	cout << "Tiempo: " << clock() / 1000;
	Console::SetCursorPosition(109, 2);
	cout << "Vidas: " << monigote->getLives();
	Console::SetCursorPosition(106, 3);
	cout << "Corazones: " << monigote->getHeartsCollected();
	Console::SetCursorPosition(109, 4);

	monigote->draw();

	for (Entity* entity : entities) {
		entity->draw();
	}
}

void GameService::detectCollisions() {

	for (Entity* entity : entities) {
		if (monigote->getRectangle().IntersectsWith(entity->getRectangle())) {
			Murcielago* murcielago = dynamic_cast<Murcielago*>(entity);
			Heart* heart = dynamic_cast<Heart*>(entity);

			if (murcielago) {
				monigote->substractLive();

				if (monigote->getLives() > 0) {
					monigote->setX(2);
					monigote->setY(12.0);
				}
				else {
					Console::ForegroundColor = ConsoleColor::DarkRed;
					system("cls");
					Console::SetCursorPosition(38, 12);
					cout << " --TERMINO EL JUEGO--";
					Console::SetCursorPosition(41, 14);
					cout << "Presiona una tecla para salir...";
					_getch();
					exit(0); // Sale del juego
				}
			}
			else if (heart) {
				monigote->collectedHearts();
				heart->erase();
				entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
				delete entity;
			}

		}

	}
}

Monigote* GameService::getMonigote() {
	return monigote;
}