// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Elevator.h"

class CmdElevatorSetLevel
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdElevatorSetLevel> {
 public:
  CmdElevatorSetLevel( elevator_level_t level );

  void Initialize() override;

  private:
  elevator_level_t m_level;
};
