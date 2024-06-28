# Police Department - Dispatcher Prototype

A prototype project for Police Department unit dispatcher system. I've created this project for First year of Computer Science Object Oriented Programming course.

### What it contains?
- Proof of concept for Emergency Call management system
- Object oriented structure for almost anything
- Interfaces (vftable) and lots of classes inherited from it
- UI/UX focused GUI utilizing Dear ImGui and OpenGL
- JSON parsing system using nlohmann json

### TODO
- [x]  Implement all unit types (IDispatchableUnit)
    - [x]  Police Unit 
    - [x]  Ambulance Unit
    - [x]  Fire Department Unit
- [ ]  Implement all emergency call types (IEmergencyCall)
    - [ ]  Medical Call
    - [ ]  Burglary Call
    - [ ]  Fire Call
    - [ ]  Shooting Call
- [x]  Parse calls from json file
- [ ]  Finish up GUI

### Used materials
- https://github.com/gabime/spdlog : Logging
- https://github.com/ocornut/imgui : GUI
- ChatGPT: Only for sample.json data generation.
