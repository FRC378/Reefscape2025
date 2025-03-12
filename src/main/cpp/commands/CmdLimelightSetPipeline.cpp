// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdLimelightSetPipeline.h"
#include "Robot.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
CmdLimelightSetPipeline::CmdLimelightSetPipeline(int pipeline) 
{
  m_pipeline = pipeline;
}

// Called when the command is initially scheduled.
void CmdLimelightSetPipeline::Initialize() 
{
  g_robotContainer.m_limelight3.SetPipeline(m_pipeline);
}
