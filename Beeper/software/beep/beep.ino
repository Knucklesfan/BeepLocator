// look, i know this code doesn't  look like much right now
// the rough part is that the buzzers i decided to purchase need at least 2 gpio pins to be a sound quality i deem "decent"
// (that means volume ofc)
// therefore, it took me nearly all day to realize i could just bridge the two gpio pins together. so I bridged 4.
// the final product will have a PCB designed, but for now this is more than good enough.
// beeperPin is the first pin, and the offsetPins are the pins that are offset from that value that get toggled.

#define beeperPin 0 // lower range
#define offsetPins 4 // upper range
void beep(int feq, int duration) {
  for(int i = 0; i < offsetPins; i++) {
    tone(beeperPin + i, feq); // Set frequency to 1000 Hz
  }
  delay(duration);            // Play tone for 500 ms
  for(int i = 0; i < offsetPins; i++) {
    noTone(beeperPin + i); // Set frequency to 1000 Hz
  }
  delay(duration);            // Play tone for 500 ms

}
void setup() {
  // put your setup code here, to run once:
  pinMode(beeperPin, OUTPUT);


  beep(1000, 250);
  beep(1000, 250);

}

void loop() {
  // put your main code here, to run repeatedly:
  beep(1000, 1000);

}
