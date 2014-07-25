#include <stdio.h>
#include <conio.h>

int sol[8][8];
int xM[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yM[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

bool isSafe(int x, int y)
{
    if ( x >= 0 && x < 8 && y >= 0 && y < 8)
        return true;
    return false;
}

void print()
{
	int i, j;
    for (i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("%2d ", sol[i][j]);
        printf("\n");
    }
}

bool solve(int x, int y, int moves) {
	int i, nx, ny;
	if(moves == 64) {
		print();
		return true;
	}
	for(i = 0; i < 8; i++) {
		nx = x + xM[i];
		ny = y + yM[i];
		if(isSafe(nx, ny) && sol[nx][ny] == -1) {
			sol[nx][ny] = moves;
			if(solve(nx, ny, moves + 1))return true;
			else
				sol[nx][ny] = -1;
		}
	}
	return false;
}

int main() {
	int i, j;
    for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
    sol[i][j] = -1;
    sol[5][5]  = 0;
	solve(5, 5, 1);
	getch();
	return 0;
}
