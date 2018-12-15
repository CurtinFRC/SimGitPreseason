/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/Spark.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/Encoder.h>
#include <frc/Timer.h>
#include <frc/drive/DifferentialDrive.h>

#include <usage.h>
#include "PendulumControlScript.h"
#include "robot_control.h"

#include <memory>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void Drive(double left, double right);

  double degrees_bound(double deg) {
    return std::fmod(deg + 180, 360) - 180;
  }

  double get_time() {
    return frc::Timer::GetFPGATimestamp();
  }

 private:
  // Don't touch this line!
  PendulumControlScript script;

  frc::Spark _left{0}, _right{1};

  robot_control _control;

  frc::XboxController _xbox{0};
};
