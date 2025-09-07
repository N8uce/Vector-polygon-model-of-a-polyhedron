#ifndef TASK_H
#define TASK_H
#include <vector>

using namespace std;

class Figure 
{
double center[3];
int n_vertex, n_face;
vector<vector<double>> vertex;
vector<vector<int>> face;
public:
Figure (double*);
void rotate(int);
void shift(int);
void drawXY();
void drawXZ();
void drawYZ();
};
void save();

#endif