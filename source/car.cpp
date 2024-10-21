#include "car.h"

Car::Car(double _speed, double _position_x, double _position_y, double _angle, double _acceleration)
    : position_x(_position_x), position_y(_position_y), acceleration(_acceleration) {
    if (_speed >= 0 && 0 <= _angle && _angle <= 360) {
        this->speed = _speed;
        this->angle = _angle;
    }
    else {
        throw "value error";
    }
}

Car::Car(const Car& etalon) {
    this->speed = etalon.speed;
    this->position_x = etalon.position_x;
    this->position_y = etalon.position_y;
    this->angle = etalon.angle;
    this->acceleration = etalon.acceleration;
}

void Car::set_speed(double new_speed) {
    if (new_speed >= 0)
        this->speed = new_speed;
    else
        throw "value error";
}

void Car::set_position(double new_position_x, double new_position_y) {
    this->position_x = new_position_x;
    this->position_y = new_position_y;
}

void Car::set_angle(double new_angle) {
    if (new_angle >= 0 && new_angle <= 360)
        this->angle = new_angle;
    else
        throw "value error";
}

void Car::set_acceleration(double new_acceleration) {
    this->acceleration = new_acceleration;
}

void Car::move() {
    speed += this->acceleration;
    double radians = this->angle * PI / 180.0;
    this->position_x += speed * cos(radians);
    this->position_y += speed * sin(radians);
}

double Car::get_speed() {
    return this->speed;
}

pair<double, double> Car::get_position() {
    return make_pair(this->position_x, this->position_y);
}

double Car::get_angle() {
    return this->angle;
}

double Car::get_acceleration() {
    return this->acceleration;
}

vector<double> Car::get_all() {
    vector<double> status(5);
    status[0] = get_speed();
    status[1] = this->position_x;
    status[2] = this->position_y;
    status[3] = get_angle();
    status[4] = get_acceleration();
    return status;
}

BMW_n5::BMW_n5(double _speed, double _position_x, double _position_y, double _angle, double _acceleration)
    : Car(_speed, _position_x, _position_y, _angle, _acceleration) {}

void BMW_n5::speed_up() {
    if (get_acceleration() > 0)
        set_speed(get_speed() + get_acceleration());
}

void BMW_n5::speed_down() {
    if (get_acceleration() < 0) {
        if (get_speed() + get_acceleration() > 0)
            set_speed(get_speed() + get_acceleration());
        else
            throw "value error";
    }
}
