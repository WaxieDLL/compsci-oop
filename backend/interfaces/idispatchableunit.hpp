#ifndef IDISPATCHABLEUNIT_HPP
#define IDISPATCHABLEUNIT_HPP

#include <vector>
#include "iemergencycall.hpp"

class IDispatchableUnit {
public:
	virtual ~IDispatchableUnit() = default;

	virtual bool AssignCall(IEmergencyCall*) = 0; // returns true if successfully assigned
	virtual const std::vector<IEmergencyCall*> GetAssignedCalls() = 0;
	virtual void DropCalls() = 0; // basically vector.clear()

	// I could've used enum instead of this, but it makes the entire interface more readable (hopefully)
	virtual bool IsPoliceUnit() = 0;
	virtual bool IsEmergencyUnit() = 0;
	virtual bool IsFireUnit() = 0;
};

#endif //IDISPATCHABLEUNIT_HPP