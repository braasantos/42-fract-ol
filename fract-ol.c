#include "fractol.h"

int close_window(void)
{
    exit(0);
}
void close_exit(t_fractal fract)
{
    mlx_hook(fract.win, 17, 0L, close_window, &fract);
    mlx_hook(fract.win, 2, 1L<<0, close_window, &fract);
}
void ft_mandelbrot(t_fractal fract)
{
    fract.mlx = mlx_init(); // inicia a minilibx library
    fract.win = mlx_new_window(fract.mlx, 640, 418, "Fract-ol - 42"); // cria a nova janela com comprimento e tamanho e titulo necessario
    close_exit(fract);
    mlx_loop(fract.mlx);
}
void ft_julia(t_fractal fract)
{
    fract.mlx = mlx_init(); // inicia a minilibx library
    fract.win = mlx_new_window(fract.mlx, 640, 418, "Fract-ol - 42"); // cria a nova janela com comprimento e tamanho e titulo necessario
    close_exit(fract);
    mlx_loop(fract.mlx);
}
void draw_fractal(t_fractal fract)
{
    fract.x = 0;
    fract.y = 0;
    while (fract.x < SIZE)
    {
        while (fract.y < SIZE)
        {
             if (ft_strncmp(fract.name, "Mandelbrot", 10) == 0)
                ft_mandelbrot(fract);
            else if (ft_strncmp(fract.name, "Julia", 6) == 0)
                 ft_julia(fract);
            else
            {
                ft_printf("Avaliable fractals: Mandelbroot or Julia\n");
                exit(0);
            }
            fract.y++;
        }
        fract.x++;
        fract.y = 0;
    }
}


int main(int ac, char **av)
{
    t_fractal fract;
    fract.name = av[1];
    if (ac != 2)
        return(ft_printf("Please choose a set: Mandelbroot or Julia\n"), 0);
    else
        draw_fractal(fract);
    return (0);
}