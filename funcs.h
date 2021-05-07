#ifndef FUNCS_H
#define FUNCS_H
#include "button.h"
#include "textbox.h"
//void fill_button_arr(Button button_arr[]); potential nonsense but i hate deleting things connor-

void reset_indicators (Button button_arr[], int cur_selected);

void run_program();

void write_to_screen(sf::Event &Event, Textbox &tbox, std::string &out); // does not literally write to screen. if someone has a better name lemme know connor- 5-1-21

void drawLoginPage(sf::RenderWindow& Window); // draws the user login window



#endif






