#ifndef CBURGLARYCALL_HPP
#define CBURGLARYCALL_HPP

#include "../../interfaces/iemergencycall.hpp"
#include "spdlog/spdlog.h"

class CBurglaryCall : public IEmergencyCall {
public:
#ifdef _DEBUG
	CBurglaryCall()
	{
		spdlog::info("CBurglaryCall created");
	}
	~CBurglaryCall() override
	{
		spdlog::warn("CBurglaryCall destroyed (Caller: {})", m_callerName);
	}
#endif
	std::vector<EUnits> GetRelevantUnits() override {
		return { UNIT_POLICE };
	}
	void AssignUnit() override;
	void AssignUnit(IDispatchableUnit* pUnit) override;
	void SetCallerName(const std::string& name) override
	{
		m_callerName = name;
	}
	void SetDetails(const std::string& details) override
	{
		m_details = details;
	}
	void SetLocation(const std::string& location) override
	{
		m_location = location;
	}
	std::string GetCallerName() override
	{
		return m_callerName;
	}
	std::string GetDetails() override
	{
		return m_details;
	}
	std::string GetLocation() override {
		return m_location;
	}
	bool IsMedicalCall() override {
		return false;
	}
	bool IsBurglaryCall() override {
		return true;
	}
	bool IsFireCall() override {
		return false;
	}
	bool IsShootingCall() override {
		return false;
	}
private:
	std::string m_callerName{};
	std::string m_details{};
	std::string m_location{};
};

#endif //CBURGLARYCALL_HPP