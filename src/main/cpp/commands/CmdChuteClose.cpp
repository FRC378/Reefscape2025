// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdChuteClose.h"
#include "Robot.h"

CmdChuteClose::CmdChuteClose() 
{
  //Chute CLOSE:  Return pin to capture next coral piece

  AddRequirements( &g_robotContainer.m_chute );
}


void CmdChuteClose::Initialize()
{

  std::cout<<"CmdChuteClose"<<std::endl;

  //Set timer 
  m_timer.Reset();
  m_timer.Start();


  // if( g_robotContainer.m_chute.GetCoralOpen() )
  // {
    //Drive Away from LimitSwitch
    g_robotContainer.m_chute.SetPinMotorPower( -0.3 );    
  // }
  // else
  // {
  //   std::cout<<"  ** ABORT:  Chute Not Open!"<<std::endl;
  // }

}


void CmdChuteClose::Execute() {}


void CmdChuteClose::End(bool interrupted)
{
  g_robotContainer.m_chute.SetPinMotorPower( 0.0 );
  g_robotContainer.m_chute.SetCoralOpen(false);
  m_timer.Stop();
}


bool CmdChuteClose::IsFinished() 
{

  //Drive for time
  if( m_timer.HasElapsed( units::second_t( 0.25 ) ) )
      return true;


  return false;
}
