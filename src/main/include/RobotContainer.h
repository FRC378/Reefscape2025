// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/POVButton.h>

//Subsystems
#include "subsystems/Drivetrain.h"
#include "subsystems/AlgaeDislodger.h"
#include "subsystems/AlgaeIntake.h" 
#include "subsystems/Chute.h"
#include "subsystems/Climber.h"
#include "subsystems/Elevator.h"



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
  Elevator       m_elevator;




  frc2::CommandPtr GetAutonomousCommand();

 private:

  //Controller (Top) Buttons
  frc2::JoystickButton m_ctrl_XButton    {&m_ctrl,frc::XboxController::Button::kX};
  frc2::JoystickButton m_ctrl_BButton    {&m_ctrl,frc::XboxController::Button::kB};
  frc2::JoystickButton m_ctrl_YButton    {&m_ctrl,frc::XboxController::Button::kY};
  frc2::JoystickButton m_ctrl_AButton    {&m_ctrl,frc::XboxController::Button::kA};
 
  frc2::JoystickButton m_ctrl_LeftBumper {&m_ctrl,frc::XboxController::Button::kLeftBumper};
  frc2::JoystickButton m_ctrl_RightBumper{&m_ctrl,frc::XboxController::Button::kRightBumper};

  frc2::JoystickButton m_ctrl_BackButton {&m_ctrl,frc::XboxController::Button::kBack};
  frc2::JoystickButton m_ctrl_StartButton{&m_ctrl,frc::XboxController::Button::kStart};

  frc2::POVButton      m_ctrl_POVup      {&m_ctrl, 0};
  frc2::POVButton      m_ctrl_POVdown    {&m_ctrl, 180};
  frc2::POVButton      m_ctrl_POVleft    {&m_ctrl, 270};
  frc2::POVButton      m_ctrl_POVright   {&m_ctrl, 90};


  //Driver (Bottom) Buttons
  frc2::JoystickButton m_driver_StartButton{&m_driver, frc::XboxController::Button::kStart };
  frc2::JoystickButton m_driver_YButton    {&m_driver, frc::XboxController::Button::kY };
  frc2::JoystickButton m_driver_BButton    {&m_driver, frc::XboxController::Button::kB };
  frc2::JoystickButton m_driver_AButton    {&m_driver, frc::XboxController::Button::kA };



  void ConfigureBindings();

};
