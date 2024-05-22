# Police Department - Dispatcher Prototype

A prototype project for Police Department unit dispatcher system. I've created this project for First year of Computer Science Object Oriented Programming course.

### What it contains?
- Proof of concept for Emergency Call management system
- Object oriented structure for almost anything
- Interfaces (vftable) and lots of classes inherited from it
- UI/UX focused GUI utilizing Dear ImGui and OpenGL
- JSON parsing system using nlohmann json

### TODO
- [ ]  Implement all unit types (IDispatchableUnit)
    - [ ]  Police Unit 
    - [ ]  Ambulance Unit
    - [ ]  Fire Department Unit
- [ ]  Implement all emergency call types (IEmergencyCall)
    - [ ]  Medical Call
    - [ ]  Burglary Call
    - [ ]  Fire Call
    - [ ]  Shooting Call
- [ ]  Parse calls from json file
- [ ]  Finish up GUI

### Notes
- I created this project only for prototype, it has missing security features. Client can be easily reversed using IDA Pro (or Ghidra), ReClass, x64dbg. It is possible to make it harder to reverse if I use xorstrings, lazy imports, virtualizing, anti debugging features (through kernel) and store all important data in a real server.
- Currently it uses local files for parsing emergency call data but I am thinking about utilizing a server communication via protobufs.

### Used materials
- https://github.com/gabime/spdlog : Logging
- https://github.com/ocornut/imgui : GUI
- Valve Source SDK : Inspiration for naming conventions
- ChatGPT: Only for sample.json data generation.