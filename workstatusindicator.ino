// initialize published variables
String version     = "2020.06.12.2";
String work_status = "uninitialized";
String last_status = "none";

String STATUS_IN_MEETINGS = "In Meetings";
String STATUS_WORKING     = "Working";
String STATUS_AVAILABLE   = "Available";
String STATUS_OFF         = "Off";

int RED_LED    = D0;
int YELLOW_LED = D1;
int GREEN_LED  = D2;

int HEARTBEAT_LED = D7;

int ONE_SECOND = 1000;

void setup() {
    // setup heart beat LED and turn it off
    pinMode(HEARTBEAT_LED, OUTPUT);
    digitalWrite(HEARTBEAT_LED, LOW);
    
    //setup status LEDs and turn them off
    pinMode(GREEN_LED, OUTPUT);
    digitalWrite(GREEN_LED, LOW);  
    
    pinMode(YELLOW_LED, OUTPUT);
    digitalWrite(YELLOW_LED, LOW);  
    
    pinMode(RED_LED, OUTPUT);
    digitalWrite(RED_LED, LOW);   
    
    // initialize published variables
    Particle.variable("version", version);
    Particle.variable("work_status", work_status);
    Particle.variable("last_status", last_status);
    
    // setup published functions
    Particle.function("in_meetings", in_meetings);
    Particle.function("working", working);
    Particle.function("available", available);
    Particle.function("off", off);
}

void loop() {
    // blink LED on and off every second to to indicate photon is alive
    digitalWrite(HEARTBEAT_LED, HIGH);
    delay(ONE_SECOND);
    digitalWrite(HEARTBEAT_LED, LOW);
    delay(ONE_SECOND);
}

// set status to 'in meeting' and turn on the red lamp
int in_meetings(String argument) {
    last_status = work_status;
    work_status = STATUS_IN_MEETINGS;
    illuminate_red_led();
    return 0;
}

// set status to 'working' and turn on the yellow lamp
int working(String argument) {
    last_status = work_status;
    work_status = STATUS_WORKING;
    illuminate_yellow_led();
    return 0;
}

// set status to 'available' and turn on the green lamp
int available(String argument) {
    last_status = work_status;
    work_status = STATUS_AVAILABLE;
    illuminate_green_led();
    return 0;
}

// turn off all lamps
int off(String argument) {
    last_status = work_status;
    work_status = STATUS_OFF;
    turn_off_leds();
    return 0;
}

// illuminate the green lamp
void illuminate_green_led() {
    digitalWrite(RED_LED, LOW);     // make sure red is off before turning green on
    digitalWrite(YELLOW_LED, LOW);  // make sure yellow is off before turning green on
    digitalWrite(GREEN_LED, HIGH);  // turn green on
}

// illuminate the yellow lamp
void illuminate_yellow_led() {
    digitalWrite(RED_LED, LOW);     // make sure red is off before turning yellow on
    digitalWrite(GREEN_LED, LOW);   // make sure green is off before turning yellow on
    digitalWrite(YELLOW_LED, HIGH); // turn yellow on
}

// illuminate the red lamp
void illuminate_red_led() {
    digitalWrite(GREEN_LED, LOW);   // make sure green is off before turning red on
    digitalWrite(YELLOW_LED, LOW);  // make sure yellow is off before turning red on
    digitalWrite(RED_LED, HIGH);    // turn red on
}

// turn off all leds
void turn_off_leds() {
    digitalWrite(GREEN_LED, LOW);   
    digitalWrite(YELLOW_LED, LOW);  
    digitalWrite(RED_LED, LOW);    
}
