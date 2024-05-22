#ifndef IEMERGENCYCALL_HPP
#define IEMERGENCYCALL_HPP

#include <iostream>
#include <string>
#include <vector>
#include "../enums/eunits.hpp"

// big fan of Valve
// exposing RTTI kinda risky 'cuz some IDA Pro big brains can reverse easily, but it's just a prototype...

class IDispatchableUnit;

class IEmergencyCall {
public:
	virtual ~IEmergencyCall() = default;

	virtual std::vector<EUnits> GetRelevantUnits() = 0; //@TODO: maybe implement vector from scratch?
	virtual void AssignUnit() = 0; // automatically assign to proper units
	virtual void AssignUnit(IDispatchableUnit* pUnit) = 0; // manually assign to a unit

	virtual void SetCallerName(const std::string& name) = 0;
	virtual void SetDetails(const std::string& details) = 0;
	virtual void SetLocation(const std::string& location) = 0;
	virtual std::string GetCallerName() = 0;
	virtual std::string GetDetails() = 0;
	virtual std::string GetLocation() = 0;

	// I believe I will use these
	virtual bool IsMedicalCall() = 0;
	virtual bool IsBurglaryCall() = 0;
	virtual bool IsFireCall() = 0; // couldn't find better name
	virtual bool IsShootingCall() = 0;
};

#endif //IEMERGENCYCALL_HPP