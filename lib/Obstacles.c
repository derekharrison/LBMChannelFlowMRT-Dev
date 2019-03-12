/*
 * Obstacles.c
 *
 *  Created on: 24 mei 2017
 *      Author: dharrison
 */


#include <stdlib.h>
#include "../inc/parameters.h"
#include "../inc/obstacle_objects.h"


void Obstacles()
{
    //rectangle(3.0, 3.0, 1.0, 1.0);

    //rectangle(60.0, 15.0, 10.0, 15.0);

    x_coordinate_circle = 13.5 * 30.0;
    y_coordinate_circle = 0.5 * Ny;
    circle_radius       = 15.0;

    circle(x_coordinate_circle, y_coordinate_circle, circle_radius);


    ///*
    double x_coordinate_circle2 = 17.5 * 30.0;
    double y_coordinate_circle2 = 0.5 * Ny;
    double circle_radius2       = 15.0;

    circle(x_coordinate_circle2, y_coordinate_circle2, circle_radius2);
    //*/

}

