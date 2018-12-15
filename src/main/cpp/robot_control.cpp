#include "robot_control.h"

const double xbox_deadzone = 0.05;

std::pair<double, double> robot_control::get_control_signal(frc::XboxController &xbox) {
  double yspeed = -xbox.GetX(frc::XboxController::JoystickHand::kRightHand);
  double xspeed = xbox.GetY(frc::XboxController::JoystickHand::kLeftHand);

  std::pair<double, double> signal;

  if (abs(xspeed) < xbox_deadzone) xspeed = 0;
  if (abs(yspeed) < xbox_deadzone) yspeed = 0;

  xspeed *= abs(xspeed);
  yspeed *= abs(yspeed);
  
  signal.first = yspeed + xspeed;
  signal.second = yspeed - xspeed;

  return signal;
}
