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
  m_climber.SetDefaultCommand(CmdClimberDefault() );


  //******************** Dashboard Buttons *******************************


  //**********************  AUTOs ****************************************




  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{

  //Controller Buttons
  m_ctrl_AButton.OnTrue( new CmdPrintText("A Button"));
  m_ctrl_BButton.OnTrue( new CmdPrintText("B Button"));
  m_ctrl_XButton.OnTrue( new CmdAlgaeDislodgerDeploy());
  m_ctrl_YButton.OnTrue( new CmdAlgaeDislodgerRetract());
  m_ctrl_RightBumper.OnTrue( new CmdAlgaeIntakeEject());

  //Controller DPad
  m_ctrl_POVup.OnTrue(    new CmdElevatorSetPosition(10.0));
  m_ctrl_POVdown.OnTrue(  new CmdElevatorSetPosition(0.0));
  m_ctrl_POVleft.OnTrue(  new CmdElevatorSetPosition(7.5));
  m_ctrl_POVright.OnTrue( new CmdElevatorSetPosition(5.0));


  //Driver Buttons


}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  return frc2::cmd::Print("No autonomous command configured");
}
