// Juego de la vida (99 lineas de código)

#include <cstdio>
#include <windows.h>

/* Variable que define tamaño del tablero */
#define N 30


/* Update de las celdas, se fija en las 8 de alrededor y en su estado actual. */
/* Los bordes siempre son 0 */
bool update(int m[][N], int status, int coorX, int coorY) {
	int cantT = 0;

	if (coorX == 0 || coorX == N-1 || coorY == 0 || coorY == N-1)
		return false;
	else {
		for (int x = coorX - 1; x <= coorX + 1; x++) {
			for (int y = coorY - 1; y <= coorY + 1; y++) {
				if (m[x][y] == 1 && !(coorX == x && coorY == y))
					cantT++;
			}
		}
	}

	/* Decide el resultado de la célula. */
	if (status == 1) {
		if (cantT == 2 || cantT == 3) 
			return true;
		else 
			return false;
	} else {
		if (cantT == 3)
			return true;
		else {
			return false;
		}
	}
}



int main() {
	int m[N][N] = {0};
	int mPT[N][N] = {0};
	int c[2];

	/* Para pedir coordenadas en las matrices de las cuales comenzar. */
	while (true) {
		printf("Escribe tu numero\n");
		scanf("%i", &c[0]);
		printf("Ahora el segundo\n");
		scanf("%i", &c[1]);
		if (c[0] == -1 or c[1] == -1)
			break;
		m[c[0]][c[1]] = 1;
		printf("Quedo registrado el m[%i][%i]\n\n", c[0], c[1]);

		for(int x = 0; x < N; x++) {
			for(int y = 0; y < N; y++) {
				printf("%i", m[x][y]);
			}
		printf("\n");
		}
	}


	/* Loop que mira el primer tablero y updatea en el segundo. */
	while (true) {
		Sleep(300);
		system("cls");

		for(int x = 0; x < N; x++) {
			for(int y = 0; y < N; y++) {
				if (m[x][y] == 1)
					printf("#", m[x][y]);
				else
					printf("r", m[x][y]);

				if (update(m, m[x][y], x, y)) {
					mPT[x][y] = 1;
				}
				else {
					mPT[x][y] = 0;
				}

			}
		printf("\n");
		}


		/* Copia todos los valores del segundo tablero para el primero. */
		for(int x = 0; x < N; x++) {
			for(int y = 0; y < N; y++) {
				m[x][y] = mPT[x][y];
			}
		}
	}
}