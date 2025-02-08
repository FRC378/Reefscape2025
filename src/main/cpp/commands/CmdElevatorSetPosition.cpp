// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdElevatorSetPosition.h"
#include "Robot.h"


CmdElevatorSetPosition::CmdElevatorSetPosition( double position) 
{
  m_position = position;
}

// Called when the command is initially scheduled.
void CmdElevatorSetPosition::Initialize() 
{
  std::cout << "CmdElevatorSetPosition " << m_position << std::endl;
  g_robotContainer.m_elevator.SetPosition( m_position );
}
