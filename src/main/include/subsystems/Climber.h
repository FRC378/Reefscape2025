// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include "RobotConstants.h"




class Climber : public frc2::SubsystemBase {
 public:
  Climber();

 bool GetUpperLimitSwitch(void);
 bool GetLowerLimitSwitch(void);
 void StopMotor(void);
 void SetMotorPower(double power);
 double GetMotorPower(void);

  void Periodic() override;

 private:

  rev::spark::SparkMax m_motor{CLIMBER_MOTOR_CAN_ID,rev::spark::SparkMax::MotorType::kBrushless};
};
