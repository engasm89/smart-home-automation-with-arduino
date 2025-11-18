/*
 * Course: Smart Home Automation With Arduino
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Smart Home Automation With Arduino" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/smart-home-automation-with-arduino/
 * Repository: https://github.com/engasm89/smart-home-automation-with-arduino
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

/*
 * Course: Smart Home Automation With Arduino
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

/*
 * Course: Smart Home Automation With Arduino
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

#include <stdio.h> // Include standard I/O for illustrative serial prints

// Define Arduino-like constants and stubs so the logic reads clearly
#define OUTPUT 1 // Pin mode output constant
#define INPUT_PULLUP 2 // Pin mode input with pull-up constant
#define HIGH 1 // Digital high
#define LOW 0 // Digital low

// Pin assignments for relays and a button
static const int RELAY1_PIN = 2; // Relay 1 connected to digital pin 2
static const int RELAY2_PIN = 3; // Relay 2 connected to digital pin 3
static const int BUTTON_PIN = 4; // Control button on digital pin 4

// Arduino-like function stubs (for illustration; on real hardware these come from Arduino)
void pinMode(int pin, int mode) { /* configure pin mode */ } // Configure a pin mode
int digitalRead(int pin) { return LOW; } // Read a pin state (placeholder)
void digitalWrite(int pin, int value) { /* set pin state */ } // Write a pin state
void delay(int ms) { /* wait */ } // Delay in milliseconds
int Serial_available(void) { return 0; } // Bytes available on serial (placeholder)
char Serial_read(void) { return '\0'; } // Read one byte from serial (placeholder)
void Serial_begin(long baud) { printf("Serial start %ld\n", baud); } // Start serial prints (illustrative)
void Serial_println(const char *s) { printf("%s\n", s); } // Print line (illustrative)

// Command buffer for simple serial commands
char cmd[32]; // Buffer to store incoming command
int cmd_len = 0; // Current length of command

// Setup function initializes IO
void setup(void) { // Initialize IO and serial
  pinMode(RELAY1_PIN, OUTPUT); // Relay 1 as output
  pinMode(RELAY2_PIN, OUTPUT); // Relay 2 as output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Button as input with pull-up
  digitalWrite(RELAY1_PIN, LOW); // Start with relay 1 off
  digitalWrite(RELAY2_PIN, LOW); // Start with relay 2 off
  Serial_begin(9600); // Initialize serial for monitoring
  Serial_println("Smart Home Automation ready"); // Status message
}

// Helper to process a completed text command
void processCommand(void) { // Parse and act on command buffer
  if (cmd_len == 0) return; // Ignore empty commands
  cmd[cmd_len] = '\0'; // Null-terminate command string
  if (!strcmp(cmd, "L1 ON")) { // If command is L1 ON
    digitalWrite(RELAY1_PIN, HIGH); // Turn relay 1 on
    Serial_println("Relay 1: ON"); // Feedback
  } else if (!strcmp(cmd, "L1 OFF")) { // If command is L1 OFF
    digitalWrite(RELAY1_PIN, LOW); // Turn relay 1 off
    Serial_println("Relay 1: OFF"); // Feedback
  } else if (!strcmp(cmd, "L2 ON")) { // If command is L2 ON
    digitalWrite(RELAY2_PIN, HIGH); // Turn relay 2 on
    Serial_println("Relay 2: ON"); // Feedback
  } else if (!strcmp(cmd, "L2 OFF")) { // If command is L2 OFF
    digitalWrite(RELAY2_PIN, LOW); // Turn relay 2 off
    Serial_println("Relay 2: OFF"); // Feedback
  } else if (!strcmp(cmd, "ALL OFF")) { // If command is ALL OFF
    digitalWrite(RELAY1_PIN, LOW); // Turn relay 1 off
    digitalWrite(RELAY2_PIN, LOW); // Turn relay 2 off
    Serial_println("All relays: OFF"); // Feedback
  } else { // Unknown command
    Serial_println("Unknown command"); // Feedback
  } // End conditional chain
  cmd_len = 0; // Reset command buffer length after processing
}

// Loop function continuously monitors button and serial commands
void loop(void) { // Main control loop
  int buttonPressed = (digitalRead(BUTTON_PIN) == LOW); // Read button state
  if (buttonPressed) { // If pressed (active low)
    digitalWrite(RELAY1_PIN, HIGH); // Turn on relay 1
    digitalWrite(RELAY2_PIN, HIGH); // Turn on relay 2
    Serial_println("Button pressed: both relays ON"); // Feedback
  } else { // If not pressed
    // Keep previous states; no change // No action
  } // End button check

  while (Serial_available()) { // While serial has data
    char c = Serial_read(); // Read one character
    if (c == '\n' || c == '\r') { // If end of line
      processCommand(); // Process the buffered command
    } else if (cmd_len < (int)sizeof(cmd) - 1) { // If buffer has space
      cmd[cmd_len++] = c; // Append character to command
    } // End buffering condition
  } // End serial read loop

  delay(100); // Small delay to reduce CPU usage
}

// Illustrative main to show call sequence on non-Arduino C targets
// Main routine: orchestrates the smart home automation with arduino scenario
int main(void) { // Program entry point
  setup(); // Initialize system
  for (int i = 0; i < 10; ++i) { // Simulate limited loop iterations
    loop(); // Run one control cycle
  } // End simulation loop
  return 0; // Exit program
}

