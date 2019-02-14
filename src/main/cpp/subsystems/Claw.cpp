#include "subsystems/Claw.h"
#include "RobotMap.h"
#include <frc/smartdashboard/SmartDashboard.h>

Claw::Claw() : frc::Subsystem("Claw"){
	claw_motor.reset(new frc::Servo(CLAW_MOT_1));
    claw_pot.reset(new frc::AnalogPotentiometer(CLAW_POT_1,3600,CLAW_POT_OFFSET_1));
}

void Claw::InitDefaultCommand(){
}

void Claw::MoveClawToFullClose(){
    //Close claw until claw pot value is less than recorded close value
    frc::SmartDashboard::PutString("Action","Move claw to Full Close");
    claw_motor->SetSafetyEnabled(false);
    do {
        if (claw_pot->Get() > CLAW_POT_VAL_FC) {
            claw_motor->Set(.25);
        } else if (claw_pot->Get() < CLAW_POT_VAL_FC) {
            claw_motor->Set(.75);
        }
        
    } while (claw_pot->Get() <= (CLAW_POT_VAL_FC - CLAW_POT_VAL_TOLERANCE) or claw_pot->Get() >= (CLAW_POT_VAL_FC + CLAW_POT_VAL_TOLERANCE));
    claw_motor->Set(.5);
}

void Claw::MoveClawToCaptureHatch(){
    //Open the claw until claw pot value is at or more than recorded capture value
    frc::SmartDashboard::PutString("Action","Move claw to Capture Hatch");
    claw_motor->SetSafetyEnabled(false);
    do {
        if (claw_pot->Get() > CLAW_POT_VAL_CH) {
            claw_motor->Set(.25);
        } else if (claw_pot->Get() < CLAW_POT_VAL_CH) {
            claw_motor->Set(.75);
        }
        
    } while (claw_pot->Get() <= (CLAW_POT_VAL_CH - CLAW_POT_VAL_TOLERANCE) or claw_pot->Get() >= (CLAW_POT_VAL_CH + CLAW_POT_VAL_TOLERANCE));
    claw_motor->Set(.5);
}

void Claw::MoveClawToFullOpen(){
    //Open the claw until claw pot value is at the max value
    frc::SmartDashboard::PutString("Action","Move claw to Full Open");
    claw_motor->SetSafetyEnabled(false);
    do {
        if (claw_pot->Get() > CLAW_POT_VAL_FO) {
            claw_motor->Set(.25);
        } else if (claw_pot->Get() < CLAW_POT_VAL_FO) {
            claw_motor->Set(.75);
        }
        
    } while (claw_pot->Get() <= (CLAW_POT_VAL_FO - CLAW_POT_VAL_TOLERANCE) or claw_pot->Get() >= (CLAW_POT_VAL_FO + CLAW_POT_VAL_TOLERANCE));
    claw_motor->Set(.5);
}

void Claw::MoveClawToCaptureCargo(){
    //Close the claw until claw pot value is at or below the recorded capture value
    frc::SmartDashboard::PutString("Action","Move claw to Capture Cargo");
    claw_motor->SetSafetyEnabled(false);
    do {
        if (claw_pot->Get() > CLAW_POT_VAL_CC) {
            claw_motor->Set(.25);
        } else if (claw_pot->Get() < CLAW_POT_VAL_CC) {
            claw_motor->Set(.75);
        }
        
    } while (claw_pot->Get() <= (CLAW_POT_VAL_CC - CLAW_POT_VAL_TOLERANCE) or claw_pot->Get() >= (CLAW_POT_VAL_CC + CLAW_POT_VAL_TOLERANCE));
    claw_motor->Set(.5);
}

void Claw::MoveClawToEmerHatchRelease(){
    //Close the claw until claw pot value is at or less than recorded min value
    frc::SmartDashboard::PutString("Action","Move claw to Emer Hatch Release");
    claw_motor->SetSafetyEnabled(false);
    do {
        if (claw_pot->Get() > CLAW_POT_VAL_EHR) {
            claw_motor->Set(.25);
        } else if (claw_pot->Get() < CLAW_POT_VAL_EHR) {
            claw_motor->Set(.75);
        }
        
    } while (claw_pot->Get() <= (CLAW_POT_VAL_EHR - CLAW_POT_VAL_TOLERANCE) or claw_pot->Get() >= (CLAW_POT_VAL_EHR + CLAW_POT_VAL_TOLERANCE));
    claw_motor->Set(.5);
}

double Claw::GetClawPotValue(){
    //Read the analogpot value and return the corrected value
    return claw_pot->Get();
}
