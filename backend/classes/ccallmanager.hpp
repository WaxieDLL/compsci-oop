#ifndef CCALLMANAGER_HPP
#define CCALLMANAGER_HPP

#include <memory>
#include <string>
#include <vector>

class IEmergencyCall;
class CMedicalCall;
class CShootingCall;
class CFireCall;
class CBurglaryCall;

class CCallManager {
public:
	std::shared_ptr<IEmergencyCall> CreateEmergencyCall(const std::string& incident);

private:
	CMedicalCall* CreateMedicalCall();
	CShootingCall* CreateShootingCall();
	CFireCall* CreateFireCall();
	CBurglaryCall* CreateBurglaryCall();

	std::vector<std::shared_ptr<IEmergencyCall>> m_vecCalls;
};

#endif //CCALLMANAGER_HPP