#include "../includes/so_long.h"

void    check_map_dupes(t_data *data)
{
    int     i;
    int     j;
    int     count;

    i = 0;
    count = 0;
    while (i < data->rows)
    {
        j = 0;
        while (j < data->columns)
        {
            if (data->map[i][j] == 'P' || data->map[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    }
    if (count != 2)
        error(data, 'd');
}
