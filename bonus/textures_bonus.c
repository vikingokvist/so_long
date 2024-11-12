#include "../includes/so_long.h"

char     *textures_w(int i)
{
    char    *texture;

    texture = NULL;
    if (i == 0)
        texture = "./textures/player_w1.png";
    else if (i == 1)
        texture = "./textures/player_w2.png";
    else if (i == 2)
        texture = "./textures/player_w3.png";
    else if (i == 3)
        texture = "./textures/player_w4.png";
    return (texture);
}

char     *textures_a(int i)
{
    char    *texture;

    texture = NULL;
    if (i == 0)
        texture = "./textures/player_a1.png";
    else if (i == 1)
        texture = "./textures/player_a2.png";
    else if (i == 2)
        texture = "./textures/player_a3.png";
    else if (i == 3)
        texture = "./textures/player_a1.png";
    return (texture);
}

char     *textures_s(int i)
{
    char    *texture;

    texture = NULL;
    if (i == 0)
        texture = "./textures/player_s1.png";
    else if (i == 1)
        texture = "./textures/player_s2.png";
    else if (i == 2)
        texture = "./textures/player_s3.png";
    else if (i == 3)
        texture = "./textures/player_s4.png";
    return (texture);
}

char     *textures_d(int i)
{
    char    *texture;

    texture = NULL;
    if (i == 0)
        texture = "./textures/player_d1.png";
    else if (i == 1)
        texture = "./textures/player_d2.png";
    else if (i == 2)
        texture = "./textures/player_d3.png";
    else if (i == 3)
        texture = "./textures/player_d4.png";
    return (texture);
}