#include <bits/stdc++.h>
using namespace std;

class SmartDevice{
protected:
    int deviceID;
    string brandName;
    double powerRating;
public:
    SmartDevice(int id, string brand, double power)
        : deviceID(id), brandName(brand), powerRating(power) {}
    virtual ~SmartDevice() {}

    int getDeviceID() const{ return deviceID; }
    string getBrandName() const{ return brandName; }
    double getPowerRating() const{ return powerRating; }

    virtual void diagnose() const = 0;
};

enum TempMod{ cooling, heating, fan_only};

class ThermostatDevice : virtual public SmartDevice{
protected:
    double temperatureRange;
    TempMod mode;
    double minTemperature;
    double maxTemperature;
public:
    ThermostatDevice(int id, string brand, double power,
                     double minTemp, double maxTemp, TempMod deviceMode)
        : SmartDevice(id, brand, power),
          minTemperature(minTemp), maxTemperature(maxTemp), mode(deviceMode) {}

    double calculatePowerConsumption(double hours)const{
        return powerRating * hours;
    }

    void diagnose() const{
        cout << "\nThermostatDevice has been diagnosed\n";
        cout << "Brand: " << brandName << ", Mode: " << mode
             << ", Temperature Range: " << minTemperature << " to " << maxTemperature << " °C\n";
    }
};

class SecurityCameraDevice : virtual public SmartDevice{
protected:
    string resolution;
    double recordingHours;
public:
    SecurityCameraDevice(int id, string brand, double power,
                         string res, double recHours)
        : SmartDevice(id, brand, power),
          resolution(res), recordingHours(recHours){}

    double calculateDataUsage(double days) {
        double dataPerHour = (resolution == "4K") ? 2.0 : 1.0; // 2GB for 4K, 1GB for 1080p
        return dataPerHour * recordingHours * days;
    }

    void diagnose() const{
        cout << "\nSecurity Camera has been diagnosed\n";
        cout << "Brand: " << brandName << ", Resolution: " << resolution
             << ", Recording Hours per Day: " << recordingHours << "\n";
    }
};

class SmartThermostat : public ThermostatDevice{
private:
    bool remoteControlEnabled;
public:
    SmartThermostat(int id, string brand, double power,
                    double minTemp, double maxTemp, TempMod deviceMode, bool r)
        : SmartDevice(id, brand, power),
          ThermostatDevice(id, brand, power, minTemp, maxTemp, deviceMode),
          remoteControlEnabled(r) {}

    double calculatePowerConsumption(double hours) const {
        double baseConsumption = powerRating * hours;
        return baseConsumption * 0.9; // Assume 10% more efficiency
    }

    void diagnose() const{
        cout << "Smart Thermostat Diagnosis:\n";
        cout << "Brand: " << brandName << ", Remote Control: "
             << (remoteControlEnabled ? "Enabled" : "Disabled") << "\n";
    }
};

class HybridThermostat :public ThermostatDevice,public SecurityCameraDevice{
private:
    double energySavingEfficiency;
public:
    HybridThermostat(int id, string brand, double power,
                     double minTemp, double maxTemp, TempMod deviceMode,
                     string res, double recHours, double efficiency)
        : SmartDevice(id, brand, power),
          ThermostatDevice(id, brand, power, minTemp, maxTemp, deviceMode),
          SecurityCameraDevice(id, brand, power, res, recHours),
          energySavingEfficiency(efficiency) {}

    double calculatePowerConsumption(double hours) const{
        double baseConsumption = ThermostatDevice::calculatePowerConsumption(hours);
        return baseConsumption * (1 - (energySavingEfficiency / 100));
    }

    double calculateDataUsage(double days){
        double baseDataUsage = SecurityCameraDevice::calculateDataUsage(days);
        return baseDataUsage;
    }

    void diagnose() const{
        cout << "Hybrid Thermostat Diagnosis:\n";
        cout << "Brand: " << brandName << ", Energy Saving Efficiency: "
             << energySavingEfficiency << "%\n";
    }
};

void sort_devices_by_power(vector<SmartDevice*>& devices) {
    sort(devices.begin(), devices.end(),
         [](SmartDevice* a, SmartDevice* b) {
             return a->getPowerRating() > b->getPowerRating();
         });
}

int main() {
    vector<SmartDevice*> devices;

    devices.push_back(new ThermostatDevice(1, "ThermoBrand", 2000, 18.0, 30.0, heating));
    devices.push_back(new SecurityCameraDevice(2, "SecureCam", 150, "1080p", 12.0));
    devices.push_back(new SmartThermostat(3, "SmartThermo", 1800, 16.0, 28.0, cooling, true));
    devices.push_back(new HybridThermostat(4, "HybridTech", 1600, 17.0, 29.0, cooling, "4K", 10.0, 20.0));

    sort_devices_by_power(devices);

    cout << "Devices sorted by power rating:\n";
    for (auto& device : devices) {
        cout << "Device ID: " << device->getDeviceID()
             << ", Brand: " << device->getBrandName()
             << ", Power Rating: " << device->getPowerRating() << "W\n";
        device->diagnose();
        cout << "---------------------\n";
    }

    cout << "\nHybrid Thermostat Information:\n";
    for (auto& device : devices) {
        if (HybridThermostat* hybrid = dynamic_cast<HybridThermostat*>(device)) {
            cout << "Device ID: " << hybrid->getDeviceID()
                 << ", Brand: " << hybrid->getBrandName()
                 << ", Power Rating: " << hybrid->getPowerRating() << "W\n";
            hybrid->diagnose();
            cout << "---------------------\n";
        }
    }

    for (auto& device : devices) {
        delete device;
    }

    return 0;
}
