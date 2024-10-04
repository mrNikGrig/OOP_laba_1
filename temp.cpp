#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

class Car {
private:
    double speed;
    double position_x;
    double position_y;
    double angle;
    double acceleration;

public:
    Car(double _speed = 0, double _position_x = 0, double _position_y = 0, double _angle = 0, double _acceleration = 0)
        : position_x(_position_x), position_y(_position_y), acceleration(_acceleration) {
        if (_speed >= 0 && 0 <= _angle && _angle <= 360) {
            this->speed = _speed;
            this->angle = _angle;
        }
        else {
            throw "value error";
        }
    }

    Car(const Car& etalon) {
        this->speed = etalon.speed;
        this->position_x = etalon.position_x;
        this->position_y = etalon.position_y;
        this->angle = etalon.angle;
        this->acceleration = etalon.acceleration;
    }

    void set_speed(double new_speed) {
        if (new_speed >= 0)
            this->speed = new_speed;
        else
            throw "value error";
    }

    void set_position(double new_position_x, double new_position_y) {
        this->position_x = new_position_x;
        this->position_y = new_position_y;
    }

    void set_angle(double new_angle) {
        if (new_angle >= 0 && new_angle <= 360)
            this->angle = new_angle;
        else
            throw "value error";
    }

    void set_acceleration(double new_acceleration) {
        this->acceleration = new_acceleration;
    }

    double get_speed() { return this->speed; }
    pair<double, double> get_position() { return make_pair(this->position_x, this->position_y); }
    double get_angle() { return this->angle; }
    double get_acceleration() { return this->acceleration; }

    vector<double> get_all() {
        vector<double> status(5);
        status[0] = get_speed();
        status[1] = this->position_x;
        status[2] = this->position_y;
        status[3] = get_angle();
        status[4] = get_acceleration();
        return status;
    }
};

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

    // Тест сеттера скорости
    double new_speed = 60;
    my_car.set_speed(new_speed);
    assert(my_car.get_speed() == new_speed);

    // Тест сеттера позиции
    double new_x = 15, new_y = 25;
    my_car.set_position(new_x, new_y);
    assert(my_car.get_position() == make_pair(new_x, new_y));

    // Тест сеттера угла
    double new_angle = 90;
    my_car.set_angle(new_angle);
    assert(my_car.get_angle() == new_angle);

    // Тест сеттера ускорения
    double new_acceleration = 9.8;
    my_car.set_acceleration(new_acceleration);
    assert(my_car.get_acceleration() == new_acceleration);

    return true;
}

int main() {
    assert(test_constructor());
    assert(test_setters());
    cout << "all test have been completed" << endl;
    return 0;
}
