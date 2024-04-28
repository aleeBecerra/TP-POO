#include "pch.h"
#include "GameService.h"
#include "Heart.h"

GameService::GameService() {
	monigote = new Monigote(2, 15, 3, 4, 8, 2);
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
	int trebolCount = 0;
	time_t lastEnemySpawnTime = 0;
	time_t lastTreasuredSpawnTime = 0;

	for (Entity* entity : entities) {
		if (dynamic_cast<Murcielago*>(entity)) {
			murcielagoCount++;
		}
		else if (dynamic_cast<Heart*>(entity)) {
			heartsCount++;
		}
		else if (dynamic_cast<Trebol*>(entity)) {
			trebolCount++;
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

	


}

// Reiniciar el juego para el nuevo nivel
void GameService::resetGame() {
	// Reiniciar las vidas, tesoros recogidos, y otras variables del juego
	monigote->setLives(3);
	monigote->setTrebolsCollected(0);

	deleteEntities();

	addEntities();
}




void GameService::checkGameResult() {
	

	if (monigote->getLives() == 0) {
		// El jugador ha perdido todas sus vidas
		Console::ForegroundColor = ConsoleColor::Red;
		system("cls");
		Console::SetCursorPosition(38, 12);
		cout << "--TERMINO EL JUEGO--"<<endl;
		Console::SetCursorPosition(38, 20);
		Console::SetCursorPosition(20, 15);
		cout << "Corazones capturados: " << monigote->getHeartsCollected() << endl;
		Console::SetCursorPosition(20, 16);
		cout << "Treboles colisionados: " << monigote->getTrebolsCollected()<<endl;
		Console::SetCursorPosition(20, 17);
		cout << "Presiona una tecla para salir...";
		_getch();

	}
}

void GameService::shoot() {
	if (rand() % 100 < 5) { // Probabilidad del 20% de lanzar un corazón
		for (Entity* entity : entities) {
			if (dynamic_cast<Murcielago*>(entity)) {
				Murcielago* murcielago = dynamic_cast<Murcielago*>(entity);
				int x = murcielago->getX(); // Obtener la posición X del murciélago
				int y = murcielago->getY(); // Lanzar desde la posición del murciélago
				entities.push_back(new Heart(x, y, 1, 1));
				break; // Solo lanzar un corazón por ciclo
			}
		}
	}
	if (rand() % 100 < 5) { // Probabilidad del 20% de lanzar un trebol
		for (Entity* entity : entities) {
			if (dynamic_cast<Murcielago*>(entity)) {
				Murcielago* murcielago = dynamic_cast<Murcielago*>(entity);
				int x = murcielago->getX(); // Obtener la posición X del murciélago
				int y = murcielago->getY(); // Lanzar desde la posición del murciélagp
				entities.push_back(new Trebol(x, y, 1, 1));
				break; // Solo lanzar un corazón por ciclo
			}
		}
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
		if (dynamic_cast <Heart*>(entity)) {
			dynamic_cast<Heart*>(entity)->move();
		}
		if (dynamic_cast <Trebol*>(entity)) {
			dynamic_cast<Trebol*>(entity)->move();
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
			Trebol* trebol = dynamic_cast <Trebol*> (entity);
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
				monigote->substractLive();
				monigote->collectedsHearts();
				heart->erase();
				entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
				delete entity;
			}
			else if (trebol) {
				monigote->addLives();
				monigote->collectedTrebols();
				trebol->erase();
				entities.erase(remove(entities.begin(), entities.end(), entity), entities.end());
				delete entity;
			}
		
			

		}

	}
}

Monigote* GameService::getMonigote() {
	return monigote;
}