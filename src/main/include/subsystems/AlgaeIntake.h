// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <frc/DigitalInput.h>
#include "Constants.h"

class AlgaeIntake : public frc2::SubsystemBase {
 public:
  AlgaeIntake();

  bool   GetUpperLimitSwitch(void);
  void   StopMotors(void);
  void   SetSwingMotorPower(double power);
  void   SetIntakeMotorPower(double power);

  bool   GetAlgaeDetect(void);
  void   Periodic() override;

 private:

  rev::spark::SparkMax m_intakeMotor{ALGAEINTAKE_INTAKE_MOTOR_CAN_ID,rev::spark::SparkMax::MotorType::kBrushless};

  rev::spark::SparkMax m_swingMotor{ALGAEINTAKE_SWING_MOTOR_CAN_ID,rev::spark::SparkMax::MotorType::kBrushed};

  frc::DigitalInput    m_swingMotorTopLimitSwitch{2};

};
