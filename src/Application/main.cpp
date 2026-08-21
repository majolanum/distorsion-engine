#include <iostream>
#include <SDL.h>

#include "main.h"
#include "Lib2D/Window.h"
#include "Distortion_engine/Entity.h"
#include "Lib2D/DEBUG.h"
#include "Lib2D/Collider.h"
#include "Lib2D/InputManager.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, World!\n";
   Window* window = new Window();
   window->OpenWindow();
  
   
   DEBUG* DebugDraw = DEBUG::Get();
   DebugDraw->SetWindow(window);

   Sprite* sprite = new Sprite("../../res/Lib2D/PlaceHolder.png", 50, 50);
   Collider* test = new Collider(); 
   sprite->SetTextureSize(200, 200);
 


   InputManager* im = InputManager::Get();
   SDL_Event event;
   while (true) { 
       window->ClearWindow();  

       while (SDL_PollEvent(&event))
       {
           im->Update(event);
       }
       
       //DebugDraw->DrawRect(50,50, 50, 50,Color::Green);
       test->UpdateCollider(new Vector2f(50, 50), sprite->GetWidth(), sprite->GetWidth());
       DebugDraw->DrawRect(test->getpos().x, test->getpos().y, test->getpos().w, test->getpos().h, Color::Red);

       sprite->Draw(window);
       window->Present();

   }

   delete window;
   return 0;
}