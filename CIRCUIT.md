# Smart Home Automation with Arduino — Circuit Schematic

- Course: Smart Home Automation with Arduino
- Author: Ashraf S A AlMadhoun
- Link: https://www.udemy.com/course/arduino-smart-home-automation-with-arduino/?couponCode=JULYMAXDICOUNT

## Connections

- Arduino `D2` → Relay Module 1 `IN`
- Arduino `D3` → Relay Module 2 `IN`
- Arduino `D4` → Button (to GND), with internal pull-up
- Arduino `5V` → Relay VCC, Button VCC (if external pull-up used)
- Arduino `GND` → Relay GND, Button GND

## Diagram (ASCII)

```
         +-----------------------+
         |       Arduino UNO     |
         |                       |
     D2 o|----> Relay1 IN        |
     D3 o|----> Relay2 IN        |
     D4 o|----> [Button]---GND   |
     5V o|----> Relay VCC        |
    GND o|----> Relay GND        |
         +-----------------------+

 Relay1: VCC->5V, GND->GND, IN->D2
 Relay2: VCC->5V, GND->GND, IN->D3
 Button: One side -> D4, other side -> GND (INPUT_PULLUP)
```

## Notes

- Use relay modules with optocouplers when switching mains loads.
- Keep mains wiring isolated and follow safety standards.

## Purchase With Discount

Unlock the full course with a discounted price — use the link above and start building now.

