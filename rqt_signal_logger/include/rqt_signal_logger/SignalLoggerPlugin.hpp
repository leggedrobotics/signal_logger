/*
 * ParametersPlugin.hpp
 *
 *  Created on: August 2016
 *      Author: Christian Gehring
 */

#pragma once

#include <rqt_gui_cpp/plugin.h>
#include <ui_signal_logger_plugin.h>
#include <QWidget>
#include <QDoubleSpinBox>
#include <QScrollArea>

#include <rqt_signal_logger/LogElement.hpp>

#include <ros/ros.h>
#include <std_srvs/Empty.h>

#include <signal_logger_msgs/SetLoggerElement.h>
#include <signal_logger_msgs/GetLoggerElement.h>
#include <signal_logger_msgs/GetLoggerInfo.h>

#include <list>
#include <memory>

class SignalLoggerPlugin : public rqt_gui_cpp::Plugin {
  Q_OBJECT
public:
  SignalLoggerPlugin();
  virtual void initPlugin(qt_gui_cpp::PluginContext& context);
  virtual void shutdownPlugin();
  virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
  virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);
private:
  Ui::SignalLogger ui_;
  QWidget* widget_;
  QGridLayout* paramsGrid_;
  QWidget* paramsWidget_;
  QWidget* paramsScrollHelperWidget_;
  QVBoxLayout* paramsScrollLayout_;

  // ROS services
  ros::ServiceClient getLogElementList_;
  ros::ServiceClient getLogElementClient_;
  ros::ServiceClient setLogElementClient_;

  std::list<std::shared_ptr<LogElement>> logElements_;
  std::vector<std::string> logElementNames_;

 protected slots:
  void refreshAll();
  void changeAll();
  void drawParamList();

signals:
  void parametersChanged();

};

