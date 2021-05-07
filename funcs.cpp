#include "funcs.h"
#include "textbox.h"
#include "includes.h"

#define btn_width 380.0
/* void fill_button_arr(Button button_arr[]) //
{
    Button btn0(70.0*0, sf::Vector2f(180.0f,70.0f), sf::Color::Cyan);
  Button btn1(70.0*1, sf::Vector2f(180.0f,70.0f), sf::Color::Cyan);
  Button btn2(70.0*2, sf::Vector2f(180.0f,70.0f), sf::Color::Cyan);
  Button btn3(70.0*3, sf::Vector2f(180.0f,70.0f), sf::Color::Cyan);
  Button btn4(70.0*4, sf::Vector2f(180.0f,70.0f), sf::Color::Cyan);
  Button btn5(70.0*5, sf::Vector2f(180.0f,70.0f), sf::Color::Cyan);
  Button btn6(70.0*6, sf::Vector2f(180.0f,70.0f), sf::Color::Cyan);

  Button a;
} */
void narg();
void nag();
void reset_indicators (Button button_arr[], int cur_select)
{
    for (int i = 0; i < 7; i++) //update this so it doesn't depend on magic num connor. -connor 5/1/21
    {
        if(i == cur_select)
        {
            continue;
        }
        button_arr[i].set_indicator(false); // 

    }


}


