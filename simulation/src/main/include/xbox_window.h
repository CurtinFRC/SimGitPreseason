#pragma once

#include "mockdata/DriverStationData.h"
#include "window.h"

class sim_xbox_window : public window {
 public:
  sim_xbox_window(int port) : window("Xbox Controller #" + std::to_string(port), 400, 250), port(port) {}

  virtual void on_open() override;
  virtual void render(cv::Mat &img) override;

  void on_left_click(int x, int y);
  void on_right_click(int x, int y);

 private:
  bool inside(cv::Point center, double radius, int x, int y, double *off_x, double *off_y);

  int              port;
  double           r = 75;
  cv::Point        cl{100, 150};
  cv::Point        cr{300, 150};
  HAL_JoystickAxes axes{6};
};