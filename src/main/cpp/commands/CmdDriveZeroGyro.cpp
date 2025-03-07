// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveZeroGyro.h"
#include "Robot.h"


CmdDriveZeroGyro::CmdDriveZeroGyro() 
{

}

void CmdDriveZeroGyro::Initialize() 
{
  g_robotContainer.m_drivetrain.ZeroGyro();
}
