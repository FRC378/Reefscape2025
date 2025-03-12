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
#include "commands/CmdAlgaeIntakeRetract.h"
#include "commands/CmdAlgaeIntakeDeploy.h"
#include "commands/CmdAbortAll.h"



//Autos
#include "commands/AutoDoNothing.h"
#include "commands/AutoCrossLine.h"
#include "commands/AutoStraightAhead.h"
#include "commands/AutoRightSide.h"
#include "commands/AutoLeftSide.h"
#include "commands/AutoStraightWithAlgae.h"

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

  frc::SmartDashboard::PutData( "Close Chute",    new CmdChuteClose() );
  frc::SmartDashboard::PutData( "Open Chute",     new CmdChuteOpen() );



  //**********************  AUTOs ****************************************
  m_chooser.SetDefaultOption("Auto Do Nothing",  new AutoDoNothing() );

  m_chooser.AddOption("Auto CrossLine",          new AutoCrossLine() );
  m_chooser.AddOption("Auto StraightAhead",      new AutoStraightAhead() );
  m_chooser.AddOption("Auto RightSide",          new AutoRightSide() );
  m_chooser.AddOption("Auto LeftSide",           new AutoLeftSide()  );
  m_chooser.AddOption("Auto StraightWithAlgae",  new AutoStraightWithAlgae()  );


  frc::SmartDashboard::PutData("Auto Mode", &m_chooser);

  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  //Controller Buttons
  m_ctrl.RightTrigger().OnTrue(  new CmdChuteOpen()  ); //Open chute when pressed
//m_ctrl.RightTrigger().OnFalse( new CmdChuteClose() ); //Close when released - Trigger doesn't close Chute anymore

  m_ctrl.LeftBumper().OnTrue( new CmdAbortAll());

  // A - Algae Intake Rollers IN  (in AlgaeIntake Subsystem)
  // B - Algae Intake Rollers OUT (in AlgaeIntake Subsystem)
  m_ctrl.X().OnTrue( new CmdAlgaeIntakeDeploy());
  m_ctrl.Y().OnTrue( new CmdAlgaeIntakeRetract());


  //Controller DPad: Elevator Control
  m_ctrl.POVUp().OnTrue(    new CmdElevatorSetLevel( ELEVATOR_L3   ));
  m_ctrl.POVRight().OnTrue( new CmdElevatorSetLevel( ELEVATOR_L2   ));
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
