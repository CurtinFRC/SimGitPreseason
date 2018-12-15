#include "Robot.h"

#include <stack.h>

#include <iostream>

void Robot::RobotInit() {
  usage::drivetrain(_left.GetChannel(), _right.GetChannel());

  usage::xbox(_xbox.GetPort());
}

void Robot::RobotPeriodic() {
  std::pair<double, double> signal = _control.get_control_signal(_xbox);
  Drive(signal.first, signal.second);
}

void Robot::Drive(double left, double right) {
  _left.Set(left);
  _right.Set(right);

  // 4-long double 'array'
  double array[4];
  std::pair<std::pair<double, double>, std::pair<double, double>> betterArray;
}
