// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <frc/DigitalInput.h>
#include "Constants.h"

class Chute : public frc2::SubsystemBase {
 public:
  Chute();


  void Periodic() override;

  void StopMotor(void);
  void SetPinMotorPower(double power);

  bool GetLimitSwitch(void);
  bool GetCoralDetectSensor(void);





 private:
  
  rev::spark::SparkMax m_pinMotor{CHUTE_PIN_MOTOR_CAN_ID,rev::spark::SparkMax::MotorType::kBrushed}; 

  frc::DigitalInput    m_pinMotorLimitSwitch{0};

};
