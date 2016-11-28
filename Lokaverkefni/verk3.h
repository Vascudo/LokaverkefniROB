
void verk3()
{
		wait1Msec(2000);						// Robot waits for 2000 milliseconds before executing program
		while(SensorValue(lightSensor) > 150 && vexRT[Btn8L] == 0)
		{
			if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
			{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
				motor[rightMotor] = 63;			// Motor on port2 is run at half (63) power forward
				motor[leftMotor]  = 63;			// Motor on port3 is run at half (63) power forward
			}
			else if(SensorValue(sonarSensor) < 20)
			{
				motor[rightMotor] = 0;
				motor[leftMotor]  = 0;

				motor[rightMotor] = 63;			// Motor on port2 is run at half (63) power forward
				motor[leftMotor]  = -63;
				wait1Msec(750);
			}
		}
}
