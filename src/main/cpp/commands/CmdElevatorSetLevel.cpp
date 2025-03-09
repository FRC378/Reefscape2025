// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdElevatorSetLevel.h"
#include "Robot.h"


CmdElevatorSetLevel::CmdElevatorSetLevel( elevator_level_t level) 
{
  m_level = level;
}

// Called when the command is initially scheduled.
void CmdElevatorSetLevel::Initialize() 
{
  std::cout << "CmdElevatorSetLevel " << m_level << std::endl;
  g_robotContainer.m_elevator.SetLevel( m_level );
}
