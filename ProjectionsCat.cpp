#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    string musicString = "";
    string note;

    const char *Marimba[37] = {"vq", "vq#", "vw", "vw#", "ve", "vr", "vr#", "vt", "vt#", "vy", "vy#", "vu", "q", "q#", "w", "w#", "e", "r", "r#", "t", "t#", "y", "y#", "u", "^q", "^q#", "^w", "^w#", "^e", "^r", "^r#", "^t", "^t#", "^y", "^y#", "^u", "."};
    const char *Piano[37] = {"v1", "v1#", "v2", "v2#", "v3", "v4", "v4#", "v5", "v5#", "v6", "v6#", "v7", "1", "1#", "2", "2#", "3", "4", "4#", "5", "5#", "6", "6#", "7", "^1", "^1#", "^2", "^2#", "^3", "^4", "^4#", "^5", "^5#", "^6", "^6#", "^7", "."};
    const char *Projection[37] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "H", "c", "c#", "d", "d#", "e", "f", "f#", "g", "g#", "a", "a#", "h", "c'", "c#'", "d'", "d#'", "e'", "f'", "f#'", "g'", "g#'", "a'", "a#'", "h'", "p"};

    map<string, string> noteTable;

    noteTable["#"] = "#";
    noteTable["."] = "p";
    noteTable[" "] = " ";
    noteTable["v1#"] = "C#";
    noteTable["v2"] = "D";
    noteTable["v2#"] = "D#";
    noteTable["v3"] = "E";
    noteTable["v4"] = "F";
    noteTable["v4#"] = "F#";
    noteTable["v5"] = "G";
    noteTable["v5#"] = "G#";
    noteTable["v6"] = "A";
    noteTable["v6#"] = "A#";
    noteTable["v7"] = "H";

    noteTable["1"] = "c";
    noteTable["1#"] = "c#";
    noteTable["2"] = "d";
    noteTable["2#"] = "d#";
    noteTable["3"] = "e";
    noteTable["4"] = "f";
    noteTable["4#"] = "f#";
    noteTable["5"] = "g";
    noteTable["5#"] = "g#";
    noteTable["6"] = "a";
    noteTable["6#"] = "a#";
    noteTable["7"] = "h";
    noteTable["^1"] = "c'";
    noteTable["^1#"] = "c'#";
    noteTable["^2"] = "d'";
    noteTable["^2#"] = "d'#";
    noteTable["^3"] = "e'";
    noteTable["^4"] = "f'";
    noteTable["^4#"] = "f'#";
    noteTable["^5"] = "g'";
    noteTable["^5#"] = "g'#";
    noteTable["^6"] = "a'";
    noteTable["^6#"] = "a'#";
    noteTable["^7"] = "h'";

    cout << "gib den Notentext ein (als BongoCat song, ohne '!bongo')";
    getline(cin, musicString);
    ofstream OutFile("PTV Notes.txt");
    OutFile << "piano ";
    string octave = "";
    cout << "Input: " << endl;
    cout << musicString << endl;
    cout << "Output: " << endl;

    for (int i = 0; i < musicString.length(); i++)
    {
        
        note = octave + musicString[i];
        octave = "";
        if (note == "v")
        {
            octave = "v";
        }
        else if (note == "^")
        {
            octave = "^";
        }

        cout << noteTable[note];
        OutFile << noteTable[note];
        
    }

    cout << " ProjectionsTV Midi text is created";
    // Close the file
    OutFile.close();
    cout << "\n";
}