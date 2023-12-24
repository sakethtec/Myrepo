#include <stdio.h>
void clearScreen(){
    system('cls');
}
// Function to print the game board
void printBoard(int a[3][3], int x, int y) {
    printf("Game Board:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == x && j == y) {
                printf("   ");
            } else {
                printf("%d  ", a[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to handle moving up
void moveUp(int a[3][3], int *x, int *y, int *k) {
    if (*x > 0) {
        int p = a[*x - 1][*y];
        a[*x - 1][*y] = a[*x][*y];
        a[*x][*y] = p;
        --(*x);
        ++(*k);
    }
}

// Function to handle moving down
void moveDown(int a[3][3], int *x, int *y, int *k) {
    if (*x < 2) {
        int p = a[*x + 1][*y];
        a[*x + 1][*y] = a[*x][*y];
        a[*x][*y] = p;
        ++(*x);
        ++(*k);
    }
}

// Function to handle moving left
void moveLeft(int a[3][3], int *x, int *y, int *k) {
    if (*y > 0) {
        int p = a[*x][*y - 1];
        a[*x][*y - 1] = a[*x][*y];
        a[*x][*y] = p;
        --(*y);
        ++(*k);
    }
}

// Function to handle moving right
void moveRight(int a[3][3], int *x, int *y, int *k) {
    if (*y < 2) {
        int p = a[*x][*y + 1];
        a[*x][*y + 1] = a[*x][*y];
        a[*x][*y] = p;
        ++(*y);
        ++(*k);
    }
}

// Function to check for a win
int checkWin(int a[3][3]) {
    int s = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (a[i][j] > a[i][j + 1]) {
                return 0; // Not a win
            }
        }
        if (i < 2 && a[i][2] > a[i + 1][0]) {
            return 0; // Not a win
        }
    }
    return 1; // Win
}

int main() {
    int a[3][3] = {{1, 3, 5}, {7, 2, 4}, {6, 8, 9}};
    int x = 2, y = 2, k = 0;
    char c;

    printf("Game starts now\n");

    // Initial print of the board
    printBoard(a, x, y);

    // Game loop
    while (k < 100) {
        printf("\nPress 'w' for up\n");
        printf("Press 's' for down\n");
        printf("Press 'a' for left\n");
        printf("Press 'd' for right\n");
        printf("Enter a move: ");
        c = getchar();
        fflush(stdin); // Clear input buffer

        // Handle player moves
        switch (c) {
            case 'w':
                moveUp(a, &x, &y, &k);
                break;
            case 's':
                moveDown(a, &x, &y, &k);
                break;
            case 'a':
                moveLeft(a, &x, &y, &k);
                break;
            case 'd':
                moveRight(a, &x, &y, &k);
                break;
            default:
                printf("Invalid move\n");
        }
        clearScreen();
        // Print board after each move
        printBoard(a, x, y);

        // Check for a win
        if (checkWin(a)) {
            printf("Congratulations! You won the game!\n");
            break;
        }

        // Check for game over
        if (k == 100) {
            printf("Game over. No more moves left.\n");
            break;
        }

    }

    return 0;
}
