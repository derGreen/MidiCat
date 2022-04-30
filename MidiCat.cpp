#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main(int argc, char *argv[]) {

    string CSV_Line; 
    int lastTime = 0;
    int delimiterPos = 0;
    int velocity = 120;
    bool firstBeat = 1;   
    string foundChannel = " "; 
    
    string usrChannel = "2"; //argv[2];
    int usrOctaveShift = 1;
    string usrPath = argv[1];
    int usrSpeed = 1;
    
    const char *marimba[36] = {"vq","vq#","vw","vw#","ve","vr","vr#","vt","vt#","vz","vz#","vu","q","q#","w","w#","e","r","r#","t","t#","z","z#","u","^q","^q#","^w","^w#","^e","^r","^r#","^t","^t#","^z","^z#","^u"};
    const char *Piano[36] = {"v1","v1#","v2","v2#","v3","v4","v4#","v5","v5#","v6","v6#","v7","1","1#","2","2#","3","4","4#","5","5#","6","6#","7","^1","^1#","^2","^2#","^3","^4","^4#","^5","^5#","^6","^6#","^7"};
    
    
    cout << "Input CSV file? (midi files have to convert to CSV files): ";
    //cin >> usrPath;
    cout << argv[1];
    cout<< "\n";
    // Read from the text file
    ifstream usrCSV1(usrPath);

    if (usrCSV1.fail()) {
         cout << "No File found! \n";
        exit;
    }

    while (getline (usrCSV1, CSV_Line)) {   
        if (CSV_Line.find("Title_t")!= -1) {            
            foundChannel = foundChannel + CSV_Line.substr(0,CSV_Line.find(",")) + ", ";
        };

    };
    usrCSV1.close();

    ifstream usrCSV(usrPath);

    cout <<  foundChannel << " as Midichannel found \n";
    cout << "input channel to convert: ";
    cin >> usrChannel;
    //cout << argv[2];

    //cout << "ocrave shift? (dafault 1) \n";
    //cin >> usrOctaveShift;  

    cout << "File is created";
    ofstream OutFile("Cat Notes.txt");
    ofstream DebugFile("Debug.txt");
    OutFile << "Notes from " << usrPath;
    OutFile << "\n";
    OutFile << "!bongo+ ";
    cout << "\n";
    cout << "!bongo+ ";

    

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (usrCSV, CSV_Line)) {   
        
        // get Song velocity, from first Line, last argument        
        if (CSV_Line.find("Header")!= -1){
        string velocityStr = CSV_Line.substr(CSV_Line.rfind(",")+2,(CSV_Line.length()-CSV_Line.rfind(",")+2));        
        velocity = stoi(velocityStr); 
     
        }
        
        if (CSV_Line.find(usrChannel) == 0) { //nur Zeilen mit Channel in pos 0 

            if(CSV_Line.find("Note_on") != -1){ // nur Zeilen in denen ein Note_on command steht. 

                string midiChannelStr = CSV_Line.substr(delimiterPos, CSV_Line.find(",",delimiterPos)-delimiterPos);            
                delimiterPos = CSV_Line.find(",",delimiterPos)+1; 
                string midiTimeStr = CSV_Line.substr(delimiterPos, CSV_Line.find(",",delimiterPos)-delimiterPos);
                int midiTimeInt = stoi(midiTimeStr);
                delimiterPos = CSV_Line.find(",",delimiterPos)+1; 
                string midiCommand =CSV_Line.substr(delimiterPos, CSV_Line.find(",",delimiterPos)-delimiterPos);
                delimiterPos = CSV_Line.find(",",delimiterPos)+1; 
                string midiArgs =  CSV_Line.substr(delimiterPos, CSV_Line.find(",",delimiterPos)-delimiterPos);
                delimiterPos = CSV_Line.find(",",delimiterPos)+1; 
                string midiNote = CSV_Line.substr(delimiterPos, CSV_Line.find(",",delimiterPos)-delimiterPos);
                int midiNoteInt = stoi(midiNote);
                delimiterPos = CSV_Line.find(",",delimiterPos)+1;                
                string midiVelocity = CSV_Line.substr(delimiterPos, CSV_Line.length());                
                delimiterPos = 0; 

                //DebugFile << "Midi Chanel ist " << midiChannelStr << "\n";
                //DebugFile << "Midi Time ist " << midiTimeStr << "\n";
                //DebugFile << "Midi Command ist " << midiCommand << "\n";    
                

                //add octave shift 
                midiNoteInt = midiNoteInt - (usrOctaveShift*12); 
                //add Time divider 
                int catTime = midiTimeInt/velocity/usrSpeed;

                //cretae Cat readable Notes
                //.... PIANO Version! 
                //string catNote = Piano[(midiNoteInt % 36)]; 
                //.... MARIMBA Version! 
                string catNote = marimba[(midiNoteInt % 36)]; 

                //some Debug output here: 
                DebugFile << "Time: " << catTime << "  Note: " << catNote  << "\n";

                //Build Song
                    //find Pause
                if(!firstBeat) {
                  for (int i = 0; i < (catTime-lastTime); i++){            
                    OutFile << " . " ;
                    cout << " . " ;
                    DebugFile << "- time hop \n";
                  }
                }
                    //same beat or next beat   
                if (catTime == lastTime) {
                    OutFile << catNote << " ";
                    cout << catNote << " "; 
                } else  { 
                    OutFile << " " << catNote;    
                    cout << " " << catNote;                 
                }

                lastTime = catTime;
                firstBeat = false;

            }
            
        } 
        
    }

// Close the file
usrCSV.close();
OutFile.close();
cout << "\n";
}
