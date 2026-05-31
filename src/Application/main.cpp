#include <iostream>
#include <SDL.h>

#include "main.h"
#include "Lib2D/Window.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, World!\n";
   Window* window = new Window();
   window->OpenWindow();
   int a;
   std::cin >> a;
   delete window;
   return 0;
}