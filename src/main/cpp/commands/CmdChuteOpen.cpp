// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdChuteOpen.h"
#include "Robot.h"

CmdChuteOpen::CmdChuteOpen() 
{
  //Chute OPEN:  Lift pin to score coral

  AddRequirements( &g_robotContainer.m_chute );
}


void CmdChuteOpen::Initialize() 
{

  std::cout<<"CmdChuteOpen"<<std::endl;

  //Drive toward LimitSwitch
  g_robotContainer.m_chute.SetPinMotorPower( 0.75 );

  //Set timer as safety
  m_timer.Reset();
  m_timer.Start();
}


void CmdChuteOpen::Execute() 
{

}


void CmdChuteOpen::End(bool interrupted) 
{
  g_robotContainer.m_chute.SetPinMotorPower( 0.0 );
  m_timer.Stop();
}


bool CmdChuteOpen::IsFinished() 
{

  //Stop if hit limit switch
  if( g_robotContainer.m_chute.GetLimitSwitch() )
    return true;

  //Safety Timeout!
  if( m_timer.HasElapsed( units::second_t(.75) ) )
  {
      std::cout<<"CmdChuteOpen: Timeout"<<std::endl;
      return true;
  }

  return false;
}
