#define TX_PIN 9
#define BIT_PERIOD1 780
#define BIT_PERIOD2 260
#define TIMES 25


float times[TIMES] = {
 .0000, .00104, .002076, .003113,  .004149, .005185, .006221, .007258,
 .008294, .00933, .010366, .011404,  .01244, .013476, .014512, .015549,
 .016585, .017622, .018658, .019696,  .020731, .021768, .022804, .023841, .024876
};

int BIT_PERIOD[TIMES]={ 780,780,780,780,260,260, 780,780,260,780,260,780,780,780,780,780,780,780,780,780,780,780,260,260,260};

/* .0079 je razmak za 4 ova */
/*trajanje prva cetiri je 0.000780 to je 780ms */
/*peti je 0,000258 tj 260ms*/
/*sesti 260ms*/
/* 7,8 isto 780, 9. 260, 10. 780, 11. 260
12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 traju 780
23,24,25 po 260 */
void setup()
{
  pinMode(TX_PIN, OUTPUT);


  Serial.begin(115200);
  Serial.println("");
  Serial.println(F("Digital Ding Dong Ditch"));
  Serial.println(F("by Anica Vukovic"));
}

void ring_bell()
{
  Serial.println("Ringing!\n");

  // the actual doorbell sends our signal 4 times, so we'll emulate it
  for (int j = 0; j < 4; j++)
  {
		single_ring();
  }
}

void single_ring()
{
	int last = 0;

	// go through each "1" bit
	for (int i = 0; i < TIMES; i++)
	{
		// calculate microseconds (us)
		int us = times[i] * 1000000;
		if (i != 0)
			delayMicroseconds(us - last - BIT_PERIOD[i-1]);

		// send a "1" for our BIT_PERIOD which is around 700-800us 
		digitalWrite(TX_PIN, HIGH);
		delayMicroseconds(BIT_PERIOD[i]);
		digitalWrite(TX_PIN, LOW);

		last = us;
	}
	delay(8);
}


void loop()
{
	ring_bell();
  delay(10000);
}
