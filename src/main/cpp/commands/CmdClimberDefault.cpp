// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberDefault.h"
#include "subsystems/Climber.h"
#include "Robot.h"


CmdClimberDefault::CmdClimberDefault() 
{
  AddRequirements(&g_robotContainer.m_climber);
}
void CmdClimberDefault::Initialize() 
{

}
void CmdClimberDefault::Execute() 
{
  const double deadband = 0.2;
  const double uppower   = 0.5;
  const double downpower = 0.5;
  double axis = -g_robotContainer.m_ctrl.GetRightY();
  if( (axis > deadband) && !g_robotContainer.m_climber.GetUpperLimitSwitch() ) 
  {
    g_robotContainer.m_climber.SetMotorPower(uppower);
  }
  
  else if( (axis < -deadband) && !g_robotContainer.m_climber.GetLowerLimitSwitch() )
  {
    g_robotContainer.m_climber.SetMotorPower(-downpower);
  }

  else
  {
    g_robotContainer.m_climber.StopMotor();
  }





}
void CmdClimberDefault::End(bool interrupted) 
{

}
bool CmdClimberDefault::IsFinished() 
{
  return false;
}
