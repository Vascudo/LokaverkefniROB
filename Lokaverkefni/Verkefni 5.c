#pragma config(Sensor, in1,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, dgtl6,  sonarSensor,    sensorSONAR_cm)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port2,           armMotor,      tmotorVex269, openLoop)
#pragma config(Motor,  port4,           clawMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	    - Triple Sensor Line Tracking -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses 3 VEX Line Follower Sensors to track a black line on a light(er) surface 				*|
|*		and uses a sonic sensor to measure the distance needed to pick up a item with the claw.       	*|
|*                                      																															*|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Lighting conditions, line darkness, and surface lightness change from place to place,       *|
|*        so the value of 'threshold' may need to be changed to better suit your environment.					*|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor  - Port 1     rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor  - Port 10    leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Analog - Port 2     lineFollowerRIGHT   VEX Light Sensor      Front-right, facing down          *|
|*    Analog - Port 3     lineFollowerCENTER  VEX Light Sensor      Front-center, facing down         *|
|*    Analog - Port 1     lineFollowerLEFT    VEX Light Sensor      Front-left, facing down						*|
|*		Digital - Port 1		sonarSensor         Vex Sonic Sensor			Distance detector									*|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

void stopMotors(int waitTime)
{
	motor(rightMotor) = 0;
	motor(leftMotor) = 0;
	motor(armMotor) = 0;
	motor(clawMotor) = 0;
	wait1Msec(waitTime);
}

void clawOpen()
{
	motor(clawMotor) = -127;
	wait1Msec(3000);
}

void armDown()
{
	motor(armMotor) = -64;
	wait1Msec(1000);
}

void drive()
{
	motor(leftMotor) = 40;
	motor(rightMotor) = 40;
	wait1Msec(1000);
}

void clawClose()
{
	motor(clawMotor) = 127;
	wait1Msec(1000);
}

void armUp()
{
	motor(armMotor) = 64;
	wait1Msec(500);
}

void turn180()
{
	motor(rightMotor) = 67;
	motor(leftMotor) = -67;
	wait1Msec(500);
}

task main()
{
	clawClose();
	armUp();
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 2400;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */

  for(int i = 1; i <= 2;)
  {
	  while(true)
	  {
	    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
	    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
	    displayLCDPos(1,0);                                     //  Sensor    |
	    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
	    displayLCDPos(1,6);                                     //  to LCD.   |
	    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
	    displayLCDPos(1,12);                                    //  L  C  R   |
	    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
	    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+


	    // RIGHT sensor sees dark:
	    if(SensorValue(lineFollowerRIGHT) > threshold)
	    {
	      // counter-steer right:
	      motor[leftMotor]  = 67;
	      motor[rightMotor] = 0;
	    }
	    // CENTER sensor sees dark:
	    if(SensorValue(lineFollowerCENTER) > threshold)
	    {
	      // go straight
	      motor[leftMotor]  = 67;
	      motor[rightMotor] = 67;
	    }
	    // LEFT sensor sees dark:
	    if(SensorValue(lineFollowerLEFT) > threshold)
	    {
	      // counter-steer left:
	      motor[leftMotor]  = 0;
	      motor[rightMotor] = 67;
	    }
			if(i == 1)
			{
				i++;
			  if(SensorValue(sonarSensor) <= 30)
			  {
				  stopMotors(1000);
				  clawOpen();
				  armDown();
				  drive();
				  stopMotors(3000);
				  clawClose();
				  armUp();
				  turn180();
				}
			}

			if(i == 2)
			{

				  if(SensorValue(sonarSensor) <= 10)
				  {
					  stopMotors(1000);
					  clawOpen();
					  armDown();
					  drive();
					  stopMotors(3000);
					  clawClose();
					  armUp();
					  turn180();
					}
				}
			}

	}
	}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
