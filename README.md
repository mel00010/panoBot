# panoBot

## Update Monday March 12th
- Entire directory structure refactored to add some consistency
- Wrote Camera library to control the camera
- Started work on writing main()
- Wrote numerous utility functions as the avr-g++ compiler does not provide any of the C++ standard library headers
- Expanded and updated build system
- Modified build process to enable debugging, and create a target with debugging symbols included.  



## Update Sunday March 11th
- Servo controls for the most part figured out, still need to fine tune timings with hardwarde, but servos now have the ability to update/calculate their angles

- Buttons are finished may need to fine tune the debounce timings as needed, but outputting the correct information

- Screen code started, menu logic is still needed.

- Hardware debugger has arrived and finishing up final hardware configuration, planning on fine tuning with the hardware the upcomming week

- certain moving parts/cases are needing to be printed, planning on doing this Monday 03/12

## Update Sunday March 4th
- Update on project status: Due to hardware issues, the project has been reformed... we are now focusing on the firmware (Interfacing the Arduino board with the physical components: Buttons, toggle switch, servo, led display)

- The board as of Friday March 2 has been updated and is ready to undergo final testing. We now have a proper debugger for the board and can begin testing soft/hardware to ensure it will work properly.

- A PID(Proportion integral derivative) loop has been created to ensure servos will move to the appropriate place

- Button/Toggle switches are 90% done, all code is working (abstractly) but delay timings and port/switch numbers will be fine tuned later.

- Button debounce(noise reduction) implemented through software, this may need to be fine tuned, but will update as needed

- Servo timings have been selected, the prescaler , WGM (Wave Generation Mode) type has been selected 

- Physical display has minimal work, but as the deadline moves closer and members finish we will have multiple people working on the display

- Current goals: Finish rough draft of firmware, test with the board and fine tune timings. 

- Update although Google protobuf was originally planned as part of the project, as a way to interact with the panobot through a laptop, this has been put on hold while we ensure the firmware works properly. If adequate time is left over we will resume working on laptop/panobot interactions

## Update Sunday February 26th

- Spent most of the week working on hardware, the majority of which is complete
- Protobuff created for servo movement , camera communication
- GUI Template done, without buttons, this will be on hold until command line is more refined
(Zach , Ben , Justin, Mel)

## Update Sunday February 18th

- decided on google protobuf syntax/types
- Starting/Stopping 
- Movement:
	Elevation angle, servo angle
- Camera interactions:
	Focus
	Shutter
We all went through the tutorial for protobuf and made sure it is installed correctly/we are all using the correct documentation.

## The circuit board has been designed and built.

## Decided on using GTK+ for GUI, began work on GUI, currently in a rough mockup stage.
(Zach, Ben, Justin , Mel, John)