/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdio.h>
    #include <math.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <SFML/Window/Keyboard.h>
    #include <unistd.h>
    #define START 0
    #define GAME 1
    #define MENU 2
    #define PAUSE 3
    #define SETTINGS 4
    #define GAMEOVER 5

typedef struct image {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} image_t;

typedef struct duck {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
} duck_t;

typedef struct my_hunter {
    int where_am_i;
    int where_was_i;
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    image_t **boutons;
    sfSprite *background;
    sfTexture *background_texture;
    sfClock *clock;
    sfTime time;
    float seconds;
    duck_t **ducks;
    int difficulty;
    int life;
    sfClock *move_clock;
    sfTime move_time;
    float move_seconds;
    float game_speed;
    int score;
    int high_score;
    char *score_str;
    sfText *score_text;
    sfFont *score_font;
    sfSprite *mouse_cursor;
    sfTexture *mouse_texture;
    sfVector2i mouse_pos;
    sfMusic *shot_sound;
    sfMusic *button_sound;
    sfMusic *gameover_sound;
    sfMusic *power_up_sound;
    sfMusic *main_theme_1;
    sfMusic *main_theme_2;
    sfTexture *easy_active;
    sfTexture *mid_active;
    sfTexture *hard_active;
    sfSprite **life_sprites;
} my_hunter_t;

void init_game(my_hunter_t *hunter);
void run_game(my_hunter_t *hunter);
image_t *create_bouton(char *path, sfVector2f position, sfVector2f scale);
void animate_logo(my_hunter_t *hunter);
void analyse_event(my_hunter_t *hunter);
void handle_menus(my_hunter_t *hunter);
void init_buttons(my_hunter_t *hunter);
void animate_ducks(my_hunter_t *hunter);
int is_in_global_bounds(my_hunter_t *hunter, int i);
void display_score(my_hunter_t *hunter);
void is_hovering_buttons(my_hunter_t *hunter);
void handle_start_menu(my_hunter_t *hunter);
void display_score(my_hunter_t *hunter);
void display_game(my_hunter_t *hunter);
void handle_pause_menu(my_hunter_t *hunter);
void handle_gamemode_menu(my_hunter_t *hunter);
void handle_pause_menu(my_hunter_t *hunter);
void handle_menu_menu(my_hunter_t *hunter);
void handle_game_menu(my_hunter_t *hunter);
void free_all(my_hunter_t *hunter);
void render_game(my_hunter_t *hunter);
char *my_revstr(char *str);
char *my_itoa(int num);
int my_strlen(char const *str);
void display_gameover(my_hunter_t *hunter);
char *my_strcat(char *dest, char const *src);
image_t *create_bouton(char *path, sfVector2f position, sfVector2f scale);
void handle_gameover_menu(my_hunter_t *hunter);
void init_ducks(my_hunter_t *hunter);
void init_buttons(my_hunter_t *hunter);
void free_ducks(my_hunter_t *hunter);
void destroy_game(my_hunter_t *hunter);
int check_hovering(my_hunter_t *hunter, int i);
void animate_menu_buttons(my_hunter_t *hunter);
void save_high_score(my_hunter_t *hunter);
int my_getnbr(char const *str);
int konami_code(my_hunter_t *hunter);
void init_sounds(my_hunter_t *hunter);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
#endif
