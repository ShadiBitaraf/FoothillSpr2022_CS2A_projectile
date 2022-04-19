//code for April 19, 2022 class
// We're gonna try and print the position of a bullet
//shot horizontally from an edge of a cliff

#include <iostream>

using namespace std;

//we plot the position of the bullet every 0.01 of a sec by using leading 
//spaces to offset the bullet position (*) from the beginning of the line
//horizontal distance travelled by the bullet is given by v * t.
//vertical distance travelled by the bullet is given by 1/2 (g * t^2)
void plot_bullet_positions(int v) { //v for velocity
    const size_t n_positions = 150; //1 position per 0.01 of a sec = 150 positions
    const double g = 9.8; 
    size_t v_distance_already_traveled = 0;

    for (size_t t = 0; t < n_positions; t++){ //you've gotta reseach what's the difference between ++i & i++
        double actual_time = t/100.0; //our time is measured in 0.01 of a sec
        size_t h_distance = v * actual_time;
        size_t v_distance = 0.5 * actual_time * actual_time * g;
        size_t v_distance_to_travel = v_distance - v_distance_already_traveled;

        //skip as many rows as determined by the vertical distance (y)
        //and print a line with the horizontal distance (x) represented by spaces
        //& vertical distance represented by blank lines

        //cout << "t = " << t << ", h_distance = " << h_distance << ", v_distance = " << v_distance << endl;

        for (size_t y = 0; y < v_distance_to_travel; y++) //no need for body ({}) since we only have 1 statement
            cout << endl;

        for (size_t x = 0; x < h_distance; x++)
            cout << ' ';
        cout << '*' << endl;

        v_distance_already_traveled = v_distance;
    }
}

int main() {
    int speed;

    //print a prompt to ask the user for the inital horizontal speed 
    //& read in the initial speed from the user via cin into speed
    cout << "Please type in the initial horizontal speed: ";
    cin >> speed;
    cout << "\nThe horizontal speed typed: " << speed;

    //call a function and pass it this speed and have it print out the 
    //bullet's trajectory
    plot_bullet_positions(speed);

    return 0;
}