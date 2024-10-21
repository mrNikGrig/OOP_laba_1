#ifndef CAR_H
#define CAR_H

#include <vector>
#include <utility>
#include <cmath>

using std::pair;
using std::make_pair;
using std::vector;

const double PI = 3.14159265358979323846;

class Car {
private:
    double speed;
    double position_x;
    double position_y;
    double angle;
    double acceleration;

public:
    Car(double _speed = 0, double _position_x = 0, double _position_y = 0, double _angle = 0, double _acceleration = 0);
    Car(const Car& etalon);

    void set_speed(double new_speed);
    void set_position(double new_position_x, double new_position_y);
    void set_angle(double new_angle);
    void set_acceleration(double new_acceleration);
    void move();

    double get_speed();
    pair<double, double> get_position();
    double get_angle();
    double get_acceleration();
    vector<double> get_all();
};

class BMW_n5 : public Car {
public:
    BMW_n5(double _speed = 0, double _position_x = 0, double _position_y = 0, double _angle = 0, double _acceleration = 0);

    void speed_up();
    void speed_down();
};

#endif
