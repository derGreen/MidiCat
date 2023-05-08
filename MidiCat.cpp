#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{

    string CSV_Line;
    int lastTime = 0;
    int delimiterPos = 0;
    int velocity = 120;
    bool firstBeat = 1;
    string foundChannel = " ";

    string usrChannel = "2"; // argv[2];
    string usrPath = argv[1];
    int elementCounter = 0;
    int catInst = 1;

    const char *Marimba[36] = {"vq", "vq#", "vw", "vw#", "ve", "vr", "vr#", "vt", "vt#", "vy", "vy#", "vu", "q", "q#", "w", "w#", "e", "r", "r#", "t", "t#", "y", "y#", "u", "^q", "^q#", "^w", "^w#", "^e", "^r", "^r#", "^t", "^t#", "^y", "^y#", "^u"};
    const char *Piano[36] = {"v1", "v1#", "v2", "v2#", "v3", "v4", "v4#", "v5", "v5#", "v6", "v6#", "v7", "1", "1#", "2", "2#", "3", "4", "4#", "5", "5#", "6", "6#", "7", "^1", "^1#", "^2", "^2#", "^3", "^4", "^4#", "^5", "^5#", "^6", "^6#", "^7"};
    const char *Drums[10] = {"x", "c", "b", "n", "m", "a", "s", "d", "f", "g"};

    map<int, string> gmInstFamiliy;

    gmInstFamiliy.insert(pair<int, string>(1, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(2, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(3, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(4, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(5, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(6, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(7, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(8, "Piano"));
    gmInstFamiliy.insert(pair<int, string>(9, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(10, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(11, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(12, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(13, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(14, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(15, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(16, "Chromatic Percussion"));
    gmInstFamiliy.insert(pair<int, string>(17, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(18, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(19, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(20, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(21, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(22, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(23, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(24, "Organ"));
    gmInstFamiliy.insert(pair<int, string>(25, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(26, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(27, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(28, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(29, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(30, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(31, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(22, "Guitar"));
    gmInstFamiliy.insert(pair<int, string>(33, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(34, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(35, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(36, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(37, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(38, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(39, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(40, "Bass"));
    gmInstFamiliy.insert(pair<int, string>(41, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(42, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(43, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(44, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(45, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(46, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(47, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(48, "Strings"));
    gmInstFamiliy.insert(pair<int, string>(49, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(50, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(51, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(52, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(53, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(54, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(55, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(56, "Ensemble"));
    gmInstFamiliy.insert(pair<int, string>(57, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(58, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(59, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(60, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(61, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(62, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(63, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(64, "Brass"));
    gmInstFamiliy.insert(pair<int, string>(65, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(66, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(67, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(68, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(69, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(70, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(71, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(72, "Reed"));
    gmInstFamiliy.insert(pair<int, string>(73, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(74, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(75, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(76, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(77, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(78, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(79, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(80, "Pipe"));
    gmInstFamiliy.insert(pair<int, string>(81, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(82, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(83, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(84, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(85, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(86, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(87, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(88, "Synth Lead"));
    gmInstFamiliy.insert(pair<int, string>(89, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(90, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(91, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(92, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(93, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(94, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(95, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(96, "Synth Pad"));
    gmInstFamiliy.insert(pair<int, string>(97, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(98, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(99, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(100, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(101, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(102, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(103, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(104, "Synth Effects"));
    gmInstFamiliy.insert(pair<int, string>(105, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(106, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(107, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(108, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(109, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(110, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(111, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(112, "Ethnic"));
    gmInstFamiliy.insert(pair<int, string>(113, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(114, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(115, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(116, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(117, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(118, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(119, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(120, "Percussive"));
    gmInstFamiliy.insert(pair<int, string>(121, "Sound Effects"));
    gmInstFamiliy.insert(pair<int, string>(122, "Sound Effects"));
    gmInstFamiliy.insert(pair<int, string>(123, "Sound Effects"));
    gmInstFamiliy.insert(pair<int, string>(124, "Sound Effects"));
    gmInstFamiliy.insert(pair<int, string>(125, "Sound Effects"));
    gmInstFamiliy.insert(pair<int, string>(126, "Sound Effects"));
    gmInstFamiliy.insert(pair<int, string>(127, "Sound Effects"));
    gmInstFamiliy.insert(pair<int, string>(128, "Sound Effects"));

    cout << gmInstFamiliy[1] << ", " << gmInstFamiliy[9] << ", "<< gmInstFamiliy[10] <<endl;

    //================================================
    // Start Programe here
    //================================================

    cout << "MIDIcat by GREEN, made for the JvPeek community (C)2022-2023";
    cout << "Input CSV file?: ";

    cout << argv[1]; // cin >> usrPath;
    cout << "\n";

    if (usrPath.substr(usrPath.find_last_of(".")) == ".mid") // find file extention and compare to .mid
    {
        cout << "File is Midi \n";
    }
    else
    {
        cout << "No Midi file \n";
        cout << "EXIT";
        return 3;
    }

    ifstream in_file(usrPath, ios::binary);
    in_file.seekg(0, ios::end);
    int file_size = in_file.tellg();
    cout << "Size of the file is " << file_size << " bytes" << endl;

    int MidiArray[file_size];
    cout << "MidiArray size is: " << file_size << endl;
    cout << "Array byte Size is: " << sizeof(MidiArray) / sizeof(int) << endl;

    // open the binary file for reading
    ifstream infile(usrPath, ios::binary);

    // check if the file was opened successfully
    if (!infile)
    {
        cerr << "Error: could not open file" << endl;
        return 1;
    }
    //========================================
    // make an array with byte values from Midi file
    //========================================

    // read the file byte by byte as integer
    unsigned char byte;
    while (infile.read(reinterpret_cast<char *>(&byte), sizeof(byte)))
    {
        int value = static_cast<int>(byte);
        MidiArray[elementCounter] = value;
        elementCounter++;
    }

    // close the file
    infile.close();

    // read Midi header here

    //====================================
    // 4 bytes ascii String "MThd"
    // 4 bytes number of bytes in Header (often just 06)
    // 2 bytes file format 0 or 1
    // 2 bytes number of tracks
    // 2 bytes ticks per quater note (speed)
    //====================================

    int headerSize = MidiArray[4];
    headerSize += MidiArray[5];
    headerSize += MidiArray[6] * 256;
    headerSize += MidiArray[7]; // Midi byte 4 to 7
    cout << "head size is: " << headerSize << endl;
    cout << endl;

    int midiTracks = MidiArray[10] * 256;
    midiTracks += MidiArray[11]; // Midi bytes 11 to 12
    if (MidiArray[9] + (MidiArray[8] * 256) == 0)
    {
        cout << "Singel track Midi file just " << midiTracks << " tarck" << endl;
    }
    else
    {
        cout << "Multi track Midi file, " << midiTracks << "  tracks" << endl;
    }

    int midiSpeed = MidiArray[12] * 256; // Midi bytes 13 to 14
    midiSpeed += MidiArray[13];          // Midi bytes 13 to 14
    cout << "Speed: " << midiSpeed << endl;

    int startTrack = 8 + headerSize;

    int bytesTrack0 = MidiArray[startTrack + 6] * 256; // Midi bytes 15 to 16
    bytesTrack0 += MidiArray[startTrack + 7];          // Midi bytes 15 to 16
    cout << "Number of Bytes in Track 0: " << bytesTrack0 << endl;
    cout << endl;

    int TrackNum = 0;
    while (startTrack < sizeof(MidiArray) / sizeof(int))
    {
        startTrack += bytesTrack0 + 8;
        TrackNum++;
        bytesTrack0 = MidiArray[startTrack + 6] * 256; // Midi bytes 15 to 16
        bytesTrack0 += MidiArray[startTrack + 7];      // Midi bytes 15 to 16
        cout << "Number of Bytes in Track " << TrackNum << ": " << bytesTrack0 << endl;
        cout << endl;

        // iterate throw the tracks
        int counter = 0;
        string trackName;
        int x = 0;
        int i = startTrack + 8;

        while (i <= startTrack + 8 + bytesTrack0)

        {

            if (MidiArray[i] == 255)
            {

                i++;
                if (MidiArray[i] == 3)
                {

                    i++;
                    counter = MidiArray[i];
                    x = 0;
                    i++;
                    while (x < counter)
                    {
                        trackName += MidiArray[i];
                        i++;
                        x++;
                    }
                    cout << "Track Name: " << trackName << endl;
                }
                else if (MidiArray[i] == 47)
                {
                    cout << "Midi FIle ende here";
                    return 5;
                }
            }

            i++;
        }
    }
    //==================================
    // get some infos here
    //==================================

    ifstream usrCSV(usrPath);

    /*
    cout << foundChannel << " found as Midichannel \n";

    cout << "Midi channel?";
    cin >> usrChannel;

    cout << "Instument? (1)Marimba (2)Piano (3)Drums \n";
    cin >> catInst;
    */

    //==================================
    // Create output file here
    //==================================

    cout << "Cat-file is created:";
    ofstream OutFile("Cat Notes.txt");
    ofstream DebugFile("Debug.txt");
    OutFile << "Notes from " << usrPath;
    OutFile << "\n";
    OutFile << "!bpm 400 \n";
    OutFile << "!bongo+ ";
    cout << "\n";
    cout << "!bpm 400 \n";
    cout << "!bongo+ ";

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(usrCSV, CSV_Line))
    {

        // get Song velocity, from first Line, last argument
        if (CSV_Line.find("Header") != -1)
        {
            string velocityStr = CSV_Line.substr(CSV_Line.rfind(",") + 2, (CSV_Line.length() - CSV_Line.rfind(",") + 2));
            velocity = stoi(velocityStr);
        }

        if (CSV_Line.find(usrChannel) == 0)
        { // nur Zeilen mit Channel in pos 0

            if (CSV_Line.find("Note_on") != -1)
            { // nur Zeilen in denen ein Note_on command steht.

                if (CSV_Line.find("0") != -1) // veruch die Note On mit Veolety 0 ausschließen.

                    string midiChannelStr = CSV_Line.substr(delimiterPos, CSV_Line.find(",", delimiterPos) - delimiterPos);
                delimiterPos = CSV_Line.find(",", delimiterPos) + 1;
                string midiTimeStr = CSV_Line.substr(delimiterPos, CSV_Line.find(",", delimiterPos) - delimiterPos);
                int midiTimeInt = stoi(midiTimeStr);
                delimiterPos = CSV_Line.find(",", delimiterPos) + 1;
                string midiCommand = CSV_Line.substr(delimiterPos, CSV_Line.find(",", delimiterPos) - delimiterPos);
                delimiterPos = CSV_Line.find(",", delimiterPos) + 1;
                string midiArgs = CSV_Line.substr(delimiterPos, CSV_Line.find(",", delimiterPos) - delimiterPos);
                delimiterPos = CSV_Line.find(",", delimiterPos) + 1;
                string midiNote = CSV_Line.substr(delimiterPos, CSV_Line.find(",", delimiterPos) - delimiterPos);
                int midiNoteInt = stoi(midiNote);
                delimiterPos = CSV_Line.find(",", delimiterPos) + 1;
                string midiVelocity = CSV_Line.substr(delimiterPos, CSV_Line.length());
                int midiVelInt = stoi(midiVelocity);
                delimiterPos = 0;

                midiNoteInt = midiNoteInt - (12); // add octave shift

                int catTime = midiTimeInt / velocity; // add Time divider
                string catNote = "";

                switch (catInst)
                { // cretae Cat readable Notes
                case 1:

                    catNote = Piano[(midiNoteInt % 36)]; //.... PIANO Version!
                    break;
                case 2:

                    catNote = Marimba[(midiNoteInt % 36)]; //.... MARIMBA Version!
                    break;
                case 3:

                    catNote = Drums[(midiNoteInt % 10)]; //.... Drum Version!
                    break;
                default:
                    cout << "No Instrument - No Song \n";
                    cout << "EXIT \n";
                    return 3;
                }

                if (midiVelInt != 0)
                {
                    // Build Song
                    // find Pause
                    if (!firstBeat)
                    {
                        for (int i = 1; i < (catTime - lastTime); i++)
                        {
                            OutFile << ". ";
                            cout << ". ";
                            DebugFile << "- Pause \n";
                        }
                    }
                    // same beat or next beat
                    if (catTime == lastTime)
                    {
                        OutFile << catNote << " ";
                        cout << catNote << " ";
                        DebugFile << "- Note: " << catNote << "\n";
                    }
                    else
                    {
                        OutFile << " " << catNote;
                        cout << " " << catNote;
                        DebugFile << "- blank \n";
                    }

                    lastTime = catTime;
                    firstBeat = false;
                }
            }
        }
    }

    // Close the file
    usrCSV.close();
    OutFile.close();
    cout << "\n";
}
