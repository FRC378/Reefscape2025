// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>
#include "commands/CmdClimberDefault.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdElevatorSetPosition.h"
#include "commands/CmdElevatorDefault.h"
#include "commands/CmdAlgaeDislodgerDeploy.h"
#include "commands/CmdAlgaeDislodgerRetract.h"
#include "commands/CmdAlgaeIntakeEject.h"
RobotContainer::RobotContainer() 
{

  //******************** Subsystem Defaults ******************************
  m_elevator.SetDefaultCommand( CmdElevatorDefault() );
  m_climber.SetDefaultCommand( CmdClimberDefault() );


  //******************** Dashboard Buttons *******************************


  //**********************  AUTOs ****************************************




  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{

  //Controller Buttons
  m_ctrl.A().OnTrue( new CmdPrintText("A Button"));
  m_ctrl.B().OnTrue( new CmdPrintText("B Button"));
  m_ctrl.X().OnTrue( new CmdAlgaeDislodgerDeploy());
  m_ctrl.Y().OnTrue( new CmdAlgaeDislodgerRetract());

  m_ctrl.RightBumper().OnTrue( new CmdAlgaeIntakeEject());

  //m_ctrl.LeftTrigger().WhileTrue( score_coral );
  //m_ctrl.RightTrigger().WhileTrue( score_algae );


  //Controller DPad
  m_ctrl.POVUp().OnTrue(    new CmdElevatorSetPosition(10.0));
  m_ctrl.POVDown().OnTrue(  new CmdElevatorSetPosition(0.0));
  m_ctrl.POVLeft().OnTrue(  new CmdElevatorSetPosition(7.5));
  m_ctrl.POVRight().OnTrue( new CmdElevatorSetPosition(5.0));


  //Driver Buttons



}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  return frc2::cmd::Print("No autonomous command configured");
}
