#include "robot_control.h"
#include "math.h"

// Group 2: 
//  Do the logic for creating the control signal based on a previous class.
std::pair<double, double> robot_control::get_control_signal(frc::XboxController &xbox) {
  double xspeed = xbox.GetX(frc::XboxController::JoystickHand::kLeftHand);
  double yspeed = -xbox.GetY(frc::XboxController::JoystickHand::kRightHand);

  std::pair<double, double> signal;
  // Do your logic here!
  signal.first = yspeed * abs(yspeed) - 0.5 * (xspeed * abs(xspeed));
  signal.second = yspeed * abs(yspeed) + 0.5 * (xspeed * abs(xspeed));
  
  return signal;
}