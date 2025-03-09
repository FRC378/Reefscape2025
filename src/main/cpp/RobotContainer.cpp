//
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project

#include "RobotContainer.h"

#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/CmdPrintText.h"
#include "commands/CmdClimberDefault.h"
#include "commands/CmdElevatorDefault.h"

#include "commands/CmdElevatorSetPosition.h"
#include "commands/CmdElevatorSetLevel.h"
#include "commands/CmdChuteClose.h"
#include "commands/CmdChuteOpen.h"
// #include "commands/CmdAlgaeDislodgerDeploy.h"
// #include "commands/CmdAlgaeDislodgerRetract.h"
// #include "commands/CmdAlgaeIntakeEject.h"

#include "commands/CmdDriveWithGamepad.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveForceTurnAngle.h"
#include "commands/CmdDriveForcePark.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveTypeToggle.h"
#include "commands/CmdDriveWithPower.h"
#include "commands/CmdDriveZeroGyro.h"
#include "commands/GrpTest1.h"



//Autos
#include "commands/AutoDoNothing.h"


RobotContainer::RobotContainer() 
{

  //******************** Subsystem Defaults ******************************
  m_drivetrain.SetDefaultCommand( CmdDriveWithGamepad() );
  m_elevator.SetDefaultCommand( CmdElevatorDefault() );
  m_climber.SetDefaultCommand( CmdClimberDefault() );


  //******************** Dashboard Buttons *******************************
  frc::SmartDashboard::PutData( "CmdDriveClearAll",  new CmdDriveClearAll() );
  frc::SmartDashboard::PutData( "Force 0",        new CmdDriveForceTurnAngle( 0.0  ) );
  frc::SmartDashboard::PutData( "Force 90",       new CmdDriveForceTurnAngle( 90.0 ) );

  frc::SmartDashboard::PutData( "DriveToggle",    new CmdDriveTypeToggle() );
  frc::SmartDashboard::PutData( "DriveWithPower", new CmdDriveWithPower( .5, 150, 0) );
  frc::SmartDashboard::PutData( "GprTest1",       new GrpTest1() );


  //**********************  AUTOs ****************************************
  m_chooser.SetDefaultOption("Auto Do Nothing",    new AutoDoNothing() );




  frc::SmartDashboard::PutData("Auto Mode", &m_chooser);

  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  //Controller Buttons
  m_ctrl.RightTrigger().OnTrue(  new CmdChuteOpen()  ); //Open chute when pressed
  m_ctrl.RightTrigger().OnFalse( new CmdChuteClose() ); //Close when released



  // m_ctrl.A().OnTrue( new CmdPrintText("A Button"));
  // m_ctrl.B().OnTrue( new CmdPrintText("B Button"));
  // m_ctrl.X().OnTrue( new CmdAlgaeDislodgerDeploy());
  // m_ctrl.Y().OnTrue( new CmdAlgaeDislodgerRetract());

  // m_ctrl.RightBumper().OnTrue( new CmdAlgaeIntakeEject());

  // //m_ctrl.LeftTrigger().WhileTrue( score_coral );
  // //m_ctrl.RightTrigger().WhileTrue( score_algae );



  //Controller DPad: Elevator Control
  m_ctrl.POVUp().OnTrue(    new CmdElevatorSetLevel( ELEVATOR_L2   ));
  m_ctrl.POVRight().OnTrue( new CmdElevatorSetLevel( ELEVATOR_L1   ));
  m_ctrl.POVDown().OnTrue(  new CmdElevatorSetLevel( ELEVATOR_HOME ));

  m_ctrl.POVLeft().OnTrue(  new CmdElevatorSetLevel( ELEVATOR_AUX  ));
 



  //Driver Buttons
  m_driver.X().OnTrue( new CmdDriveForcePark() );
  m_driver.Y().OnTrue( new CmdDriveForceTurnAngle( 0.0 ) );
  m_driver.Start().OnTrue( new CmdDriveZeroGyro() );



}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  return m_chooser.GetSelected();
}
