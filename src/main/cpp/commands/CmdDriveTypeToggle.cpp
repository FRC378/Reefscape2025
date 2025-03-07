// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveTypeToggle.h"
#include "Robot.h"
#include "subsystems/Drivetrain.h"


CmdDriveTypeToggle::CmdDriveTypeToggle() 
{

}


void CmdDriveTypeToggle::Initialize() 
{
  if( g_robotContainer.m_drivetrain.GetDriveType() == Drivetrain::ROBOTCENTRIC )
    g_robotContainer.m_drivetrain.SetDriveType(Drivetrain::FIELDCENTRIC);
  
  else
    g_robotContainer.m_drivetrain.SetDriveType(Drivetrain::ROBOTCENTRIC);
}
