/*
 * LogElementTypes.hpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Gabriel Hottiger
 */

#pragma once

#ifdef SILO_USE_KINDR
// kindr
#include <kindr/Core>
#endif

// Eigen
#include <Eigen/Core>

namespace signal_logger {

//! Time stamp pair <s,ns>
typedef std::pair<int64_t, int64_t> TimestampPair;

// Eigen
typedef Eigen::Vector3d  Vector3d;
typedef Eigen::MatrixXf  MatrixXf;
typedef Eigen::MatrixXd  MatrixXd;
typedef Eigen::MatrixXi  MatrixXi;
typedef Eigen::Matrix< long ,Eigen::Dynamic, Eigen::Dynamic >           MatrixXl;
typedef Eigen::Matrix< short ,Eigen::Dynamic, Eigen::Dynamic >          MatrixXs;
typedef Eigen::Matrix< char ,Eigen::Dynamic, Eigen::Dynamic >           MatrixXc;
typedef Eigen::Matrix< unsigned char ,Eigen::Dynamic, Eigen::Dynamic >  MatrixXUc;
typedef Eigen::Matrix< bool ,Eigen::Dynamic, Eigen::Dynamic >           MatrixXb;
typedef Eigen::Matrix< std::string ,Eigen::Dynamic, Eigen::Dynamic >    MatrixXstring;

#ifdef SILO_USE_KINDR

// Kindr
typedef kindr::Position3D             KindrPositionD;
typedef kindr::RotationQuaternionPD   KindrRotationQuaternionD;
typedef kindr::EulerAnglesZyxPD       KindrEulerAnglesZyxD;
typedef kindr::LocalAngularVelocityPD KindrAngularVelocityD;
typedef kindr::AngleAxisPD            KindrAngleAxisD;
typedef kindr::RotationMatrixPD       KindrRotationMatrixD;
typedef kindr::RotationVectorPD       KindrRotationVectorD;
typedef kindr::Velocity3D             KindrLinearVelocityD;
typedef kindr::Acceleration3D         KindrLinearAccelerationD;
typedef kindr::AngularAcceleration3D  KindrAngularAccelerationD;
typedef kindr::Force3D                KindrForceD;
typedef kindr::Torque3D               KindrTorqueD;
typedef kindr::VectorTypeless3D       KindrVectorD;

template<typename VectorType_>
struct KindrVectorAtPosition {
  VectorType_ vector;
  KindrPositionD position;
};



#endif

}
