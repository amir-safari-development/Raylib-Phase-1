#include "player.h"

Player player = {{}, {1, 0}};

void DrawPlayer()
{
    DrawCircle(player.pos.x, player.pos.y, PLAYER_RADIUS, RED);
    DrawLine(player.pos.x, player.pos.y, player.pos.x + player.dir.x * 30, player.pos.y - player.dir.y * 30, RED);
}
