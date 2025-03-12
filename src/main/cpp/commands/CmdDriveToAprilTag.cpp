// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveToAprilTag.h"
#include "Robot.h"


//heading - heading to maintain during entire operation

CmdDriveToAprilTag::CmdDriveToAprilTag(  double heading ) 
{
  m_inputH = heading;
}


void CmdDriveToAprilTag::Initialize() 
{
  m_currState = 0;
  m_prevState = 0;


  m_timer.Reset();
  m_timer.Start();

  std::cout<< "CmdDriveToAprilTag" << std::endl;
}


void CmdDriveToAprilTag::Execute() 
{



  const double STRAFE_MAX_VELOCITY = .25; 
  const double STRAFE_Kp           = (0.01 / 1.0);  //0.5 at 1 degree error

  // *** REMEMBER:  We are going BACKWARDs!  Controls are inverted

  double vx = 0;
  double vy = 0;
  double yAngle;
  double currX;
  double currY;

  double deltaX,deltaY;



  switch( m_currState )
  {


    //Drive Straight ahead and search for AprilTag
    case 0:

      vx = -0.4;
      vy = 0;

      //Detect AprilTag!
      if( g_robotContainer.m_limelight3.IsTargetValid() )
      {
        std::cout<< "Target:" << g_robotContainer.m_limelight3.GetTargetId() << std::endl;
        m_currState++;
      }

      //Timeout
      if( m_timer.HasElapsed( 2.0_s) )
      {
        std::cout<< "Timeout" << std::endl;
        m_currState = 10; //Abort!
      }

      break;



    //Drive towards apriltag, maintain zero deltaY, until we lose AprilTag 
    case 1:

      vx = -0.3;      
      vy = 0;

      //Keep moveing forward until we lose Apriltag
      if( !g_robotContainer.m_limelight3.IsTargetValid() )
      {
        m_currState++;
        break;
      }


      //Get Angle to April Tag.  wanto to reduce this to zero
      yAngle = -g_robotContainer.m_limelight3.GetTargetHAngle();

      vy = yAngle * STRAFE_Kp;

      //Limit max drive
      if( vy >  STRAFE_MAX_VELOCITY ) vy =  STRAFE_MAX_VELOCITY;
      if( vy < -STRAFE_MAX_VELOCITY ) vy = -STRAFE_MAX_VELOCITY;


      //Keep moveing forward until we lose Apriltag
      if( !g_robotContainer.m_limelight3.IsTargetValid() )
      {
        m_timer.Restart();  //Restart timer
        m_currState++;
      }
      break;


    //Drive until X stops incrementing 
    case 2:

      vx = -0.25;      
      vy = 0;


      currX = g_robotContainer.m_drivetrain.GetOdometryX();
      currY = g_robotContainer.m_drivetrain.GetOdometryY();

      deltaX = m_prevXValue - currX;
      deltaY = m_prevyValue - currY;

      //if(  ( abs( deltaX) + abs(deltaY) )  < 0.25 )
      if(  deltaX*deltaX + deltaY*deltaY   < 0.1 ) 
      {
        m_currState++; //DONE!
        std::cout<< "S2 Done!" << std::endl;
      }


      std::cout<< "S2: " <<  deltaX*deltaX + deltaY*deltaY   << std::endl;

      m_prevXValue = currX;
      m_prevyValue = currY;


      //Timeout - to prevent wheels from digging a hole in the carpet!
      if( m_timer.HasElapsed( 3.0_s) )
      {
        std::cout<< "Timeout" << std::endl;
        m_currState++; //DONE!
      }

      break;



    //ABORT!!!!
    //Hang forever and prevent Autonomous from continuing......
    case 10:
      vx = 0;
      vy = 0;
      break;

  }

  //Detect State Change
  if( m_currState != m_prevState )
  {
    std::cout<< "CurrState: " << m_currState << std::endl;
    m_prevState = m_currState;
  }



  //-------------------------------------
  //  Rotational correction

  //Min turn power is 0.0625.
  //  Set Kp to reach 0.05 turn power at 1 deg error 
  const double TURN_MAX_VELOCITY = .25; 
  const double TURN_Kp           = (0.01 / 1.0);

  double delta_angle   = m_inputH - g_robotContainer.m_drivetrain.GetGyroYaw();  //GetGyroYaw returns [-inf to +inf ]

  double vr = abs( delta_angle * TURN_Kp );

  //Limit max drive
  if( vr > TURN_MAX_VELOCITY ) vr = TURN_MAX_VELOCITY;


  //-------------------------------------
  //  Write solution to drivetrain
  //    + delta angle:  +vr to correct (CCW)
  //    - delta angle:  -vr to correct (CW)

  if( delta_angle < 0 )
    g_robotContainer.m_drivetrain.Drive( vx, vy, -vr, Drivetrain::ROBOTCENTRIC);
  else
    g_robotContainer.m_drivetrain.Drive( vx, vy,  vr, Drivetrain::ROBOTCENTRIC);

}


void CmdDriveToAprilTag::End(bool interrupted) 
{
  std::cout<< "CmdDriveToAprilTag Done!" << std::endl;
  g_robotContainer.m_drivetrain.Stop();
}


bool CmdDriveToAprilTag::IsFinished() 
{
  return m_currState == 3;
}
