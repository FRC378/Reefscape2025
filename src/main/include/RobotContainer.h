// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

//Subsystems
#include "subsystems/Drivetrain.h"

#include "subsystems/AlgaeDislodger.h"

#include "subsystems/AlgaeIntake.h" 

#include "subsystems/Chute.h"

#include "subsystems/Climber.h"

#include <frc/XboxController.h>




class RobotContainer {
 public:
  RobotContainer();


  //****************Controllers*******************
  frc::XboxController m_driver {0};
  frc::XboxController m_ctrl   {1};
  //****************Subsystems*******************
  Drivetrain     m_drivetrain;
  AlgaeDislodger m_algaedislodger;
  AlgaeIntake    m_algaeintake;
  Chute          m_chute;
  Climber        m_climber;





  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();

  




};
