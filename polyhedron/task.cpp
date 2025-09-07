#include "graphics.h"
#include "task.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>
#include <iostream>
#define width 800
#define height 600

int point[16];
Figure::Figure (double *center1) 
{
   for(int i = 0;i<3;i++)
   center[i] = center1[i];
   
   ifstream inp("figure.txt");
   
   inp >> n_vertex >> n_face;
   
   vertex.resize(n_vertex, vector <double> (3));
   for (int i = 0; i < n_vertex; i++)
      for (int j = 0; j < 3; j++)
         inp >> vertex[i][j];
   
   face.resize(n_face, vector <int> (n_vertex));
   for (int i = 0; i < n_face; i++)
      for (int j = 0; j < 4; j++)
         inp >> face[i][j];
   
   inp.close();
}

void Figure:: rotate(int Dism)
{
   double phi = 15*M_PI/180;
   if(Dism == 0)
      {
      double t;
      for (int i = 0; i < n_vertex; i++)
      {
         t = vertex[i][0];
         vertex[i][0] = center[0] + (t-center[0])*cos(phi) + (vertex[i][1]-center[1])*sin(phi);
         vertex[i][1] = center[1] + (-1)*sin(phi)*(t - center[0]) + (vertex[i][1]-center[1])*cos(phi);
      }
   }
   if(Dism == 1)
      {
      double t;
      for (int i = 0; i < n_vertex; i++)
         {
         t = vertex[i][0];
         vertex[i][0] =center[0] + (t-center[0])*cos(phi) - (vertex[i][2]-center[2])*sin(phi);
         vertex[i][2] =center[2] + (t-center[0])*sin(phi) + (vertex[i][2]-center[2])*cos(phi);
      }
   }
   if(Dism == 2)
      {
      double t;
      for (int i = 0; i < n_vertex; i++)
      {
         t = vertex[i][1];
         vertex[i][1] =center[1] + (t-center[1])*cos(phi) + (vertex[i][2]-center[2])*sin(phi);
         vertex[i][2] =center[2] + (-1)*(t-center[1])*sin(phi) + (vertex[i][2]-center[2])*cos(phi);
      }
   }
}

void Figure::shift(int Dism)
{
   if(Dism == 0)
 {
   center[0] += 1;
   for (int i = 0; i < n_vertex; i++)
   vertex[i][0] += 10;
 }
 if(Dism == 1)
 {
   center[1] += 1;
   for (int i = 0; i < n_vertex; i++)
   vertex[i][1] += 10;
 }
 if(Dism == 2)
 {
   center[2] += 1;
   for (int i = 0; i < n_vertex; i++)
      vertex[i][2] += 10;
 }
}

void Figure:: drawXY() 
{
   for (int i = 0; i < n_face; i++) 
{
      int k = 0;
      for (int j = 0; j < 4; j++) 
   {
         point[2 * k] = width / 2  + vertex[face[i][j]][0];
         point[2 * k + 1] =  4*height / 8 - vertex[face[i][j]][1];
         k++;
      }
      drawpoly(k, point);
   }
}

void Figure:: drawXZ() 
{
   for (int i = 0; i < n_face; i++) 
   {
      int k = 0;
      for (int j = 0; j < 4; j++) 
      {
         point[2 * k] = width / 2 + vertex[face[i][j]][0];
         point[2 * k + 1] = 4*height / 8 - vertex[face[i][j]][2];
         k++;
      }
      drawpoly(k, point);
   }
}

void Figure:: drawYZ() 
{
   for (int i = 0; i < n_face; i++) 
   {
      int k = 0;
      for (int j = 0; j < 4; j++) 
      {
         point[2 * k] = width / 2 + vertex[face[i][j]][1];
         point[2 * k + 1] = 4*height / 8 - vertex[face[i][j]][2];
         k++;
      }
      drawpoly(k, point);
   }
}

void save()
{
   int width1, height1;
   IMAGE *output;

   width1 = getmaxx() + 1;
   height1 = getmaxy() + 1;
   output = createimage(width1, height1);

   getimage(0, 0, width1 - 1, height1 - 1, output);
   getimage(0, 0, width1- 1, height1- 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}
