#include "RobotMap.h"
#include "subsystems/Drivetrain.h"

#include "commands/Drivetrain/TeleopMecanumDrive.h"

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain"){
	lf = new WPI_VictorSPX(DRIVE_MOT_LF);
	lr = new WPI_VictorSPX(DRIVE_MOT_LR);
	rf = new WPI_VictorSPX(DRIVE_MOT_RF);
	rr = new WPI_VictorSPX(DRIVE_MOT_RR);

	robotDrive = new MecanumDrive(lf, lr, rf, rr);
	//robotDrive.SetExpiration(0.1);

	//invert right side
	rf->SetInverted(true);
	rr->SetInverted(true);

	try {
		/***********************************************************************
		 * navX-MXP:
		 * - Communication via RoboRIO MXP (SPI, I2C, TTL UART) and USB.
		 * - See http://navx-mxp.kauailabs.com/guidance/selecting-an-interface.
		 *
		 * Multiple navX-model devices on a single robot are supported.
		 ************************************************************************/
		gyro = new AHRS(SPI::Port::kMXP);
	} catch (std::exception& ex ) {
		std::string err_string = "Error instantiating navX MXP:  ";
		err_string += ex.what();
		DriverStation::ReportError(err_string.c_str());
	}

}

void Drivetrain::InitDefaultCommand(){
	SetDefaultCommand(new TeleopMecanumDrive());
}

void Drivetrain::DriveMecanum(double throttle, double strafe, double turn, bool fieldCentric){
	if (fieldCentric){
		//field centric drive
		//robotDrive.MecanumDrive_Cartesian(throttle, strafe, turn, Drivetrain->GetGyroAngle());
		//robotDrive.driveCartesian(throttle, strafe, turn, Drivetrain->GetGyroAngle());
	} else {
		//not field centric
		//robotDrive.driveCartesian(throttle, strafe, turn);
	}
}

double Drivetrain::GetGyroAngle(){
	return gyro->GetAngle();
}