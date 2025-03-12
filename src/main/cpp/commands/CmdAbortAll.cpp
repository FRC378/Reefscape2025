// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdAbortAll.h"
#include "Robot.h"


CmdAbortAll::CmdAbortAll() 
{
  AddRequirements(&g_robotContainer.m_elevator);
  AddRequirements(&g_robotContainer.m_algaeintake);
  AddRequirements(&g_robotContainer.m_chute);

}

// Called when the command is initially scheduled.
void CmdAbortAll::Initialize() 
{
  std::cout<<"--CmdAbortAll--"<<std::endl;
  g_robotContainer.m_elevator.Stop();
  g_robotContainer.m_algaeintake.StopMotors();
  g_robotContainer.m_chute.StopMotor(); 

}
