// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chute.h"
#include  <rev/config/SparkMaxConfig.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"

#include <frc2/command/CommandScheduler.h>
#include "commands/CmdChuteClose.h"


Chute::Chute()
{
    

  m_coralOpenFlag = false;
}

// This method will be called once per scheduler run
void Chute::Periodic() 
{

  // const double pinUpPower  = 0.5;     //Pin UP, to eject coral
  // const double pinDownPower = 0.3;    //Pin down, to capture next coral

  // bool Xbtn = g_robotContainer.m_ctrl.X().Get();
  // bool Ybtn = g_robotContainer.m_ctrl.Y().Get();


  // if( Xbtn && !GetLimitSwitch() ) 
  // {
  //   SetPinMotorPower(pinUpPower);
  // }
  // else if( Ybtn  )
  // {
  //   SetPinMotorPower(-pinDownPower);
  // }
  // else
  // {
  //   SetPinMotorPower(0.0);
  // }


  frc::SmartDashboard::PutBoolean("ChutePinLimitSw",  GetLimitSwitch() );
  frc::SmartDashboard::PutBoolean("ChuteCoralDetect", GetCoralDetectSensor() );
  frc::SmartDashboard::PutBoolean("ChuteCoralOpen",   m_coralOpenFlag );


  c1 = GetCoralDetectSensor();

  if( c1 != c2 )
  {
    std::cout<<"Change "<<c1<<std::endl;
    c2 = c1;
  }




  //Check for OPEN and automatcally set flag
  if( GetLimitSwitch() )
  {
    m_coralOpenFlag = true;
  }


  


  //Call command when Coral is detected and OPEN to capture coral
  if( m_coralOpenAndClearFlag && GetCoralDetectSensor() )
  {

    //Create Instance
    CmdChuteClose* closeChuteCmd = new CmdChuteClose();

    // Schedule the command
    frc2::CommandScheduler::GetInstance().Schedule(closeChuteCmd);

  }


  if( m_coralOpenFlag &&  !GetCoralDetectSensor() )
  {
    m_coralOpenAndClearFlag =  true;
  }
  else if( GetCoralDetectSensor() )
  {
    m_coralOpenAndClearFlag = false;
  }
  



}

void   Chute::StopMotor(void)
{
  m_pinMotor.Set(0.0);
}
void   Chute::SetPinMotorPower(double power)
{
  m_pinMotor.Set(power);
}

bool   Chute::GetCoralDetectSensor(void)
{
  return !m_coralDetect.Get();  //sensor is inverted
}

bool Chute::GetLimitSwitch(void)
{
  return !m_pinMotorLimitSwitch.Get(); //Limit switch inverted
}




void Chute::SetCoralOpen(bool value)
{
  m_coralOpenFlag = value;
}
bool Chute::GetCoralOpen(void)
{
  return m_coralOpenFlag;
}