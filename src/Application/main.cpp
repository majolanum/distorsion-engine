#include <iostream>
#include <SDL.h>

#include "main.h"
#include "Lib2D/Window.h"
#include "Lib2D/Sprite.h"
#include "Lib2D/DEBUG.h"
#include "Lib2D/InputManager.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, World!\n";
   Window* window = new Window();
   window->OpenWindow();
   Sprite* sprite = new Sprite("../../res/Lib2D/PlaceHolder.png");
   sprite->SetTextureSize(200, 200);
   
   DEBUG* DebugDraw = DEBUG::Get();
   DebugDraw->SetWindow(window);

   InputManager* im = InputManager::Get();
   SDL_Event event;
   while (true) { 
       window->ClearWindow();  

       while (SDL_PollEvent(&event))
       {
           im->Update(event);
       }
      
       DebugDraw->DrawRect(50,50, 50, 50,Color::Green);

       sprite->Draw(window);
       window->Present();

   }

   delete window;
   return 0;
}