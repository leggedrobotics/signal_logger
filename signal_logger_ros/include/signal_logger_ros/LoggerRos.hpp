/************************************************************************
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2014,  Christian Gehring, Michael Bloesch,
 * Peter Fankhauser, C. Dario Bellicoso
 * All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Autonomous Systems Lab nor ETH Zurich
 *     nor the names of its contributors may be used to endorse or
 *     promote products derived from this software without specific
 *     prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * LoggerRos.hpp
 *
 *  Created on: Jan 27, 2015
 *      Author: C. Dario Bellicoso
 */

#ifndef LOGGERROS_HPP_
#define LOGGERROS_HPP_

#include "signal_logger_ros/LogElement.hpp"

namespace signal_logger_ros {

class LoggerRos : public signal_logger::LoggerBase {
 public:
  LoggerRos(ros::NodeHandle& nodeHandle);
  virtual ~LoggerRos();

  /****************
   * Util methods *
   ****************/
  virtual void initLogger(int updateFrequency, int samplingFrequency, double samplingTime, const std::string& logScriptFileName = std::string{LOGGER_DEFAULT_FILENAME});
  virtual void startLogger();
  virtual void stopLogger();
  virtual void saveLoggerData();
  virtual void updateLogger(bool updateScript = true);
  virtual void collectLoggerData();
  virtual void lockUpdate();
  virtual void stopAndSaveLoggerData();
  /****************/


