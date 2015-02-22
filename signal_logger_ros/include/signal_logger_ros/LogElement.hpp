/*
 * LogElement.hpp
 *
 *  Created on: Feb 21, 2015
 *      Author: C. Dario Bellicoso
 */

#ifndef LOGELEMENT_HPP_
#define LOGELEMENT_HPP_

#include "signal_logger_ros/LogElementBase.hpp"
#include "signal_logger_ros/signal_logger_ros_traits.hpp"

#include <ros/ros.h>
#include <boost/any.hpp>

#include <realtime_tools/realtime_publisher.h>

namespace signal_logger_ros {

template <typename LogType_>
class LogElement : public LogElementBase {
 public:

  typedef traits::slr_traits<LogType_> Traits;

  LogElement() :
    topicName_(""),
    type_(Traits::varType),
    vectorPtr_(nullptr),
    positionPtr_(nullptr),
    rtPub_(nullptr)
  {

  }

  LogElement(const ros::NodeHandle& nodeHandle,
             const std::string& name,
             const LogType_* varPtr) :
    topicName_(name),
    type_(Traits::varType),
    vectorPtr_(varPtr),
    positionPtr_(nullptr)
  {
    rtPub_ = new realtime_tools::RealtimePublisher<typename Traits::msgtype>(nodeHandle, name, 100);
  }

  LogElement(const ros::NodeHandle& nodeHandle,
             const std::string& name,
             LogType_* varPtr,
             signal_logger::LoggerBase::KindrPositionD* positionPtr) :
    topicName_(name),
    type_(Traits::varType),
    vectorPtr_(varPtr),
    positionPtr_(positionPtr)
  {
    rtPub_ = new realtime_tools::RealtimePublisher<kindr_msgs::VectorAtPosition>(nodeHandle, name, 100);
  }

  LogElement(const ros::NodeHandle& nodeHandle,
             const std::string& topic,
             LogType_* varPtr,
             signal_logger::LoggerBase::KindrPositionD* positionPtr,
             const signal_logger::LoggerBase::KindrPositionD* pos,
             const std::string& vectorFrame,
             const std::string& positionFrame,
             const std::string& name
             ) :
    topicName_(topic),
    type_(Traits::varType),
    vectorPtr_(varPtr),
    positionPtr_(positionPtr)
  {
    rtPub_ = new realtime_tools::RealtimePublisher<kindr_msgs::VectorAtPosition>(nodeHandle, name, 100);
//    msg_.type = kindr_msgs::VectorAtPosition::TYPE_TYPELESS;
//    msg_.header.frame_id = vectorFrame;
//    msg_.position_frame_id = positionFrame;
//    msg_.name = name;
  }

  ~LogElement() {
  }

  virtual void setLogVarPointer(const LogType_* varPtr) {
    vectorPtr_ = varPtr;
  }

  virtual void setLogVarAtPositionPointer(const LogType_* varPtr,
                                          const signal_logger::LoggerBase::KindrPositionD* pos,
                                          const std::string& vectorFrame,
                                          const std::string& positionFrame,
                                          const std::string& name) {
    vectorPtr_ = varPtr;
    positionPtr_ = pos;
//    msg_.type = kindr_msgs::VectorAtPosition::TYPE_TYPELESS;
//    msg_.header.frame_id = vectorFrame;
//    msg_.position_frame_id = positionFrame;
//    msg_.name = name;
  }

  virtual const std::string& getTopicName() {
    return topicName_;
  }

  virtual void publish(const ros::Time& timeStamp) {
    typename Traits::msgtype msg;
    Traits::updateMsg(vectorPtr_, msg, timeStamp);
    if (rtPub_->trylock()) {
      rtPub_->msg_ = msg;
      rtPub_->unlockAndPublish();
    }
  }

 private:
  std::string topicName_;
  traits::VarType type_;
  kindr_msgs::VectorAtPosition::Type kindrMsgType_;
  const LogType_* vectorPtr_;
//  typename Traits::msgtype msg_;
  const signal_logger::LoggerBase::KindrPositionD* positionPtr_;
  realtime_tools::RealtimePublisher<typename Traits::msgtype>* rtPub_;
};

} /* namespace signal_logger_ros */

#endif /* LOGELEMENT_HPP_ */