void run_program()
{
  
  
  sf::RenderWindow Window(sf::VideoMode(1300, 700), "Library Management");
  
  sf::Texture background;
  background.loadFromFile("blk.png");
  
  sf::Texture btn;
  btn.loadFromFile("botton.png");

  sf::Texture grn;
  //grn.loadFromFile("green.png");
  

  sf::RectangleShape back_g(sf::Vector2f(1300.0f,700.0f));
  back_g.setTexture(&background);

  /* std::vector<std::unique_ptr<Button> > button_vec;
  for(int i = 0; i < 7; i++)
  {
    button_vec.push_back ( new Button(70.0*i, sf::Vector2f(150.0f,70.0f), sf::Color::Cyan) );
  } */

  //Button *btn;
   
  sf::Font ocra;
  ocra.loadFromFile("OCRAEXT.TTF");
  //(sf::Vector2f location, sf::Vector2f size, sf::Font &font)
  Textbox state_input(sf::Vector2f(620.0f, 30.0f), sf::Vector2f(350.0f,35.0f), ocra);
  //state_i
  state_input.set_text_size(25);
  state_input.set_box_color(sf::Color(170,170,170,220));
  sf::Text state_label;
  state_label.setFont(ocra);
  state_label.setString("Enter text:");
  state_label.setCharacterSize(20);
  state_label.setPosition(sf::Vector2f(475.0f,33.0f));
  state_label.setFillColor(sf::Color::Red);


  Textbox date_input (sf::Vector2f(150.0f, 550.0f), sf::Vector2f(200.0f,35.0f), ocra);
  date_input.set_box_color(sf::Color(170,170,170,220));

  sf::Text date_label;
  
  date_label.setFont(ocra);
  date_label.setString("Date:");
  date_label.setCharacterSize(20);
  date_label.setPosition(sf::Vector2f(75.0f,550.0f));
  date_label.setFillColor(sf::Color::Red);



   // Textbox(sf::Vector2f position, int char_size, std::string to_write, sf::Font &font, sf::Color)
  Textbox help_str(sf::Vector2f(505.0f ,95.0f), 15, help, ocra, sf::Color::White);

  //float ypos, sf::Vector2f size, sf::Color color, std::string label, sf::Font & font
  Button btn0(70.0*0 , sf::Vector2f(btn_width,70.0f), sf::Color::Cyan, "Lookup Book", ocra);
  Button btn1(70.0*1 , sf::Vector2f(btn_width,70.0f), sf::Color::Cyan,"Checkout book", ocra );
  Button btn2(70.0*2, sf::Vector2f(btn_width,70.0f), sf::Color::Cyan, "User Management", ocra);
  Button btn3(70.0*3, sf::Vector2f(btn_width,70.0f), sf::Color::Cyan, "User Registration", ocra);
  Button btn4(70.0*4, sf::Vector2f(btn_width,70.0f), sf::Color::Cyan, "User Login", ocra);
  Button btn5(70.0*5, sf::Vector2f(btn_width,70.0f), sf::Color::Cyan, "Book Management", ocra);
  Button btn6(70.0*6, sf::Vector2f(btn_width,70.0f), sf::Color::Cyan, "help", ocra);

  Button butt_arr[7];
  butt_arr[0] = btn0;
  butt_arr[1] = btn1;
  butt_arr[2] = btn2;
  butt_arr[3] = btn3;
  butt_arr[4] = btn4;
  butt_arr[5] = btn5;
  butt_arr[6] = btn6;
  //Button btn1(70.0*7, sf::Vector2f(150.0f,70.0f), sf::Color::Cyan);




  sf::RectangleShape text_sq(sf::Vector2f(650.0f, 510.0f)); 
  text_sq.setFillColor(sf::Color(47,79,79,180));
  text_sq.setPosition(500,90);
  text_sq.setOutlineColor(sf::Color(35, 67,67,220));
  text_sq.setOutlineThickness(2.5f);


  
  Window.setSize(sf::Vector2u(1300,700)); 

  int index = 0;
  int cur_btn = -1;

  Window.setKeyRepeatEnabled(false);
  while(Window.isOpen())
  {
      Window.draw(back_g);
      for(int i = 0; i < 7; i++)
    {
      butt_arr[i].draw_to_screen(Window);

    }
    
    
    state_input.draw_to_screen(Window);
    Window.draw(state_label);
    date_input.draw_to_screen(Window);
    Window.draw(date_label);
    Window.draw(text_sq);
    
      sf::Event Event;
      while(Window.pollEvent(Event))
      {

        switch(Event.type)
        {
            case sf::Event::Closed:
                Window.close();
                break;
            case sf::Event::MouseMoved:
              {
                for (int i =0; i < NUMBTNS; i++)
                {
                  if (butt_arr[i].hover(Window))
                  {
                      butt_arr[i].set_color(sf::Color::Green);
                  }
                  else
                  {
                    {
                       butt_arr[i].set_color(sf::Color::Cyan);
                    }
                  }
                  
                }
              }

                //std::cout << "Mouse within bounds" << std::endl;
                break;
            case sf::Event::TextEntered:
            {
              if(state_input.get_selected())
              {
              write_to_screen(Event,state_input, state_input_str );
              }
              else if (date_input.get_selected())
              {
                write_to_screen(Event, date_input, date_input_str);
              }
               
              break;  
              
            }
            case sf::Event::MouseButtonPressed:
            {

          sf::Vector2i cur_pos= sf::Mouse::getPosition(Window);
          if(cur_pos.x < btn_width && cur_pos.y <= 70)
          {
            butt_arr[0].set_indicator(true);
            cur_btn = 0;
            help_str.set_text(lookup_book_str);
            reset_indicators(butt_arr, 0);
          }
          else if (cur_pos.x < btn_width && cur_pos.y <= 140)
          {
            butt_arr[1].set_indicator(true);
            cur_btn = 1;
            reset_indicators(butt_arr, 1);
          }
          else if (cur_pos.x < btn_width && cur_pos.y <= 210)
          {
            butt_arr[2].set_indicator(true);
            cur_btn = 2;
            reset_indicators(butt_arr, 2);
          }
          else if (cur_pos.x < btn_width && cur_pos.y <= 280)
          {
            butt_arr[3].set_indicator(true);
            cur_btn = 3;
            reset_indicators(butt_arr, 3);
          }
          else if (cur_pos.x < btn_width && cur_pos.y <= 350)
          {
            butt_arr[4].set_indicator(true);
            cur_btn = 4;
            reset_indicators(butt_arr, 4);
          }
          else if (cur_pos.x < btn_width && cur_pos.y <= 420)
          {
            butt_arr[5].set_indicator(true);
            cur_btn = 5;
            reset_indicators(butt_arr, 5);
          }
          else if (cur_pos.x < btn_width && cur_pos.y <= 490)
          {
            help_str.set_text(help);
            butt_arr[6].set_indicator(true);
            cur_btn = 6;
            reset_indicators(butt_arr, 6);
          }
          else if (cur_pos.x > 620.0f && cur_pos.x < 820.0f && cur_pos.y > 30.0f && cur_pos.y < 65.0f )
          {
            state_input.set_selected(true);
            //tate_input.set_text("selected state");

          }
          else if (cur_pos.x > 150.f && cur_pos.x < 350.0f && cur_pos.y > 550.0f && cur_pos.y < 585.0f)
          {
            date_input.set_selected(true);
            state_input.set_selected(false);
          }
          else
          {
            state_input.set_selected(false);
            date_input.set_selected(false);
          }
            }
                
        }
      
        /* if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

           
        } */
      }
    switch(cur_btn)
    {
        case -1:
        break;
        case 0:
        help_str.draw_to_screen(Window);
        break;
        case 1:
       // help_str.draw_to_screen(Window);
        break;
        case 2:
        break;
        case 3:
        break;
        case 4: // user login

        drawLoginPage(Window, cur_btn);
        break;
        case 5:
      //  std::cout << "case 5";
        break;
        case 6:
        //std::cout << "case 6";
        help_str.draw_to_screen(Window);
        break;


    }


      
      //square_0.getPosition///
      /* for(auto it = rect_vec->begin(); it != rect_vec->end(); it++)
      {
        Window.draw(*it);
      } */
      
    // for(auto it = button_vec->begin(); it != button_vec->end(); it++)





     /* for(auto x : button_vec)
     {
       int i = 0;
       //*it.draw_to_screen(Window);
       x->draw_to_screen(Window);
     } */


    
     
      /* Window.draw(text_sq);
      Window.draw(square_0);
      Window.draw(circle_0);
      Window.draw(square_1);
      Window.draw(square_2); */ 
      
      Window.display();

   
  }




}


