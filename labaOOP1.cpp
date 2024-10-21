#include <iostream>
#include <cassert>
#include "source/car.h"

using namespace std;

bool test_constructor() {
    Car my_car(50, 10, 20, 30, 5);
    assert(my_car.get_speed() == 50);
    assert(my_car.get_position() == make_pair(10.0, 20.0));
    assert(my_car.get_angle() == 30);
    assert(my_car.get_acceleration() == 5);

    Car second_car;
    assert(second_car.get_speed() == 0);
    assert(second_car.get_position() == make_pair(0.0, 0.0));
    assert(second_car.get_angle() == 0);
    assert(second_car.get_acceleration() == 0);

    return true;
}

bool test_setters() {
    Car my_car;
    double new_speed = 60;
    my_car.set_speed(new_speed);
    assert(my_car.get_speed() == new_speed);

    double new_x = 15, new_y = 25;
    my_car.set_position(new_x, new_y);
    assert(my_car.get_position() == make_pair(new_x, new_y));

    double new_angle = 90;
    my_car.set_angle(new_angle);
    assert(my_car.get_angle() == new_angle);

    double new_acceleration = 9.8;
    my_car.set_acceleration(new_acceleration);
    assert(my_car.get_acceleration() == new_acceleration);

    return true;
}

bool test_moving() {
    Car my_car(10, 0, 0, 0, 0);
    my_car.move();
    assert(my_car.get_position() == make_pair(10.0, 0.0));
    return true;
}

bool test_speed_change() {
    BMW_n5 my_car(10);
    my_car.set_acceleration(10);
    my_car.speed_up();
    assert(my_car.get_speed() == 20);

    my_car.set_acceleration(-10);
    my_car.speed_down();
    assert(my_car.get_speed() == 10);

    return true;
}

int main() {
    assert(test_constructor());
    assert(test_setters());
    assert(test_moving());
    assert(test_speed_change());

    cout << "All tests have been completed." << endl;
    return 0;
}
