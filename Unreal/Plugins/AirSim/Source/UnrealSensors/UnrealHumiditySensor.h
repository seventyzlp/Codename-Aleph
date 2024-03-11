#pragma once

#include "NedTransform.h"
#include "common/AirSimSettings.hpp"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "sensors/humidity/HumiditySimple.hpp"




class UnrealHumiditySensor : public msr::airlib::HumiditySimple
{
public:
    typedef msr::airlib::AirSimSettings AirSimSettings;
	
    UnrealHumiditySensor(const AirSimSettings::HumiditySetting& setting,
                                              AActor* actor, const NedTransform* ned_transform);
	
    virtual float getHumidity() override;
	
private:
    AActor* actor_;
    const NedTransform* ned_transform_;
    float humidityvalue_;

    AActor* HumiditySensor;
    FDoubleProperty* HumidityProperty;

};
