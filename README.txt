#########################################
#                                       #
#             - Midi Cat - 		        #
#   create Bongocat notes form Midi	    #
#					                    #
#########################################

# How to
midi file have to convert to a csv file (so its more a scv to BongoCat converter bu this will chnage in future)

-start midiCat.exe in cmd
-Input CSV? paht to .csv file goes here. 
-Channel?, chose the midi channel mit the Melodie line you need, 0 to 15 (channel 0 is only Header, channel 10 is normaly Drums) you have to try. 
-Octave shift?, !Bongo+ has only 3 Octaves (C3 to H5) so Midi notes greater than this rollover and become lower notes again.  
    normal Note C4 is Midi value 60 is Keyboard key "Q" or "1" in BongoCat 
    when Octave Shift is 0 Bongo Key Q/1 is C3  
    when Octave Shift is 1 Bongo Key Q/1 is C4 (dafault)
    when Octave Shift is 2 Bongo Key Q/1 is C5

-copy paste text in chat, BongoCat will play it. 


#todo

-need to add channel names! data in midi file: 7, 0, Title_t, "Vocals" 

-Find out how matching speed for !bpm can be extractet from midi.

-integradte midi to CSV in midiCat. 

-export in txt file.

-show all midi channel at once, no chosing.

-find out haw many channels with Note_on command in file, to show in meune.

-two channel Support.

-Drumm support.

-cut Notes after 3 element at once to save letters. 

# History
28.04.22 create midiCat
