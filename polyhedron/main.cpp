#include "graphics.h"
#include "control.h"
#include "task.hpp"

double c[3] = {50,150,100};
Figure F(c);

void goC()
{
setfillstyle(1, BLACK);
bar(0, 0, 800, 599);
F.drawXZ();
}

int main() 
{
   initwindow(800, 800);

   line(0,600,800,600);
   create_control (SAVE, 700, 601, "save.bmp");
   create_control (EXIT, 750, 601, "exit.bmp");
   create_control (SHIFTX, 0, 601, "shiftX.bmp");
   create_control (SHIFTY, 101, 601, "shiftY.bmp");
   create_control (SHIFTZ, 201, 601, "shiftZ.bmp");
   create_control (ROTATEXY, 0, 701, "RTXY.bmp");
   create_control (ROTATEXZ, 101, 701, "RTXZ.bmp");
   create_control (ROTATEYZ, 201, 701, "RTYZ.bmp");
   goC();
   while (1) 
      {
      while (mousebuttons() != 1);
      switch (select_control()) 
      {
         case NONE: break;
         case SHIFTX : F.shift(0); goC();break;
         case SHIFTY : F.shift(1); goC(); break;
         case SHIFTZ : F.shift(2); goC(); break;
         case ROTATEXY: F.rotate(0);goC(); break;
         case ROTATEXZ: F.rotate(1);goC(); break;
         case ROTATEYZ: F.rotate(2);goC();break;
         case SAVE: save(); break;
         case EXIT: closegraph(); return 0;
      }
      delay(50);
   }
}

