#define STEREO         // Define this for SBPro CT-1330 or later card.
#define OPL3           // Also define this for SBPro CT-1600 or later card.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

#define KEYON	 0x20     // key-on bit in regs b0 - b8

// These are offsets from the base I/O address.
#define FM       8        // SB (mono) ports (e.g. 228H and 229H)
#define PROFM1   0        // On CT-1330, this is left OPL-2.  On CT-1600 and
			  // later cards, it's OPL-3 bank 0.
#define PROFM2   2        // On CT-1330, this is right OPL-2.  On CT-1600 and
			  // later cards, it's OPL-3 bank 1.

#define LEFT    75
#define RIGHT	77

unsigned IOport;        // Sound Blaster port address

void mydelay(unsigned long clocks)
{
   unsigned long elapsed=0;
   unsigned int last,next,ncopy,diff;

   // Read the counter value.
   outp(0x43,0);                              // want to read timer 0
   last=inp(0x40);                            // low byte
   last=~((inp(0x40)<< 8) + last);            // high byte

   do {
      // Read the counter value.
      outp(0x43,0);                           // want to read timer 0
      next=inp(0x40);                         // low byte
      ncopy=next=~((inp(0x40)<< 8) + next);   // high byte

      next-=last; // this is now number of elapsed clock pulses since last read
      elapsed += next; // add to total elapsed clock pulses
      last=ncopy;
   } while (elapsed<clocks);
}

int base16(char **str, unsigned *val)
// Takes a double pointer to a string, interprets the characters as a
// base-16 number, and advances the pointer. Returns 0 if successful, 1 if not.
{
   char c;
   int digit;
   *val = 0;

   while ( **str != ' ')
   {
      c = toupper(**str);
      if (c >= '0' && c <= '9') digit = c - '0';
      else if (c >= 'A' && c <= 'F') digit = c - 'A'  + 10;
      else return 1; // error in string

      *val = *val * 16 + digit;
      (*str)++;
   }
   return 0;
}

int base10(char **str, unsigned *val)
// Takes a double pointer to a string, interprets the characters as a
// base-10 number, and advances the pointer.
// Returns 0 if successful, 1 if not.
{
   char c;
   int digit;
   *val = 0;

   while ( **str != ' ')
   {
      c = toupper(**str);
      if (c >= '0' && c <= '9') digit = c - '0';
      else return 1;          // error in string

      *val = *val * 10 + digit;
      (*str)++;
   }
   return 0;
}

unsigned ReadBlasterEnv(unsigned *port, unsigned *irq, unsigned *dma8, unsigned *dma16)
// Gets the Blaster environment statement and stores the values in the
// variables whose addresses were passed to it. Returns: 0  if successful,
// 1 if there was an error reading the port address, 2 if there was an error
// reading the IRQ number, 3  if there was an error reading the 8-bit DMA
// channel and 4 if there was an error reading the 16-bit DMA channel.
{
   char     *env;
   unsigned val;
   int      digit;

   env = getenv("BLASTER");

   while (*env) {
      switch(toupper( *(env++) )) {
	 case 'A':
	    if (base16(&env, port))     // interpret port value as hex
	       return 1;                // error
	    break;
	 case 'I':
	    if (base10(&env, irq))      // interpret IRQ as decimal
	       return 2;                // error
	    break;
	 case 'D':
	    if (base10(&env, dma8))     // 8-bit DMA channel is decimal
	       return 3;
	    break;
	 case 'H':
	    if (base10(&env, dma16))    // 16-bit DMA channel is decimal
	       return 4;
	    break;
	 default:
	    break;
      }
   }
   return 0;
}

void FMoutput(unsigned port, int reg, int val)
// This outputs a value to a specified FM register at a specified FM port.
{
   outp(port, reg);
   outp(port+1, val);
}

void fm(int reg, int val)
// This function outputs a value to a specified FM register at the Sound
// Blaster (mono) port address.
{
   FMoutput(IOport+FM, reg, val);
}

void Profm1(int reg, int val)
// This function outputs a value to a specified FM register at the Sound
// Blaster Pro left FM port address (or OPL-3 bank 0).
{
   FMoutput(IOport+PROFM1, reg, val);
}

void Profm2(int reg, int val)
// This function outputs a value to a specified FM register at the Sound
// Blaster Pro right FM port address (or OPL-3 bank 1).
{
   FMoutput(IOport+PROFM2, reg, val);
}
