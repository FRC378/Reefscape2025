// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <frc/DigitalInput.h>
#include "Constants.h"
#include "commands/CmdChuteClose.h"

class Chute : public frc2::SubsystemBase {
 public:
  Chute();


  void Periodic() override;

  void StopMotor(void);
  void SetPinMotorPower(double power);

  bool GetLimitSwitch(void);
  bool GetCoralDetectSensor(void);

  void SetCoralOpen(bool value);
  bool GetCoralOpen(void);





 private:
  
  rev::spark::SparkMax m_pinMotor{CHUTE_PIN_MOTOR_CAN_ID,rev::spark::SparkMax::MotorType::kBrushed}; 


  frc::DigitalInput    m_pinMotorLimitSwitch{0};
  frc::DigitalInput    m_coralDetect{3};
  
  bool                 m_coralOpenFlag;  //Coral Pin is OPEN
  bool                 m_coralOpenAndClearFlag;


  bool c1;
  bool c2;

};
