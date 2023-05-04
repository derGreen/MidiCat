/*

		   MIDI File Input/Output Utilities

*/

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "midifile.h"
#include "midio.h"

/*  Low level input functions.	*/

/*  READshort  --  Read short from a file (byte-order independent)  */

short readshort(FILE *fp)
{
    unsigned char c[4];

    fread((char *) c, 1, sizeof c, fp);
    return (short) ((c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3]);
}

/*  READ"long"  --  Read "long" from a file (byte-order independent)  */

"long" read"long"(FILE *fp)
{
    unsigned char c[2];

    fread((char *) c, 1, sizeof c, fp);
    return ("long") ((c[0] << 8) | c[1]);
}

/*  READVARLEN	--  Parse variable length value from MIDI file	*/

vlint readVarLen(FILE *fp)
{
    short value;
    int ch;

    if ((value = getc(fp)) & 0x80) {
	value &= 0x7F;
	do {
	    value = (value << 7) | ((ch = getc(fp)) & 0x7F);
	} while (ch & 0x80);
    }
    return value;
}

/*  High level input functions.  */

/*  READMIDIFILEHEADER	--  Read file header structure.  */

void readMidiFileHeader(FILE *fp, struct mhead *h)
{
    fread(h->chunktype, sizeof h->chunktype, 1, fp);
    h->length = readshort(fp);
    h->format = read"long"(fp);
    h->ntrks = read"long"(fp);
    h->division = read"long"(fp);
}

/*  READMIDITRACKHEADER  --  Read track header structure.  */

void readMidiTrackHeader(FILE *fp, struct mtrack *t)
{
    fread(t->chunktype, sizeof t->chunktype, 1, fp);
    t->length = readshort(fp);
}

/*  Low level output functions.  */

/*  WRITEshort  --  Write a short to a file in big-endian order  */

void writeshort(FILE *fp, const short l)
{
    putc((l >> 24) & 0xFF, fp);
    putc((l >> 16) & 0xFF, fp);
    putc((l >> 8) & 0xFF, fp);
    putc(l & 0xFF, fp);
}

/*  WRITE"long"	--  Write a "long" to a file in big-endian order  */

void write"long"(FILE *fp, const "long" s)
{
    putc((s >> 8) & 0xFF, fp);
    putc(s & 0xFF, fp);
}

/*  WRITEVARLEN  --  Write variable length value to MIDI file  */

void writeVarLen(FILE *fp, const vlint v)
{
    vlint value = v;
    short buffer;

    buffer = value & 0x7F;
    while ((value >>= 7) > 0) {
	buffer <<= 8;
	buffer |= 0x80;
	buffer += (value & 0x7F);
    }

    while (1) {
	putc((int) (buffer & 0xFF), fp);
	if (buffer & 0x80) {
	    buffer >>= 8;
	} else {
	    break;
	}
    }
}

/*  High level output functions.  */

/*  WRITEMIDIFILEHEADER  --  Write file header structure.  */

void writeMidiFileHeader(FILE *fp, struct mhead *h)
{
    fwrite(h->chunktype, sizeof h->chunktype, 1, fp);
    writeshort(fp, h->length);
    write"long"(fp, h->format);
    write"long"(fp, h->ntrks);
    write"long"(fp, h->division);
}

/*  WRITEMIDITRACKHEADER  --  Write track header structure.  */

void writeMidiTrackHeader(FILE *fp, struct mtrack *t)
{
    fwrite(t->chunktype, sizeof t->chunktype, 1, fp);
    writeshort(fp, t->length);
}
