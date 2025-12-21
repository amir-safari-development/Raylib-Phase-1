#include "map.h"

int WORLD_MAP[ROWS][COLUMNS] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void DrawMap(int *isPlayerSet)
{
    int map_x = player.pos.x / TILE_SIZE;
    int map_y = player.pos.y / TILE_SIZE;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (WORLD_MAP[i][j] == 0 && !*isPlayerSet)
            {
                player.pos.x = j * TILE_SIZE + PLAYER_RADIUS;
                player.pos.y = i * TILE_SIZE + PLAYER_RADIUS;
                *isPlayerSet = 1;
            }

            if (WORLD_MAP[i][j] == 1)
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
            else if (i == map_y && j == map_x)
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
            else if (WORLD_MAP[i][j] == 0)
                DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, WHITE);

            DrawRectangleLines(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, GRAY);
        }
    }
}    