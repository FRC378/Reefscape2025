// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

#include <frc2/command/button/CommandXboxController.h>
#include <frc/smartdashboard/SendableChooser.h>

//Subsystems
#include "subsystems/Drivetrain.h"     
#include "subsystems/AlgaeDislodger.h"
#include "subsystems/AlgaeIntake.h"   
#include "subsystems/Chute.h"         
#include "subsystems/Climber.h"     
#include "subsystems/Elevator.h"
#include "subsystems/LimeLight.h"  



class RobotContainer {
 public:
  RobotContainer();


  //****************Controllers*******************
  //frc2::CommandXboxController m_driver {0};
  frc2::CommandXboxController m_ctrl   {1};

  //****************Subsystems*******************
  Drivetrain     m_drivetrain;     
  AlgaeDislodger m_algaedislodger;
  AlgaeIntake    m_algaeintake;    
  Chute          m_chute;         
  Climber        m_climber;     
  Elevator       m_elevator;

  LimeLight      m_limelight3{"limelight-vthree"};
  LimeLight      m_limelight2{"limelight-vtwo"};     




  frc2::Command* GetAutonomousCommand();

 private:


  frc::SendableChooser<frc2::Command*> m_chooser;
  void ConfigureBindings();

};
