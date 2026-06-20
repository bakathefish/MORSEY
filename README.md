
<img width="468" height="665" alt="image" src="https://github.com/user-attachments/assets/e5c7a8f4-2c94-4bbe-aed2-ca8e1304eb37" />


# MORSEY

**a bare pcb keychain that decodes your morse code**

morsey is a bare pcb keychain that decodes your morse code. a short tap registers as a dot, a long hold is a dash, and the letters you spell with the dots and dashes show up on the little oled screen. one button does everything, and it runs off a single coin cell that clips in.

## why did i make it

i wanted to make something small and useful that i can attach to my keys, and since recently me and my friends started to learn morse code this is super helpful and lets you decode anything in morse code you see. and instead of a big board its just a super cheap tiny chip doing all of the work.


## bom

everything is in the bom, heres the list:

| No. | Qty | Comment | MPN | LCSC | Price (USD) | Total |
|-----|-----|---------|-----|------|-------------|-------|
| 1 | 1 | the MCU (WCH) | CH32V003J4M6 | [C5346354](https://www.lcsc.com/search?q=C5346354) | 0.2194 | 0.22 |
| 2 | 1 | oled module, SSD1306 0.96 inch 128x64 i2c | GMC096GW | [SSD1306 0.96](https://www.lcsc.com/search?q=SSD1306+0.96+128x64) | 1.50 | 1.50 |
| 3 | 1 | the button (XUNPU) | TS-1088-AR02016 | [C720477](https://www.lcsc.com/search?q=C720477) | 0.053 | 0.05 |
| 4 | 1 | coin cell holder (QIJEY) | CR2032-BS-6-1 | [C70377](https://www.lcsc.com/search?q=C70377) | 0.138 | 0.14 |
| 5 | 1 | CR2032 battery | CR2032 | local | 0.20 | 0.20 |
| 6 | 1 | buzzer (Huaneng) | MLT-5030 | [C95297](https://www.lcsc.com/search?q=C95297) | 0.5404 | 0.54 |
| 7 | 1 | 22 ohm res (Walsin) | WR06X22R0FTL | [C163887](https://www.lcsc.com/search?q=C163887) | 0.0025 | 0.01 |
| 8 | 1 | 100nF cap (Samsung) | CL10B104KB8NNNC | [C1591](https://www.lcsc.com/search?q=C1591) | 0.0115 | 0.01 |
| 9 | 1 | 10uF cap (Samsung) | CL10A106KP8NNNC | [C19702](https://www.lcsc.com/search?q=C19702) | 0.0265 | 0.03 |
| 10 | 1 | keyring / split ring (through the hole) | - | local | 0.05 | 0.05 |
| 11 | 1 | PCB | - | [JLCPCB](https://cart.jlcpcb.com/quote) | 2.00 | 2.00 |
|  |  |  |  |  | **Total** | **4.75** |

**schematic**

<img width="100%" alt="schematic" src="https://github.com/user-attachments/assets/dfa98473-59df-400b-abd0-5f2bc167fc84" />

**pcb (2 layer)**

<table>
  <tr>
    <td align="center"><b>front</b><br><img width="420" alt="pcb front" src="https://github.com/user-attachments/assets/6ced4252-bbe8-454a-a3bc-9527036158d0" /></td>
    <td align="center"><b>back</b><br><img width="420" alt="pcb back" src="https://github.com/user-attachments/assets/fda39d93-f71f-4b84-8426-19b22b5d52ac" /></td>
  </tr>
</table>

## assembly

1. solder all the parts onto the pcb. hot air or a fine tip iron both work. the ch32v003 is the fiddliest part so do it first.
2. drop a CR2032 into the holder.
3. flash the firmware with a WCH-LinkE on the SWIO pads (SWIO to pin 8, plus VCC and GND).
4. put a keyring or lanyard through the hole.
5. press the button to wake it, then tap your morse. theres no power switch, it sleeps on its own when idle.

note: nothing to set up in the firmware, just flash it and go. tap `... --- ...` to test, you should see SOS.


ps i added a 3d model if you want to use it but its not recommended since the pcb itself is very tiny anyways the pcb doesnt assemble with screws it has clips to attach the pieces
