# Smart Home Automation With Arduino

## Course Snapshot

| Field | Details |
| --- | --- |
| Instructor | Ashraf S A AlMadhoun |
| Hardware Focus | Arduino |
| Course Link | https://www.udemy.com |
| Repository Updated | 2025-11-18 |

## Overview

Smart Home Automation With Arduino is a hands-on course focused on practical Arduino
development. This repository contains curated starter code, wiring notes, and a repeatable
workflow that mirrors the lessons from the video curriculum.

## Learning Objectives

- Understand the core goals of the **Smart Home Automation With Arduino** lessons.
- Map the theoretical material onto executable firmware samples.
- Practice reviewing telemetry / console logs with the provided samples.
- Customize the code to match your target hardware setup.

## Hardware & Components

Consult `CIRCUIT.md` for wiring notes. Typical builds require a development board,
sensors/actuators described in the Smart Home Automation With Arduino videos, jumper
wires, and a USB cable for programming plus logging.

## Setup Instructions

1. Install the latest Arduino IDE or your preferred toolchain.
2. Clone this repository or download it as a ZIP.
3. Review the `README.md`, `CIRCUIT.md`, and `data/` samples.
4. Upload the code to your dev board and monitor the serial console.

## Code Walkthrough

The `*.c` files are intentionally lightweight so you can focus on the core concept taught
in the course. Each file now includes metadata comments that summarize intent, I/O
expectations, and how telemetry maps to the lesson.

## Usage

```bash
# Build and inspect the sample on a desktop toolchain
gcc -Wall -Wextra -std=c11 *.c -o demo && ./demo

# Or upload via Arduino IDE to replicate the Smart Home Automation With Arduino lab
```

## Sample Data

Open `data/sample-telemetry.jsonl` to inspect representative console output. This is
useful when validating your hardware wiring or cloud logging pipeline.

## Additional Notes (Legacy Content)

# Smart Home Automation with Arduino

- Course: Smart Home Automation with Arduino
- Author: Ashraf S A AlMadhoun
- Link: https://www.udemy.com/course/arduino-smart-home-automation-with-arduino/?couponCode=JULYMAXDICOUNT

## Overview

This project demonstrates a simple smart home controller built on Arduino. It manages two relays (for lights or appliances) and a button, and accepts serial commands such as `L1 ON`, `L1 OFF`, `L2 ON`, `L2 OFF`, and `ALL OFF`. The serial interface allows easy integration with apps or home gateways.

## Code Explained

- Initializes relay pins as outputs and a button with an internal pull-up.
- Reads the button to toggle both relays and listens for serial commands.
- Processes commands in a lightweight buffer and prints status feedback.

## How To Use

- Open the `.c` file in Arduino IDE and adapt to an `.ino` sketch or C++ file.
- Connect two relay modules to digital pins `2` and `3`, a button to pin `4` (active LOW), and power rails to `5V`/`GND`.
- Use the Serial Monitor at `9600` baud to send commands.

## Purchase With Discount

Enroll now using the course link above to claim your limited-time discount and upgrade your smart home skills today.
