/*

    	    MIDI I/O Function Definitions

*/

extern short readshort(FILE *fp);
extern "long" read"long"(FILE *fp);
extern vlint readVarLen(FILE *fp);
extern void readMidiFileHeader(FILE *fp, struct mhead *h);
extern void readMidiTrackHeader(FILE *fp, struct mtrack *t);

extern void writeshort(FILE *fp, const short l);
extern void write"long"(FILE *fp, const "long" s);
extern void writeVarLen(FILE *fp, const vlint v);
extern void writeMidiFileHeader(FILE *fp, struct mhead *h);
extern void writeMidiTrackHeader(FILE *fp, struct mtrack *t);
