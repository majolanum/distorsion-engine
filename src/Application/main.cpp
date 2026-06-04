#include <iostream>
#include <SDL.h>

#include "main.h"
#include "Lib2D/Window.h"
#include "Lib2D/Sprite.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, World!\n";
   Window* window = new Window();
   window->OpenWindow();
   Sprite* sprite = new Sprite("../../res/Lib2D/PlaceHolder.png");
   sprite->SetTextureSize(200, 200);
   while (true) { sprite->Draw(window); }
   delete window;
   return 0;
}