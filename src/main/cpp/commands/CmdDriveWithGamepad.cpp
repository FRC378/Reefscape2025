// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithGamepad.h"
#include "Robot.h"
#include <frc/MathUtil.h>
#include "subsystems/Drivetrain.h"

CmdDriveWithGamepad::CmdDriveWithGamepad()
{

  AddRequirements( &g_robotContainer.m_drivetrain );
}


void CmdDriveWithGamepad::Initialize() 
{
  std::cout<<"Starting CmdDriveWithGamepad"<<std::endl;
}


void CmdDriveWithGamepad::Execute() 
{

  const double DEADBAND  = 0.05;

  //Get Gamepad input
  double leftY  = -frc::ApplyDeadband( g_robotContainer.m_driver.GetLeftY(),  DEADBAND, 1.0 );  //invert: Positive is forward
  double leftX  = -frc::ApplyDeadband( g_robotContainer.m_driver.GetLeftX(),  DEADBAND, 1.0 );  //invert: Positive is left
  double rightX = -frc::ApplyDeadband( g_robotContainer.m_driver.GetRightX(), DEADBAND, 1.0 );  //Invert: Positive is CCW



  //WPILib kinematics uses X-axis as forward, and Y-axis sideways.  Swap joystick inputs when calling Drive
  g_robotContainer.m_drivetrain.Drive(leftY, leftX, rightX,  g_robotContainer.m_drivetrain.GetDriveType() );

}


void CmdDriveWithGamepad::End(bool interrupted) 
{
  std::cout<<"End CmdDriveWithGamepad " << interrupted <<std::endl;
}


bool CmdDriveWithGamepad::IsFinished() 
{
  return false;
}
