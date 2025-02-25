// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdChuteDefault.h"
#include "robot.h"
CmdChuteDefault::CmdChuteDefault() 
{
  AddRequirements(&g_robotContainer.m_chute);
}

// Called when the command is initially scheduled.
void CmdChuteDefault::Initialize() 
{
  m_currstate = 0;
}

// Called repeatedly when this Command is scheduled to run
void CmdChuteDefault::Execute() 
{
  //state 0 = idle, wait for button press
  //state 1 = pin moved
  //state 2 = wait for button released
  //state 3 = wait for pin return
  if(m_currstate == 0 )
  {
    if (g_robotContainer.m_ctrl.GetRightTriggerAxis() > 0.5)
    {
      g_robotContainer.m_chute.SetPinMotorPower(0.1);
      m_currstate = 1;
    }
  }

  if(m_currstate ==1)
  {
    if (g_robotContainer.m_chute.GetPinMotorEncoder() > 0.25)
    {
      g_robotContainer.m_chute.StopMotor();
      m_currstate = 2;
    }
  }

  if(m_currstate ==2)
  {
    if (g_robotContainer.m_ctrl.GetRightTriggerAxis() < 0.5)
    {
      g_robotContainer.m_chute.SetPinMotorPower(-0.1);
      m_currstate = 3;
    }
  }

  if(m_currstate ==3)
  {
    if (g_robotContainer.m_chute.GetPinMotorEncoder() <= 0)
    {
      g_robotContainer.m_chute.StopMotor();
      m_currstate = 0;
    }
  }















}

// Called once the command ends or is interrupted.
void CmdChuteDefault::End(bool interrupted) 
{

}

// Returns true when the command should end.
bool CmdChuteDefault::IsFinished() 
{
  return false;
}
