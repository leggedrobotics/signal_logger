/*
 * signal_logger_ros_traits.hpp
 *
 *  Created on: Feb 21, 2015
 *      Author: C. Dario Bellicoso
 */

#ifndef SIGNAL_LOGGER_ROS_TRAITS_HPP_
#define SIGNAL_LOGGER_ROS_TRAITS_HPP_

#include "signal_logger/LoggerBase.hpp"

#include "geometry_msgs/WrenchStamped.h"
#include "geometry_msgs/QuaternionStamped.h"

#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Char.h>

#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Int64MultiArray.h>
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Int8MultiArray.h>

#include <signal_logger_msgs/EigenMatrixDouble.h>
#include <signal_logger_msgs/EigenMatrixFloat.h>

#include "geometry_msgs/Vector3Stamped.h"
#include "kindr_msgs/VectorAtPosition.h"

namespace signal_logger_ros {

namespace traits {

// generic interface
template<typename LogType_, bool VectorAtPosition_ = false> struct slr_traits;

typedef signal_logger::LoggerBase base_type;

/*******************************
 * Specializations: core types *
 *******************************/
template<>
struct slr_traits<double> {
  typedef std_msgs::Float32 msgtype;
  static void updateMsg(const double* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
      msg.data = *vectorPtr_;
    }
};

template<>
struct slr_traits<float> {
  typedef std_msgs::Float32 msgtype;
  static void updateMsg(const float* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.data = *vectorPtr_;
  }
};

template<>
struct slr_traits<int> {
  typedef std_msgs::Int32 msgtype;
  static void updateMsg(const int* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.data = *vectorPtr_;
  }
};

template<>
struct slr_traits<short> {
  typedef std_msgs::Int8 msgtype;
  static void updateMsg(const short* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.data = *vectorPtr_;
  }
};

template<>
struct slr_traits<long> {
  typedef std_msgs::Int64 msgtype;
  static void updateMsg(const long* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.data = *vectorPtr_;
  }
};

template<>
struct slr_traits<char> {
  typedef std_msgs::Int8 msgtype;
  static void updateMsg(const char* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.data = *vectorPtr_;
  }
};

template<>
struct slr_traits<bool> {
  typedef std_msgs::Bool msgtype;
  static void updateMsg(const bool* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.data = *vectorPtr_;
  }
};
/********************************/


/********************************
 * Specializations: eigen types *
 ********************************/
template<>
struct slr_traits<Eigen::Ref<Eigen::Vector3d>> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const Eigen::Ref<Eigen::Vector3d>* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};
/********************************/


/********************************
 * Specializations: kindr types *
 ********************************/
template<>
struct slr_traits<base_type::KindrPositionD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrPositionD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrRotationQuaternionD> {
  typedef geometry_msgs::QuaternionStamped msgtype;
  static void updateMsg(const base_type::KindrRotationQuaternionD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.quaternion.w = vectorPtr_->w();
    msg.quaternion.x = vectorPtr_->x();
    msg.quaternion.y = vectorPtr_->y();
    msg.quaternion.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrEulerAnglesZyxD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrEulerAnglesZyxD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrAngularVelocityD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrAngularVelocityD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrLinearVelocityD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrLinearVelocityD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrLinearAccelerationD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrLinearAccelerationD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrAngularAccelerationD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrAngularAccelerationD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrForceD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrForceD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrTorqueD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrTorqueD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};

template<>
struct slr_traits<base_type::KindrVectorD> {
  typedef geometry_msgs::Vector3Stamped msgtype;
  static void updateMsg(const base_type::KindrVectorD* vectorPtr_, msgtype& msg, const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
  }
};
/********************************/

/***************************************************
 * Specializations: kindr vector at position types *
 ***************************************************/
template<>
struct slr_traits<base_type::KindrForceD, true> {
  typedef kindr_msgs::VectorAtPosition msgtype;
  static void updateMsg(const base_type::KindrForceD* vectorPtr_,
                        const base_type::KindrPositionD* positionPtr_,
                        const std::string& vectorFrameId,
                        const std::string& positionFrameId,
                        const std::string& name,
                        msgtype& msg,
                        const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.header.frame_id = vectorFrameId;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
    msg.position.x = positionPtr_->x();
    msg.position.y = positionPtr_->y();
    msg.position.z = positionPtr_->z();
    msg.position_frame_id = positionFrameId;
    msg.name = name;
    msg.type = kindr_msgs::VectorAtPosition::TYPE_FORCE;
  }
};

template<>
struct slr_traits<base_type::KindrTorqueD, true> {
  typedef kindr_msgs::VectorAtPosition msgtype;
  static void updateMsg(const base_type::KindrTorqueD* vectorPtr_,
                        const base_type::KindrPositionD* positionPtr_,
                        const std::string& vectorFrameId,
                        const std::string& positionFrameId,
                        const std::string& name,
                        msgtype& msg,
                        const ros::Time& timeStamp) {
    msg.header.stamp = timeStamp;
    msg.header.frame_id = vectorFrameId;
    msg.vector.x = vectorPtr_->x();
    msg.vector.y = vectorPtr_->y();
    msg.vector.z = vectorPtr_->z();
    msg.position.x = positionPtr_->x();
    msg.position.y = positionPtr_->y();
    msg.position.z = positionPtr_->z();
    msg.position_frame_id = positionFrameId;
    msg.name = name;
    msg.type = kindr_msgs::VectorAtPosition::TYPE_TORQUE;
  }
};
/***************************************************/

} /* namespace traits */

} /* namespace signal_logger_ros */

#endif /* SIGNAL_LOGGER_ROS_TRAITS_HPP_ */
