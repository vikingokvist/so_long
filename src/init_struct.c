#include "../includes/so_long.h"

void    init_struct(t_data *data)
{
    data->mlx_ptr = NULL;
	data->img = NULL;
	data->window_name = "so_long";
	data->window_w = 0;
	data->window_h = 0;
	data->image_w = 0;
	data->image_h = 0;
	data->pre_map = NULL;
	data->map = NULL;
	data->rows = 0;
	data->columns = 0;
	data->p_pos = NULL;
	data->p_row = 0;
	data->p_col = 0;
	data->p_image = NULL;
	data->moves = 0;
}