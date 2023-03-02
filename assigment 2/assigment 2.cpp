#include <iostream>
#include "Header.h"
#include <cstdlib>
#include<ctime>
using namespace std;

void randompoints(points clustera[], points clusterb[],points pts[])
{
	srand((unsigned int)time(0));
	float x_upper = 90.0;
	float x_lower = 70.0;

	float y_upper = 40.0;
	float y_lower = 20.0;

	float p_upper = 100.0;
	float p_lower = 5.0;

	for (int i = 0; i < 200; i++)
	{
		float x = x_lower + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (x_upper - x_lower)));
		float y = y_lower + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (y_upper - y_lower)));
		
		clustera[i].setX(x);
		clustera[i].setY(y);
		clusterb[i].setX(x);
		clusterb[i].setY(y);
	
	}

	for (int j = 0; j < 200; j++)
	{
		float x = x_lower + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (x_upper - x_lower)));
		float y = y_lower + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (y_upper - y_lower)));

		clusterb[j].setX(x);
		clusterb[j].setY(y);

	}


	for (int k = 0; k < 200; k++)
	{
		float x = p_lower + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (p_upper - p_lower)));
		float y = p_lower + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (p_upper - p_lower)));
		
		pts[k].setX(x);
		pts[k].setY(y);
		


	}


}



points center(points cluster[], int num)
{
	float centre_x = 0.0;
	float centre_y = 0.0;
	points c;

	for (int i = 0; i < 200; i++)
	{
		centre_x = (centre_x + cluster[i].GetX());
		centre_y = (centre_y + cluster[i].GetY());

	}
	centre_x = centre_x / num;
	centre_y = centre_y / num;
	
	c.setX(centre_x);
	c.setY(centre_y);

	 return c;

	

}

void closest(points a[], points b[], points ptr[])
{
	points a_centre;
	points b_centre;
	points p;
	float a_distance;
	float b_distance;

	float x;
	float y;

	x = ptr->GetX();
	y = ptr->GetY();

	p.setX(x);
	p.setY(y);


	a_centre = center(a, 4);
	b_centre = center(b, 4);

	a_distance = a_centre.distance(p, a_centre);
	b_distance = b_centre.distance(p, b_centre);

	if (a_distance > b_distance)
	{
		cout << "the point p is closest to cluster b centre point" << endl;
	}
	else if (a_distance < b_distance)
	{
		cout << "the point p is closest to cluster a centre point" << endl;
	}
	else if (a_distance == b_distance)
	{
		cout << "the point p is equally close to both  cluster a and b's centre point" << endl;
		
	}


}






int main()
{

	int numforp = 20;
    points *ClusterA;
	points *ClusterB;
	points *p;

	points c;
	ClusterA = new points[4];
	ClusterB = new points[4];
	p = new points[4];


	
	
	randompoints(ClusterA, ClusterB,p);

	cout<<center(ClusterA, 4).GetX() << endl;
	cout << center(ClusterA, 4).GetY() << endl;
	 
	
	closest(ClusterA, ClusterB, p);
	
	
}