  /****************
   * Core methods *
   ****************/
  virtual void addFloatToLog(float* var,    const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleToLog(double* var,  const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addIntToLog(int* var,        const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addShortToLog(short* var,    const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addLongToLog(long* var,      const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addCharToLog(char* var,      const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addBoolToLog(bool* var,      const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  /****************/


  /******************
   * Eigen wrappers *
   ******************/
  virtual void addDoubleEigenMatrixToLog(const Eigen::Ref<Eigen::MatrixXd>& var,              const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addFloatEigenMatrixToLog(const Eigen::Ref<Eigen::MatrixXf>& var,               const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addIntEigenMatrixToLog(const Eigen::Ref<Eigen::MatrixXi>& var,                 const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addShortEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXs>& var,          const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addLongEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXl>& var,           const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addCharEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXc>& var,           const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addUnsignedCharEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXUc>& var,  const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addBoolEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXb>& var,           const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleEigenVector3ToLog(const Eigen::Ref<Eigen::Vector3d>& var,             const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);

  virtual void addDoubleEigenMatrixToLog(const Eigen::Ref<Eigen::MatrixXd>& var,              const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addFloatEigenMatrixToLog(const Eigen::Ref<Eigen::MatrixXf>& var,               const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addIntEigenMatrixToLog(const Eigen::Ref<Eigen::MatrixXi>& var,                 const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addShortEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXs>& var,          const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addLongEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXl>& var,           const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addCharEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXc>& var,           const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addUnsignedCharEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXUc>& var,  const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addBoolEigenMatrixToLog(const Eigen::Ref<LoggerBase::MatrixXb>& var,           const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleEigenVector3ToLog(const Eigen::Ref<Eigen::Vector3d>& var,             const Eigen::Ref<LoggerBase::MatrixXstring>& names, const std::string& group = std::string {LOGGER_DEFAULT_GROUP_NAME }, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  /******************/


  /******************
   * Kindr wrappers *
   ******************/
  virtual void addDoubleKindrPositionToLog(const KindrPositionD& position,                      const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrRotationQuaternionToLog(const KindrRotationQuaternionD& rotation,  const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrEulerAnglesZyxToLog(const KindrEulerAnglesZyxD& rotation,          const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrLocalAngularVelocityToLog(const KindrAngularVelocityD& angVel,     const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrAngleAxisToLog(const KindrAngleAxisD& angleAxis,                   const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrRotationMatrixToLog(const KindrRotationMatrixD& rotMat,            const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrRotationVectorToLog(const KindrRotationVectorD& rotVec,            const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrLinearVelocityToLog(const KindrLinearVelocityD& linVel,            const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrLinearAccelerationToLog(const KindrLinearAccelerationD& linAcc,    const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrAngularAccelerationToLog(const KindrAngularAccelerationD& angAcc,  const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrForceToLog(const KindrForceD& force,                               const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrTorqueToLog(const KindrTorqueD& torque,                            const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrVectorToLog(const KindrVectorD& vector,                            const std::string& name, const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME}, const std::string& unit = std::string{LOGGER_DEFAULT_UNIT}, bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrVectorAtPositionToLog(const KindrVectorD& vector,
                                                   const KindrPositionD& position,
                                                   const std::string& name,
                                                   const std::string& vectorFrame = "world",
                                                   const std::string& positionFrame = "world",
                                                   const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME},
                                                   const std::string& unit = std::string{LOGGER_DEFAULT_UNIT},
                                                   bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrForceAtPositionToLog( const KindrForceD& force,
                                                   const KindrPositionD& position,
                                                   const std::string& name,
                                                   const std::string& forceFrame = "world",
                                                   const std::string& positionFrame = "world",
                                                   const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME},
                                                   const std::string& unit = std::string{LOGGER_DEFAULT_UNIT},
                                                   bool update = LOGGER_DEFAULT_UPDATE);
  virtual void addDoubleKindrTorqueAtPositionToLog(const KindrTorqueD& torque,
                                                   const KindrPositionD& position,
                                                   const std::string& name,
                                                   const std::string& torqueFrame = "world",
                                                   const std::string& positionFrame = "world",
                                                   const std::string& group = std::string{LOGGER_DEFAULT_GROUP_NAME},
                                                   const std::string& unit = std::string{LOGGER_DEFAULT_UNIT},
                                                   bool update = LOGGER_DEFAULT_UPDATE);

  /******************/

 protected:

  virtual bool checkIfVarCollected(const std::string& topicName, std::vector<LogElementBase*>::iterator& it);

  ros::NodeHandle& nodeHandle_;
  std::vector<LogElementBase*> collectedVars_;

  template<typename LogType_>
  void addVarToCollection(const std::string& topicName, const LogType_* varPtr) {
    std::vector<LogElementBase*>::iterator collectedIterator;
    if (checkIfVarCollected(topicName, collectedIterator)) {
      dynamic_cast<LogElement<LogType_>*>(*collectedIterator)->setLogVarPointer(varPtr);
    } else {
      collectedVars_.push_back(new LogElement<LogType_>(nodeHandle_, topicName, varPtr));
    }
  }

//  template <typename KindrType_, typename MsgType_>
//  void addKindr3DToCollectedVariables(const std::string& topicName, const LoggerRos::VarType& varType, const KindrType_* varPtr) {
//    std::vector<LoggerVarInfo>::iterator collectedIterator;
//    if (checkIfVarCollected(topicName, collectedIterator)) {
//      collectedIterator->vectorPtr_ = varPtr;
//    } else {
//      LoggerVarInfo varInfo(topicName);
//      varInfo.type_ = varType;
//      varInfo.vectorPtr_ = varPtr;
//      varInfo.rtPub_ = new realtime_tools::RealtimePublisher<MsgType_>(nodeHandle_, topicName, 100);
//      collectedVars_.push_back(varInfo);
//    }
//  }
//
//  template <typename VectorType_>
//  void addKindr3DVectorAtPositionToCollectedVariables(const std::string& topicName, const kindr_msgs::VectorAtPosition& kindrMsg, const VectorType_* varPtr, const KindrPositionD* position) {
//    std::vector<LoggerVarInfo>::iterator collectedIterator;
//    if (checkIfVarCollected(topicName, collectedIterator)) {
//      collectedIterator->vectorPtr_ = varPtr;
//      collectedIterator->positionPtr_ = position;
//    } else {
//      LoggerVarInfo varInfo(topicName);
//      varInfo.rtPub_ = new realtime_tools::RealtimePublisher<kindr_msgs::VectorAtPosition>(nodeHandle_, topicName, 100);
//      varInfo.type_ = LoggerRos::VarType::KindrVectorAtPositionType;
//
//      varInfo.kindrMsg_ = kindrMsg;
//      varInfo.vectorPtr_ = varPtr;
//      varInfo.positionPtr_ = position;
//      collectedVars_.push_back(varInfo);
//    }
//  }
//
//  template <typename ScalarType_, typename MsgType_>
//  void addScalarToCollectedVariables(const std::string& topicName, const LoggerRos::VarType& varType, ScalarType_* varPtr) {
//    std::vector<LoggerVarInfo>::iterator collectedIterator;
//    if (checkIfVarCollected(topicName, collectedIterator)) {
//      collectedIterator->vectorPtr_ = varPtr;
//    } else {
//      LoggerVarInfo varInfo(topicName);
////      varInfo.pub_ = nodeHandle_.advertise<traits::slr_traits<varType>::msgtype>(topicName, 100);
//      varInfo.pub_ = nodeHandle_.advertise<MsgType_>(topicName, 100);
//      varInfo.type_ = varType;
//      varInfo.vectorPtr_ = varPtr;
//      collectedVars_.push_back(varInfo);
//    }
//  }

};

} /* namespace signal_logger_ros */

#endif /* LOGGERROS_HPP_ */