void write_to_screen(sf::Event &Event, Textbox &tbox, std::string &out)//doesn't actually write to screen, more updates what will be
{
  std::cout << "writing to screen" << std::endl;
  std::string input;
  std::string str;
    if(Event.text.unicode != 13 && Event.text.unicode != 8) //carriage return. and backspace respectively.
    {
      str += Event.text.unicode;
      tbox.append(str);
    }
    else if( Event.text.unicode == 13)
    {
      input = tbox.get_string();
      out = input;
      std::cout << "entered: " << input ;
    }
    else
    {
      tbox.del_char();
     // std::cout << "\nleft del char\n";
      
    }
  input = tbox.get_string();
      //return input;

}

void drawLoginPage(sf::RenderWindow& Window, int &cur_btn){
  Window.clear();
  std::cout << "Drawing login page" << std::endl;
  sf::Texture background;
  background.loadFromFile("blk.png");

  sf::RectangleShape back_g(sf::Vector2f(1300.0f,700.0f));
  back_g.setTexture(&background);

  std::ifstream file;
  file.open("users.csv");

  sf::Font ocra;
  ocra.loadFromFile("OCRAEXT.TTF");
  Textbox state_input(sf::Vector2f(430.0f, 230.0f), sf::Vector2f(350.0f,35.0f), ocra);
  state_input.set_text_size(25);
  state_input.set_box_color(sf::Color(170,170,170,220));

  Textbox pass_input(sf::Vector2f(430.0f, 330.0f), sf::Vector2f(350.0f,35.0f), ocra);
  pass_input.set_text_size(25);
  pass_input.set_box_color(sf::Color(170,170,170,220));

  sf::Text loginText;
  loginText.setFont(ocra);
  loginText.setPosition(sf::Vector2f(400,30));
  loginText.setCharacterSize(70);
  loginText.setFillColor(sf::Color::Red);
  loginText.setString("User Login");

  sf::Text username;
  username.setFont(ocra);
  username.setPosition(sf::Vector2f(250,230));
  username.setCharacterSize(30);
  username.setFillColor(sf::Color::Red);
  username.setString("Username:");

  sf::Text password;
  password.setFont(ocra);
  password.setPosition(sf::Vector2f(250,330));
  password.setCharacterSize(30);
  password.setFillColor(sf::Color::Red);
  password.setString("Password:");

  sf::Text invalid;
  invalid.setFont(ocra);
  invalid.setPosition(sf::Vector2f(250,130));
  invalid.setCharacterSize(30);
  invalid.setFillColor(sf::Color::Red);
  invalid.setString("Invalid username/password, try again");

  Button verify(0, sf::Vector2f(180,40), sf::Color::White, std::string("Verify"), ocra);
  verify.set_pos(sf::Vector2f(800,400));

  Button back(0, sf::Vector2f(180,40), sf::Color::White, std::string("Back"), ocra);
  back.set_pos(sf::Vector2f(50,600));

  bool foundUser = false;

  while(Window.isOpen() && foundUser == false){
  sf::Event Event;
    while(Window.pollEvent(Event))
    {
      Window.draw(back_g);  
      state_input.draw_to_screen(Window);
      pass_input.draw_to_screen(Window);
      Window.draw(loginText);
      Window.draw(username);
      Window.draw(password);
      verify.draw_to_screen(Window);
      back.draw_to_screen(Window);
      switch(Event.type)
      {
          case sf::Event::Closed:
              Window.close();
              std::cout << "Successfully closed";
              break;
          case sf::Event::TextEntered: // enter text into the boxes
          {
            std::cout << "entering text" << std::endl;
              if(state_input.get_selected())
              {
                write_to_screen(Event,state_input,state_input_str);
              } else if(pass_input.get_selected()){
                write_to_screen(Event,pass_input,state_input_str);
              }
              break;
          }
          case sf::Event::MouseMoved:
          {
            if(verify.hover(Window))
              verify.set_color(sf::Color::Green);
            else
              verify.set_color(sf::Color::White);
            if(back.hover(Window))
              back.set_color(sf::Color::Green);
            else
              back.set_color(sf::Color::White);
            break;
          }
          case sf::Event::MouseButtonPressed: // check whether the user selected the boxes
          {
            sf::Vector2i cur_pos = sf::Mouse::getPosition(Window);
            if(cur_pos.x > 430 && cur_pos.x < 780 && cur_pos.y > 230 && cur_pos.y < 265){
              state_input.set_selected(true);
              pass_input.set_selected(false);
            }
            if(cur_pos.x > 430 && cur_pos.x < 780 && cur_pos.y > 330 && cur_pos.y < 365){
              pass_input.set_selected(true);
              state_input.set_selected(false);
            }
            if(cur_pos.x > verify.get_pos().x && cur_pos.x < verify.get_pos().x + verify.get_size().x && cur_pos.y > verify.get_pos().y && cur_pos.y < verify.get_pos().y + verify.get_size().y){ // if the user clicked verify check if they entered a real username and password
              verify.set_indicator(true);
              std::string username = state_input.get_string();
              std::string password = pass_input.get_string();
              //std::cout << username << std::endl;
              //std::cout << password << std::endl;
              std::string verifiedUsername;
              std::string verifiedPassword;
              while(!file.eof() && foundUser == false){
                getline(file,verifiedUsername,',');
                std::cout << verifiedUsername << std::endl;
                getline(file,verifiedPassword,'\n');
                std::cout << verifiedPassword << std::endl;
                if(verifiedUsername == username && verifiedPassword == password){
                  foundUser = true;
                  std::cout << "found user" << std::endl;
                  return;
                }
              }
              //Window.draw(invalid);
            } else {
              verify.set_indicator(false);
            }
            if(back.hover(Window)){
              cur_btn = -1;
              return;
            }
          }
      }
    }
  Window.display();
  }
  file.close();
  return;
}