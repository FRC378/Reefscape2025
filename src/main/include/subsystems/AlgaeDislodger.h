// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include "Constants.h"
#include <rev/config/SparkMaxConfig.h> 

class AlgaeDislodger : public frc2::SubsystemBase 
{
 public:
  AlgaeDislodger();

  void   Periodic() override;

  void   StopMotor(void);
  void   SetAlgaeDislodgerMotorPower(double power);
  double GetAlgaeDislodgerMotorPower(void);






 private:
 
  /// initialize Algae Dislodger motor 
  rev::spark::SparkMax m_algaedislodger{ALGAE_DISLODGER_MOTOR_CAN_ID, rev::spark::SparkMax::MotorType::kBrushed};

  bool m_manualControl;

};
