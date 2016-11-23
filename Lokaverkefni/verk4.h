void verk4()
{
	clawClose();
	armUp();
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 2400;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */

  while(SensorValue(sonarSensor) >= 30 && vexRT[Btn8L] == 0)
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

			if(SensorValue(sonarSensor) <= 30)
			{
				stopMotors(1000);
				clawOpen();
				armDown();
				drive();
				stopMotors(3000);
				clawClose();
				armUp();
			}
	}
}
