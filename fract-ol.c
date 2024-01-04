#include "fractol.h"

int close_window(void)
{
    exit(0);
}
void draw_fractal()
{
    int x = 50;
    int y = 50;
    int i = 0;
    t_fractal fract;
    fract.mlx = mlx_init(); // inicia a minilibx library
    fract.win = mlx_new_window(fract.mlx, 640, 418, "Fract-ol - 42"); // cria a nova janela com comprimento e tamanho e titulo necessario
    while(i < 100)
    {
        mlx_pixel_put(fract.mlx, fract.win, x, y,  0xFFFFFF);
        y++;
        i++;
    }
    mlx_hook(fract.win, 17, 0L, close_window, &fract);
    mlx_hook(fract.win, 2, 1L<<0, close_window, &fract);
    mlx_loop(fract.mlx);
}


int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        ft_printf("Please select a set: Mandelbroot or Julia");
        exit(0);
    }
    else
        draw_fractal();
    return (0);
}