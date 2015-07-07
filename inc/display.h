/*
** display.h for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun May  4 19:01:29 2014 jolivald
** Last update Sun May  4 23:10:35 2014 jolivald
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

typedef struct		s_display
{
  int			ant_num;
  int			room_num;
  int			pos;
  int			way;
  char			ended;
  struct s_display	*next;
  struct s_display	*prev;
}			t_display;

typedef struct		s_calc
{
  char			first;
  t_display		*tmp;
}			t_calc;

int			add_ants_in_list(t_display *display);
int			get_ant_num(t_ants ants, int max, int tmp);
void			show_list(t_display *display);
int			end_display(t_ants ants, int nb_ants, t_graph **graph);
void			assign_way(t_ants ants, t_display *display);
void			process_display(t_display *display,
					t_graph **graph, t_ants ants);
int			test_ended(t_display *display);
void			aff_ant_way(t_display *display,
				    t_graph **graph, t_ants ants, int end_room);
void			aff_ant_move(t_display *display,
				     t_graph **graph, int end_room);
void			process_already_used(t_calc *calc, t_ants ants,
			     t_graph **graph, int end_room);
void			process_not_used(t_calc *calc, t_ants ants,
			 t_graph **graph, int end_room);


#endif /* !DISPLAY_H_ */
