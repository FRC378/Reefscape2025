// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/SparkRelativeEncoder.h>
#include <rev/SparkClosedLoopController.h>
#include "Constants.h"

typedef enum { ELEVATOR_HOME, ELEVATOR_L2, ELEVATOR_L3, ELEVATOR_AUX } elevator_level_t;

class Elevator : public frc2::SubsystemBase {
 public:
  Elevator();

  void   Stop(void);

  bool   GetLowerLimitSwitch(void);
  bool   GetUpperLimitSwitch(void);
  double GetPosition(void);

  void   SetPosition(double position);
  void   SetLevel(elevator_level_t level);
  void   SetPower(double power);

  void   ZeroEncoder(void);

  void   Periodic() override;

 private:

 rev::spark::SparkMax m_elevator{ELEVATOR_MOTOR_CAN_ID, rev::spark::SparkMax::MotorType::kBrushless};
 rev::spark::SparkRelativeEncoder m_motorEncoder = m_elevator.GetEncoder();
 rev::spark::SparkClosedLoopController m_motorPID = m_elevator.GetClosedLoopController();


};
