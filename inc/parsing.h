/*
** parsing.h for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sat May  3 19:59:15 2014 jolivald
** Last update Sun May  4 23:06:55 2014 jolivald
*/

#ifndef PARSING_H_
# define PARSING_H_

# include <stdlib.h>

typedef struct		s_room
{
  char			*name;
  int			posx;
  int			posy;
  int			num;
  int			extremity;
  char			used;
  struct s_room		*next;
}			t_room;

typedef struct		s_pipe
{
  char			*start;
  char			*end;
  struct s_pipe		*next;
}			t_pipe;

typedef struct		s_ways
{
  int			len;
  int			*way;
  struct s_ways		*next;
}			t_ways;

typedef struct		s_graph
{
  struct s_room		*room;
  struct s_graph	**links;
  struct s_graph	**root_node;
}			t_graph;

typedef struct		s_recurs
{
  t_graph		*node;
  int			rec;
  int			**ways;
  int			start_num;
}			t_recurs;

int			process_ants(int **ways, int nb_ants, int max_way, t_graph **graph);

/*
** main.c
*/

int			count_links(t_graph *graph);
int			**init_ways(t_graph ***graph, int *nbr_ants);
int			get_process(t_graph **graph, int **ways, int nb_ants);

/*
** display.c
*/

void			aff_rooms(t_room *rooms, t_pipe *pipes);
void			aff_graph(t_graph **graph);
void			aff_ways(int **ways);

/*
** my_realloc.c
*/

t_graph			**my_realloc(t_graph **map, t_graph *new_elem);
void			*my_calloc(int nmemb, int size);
int			count_nodes(t_graph **map);
char			*my_memset(char *result, int size);

/*
** basics.c
*/

void			my_putstr(char *s);
int			my_strlen(char *str);
int			my_strcmp(char *s1, char *s2);
char			*my_strcpy(char *dest, char *src);
char			*my_strdup(char *src);
/*
** basics_2.c
*/

int			my_getnbr(char *str);
int			my_putnbr(int nb);
void			my_putchar(char c);

/*
** get_data.c
*/

int			loop_data_pipes(t_pipe **pipes, char *s, int i);
int			loop_data_rooms(t_room **rooms, char *s, int i);
t_room			*get_data_rooms(t_room *rooms, char **s);
t_pipe			*get_data_pipes(t_pipe *pipes, char *s);
int			my_put_error(char *s, int i);

/*
** get_data_utils.c
*/

void			free_tab(char **tab);
int			fill_pipe(t_pipe **pipes, char *str);
int			fill_rooms(t_room **rooms, char **tab, char *extremity);

/*
** add_elem_in_list.c
*/

t_room			*add_room_in_list(t_room *list);
t_pipe			*add_pipe_in_list(t_pipe *list);


/*
** my_str_to_wordtab.c
*/

int			word_nbr(char *str);
int			my_char_isnum(char c);
void			fill_tab(char *tab, char *str, int i, int stock);
char			**my_str_to_wordtab(char *str);

/*
** graph.c
*/

int			check_links(t_graph *start, char *name);
int			get_pipes(t_graph **graph, t_pipe *pipes);
t_graph			**get_rooms(t_room *rooms, int *max);
t_graph			**do_graph(t_room *rooms, t_pipe *pipes, int *len);

/*
** graph_utils.c
*/

t_graph			*search_connexion(char *name, t_graph **graph);
t_graph			*get_start(t_graph **graph);
int			get_room_len(t_room *rooms);
t_graph			*get_end(t_graph **graph);

/*
** onsenfoudsa.c
*/

void			my_aff_way(int *way);
int			**my_recursivity(t_recurs *recurs, int start_line);
int			**loop_graph(t_graph **graph);

/*
** new_rooms.c
*/

int			not_used(t_recurs *recurs, int i,
				 t_recurs *recurs_tmp, int *line);
int			already_used(t_recurs *recurs, int i,
				     t_recurs *recurs_tmp, int *line);
int			new_rooms(t_recurs *recurs, int *line,
				  char *used, int i);

/*
** functs.c
*/

int			end_found(t_recurs *recurs, int *line);
int			my_cpy_way_if_used(t_recurs *recurs, int line, int num);
int			my_cpy_way(t_recurs *recurs, int line);

/*
** onsenfoupasdca.c
*/

int			add_room_in_way(int **ways, int nb, int tmp);
int			my_freeways(int **ways);
int			my_realloc_ways(t_recurs *recurs);

/*
** sort_ways.c
*/

int			tab_len(int *way);
void			swap_tab(int **ways, int len);
int			sort_ways(int **ways);

/*
** quick_sort.c
*/

int			*init_sort(int **ways, int *i);
int			partition(int *len_ways, int first,
				  int last, int pivot);
void			quick_sort(int *len_ways, int first, int last);

#endif /* !PARSING_H_ */
