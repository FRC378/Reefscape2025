// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include "RobotConstants.h"

class Chute : public frc2::SubsystemBase {
 public:
  Chute();


  void Periodic() override;

  //bool   GetLimitSwitch(void);
  void   StopMotor(void);
  void   SetPinMotorPower(double power);
  double GetPinMotorEncoder(void);

  bool GetCoralDetectSensor(void);





 private:
  
  rev::spark::SparkMax m_pinMotor{CHUTE_PIN_MOTOR_CAN_ID,rev::spark::SparkMax::MotorType::kBrushless}; 
  rev::spark::SparkRelativeEncoder m_pinMotorEncoder = m_pinMotor.GetEncoder();

};
