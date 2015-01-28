#include "View.h"

View::View()
{
	size = 11;
	scale = 2;
	Cart_Point origin;
}

void View::clear()
{
	for(int iy = 0; iy < size; iy++)
		for(int ix = 0; ix < size; ix++)
		{
			grid[iy][ix][0] = '.';
			grid[iy][ix][1] = ' ';
		}
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	ix = (location.x - origin.x)/scale;
	iy = (location.y - origin.y)/scale;
	if ( ix <= size && iy <= size)
		return true;
	else {
		cout << "An object is outside the display" << endl;
		return false;
	}
}

void View::plot(Game_Object * ptr)
{
	int tempx = ptr->get_location().x;
	int tempy = ptr->get_location().y;
	if(get_subscripts(tempx, tempy, ptr->get_location()))
	{
		if (grid[tempy][tempx][0] == '.' && grid[tempy][tempx][1] == ' ')
		{
			ptr->drawself(grid[tempy][tempx]);
		}
		else 
		{
			grid[tempy][tempx][0] = '*';
			grid[tempy][tempx][1] = ' ';
		}
	}
}

void View::draw()
{
	for(int iy = 0; iy < size; iy++)
	{
		if(iy%2 == 0)  //y-axis
		{ 
			cout << view_maxsize - 2*iy;
			if (iy > 5) //for formating, #<10 got extra space
				cout << " ";
		}
		else
			cout << "  ";
		for(int ix = 0; ix < size; ix++) //x-axis
		{
			cout << grid[size - 1 - iy][ix][0] << grid[size - 1 - iy][ix][1];
		}
		cout << endl;
	}
	for(int k = 0; k <=20; k = k+4)
	{
		cout << "  ";
		cout << k;
		if (k < 10)
			cout << " ";
	}
	cout << endl;
}