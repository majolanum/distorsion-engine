#include <iostream>
#include <SDL.h>

#include "main.h"
#include "Lib2D/Window.h"
#include "Lib2D/Sprite.h"
#include "Lib2D/DEBUG.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, World!\n";
   Window* window = new Window();
   window->OpenWindow();
   Sprite* sprite = new Sprite("../../res/Lib2D/PlaceHolder.png");
   sprite->SetTextureSize(200, 200);
   
   DEBUG* DebugDraw = DEBUG::Get();
   DebugDraw->SetWindow(window);


   
   while (true) { 
       window->ClearWindow();
       DebugDraw->DrawRect(50,50, 50, 50,Color::Green);

       sprite->Draw(window);
       window->Present();

   }
   delete window;
   return 0;
}